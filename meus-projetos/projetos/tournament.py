import csv
import sys
import random

# Quantas vezes o torneio será simulado
N = 1000

# Simula um jogo entre duas equipes com base em suas classificações
def simulate_game(team1, team2):
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

# Simula uma rodada de jogos (ex: oitavas, quartas, etc.)
def simulate_round(teams):
    winners = []
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners

# Simula um torneio completo até sobrar um campeão
def simulate_tournament(teams):
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]

# Função principal
def main():
    # Verifica se o arquivo foi passado como argumento
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    counts = {}

    # Lê os times do arquivo CSV
    filename = sys.argv[1]
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            team = {
                "team": row["team"],
                "rating": int(row["rating"])
            }
            teams.append(team)

    # Simula o torneio N vezes e conta os vencedores
    for _ in range(N):
        winner = simulate_tournament(teams.copy())
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    # Exibe os resultados ordenados por maior chance de vitória
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        percentage = (counts[team] / N) * 100
        print(f"{team}: {percentage:.1f}% chance of winning")

# Executa a função principal
if __name__ == "__main__":
    main()

