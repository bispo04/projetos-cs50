def get_altura():
    while True:
        try:
            n = int(input("high: "))
            if 1<=n <= 8 :
                return n
        except ValueError:
            continue

altura = get_altura()

for i in range(1, altura + 1):
    espacos = altura - i
    blocos = i
    print(" " * espacos + "#" * blocos + " " + "#" * blocos )
