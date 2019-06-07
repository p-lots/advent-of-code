import Foundation

func part1(_ input: String) -> Int {
    let inputArr = input.compactMap { Int(String($0)) }
    var sum = 0
    for (n, m) in (zip(inputArr, inputArr[1...])) {
        if n == m {
            sum += n
        }
    }
    if inputArr[0] == inputArr[inputArr.count - 1] {
        sum += inputArr[0]
    }
    return sum
}