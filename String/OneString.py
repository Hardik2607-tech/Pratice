def areAlmostEqual(s1: str, s2: str) -> bool:
    # Find mismatched pairs
    diffs = [(a, b) for a, b in zip(s1, s2) if a != b]

    # Case 1: No difference
    if not diffs:
        return True

    # Case 2: Exactly two differences and they are swappable
    if len(diffs) == 2 and diffs[0] == diffs[1][::-1]:
        return True

    # Otherwise not possible
    return False


# ✅ Example tests
print(areAlmostEqual("bank", "kanb"))    # True
print(areAlmostEqual("attack", "defend")) # False
print(areAlmostEqual("kelb", "kelb"))    # True
