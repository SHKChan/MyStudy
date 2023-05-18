# TODO
from re import L


def main():
    text = get_str('Please input text: ')
    print(colemanLiauFormula(text))


def colemanLiauFormula(text):
    letters = 0
    words = 0
    sentences = 0
    for str in text:
        if str == ' ':
            words += 1
        if str in {'.', '!', '?'}:
            sentences += 1
        elif str.isalpha():
            letters += 1

    if text != '':
        words += 1

    L = letters / words * 100
    S = 100 / (words / sentences)

    grade = round(0.0588*L - 0.296*S - 15.8)

    return ('Before Grade 1' if grade < 1 else
            'Grade 16+' if grade > 16 else
            f'Grade: {int(grade)}')


def get_str(str):
    rec = input(str)
    return rec


if __name__ == "__main__":
    main()
