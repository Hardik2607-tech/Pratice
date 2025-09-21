from typing import List

def shortestToChar(s: str, c: str) -> List[int]:
    n = len(s)
    answer = [float("inf")] * n

    # Left-to-right pass
    prev = -float("inf")
    for i in range(n):
        if s[i] == c:
            prev = i
        answer[i] = i - prev

    # Right-to-left pass
    prev = float("inf")
    for i in range(n - 1, -1, -1):
        if s[i] == c:
            prev = i
        answer[i] = min(answer[i], prev - i)

    return answer


# Example usage
print(shortestToChar("loveleetcode", "e"))  # [3,2,1,0,1,0,0,1,2,2,1,0]
print(shortestToChar("aaab", "b"))          # [3,2,1,0]
