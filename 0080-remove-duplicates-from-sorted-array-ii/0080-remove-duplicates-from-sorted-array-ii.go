func removeDuplicates(nums []int) int {
    var position int = 0
    var counter int = 0
    var prev int = nums[0]
    for _ , a := range nums{
        if a == prev && counter < 2{
            counter++
            nums[position] = a
            position++

        } else if a != prev{
            counter = 1
            prev = a
            nums[position] = a
            position++
        }
    }  
    return position
}