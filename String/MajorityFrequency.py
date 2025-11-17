from collections import Counter, defaultdict

def majorityFrequencyGroup(s: str) -> str:
    freq = Counter(s)
    groups = defaultdict(list)

    # Group characters by frequency
    for ch, count in freq.items():
        groups[count].append(ch)

    best_k = -1
    best_group = []

    # Select the majority frequency group
    for k, chars in groups.items():
        if len(chars) > len(best_group) or (len(chars) == len(best_group) and k > best_k):
            best_k = k
            best_group = chars

    return "".join(best_group)


# -----------------------------
# MAIN PROGRAM FOR VS CODE RUN
# -----------------------------
if __name__ == "__main__":
    s = input("Enter a string: ").strip()
    result = majorityFrequencyGroup(s)
    print("Output:", result)
