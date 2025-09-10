def defangIPaddr(address: str) -> str:
    return address.replace(".", "[.]")

# Example test cases
print(defangIPaddr("1.1.1.1"))        # "1[.]1[.]1[.]1"
print(defangIPaddr("255.100.50.0"))   # "255[.]100[.]50[.]0"
