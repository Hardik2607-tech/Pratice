
n = int(input())

arr =  list(map(int,input().split()))

cnt = 0
maxi = 0

for i in range(n):
  if arr[i] == 1:
    cnt += 1
    maxi = max(maxi,cnt)
  else:
    cnt = 0


print(maxi)