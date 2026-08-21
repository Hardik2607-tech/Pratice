
n = int(input())
arr = list(map(int, input().split()))
k = 1

for j in range(1,n):
  if(arr[j]!= arr[j-1]):
    arr[k] = arr[j]
    k += 1

print(k)
