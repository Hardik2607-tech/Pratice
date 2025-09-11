from collections import Counter

def sortString(s: str) -> str:
    count = Counter(s)
    result = []

    while len(result) < len(s):
        # Step 1: smallest → largest
        for ch in sorted(count.keys()):
            if count[ch] > 0:
                result.append(ch)
                count[ch] -= 1

        # Step 2: largest → smallest
        for ch in sorted(count.keys(), reverse=True):
            if count[ch] > 0:
                result.append(ch)
                count[ch] -= 1

    return "".join(result)


# Example usage
print(sortString("aaaabbbbcccc"))  # Output: "abccbaabccba"
print(sortString("rat"))           # Output: "art"
