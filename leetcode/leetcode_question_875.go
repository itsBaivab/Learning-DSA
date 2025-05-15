package main

import (
	"fmt"
	"math"
)

func minEatingSpeed(piles []int, h int) int {
	maxPile := 0
	for _, pile := range piles {
		if pile > maxPile {
			maxPile = pile
		}
	}

	low, high, ans := 1, maxPile, math.MaxInt

	for low < high {
		mid := low + (high-low)/2

		rate := findMinimumBananas(piles, mid)
		if rate <= h {
			ans = mid
			high = mid - 1
		} else {
			low = mid + 1
		}

	}
	return ans

}

func findMinimumBananas(bananas []int, speed int) int {
	totalhour := 0
	for _, pile := range bananas {
		totalhour += int(math.Ceil(float64(pile) / float64(speed)))
	}
	return totalhour
}

func main() {
	piles := []int{30, 11, 23, 4, 20}
	h := 5
	fmt.Printf("koko will eat maximum of %d per %d hour\n", minEatingSpeed(piles, h), h)

}
