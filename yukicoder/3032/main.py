def main():
    n = int(input())

    for _ in range(n):
        a, b = map(int, input().split())
        if a.__eq__(b):
            print(chr(61))
        elif a.__lt__(b):
            print(chr(60))
        else:
            print(chr(62))


if __name__ == "__main__":
    main()
