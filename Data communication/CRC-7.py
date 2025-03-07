def xor(a, b):
    """Perform XOR operation between two binary strings of the same length."""
    result = ""
    b = b.zfill(len(a))  # Ensure both strings are the same length
    for i in range(len(a)):
        result += "0" if a[i] == b[i] else "1"
    return result.lstrip('0')  # Remove leading zeros

def mod2div(dividend, divisor):
    """Perform Modulo-2 division (binary division)."""
    pick = len(divisor)
    tmp = dividend[:pick]

    while pick < len(dividend):
        if tmp[0] == '1':  # If first bit is 1, XOR with divisor
            tmp = xor(tmp, divisor) + dividend[pick]
        else:  # If first bit is 0, XOR with a zero string
            tmp = xor(tmp, '0' * pick) + dividend[pick]
        pick += 1

    # Final XOR operation
    if tmp[0] == '1':
        tmp = xor(tmp, divisor)
    else:
        tmp = xor(tmp, '0' * len(divisor))

    return tmp.zfill(len(divisor) - 1)  # Ensure correct CRC length

def encode_data(data, key="10000011"):  # Default CRC-7 polynomial
    """Append CRC-7 checksum to data for transmission."""
    key_len = len(key)
    appended_data = data + '0' * (key_len - 1)  # Append zero bits
    remainder = mod2div(appended_data, key)
    return data + remainder  # Final transmitted message

def decode_data(received_data, key="10000011"):  # Default CRC-7 polynomial
    """Check for errors in received data using CRC-7 validation."""
    remainder = mod2div(received_data, key)
    return remainder == '0' * (len(key) - 1)  # If remainder is all zeros, data is valid

# Example Usage with CRC-7
data = input("Enter Data (binary): ")  # Example: "1101011011"
key = "10000011"  # CRC-7 Polynomial (X^7 + X^3 + 1)

print("\nOriginal Data:", data)
transmitted_data = encode_data(data, key)
print("Transmitted Data (with CRC-7):", transmitted_data)

# Simulate error (optional)
received_data = transmitted_data  # No error
# received_data = "11010110101101"  # Example: Introduce an error


