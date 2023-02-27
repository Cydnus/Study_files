# import sys
# sys.stdin = open("input.txt", "r")


def increase(appear, num, now):
    while num > 0:
        appear[num % 10] += now
        num = int(num / 10)
    return appear


def cals(a, b, appear):
    now = 1
    a = a if a != 0 else 1
    while a <= b:
        while a % 10 != 0 and a <= b:
            appear = increase(appear, a, now)
            a += 1
        if a > b:
            break

        while b % 10 != 9 and a <= b:
            appear = increase(appear, b, now)
            b -= 1

        a = int(a / 10)
        b = int(b / 10)
        cnt = b - a + 1

        appear = [i + cnt * now for i in appear]
        now *= 10

    return appear


if __name__ == "__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        a, b = map(int, input().split())

        appear = [0 for _ in range(10)]

        appear = cals(a, b, appear)

        total = 0
        for i in range(len(appear)):
            total += i * appear[i]

        print(f"#{test_case} {total}")
