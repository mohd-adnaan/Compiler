package main

import "fmt"

const half = 0.5

var base float64
var height float64
var area float64

func calculateArea(base float64, height float64) float64 {
    return half * base * height
}

func main() {
    fmt.Println("Enter the base of the right-angled triangle:")
    fmt.Scan(&base)
    fmt.Println("Enter the height of the right-angled triangle:")
    fmt.Scan(&height)
    
    area = calculateArea(base, height)
    fmt.Printf("The area of the right-angled triangle with base %.2f and height %.2f is %.2f\n", base, height, area)
    
    if area > 100 {
        fmt.Println("The area is greater than 100 sq units.")
    } else {
        fmt.Println("The area is not greater than 100 sq units.")
    }
    
    for i := 1; i <= 5; i++ {
        fmt.Printf("Loop iteration %d\n", i)
    }
}