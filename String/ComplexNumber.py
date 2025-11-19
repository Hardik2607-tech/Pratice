def complexNumberMultiply(num1: str, num2: str) -> str:
    # Parse num1
    a, b = num1[:-1].split("+")
    a, b = int(a), int(b)

    # Parse num2
    c, d = num2[:-1].split("+")
    c, d = int(c), int(d)

    # Multiply: (ac - bd) + (ad + bc)i
    real = a * c - b * d
    imag = a * d + b * c

    return f"{real}+{imag}i"


# Example usage:
if __name__ == "__main__":
    num1 = "1+1i"
    num2 = "1+1i"
    print(complexNumberMultiply(num1, num2))  # Output: "0+2i"
