package main

import (
	"math/rand"
)

type RandomizedSet struct {
	m     map[int]int
	array []int
}

func Constructor() RandomizedSet {
	randomizedSet := RandomizedSet{m: make(map[int]int), array: make([]int, 0)}
	return randomizedSet
}

func (randomSet *RandomizedSet) Insert(val int) bool {
	if _, ok := randomSet.m[val]; ok {
		return false
	}
	randomSet.m[val] = len(randomSet.array)
	randomSet.array = append(randomSet.array, val)
	return true
}

func (randomSet *RandomizedSet) Remove(val int) bool {
	if _, ok := randomSet.m[val]; ok {
		endPos, deletedPos := len(randomSet.array)-1, randomSet.m[val]
		randomSet.array[endPos], randomSet.array[deletedPos] = randomSet.array[deletedPos], randomSet.array[endPos]
		randomSet.m[randomSet.array[deletedPos]] = deletedPos
		randomSet.array = randomSet.array[:len(randomSet.array)-1]
		delete(randomSet.m, val)
		return true
	}
	return false
}

func (randomSet *RandomizedSet) GetRandom() int {
	i := rand.Intn(len(randomSet.array))
	return randomSet.array[i]
}
