package main

import "fmt"

func isPrime(num int) bool {
	if num < 2 {
		return false
	} else if num == 2 || num == 3 {
		return true
	} else if num%2 == 0 || num%3 == 0 {
		return false
	}

	i := 5
	for i*i <= num {
		if num%i == 0 || num%(i+2) == 0 {
			return false
		}
		i += 6
	}

	return true
}

func getInput() int {
	var k int
	for k < 2 {
		fmt.Print("Type a number: ")
		fmt.Scan(&k)
	}
	return k
}

func printPrimes(n int) {
	if n >= 2 {
		printPrimes(n - 1)
		if isPrime(n) {
			fmt.Println(n)
		}
	}
}

func main() {
	k := getInput()
	printPrimes(k)
}
