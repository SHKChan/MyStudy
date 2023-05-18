# TODO
H = 0


def get_int(str):
    while True:
        rec = input(str)
        try:
            x = eval(rec)
            if type(x) == int:
                break
        except:
            pass

    return x


def printSharp(number):
    if number < 1:
        return
    printSharp(number-1)

    str = " "*(H-number) + "*"*number + "  " + "*"*number
    print(str)


while True:
    H = get_int("Height: ")
    if H > 0:
        break

printSharp(H)
