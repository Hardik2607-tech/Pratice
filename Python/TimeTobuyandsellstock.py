
n = int(input())

prices = list(map(int, input().split()))

buy = prices[0]
profit = 0

for i in range(0,n):
  if prices[i]<buy:
    buy = prices[i]
  elif prices[i]-buy>profit:
    profit = prices[i] - buy

print(profit)