

n = int(input())

arr =  list(map(int,input().split()))

k = int(input())

sum = 0
maxsum = sum

for i in range(k):
  sum += arr[i]

for i in range(k,n):
  sum += arr[i]
  sum -= arr[i-k]
  maxsum = max(sum,maxsum)

print(maxsum)