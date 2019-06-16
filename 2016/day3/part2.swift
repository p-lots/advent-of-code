// TODO: Cleanup

import Foundation

func parseInput(_ input: String) -> [[Int]] {
    let lines = input.components(separatedBy: "\n").map { $0.components(separatedBy: " ").compactMap { Int(String($0)) } }
    var ret = [[Int]]()
    var breakAll = false
    var counter = 0
    var j = 0
    var totalCounter = 0
    for _ in lines {
        for i in 0..<3 {
            var toAppend = [Int]()
                while counter < 3 {
                    toAppend.append(lines[j][i])
                    counter += 1
                    j += 1
                    if j >= lines.count {
                        j = 0
                        totalCounter += 1
                        if totalCounter == 2 {
                            breakAll = true
                            break
                        }
                    }
                }
            ret.append(toAppend)
            toAppend = []
            counter = 0
        }
        if breakAll {
            break
        }
    }
    return ret
}

func part2(_ input: String) -> Int {
    let result = parseInput(input)
    var ret = 0
    for line in result {
        let lineSorted = line.sorted(by: <)
        if lineSorted[0] + lineSorted[1] > lineSorted[2] {
            ret += 1
        }
    }
    return ret
}
