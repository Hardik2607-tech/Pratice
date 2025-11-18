def checkInclusion(s1: str, s2: str) -> bool:
    if len(s1) > len(s2):
        return False

    count1 = [0] * 26
    count2 = [0] * 26

    for c in s1:
        count1[ord(c) - ord('a')] += 1

    for i in range(len(s2)):
        count2[ord(s2[i]) - ord('a')] += 1

        if i >= len(s1):
            count2[ord(s2[i - len(s1)]) - ord('a')] -= 1

        if count1 == count2:
            return True

    return False


# ---- Testcases ----
print(checkInclusion("ab", "eidbaooo"))  # True
print(checkInclusion("ab", "eidboaoo"))  # False
