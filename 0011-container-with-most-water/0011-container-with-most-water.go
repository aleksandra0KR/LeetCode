func maxArea(height []int) int {

    res := 0
    left := 0
    right := len(height) - 1
    var square int

    for left < right{
        square = min(height[left], height[right]) * (right - left)

        if res < square{
            res = square
        }

        if height[left] < height[right]{
            left++
        } else{
            right--
        }
    }

    return res
}