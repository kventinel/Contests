if __name__ == "__main__":
	dp = [0 for i in range(101)]
	dp[0] = 1
	for i in range(99, 0, -1):
		for j in range(99, -1, -1):
			k = i
			while k + j <= 100:
				dp[k + j] += dp[j]
				k += i
	print(dp)