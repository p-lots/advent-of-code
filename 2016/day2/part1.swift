import Foundation

enum Move {
    case up, down, left, right
}

func parseLine(_ input: String) -> [Move] {
    let moveLookupTable: [Character: Move] = ["U": .up, "D": .down, "L": .left, "R": .right]
    return input.compactMap { moveLookupTable[$0] }
}

func part1(_ input: String) -> Int {
    let moves: [[Move]] = input.components(separatedBy: "\n").map { parseLine($0) }
    let keypad = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    var currentPosition = [1, 1]
    var ret: [Int] = []
    for row in moves {
        for move in row {
            switch move {
                case .up:
                if currentPosition[1] > 0 {
                    currentPosition[1] -= 1
                }
                case .down:
                if currentPosition[1] < 2 {
                    currentPosition[1] += 1
                }
                case .left:
                if currentPosition[0] > 0 {
                    currentPosition[0] -= 1
                }
                case .right:
                if currentPosition[0] < 2 {
                    currentPosition[0] += 1
                }
            }
        }
        ret.append(keypad[currentPosition[1]][currentPosition[0]])
    }
    return ret.reduce(0) { acc, n in return acc * 10 + n }
}
