def main():
    s = input()
    ch = "…"

    cnt, max_cnt = 0, 0
    for c in s:
        if c == ch:
            cnt += 1
        else:
            cnt = 0
        max_cnt = max(max_cnt, cnt)
    print(max_cnt)


if __name__ == "__main__":
    main()
