def compress(chars):
    write = 0  # position to write compressed characters
    read = 0   # position to read through chars

    while read < len(chars):
        char = chars[read]
        count = 0

        # Count how many times the current character repeats
        while read < len(chars) and chars[read] == char:
            read += 1
            count += 1

        # Write the character
        chars[write] = char
        write += 1

        # If count > 1, write its digits one by one
        if count > 1:
            for c in str(count):
                chars[write] = c
                write += 1

    # Return the new length
    return write


# ----------------------------
# 🧪 Test Cases
# ----------------------------
if __name__ == "__main__":
    # Example 1
    chars1 = ["a","a","b","b","c","c","c"]
    new_len1 = compress(chars1)
    print("Example 1:")
    print("New length:", new_len1)
    print("Compressed array:", chars1[:new_len1])
    print()

    # Example 2
    chars2 = ["a"]
    new_len2 = compress(chars2)
    print("Example 2:")
    print("New length:", new_len2)
    print("Compressed array:", chars2[:new_len2])
    print()

    # Example 3
    chars3 = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    new_len3 = compress(chars3)
    print("Example 3:")
    print("New length:", new_len3)
    print("Compressed array:", chars3[:new_len3])
    print()

    # Additional Example
    chars4 = ["x","x","x","y","y","z"]
    new_len4 = compress(chars4)
    print("Additional Example:")
    print("New length:", new_len4)
    print("Compressed array:", chars4[:new_len4])
