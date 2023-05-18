# TODO
from functools import cached_property
from enum import Enum


def main():
    card = get_int("Please input your credit card number: ")
    print()
    print(f"{creditCard(whichCard(card)).name}")


def luhnsAlgorithm(numberStr):
    sum = 0
    length = len(numberStr)
    for i in range(length):
        if (i+1) % 2 == 0:
            temp = str(int(numberStr[i])*2)
            for i in range(len(temp)):
                sum += int(temp[i])
        else:
            sum += int(numberStr[i])

    return str(sum)[-1] == "0"


class creditCard(Enum):
    INVALID = 0
    AMEX = 1
    MASTERCARD = 2
    VISA = 3


def whichCard(cardNumber):
    # Convert into string and reverse string
    numberStr = str(cardNumber)
    cardType = creditCard(0)
    match len(numberStr):
        case 15:
            if numberStr[0:2] in {"34", "37"}:
                cardType = creditCard(1)
        case 16:
            if numberStr[0:2] in {"51", "52", "53", "54", "55"}:
                cardType = creditCard(2)
            elif numberStr[0] == "4":
                cardType = creditCard(3)
        case 13:
            if numberStr[0] == "4":
                cardType = creditCard(3)

    return cardType.value*luhnsAlgorithm(numberStr[::-1])


def get_int(str):
    while True:
        rec = input(str)
        try:
            x = eval(rec)
            if type(x) == int:
                break
        except:
            print(f"foo")
            pass

    return x


if __name__ == "__main__":
    main()
