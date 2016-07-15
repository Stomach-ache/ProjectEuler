package main

import "fmt"

const MAX_N = 1010

var dp [MAX_N][MAX_N]int
var p [MAX_N]int

func solve(n, cc int) int {
	if n == 0 {
		return 1
	}
	if cc < 0 {
		return 0
	}
	if dp[n][cc] != -1 {
		return dp[n][cc]
	}

	var ans = 0
	for i := 0; i*p[cc] <= n; i++ {
		ans += solve(n-i*p[cc], cc-1)
	}
	dp[n][cc] = ans
	return ans
}

func main() {
	var vis [MAX_N]bool
	cc := 0
	for i := 2; i < MAX_N; i++ {
		if !vis[i] {
			p[cc] = i
			cc += 1
			for j := i + i; j < MAX_N; j += i {
				vis[j] = true
			}
		}
	}
	for i := 2; i < MAX_N; i++ {
		for j := 0; j < cc; j++ {
			dp[i][j] = -1
		}
	}

	var T int
	fmt.Scanf("%d", &T)
	for T > 0 {
		T -= 1
		var N int
		fmt.Scanf("%d", &N)
		fmt.Printf("%d\n", solve(N, cc-1))
	}
}
