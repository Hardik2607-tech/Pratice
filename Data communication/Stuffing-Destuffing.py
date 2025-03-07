def bit_stuffing(data):
    stuffed_data = ""
    count = 0

    for bit in data:
        if bit == '1':
            count += 1
        else:
            count = 0

        stuffed_data += bit

        # If we have seen five consecutive '1's, we need to stuff a '0'
        if count ==5:
            stuffed_data += '0'
            count = 0  # Reset count after stuffing

    return stuffed_data


def bit_destuffing(stuffed_data):
    destuffed_data = ""
    count = 0
    i = 0

    while i < len(stuffed_data):
        bit = stuffed_data[i]
        destuffed_data += bit

        if bit == '1':
            count += 1
        else:
            count = 0

        # If we see five '1's, we check the next bit
        if count == 5:
            # Skip the next '0' (the stuffed bit)
            i += 1  # Skip the stuffed '0'

        i += 1  # Move to the next bit

    return destuffed_data


if __name__ == "__main__":
    original_data = input("Enter the Data: ")
    print("Original Data: ", original_data)

    stuffed_data = bit_stuffing(original_data)
    print("Stuffed Data: ", stuffed_data)

    destuffed_data = bit_destuffing(stuffed_data)
    print("De-stuffed Data: ", destuffed_data)

    # Verify that the de-stuffed data matches the original data
    assert original_data == destuffed_data, "De-stuffed data does not match original data!"