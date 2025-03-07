def hamming_distance(str1, str2):
    """
    Calculate the Hamming distance between two binary strings.
    """
    if len(str1) != len(str2):
        raise ValueError("Binary strings must be of equal length")

    return sum(c1 != c2 for c1, c2 in zip(str1, str2))


# Example usage
binary1 = "110101"
binary2 = "100101"

distance = hamming_distance(binary1, binary2)
print(f"Hamming Distance: {distance}")

# Error detection threshold (example)
if distance > 0:
    print("Error detected!")
else:
    print("No errors detected.")