def int_to_roman(num):
    # Roman numeral symbols and their corresponding integer values
    val = [
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    ]
    syms = [
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    ]

    roman = ""
    i = 0
    while num > 0:
        count = num // val[i]
        roman += syms[i] * count   # Append symbol 'count' times
        num -= val[i] * count
        i += 1

    return roman


# Example usage:
print(int_to_roman(3749))  # Output: MMMDCCXLIX
print(int_to_roman(58))    # Output: LVIII
print(int_to_roman(1994))  # Output: MCMXCIV
