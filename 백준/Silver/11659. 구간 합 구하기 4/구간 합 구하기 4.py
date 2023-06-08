import sys

N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr2 = [list(map(int, input().split())) for _ in range(M)] 

#sums = list(0 for _ in range(N+1))
sums = [0] + arr

for i in range(1, N+1):
    sums[i] += sums[i - 1]

result = list()
for gugan in arr2:
    start, end = gugan
    result.append(sums[end] - sums[start-1])
    
for n in result:
    print(n)

