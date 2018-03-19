n = int(input())
arr = sorted(map(int, input().split(' ')))
temp = arr[1] - arr[0]
for i in range(2, n):
    temp2 = arr[i] - arr[i - 1]
    while temp2 > 0 and temp > 0:
        if temp > temp2:
            temp %= temp2
        else:
            temp2 %= temp
    temp = temp + temp2
print((arr[-1] - arr[0]) // temp + 1 - n)
