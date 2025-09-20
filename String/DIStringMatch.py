from typing import List

def diStringMatch(s: str) -> List[int]:
    n = len(s)
    low, high = 0, n
    result = []

    for ch in s:
        if ch == 'I':
            result.append(low)
            low += 1
        else:  # 'D'
            result.append(high)
            high -= 1

    # Only one number left
    result.append(low)  # same as high
    return result


# ---------- Test cases ----------
print(diStringMatch("IDID"))  # [0,4,1,3,2]
print(diStringMatch("III"))   # [0,1,2,3]
print(diStringMatch("DDI"))   # [3,2,0,1]
