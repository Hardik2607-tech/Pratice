def isLongPressedName(name: str, typed: str) -> bool:
    i, j = 0, 0  # pointers for name and typed

    while j < len(typed):
        if i < len(name) and name[i] == typed[j]:
            # characters match → move both
            i += 1
            j += 1
        elif j > 0 and typed[j] == typed[j-1]:
            # long press of previous character
            j += 1
        else:
            return False
    
    return i == len(name)


# Example test cases
print(isLongPressedName("alex", "aaleex"))   # True
print(isLongPressedName("saeed", "ssaaedd")) # False
print(isLongPressedName("leelee", "lleeelee")) # True
print(isLongPressedName("laiden", "laiden"))   # True
