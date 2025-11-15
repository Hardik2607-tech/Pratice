def nextGreaterElement(n: int) -> int:
    s = list(str(n))
    
    # 1. Find pivot index i
    i = len(s) - 2
    while i >= 0 and s[i] >= s[i+1]:
        i -= 1
    if i < 0:
        return -1  # No next permutation
    
    # 2. Find rightmost digit greater than s[i]
    j = len(s) - 1
    while s[j] <= s[i]:
        j -= 1
    
    # 3. Swap pivot with digit at j
    s[i], s[j] = s[j], s[i]
    
    # 4. Reverse the digits after position i
    s[i+1:] = reversed(s[i+1:])
    
    # 5. Convert back to int and check 32-bit bound
    result = int("".join(s))
    if result > (1 << 31) - 1:
        return -1
    
    return result


# ----------- MAIN -------------
if __name__ == "__main__":
    n = int(input("Enter n: "))
    print(nextGreaterElement(n))
