s = input()
k = int(input())

vowels = "aeiou"
cnt = 0


for i in range(k):
    if s[i] in vowels:
      cnt += 1

max_vowels = cnt

for right in range(k, len(s)):
    if s[right] in vowels:
      cnt += 1

    if s[right - k] in vowels:
      cnt -= 1

    max_vowels = max(max_vowels, cnt)

print(max_vowels)