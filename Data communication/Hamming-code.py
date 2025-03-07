def calculate_parity_bits(data, r):
    """Calculate parity bits for Hamming Code."""
    n = len(data)
    hamming_code = list('0' * (n + r))  # Initialize with zeros

    # Place data bits in appropriate positions (skipping power of 2 positions)
    j = 0  # Data bit index
    for i in range(1, len(hamming_code) + 1):
        if i & (i - 1) == 0:  # Power of 2 positions for parity bits
            continue
        hamming_code[i - 1] = data[j]  # Insert data bit
        j += 1

    # Calculate parity bits
    for i in range(r):
        parity_position = 2 ** i  # 1, 2, 4, 8...
        parity = 0
        for j in range(parity_position - 1, len(hamming_code), 2 * parity_position):
            parity ^= sum(int(hamming_code[k]) for k in range(j, min(j + parity_position, len(hamming_code))))
        hamming_code[parity_position - 1] = str(parity)

    return ''.join(hamming_code)

def detect_and_correct_error(received):
    """Detect and correct errors in received Hamming code."""
    n = len(received)
    r = 0
    while 2**r < n + 1:
        r += 1  # Determine number of parity bits

    received = list(received)  # Convert to mutable list
    error_position = 0

    # Check each parity bit
    for i in range(r):
        parity_position = 2 ** i
        parity = 0
        for j in range(parity_position - 1, n, 2 * parity_position):
            parity ^= sum(int(received[k]) for k in range(j, min(j + parity_position, n)))
        if parity:
            error_position += parity_position

    # Correct the error if detected
    if error_position:
        print(f"Error detected at position: {error_position}")
        received[error_position - 1] = '0' if received[error_position - 1] == '1' else '1'
    else:
        print("No errors detected.")

    return ''.join(received)

# Example Usage
data = input("Enter binary data: ")  # Example: "1011"
m = len(data)

# Calculate required parity bits
r = 0
while 2**r < m + r + 1:
    r += 1

# Encode the data
hamming_code = calculate_parity_bits(data, r)
print("Hamming Code (Transmitted):", hamming_code)

# Simulating an error (Uncomment to introduce an error)
received_data = hamming_code
# received_data = received_data[:2] + ('0' if received_data[2] == '1' else '1') + received_data[3:]  # Flip one bit

# Decode and correct if needed
corrected_data = detect_and_correct_error(received_data)
print("Corrected Data:", corrected_data)
