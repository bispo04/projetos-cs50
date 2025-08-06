def luhn_checksum(card_number):
    total = 0
    reversed_digits = card_number[::-1]

    for i, digit in enumerate(reversed_digits):
        n = int(digit)
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9
        total += n

    return total % 10 == 0


def get_card_type(number):
    length = len(number)
    start = number[:2]
    start1 = number[0]

    if luhn_checksum(number):
        if length == 15 and start in ["34", "37"]:
            return "AMEX"
        elif length == 16 and start in ["51", "52", "53", "54", "55"]:
            return "MASTERCARD"
        elif length in [13, 16] and start1 == "4":
            return "VISA"
        else:
            return "INVALID"
    else:
        return "INVALID"


def main():
    while True:
        number = input("Number: ")
        if number.isdigit():
            break

    print(get_card_type(number))


if __name__ == "__main__":
    main()
