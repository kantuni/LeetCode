func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	ans := 0
	for i, j := 0, 0; i < len(g) && j < len(s); j++ {
		if s[j] >= g[i] {
			ans++
			i++
		}
	}
	return ans
}
