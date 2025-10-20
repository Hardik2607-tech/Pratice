def decodeString(s: str) -> str:
    stack = []
    curr_str = ""
    curr_num = 0

    for ch in s:
        if ch.isdigit():
            curr_num = curr_num * 10 + int(ch)
        elif ch == '[':
            stack.append((curr_str, curr_num))
            curr_str = ""
            curr_num = 0
        elif ch == ']':
            prev_str, num = stack.pop()
            curr_str = prev_str + num * curr_str
        else:
            curr_str += ch

    return curr_str


# 🔹 Example Test Cases
print(decodeString("3[a]2[bc]"))      # Output: "aaabcbc"
print(decodeString("3[a2[c]]"))       # Output: "accaccacc"
print(decodeString("2[abc]3[cd]ef"))  # Output: "abcabccdcdcdef"
print(decodeString("10[a]"))          # Output: "aaaaaaaaaa"
