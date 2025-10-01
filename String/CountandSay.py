def countAndSay(n: int) -> str:
    s = "1"
    for _ in range(n - 1):  # repeat n-1 times
        i, next_seq = 0, []
        while i < len(s):
            count = 1
            # Count consecutive identical digits
            while i + 1 < len(s) and s[i] == s[i + 1]:
                i += 1
                count += 1
            next_seq.append(str(count) + s[i])
            i += 1
        s = "".join(next_seq)
    return s


# Example test cases
if __name__ == "__main__":
    print(countAndSay(1))  # "1"
    print(countAndSay(2))  # "11"
    print(countAndSay(3))  # "21"
    print(countAndSay(4))  # "1211"
    print(countAndSay(5))  # "111221"
