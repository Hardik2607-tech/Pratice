def generateTheString(n: int) -> str:
    if n % 2 == 1:
        return "a" * n
    else:
        return "a" * (n - 1) + "b"


if __name__ == "__main__":
    n = int(input("Enter n: ").strip())
    result = generateTheString(n)
    print("Output:", result)
