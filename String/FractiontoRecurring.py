def fractionToDecimal(numerator: int, denominator: int) -> str:
    if numerator == 0:
        return "0"

    res = []

    # Handle sign
    if (numerator < 0) ^ (denominator < 0):
        res.append('-')

    # Work with absolute values
    numerator, denominator = abs(numerator), abs(denominator)

    # Integer part
    integer_part = numerator // denominator
    res.append(str(integer_part))
    remainder = numerator % denominator

    # If no remainder, return integer part
    if remainder == 0:
        return ''.join(res)

    res.append('.')

    # Dictionary to store remainder positions
    remainder_position = {}

    while remainder != 0:
        if remainder in remainder_position:
            # Insert '(' at repeating start position
            res.insert(remainder_position[remainder], '(')
            res.append(')')
            break

        remainder_position[remainder] = len(res)
        remainder *= 10
        res.append(str(remainder // denominator))
        remainder %= denominator

    return ''.join(res)


# 🔹 Example Test Cases
print(fractionToDecimal(1, 2))     # "0.5"
print(fractionToDecimal(2, 1))     # "2"
print(fractionToDecimal(4, 333))   # "0.(012)"
print(fractionToDecimal(1, 6))     # "0.1(6)"
print(fractionToDecimal(-50, 8))   # "-6.25"
