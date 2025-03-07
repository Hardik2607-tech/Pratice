 ## In this code capital letter will be prioritized.
s =  input("Enter String: ")
s1 = s.casefold() ## Case fold is used to lower the character.
alphabets = []
digits = []
for ch in s:
    if ch.isalpha():
        alphabets.append(ch)
    else:
        digits.append(ch)
output = ''.join(sorted(alphabets)+sorted(digits))
print(output)