while True:
    try:
        troco = float(input("change owed: "))
        if troco >= 0:
            break
    except ValueError:
        pass #ignora se o valor nao for numero

#converte para centavos e arredonda
centavos = round(troco * 100)
moedas = 0

#moeda 25
moedas_25 = centavos //25
centavos %=25

# moedda10
moedas_10 = centavos //10
centavos %=10

#moedas5
moedas_5 = centavos //5
centavos %=5

#moedas 1
moedas_1 = centavos

total = moedas_25 + moedas_10 + moedas_5 + moedas_1


print(f"total de moedas: {total}")
print(f"moedas de 25: {moedas_25}")
print(f"moedas de 10: {moedas_10}")
print(f"moedas de 5: {moedas_5}")
print(f"moedas de 1: {moedas_1}")
