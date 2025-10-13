def compareVersion(version1: str, version2: str) -> int:
    v1 = list(map(int, version1.split('.')))
    v2 = list(map(int, version2.split('.')))
    
    # Pad shorter version with zeros
    max_len = max(len(v1), len(v2))
    v1 += [0] * (max_len - len(v1))
    v2 += [0] * (max_len - len(v2))
    
    # Compare revisions
    for a, b in zip(v1, v2):
        if a < b:
            return -1
        elif a > b:
            return 1
    return 0


# ---- Example Tests ----
print(compareVersion("1.2", "1.10"))      # Output: -1
print(compareVersion("1.01", "1.001"))    # Output: 0
print(compareVersion("1.0", "1.0.0.0"))   # Output: 0
print(compareVersion("2.0", "1.9.9"))     # Output: 1
