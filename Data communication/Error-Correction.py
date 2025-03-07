def hamming_distance(str1, str2):
    """
    Calculate the Hamming distance between two binary strings.
    """
    if len(str1) != len(str2):
        raise ValueError("Binary strings must be of equal length")

    return sum(c1 != c2 for c1, c2 in zip(str1, str2))


def correct_error(codeword, parity_positions):
    """
    Correct a single-bit error in the given codeword using Hamming code.
    """
    error_position = 0

    for i, pos in enumerate(parity_positions):
        parity_check = 0
        for j in range(1, len(codeword) + 1):
            if j & pos:
                parity_check ^= int(codeword[j - 1])

        if parity_check:
            error_position += pos

    if error_position:
        codeword = list(codeword)
        codeword[error_position - 1] = '1' if codeword[error_position - 1] == '0' else '0'
        return "".join(codeword), error_position
    return codeword, None


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

# Example error correction using Hamming code
codeword = "1011001"  # Example received codeword with an error
parity_positions = [1, 2, 4]  # Example parity bit positions
corrected_codeword, error_pos = correct_error(codeword, parity_positions)

if error_pos:
    print(f"Error found at position {error_pos}. Corrected codeword: {corrected_codeword}")
else:
    print("No errors found in codeword.")
