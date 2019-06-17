import Foundation

func parseInput(_ input: String) -> [[Int]] {
    let lines = input.components(separatedBy: "\n").map { $0.components(separatedBy: " ").compactMap { Int(String($0)) } }
    var ret = [[Int]]()
    var startIdx = 0
    for _ in 0..<(lines.count / 3) {
        for j in 0..<3 {
            var triangle = [Int]()
            for i in startIdx..<(startIdx + 3) {
                triangle.append(lines[i][j])
            }
            ret.append(triangle)
        }
        startIdx += 3
    }
    return ret
}

func part2(_ input: String) -> Int {
    let lines = parseInput(input)
    let ret = lines.map { (line: [Int]) -> Int in 
        let lineSorted = line.sorted(by: <)
        return (lineSorted[0] + lineSorted[1] > lineSorted[2] ? 1 : 0)
    }
    return ret.reduce(0, +)
}
