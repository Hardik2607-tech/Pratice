from typing import List

def shiftingLetters(s: str, shifts: List[int]) -> str:
    n = len(s)
    total_shift = 0
    result = []

    # Traverse from the end and accumulate total shifts
    for i in range(n - 1, -1, -1):
        total_shift = (total_shift + shifts[i]) % 26
        # Shift current character
        new_char = chr((ord(s[i]) - ord('a') + total_shift) % 26 + ord('a'))
        result.append(new_char)

    # Reverse the result because we processed from end to start
    return ''.join(reversed(result))


# 🧩 Test Cases
print(shiftingLetters("abc", [3, 5, 9]))    # Output: "rpl"
print(shiftingLetters("aaa", [1, 2, 3]))    # Output: "gfd"
print(shiftingLetters("xyz", [1, 1, 1]))    # Output: "yay"
print(shiftingLetters("z", [52]))           # Output: "z"
print(shiftingLetters("abc", [0, 0, 0]))    # Output: "abc"
