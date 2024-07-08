

func maxDistToClosest(seats []int) int {
    
    var result, i int
    var counter float64
    
    if seats[i] == 0 {
        for seats[i] != 1 {
            counter++
            i++
        }
        result = max(result, int(counter))
    }
    
    for i < len(seats) {
        if seats[i] == 0 && i == len(seats) - 1 {
            counter++
            result = max(result, int(counter))
        } else if seats[i] == 1 {
            result = max(result, int(math.Ceil(counter / 2.0)))
            counter = 0
        } else {
            counter++
        }
        i++
        
    }
    result = max(result, int(math.Ceil(counter / 2.0)))
    
    return result
}