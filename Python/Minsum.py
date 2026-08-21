

n = int(input())

arr =  list(map(int,input().split()))

k = int(input())

sum = 0

for i in range(k):
  sum += arr[i]

minsum = sum

for i in range(k,n):
  sum += arr[i]
  sum -= arr[i-k]
  minsum = min(sum,minsum)

print(minsum)