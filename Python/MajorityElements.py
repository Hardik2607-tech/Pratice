
n = int(input())

arr =  list(map(int,input().split()))

cnt = 0
cand = 0

for i in range(n):
  if(cnt==0):
    cand = arr[i]
    cnt = 1
  elif(arr[i]==cand):
    cnt += 1
  else:
    cnt -= 1

print(cand)