from collections import Counter

def maxNumberOfBalloons(text: str) -> int:
    count = Counter(text)
    return min(
        count['b'] // 1,
        count['a'] // 1,
        count['l'] // 2,
        count['o'] // 2,
        count['n'] // 1
    )

# Example runs
print(maxNumberOfBalloons("nlaebolko"))         # Output: 1
print(maxNumberOfBalloons("loonbalxballpoon"))  # Output: 2
print(maxNumberOfBalloons("leetcode"))          # Output: 0
