
n = int(input())
arr = list(map(int, input().split()))
k = int(input())

if n==0:
  print(-1)
else:
  k = k%n

def reverse(l,r):

  while(l<r):
    arr[l],arr[r] = arr[r],arr[l]
    l += 1
    r -= 1

reverse(0,n-1)
reverse(0,k-1)
reverse(k,n-1)

for i in range(n):
  print(arr[i],end=" ")