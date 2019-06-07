import Foundation

func part2(_ input: String) -> Int {
    let inputDoubled = input + input
    let inputArr = inputDoubled.compactMap { Int(String($0)) }
    let halfwayAround = input.count / 2
    var sum = 0
    for i in (0..<input.count) {
        if inputArr[i] == inputArr[i + halfwayAround] {
            sum += inputArr[i]
        }
    }
    return sum
}
