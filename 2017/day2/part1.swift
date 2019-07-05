import Foundation

func part1(_ input: String) -> Int {
    let result = input.components(separatedBy: "\n").map { (line: String) -> Int in
        let lineIntArrSorted = line.components(separatedBy: " ").compactMap { Int(String($0)) }.sorted()
        return lineIntArrSorted[lineIntArrSorted.count - 1] - lineIntArrSorted[0]
    }
    return result.reduce(0, +)
}
