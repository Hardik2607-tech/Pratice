import math


def calculate_redundant_bits(k):
    r = 0
    while (2 ** r) < (k + r + 1):
        r += 1
    return r


def generate_hamming_code(data):
    k = len(data)
    r = calculate_redundant_bits(k)
    n = k + r
    hamming_code = ['0'] * n
    j = 0

    # Placing data and parity bits
    for i in range(n):
        if math.log2(i + 1).is_integer():
            continue
        hamming_code[i] = data[j]
        j += 1

    # Calculating parity bits
    for i in range(r):
        parity_index = (2 ** i) - 1
        parity = 0
        for j in range(parity_index, n, 2 * (parity_index + 1)):
            for k in range(j, min(j + parity_index + 1, n)):
                parity ^= int(hamming_code[k])
        hamming_code[parity_index] = str(parity)

    return ''.join(hamming_code)


def detect_and_correct_error(received):
    n = len(received)
    r = calculate_redundant_bits(n - calculate_redundant_bits(n))
    error_position = 0
    received = list(received)

    for i in range(r):
        parity_index = (2 ** i) - 1
        parity = 0
        for j in range(parity_index, n, 2 * (parity_index + 1)):
            for k in range(j, min(j + parity_index + 1, n)):
                parity ^= int(received[k])
        if parity != 0:
            error_position += parity_index + 1

    if error_position == 0:
        print("No error detected.")
    else:
        print(f"Error detected at position: {error_position}")
        received[error_position - 1] = '1' if received[error_position - 1] == '0' else '0'
        print("Corrected code:", ''.join(received))


if __name__ == "__main__":
    data = input("Enter binary data: ")
    hamming_code = generate_hamming_code(data)
    print("Hamming Code:", hamming_code)

    received = input("Enter received codeword: ")
    detect_and_correct_error(received)
