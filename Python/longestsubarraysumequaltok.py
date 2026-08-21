
n = int(input())

arr = list(map(int,input().split()))

k = int(input())

left = 0
sum = 0

for right in range(n):
  sum += arr[right]

  while sum>k:
    sum -= arr[left]
    left += 1

print(left)