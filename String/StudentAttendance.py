def checkRecord(s: str) -> bool:
    # Condition 1: fewer than 2 'A's
    if s.count('A') >= 2:
        return False
    # Condition 2: no substring "LLL"
    if "LLL" in s:
        return False
    return True


# Example usage:
print(checkRecord("PPALLP"))  # True
print(checkRecord("PPALLL"))  # False
print(checkRecord("LALL"))    # True
print(checkRecord("ALLL"))    # False
