package main

import "fmt"

func main() {

	var numberOfData int
	fmt.Scan(&numberOfData)

	var numberOfUsers, numberOfScreens, prev, current int

	for t := 0; t < numberOfData; t++ {
		fmt.Scan(&numberOfUsers)

		fmt.Scan(&numberOfScreens)

		values := make(map[int][]int, numberOfUsers+1)
		degree := make(map[int]int, numberOfUsers+1)

		for i := 0; i < numberOfScreens; i++ {
			fmt.Scan(&prev)
			if numberOfUsers > 1 {
				fmt.Scan(&prev)
			}
			for j := 2; j < numberOfUsers; j++ {
				fmt.Scan(&current)
				values[prev] = append(values[prev], current)
				degree[current]++
				prev = current
			}
		}

		Q := make([]int, numberOfUsers)
		qIndex := 0

		for i := 1; i < numberOfUsers+1; i++ {
			if degree[i] == 0 {
				Q[qIndex] = i
				qIndex++
			}
		}

		count := 0
		for qIndex > 0 {
			front := Q[count]
			count++
			qIndex--
			for _, value := range values[front] {
				degree[value]--
				if degree[value] == 0 {
					Q[count+qIndex] = value
					qIndex++
				}
			}
		}
		if count == numberOfUsers {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}

}
