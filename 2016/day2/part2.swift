import Foundation

enum Move {
    case up, down, left, right
}

func parseLine(_ input: String) -> [Move] {
    let moveLookupTable: [Character: Move] = ["U": .up, "D": .down, "L": .left, "R": .right]
    return input.compactMap { moveLookupTable[$0] }
}

func part2(_ input: String) -> String {
    let moves: [[Move]] = input.components(separatedBy: "\n").map { parseLine($0) }
    let keypad = [["0", "0", "1", "0", "0"],
        ["0", "2", "3", "4", "0"],
        ["5", "6", "7", "8", "9"],
        ["0", "A", "B", "C", "0"],
        ["0", "0", "D", "0", "0"]]
    var currentPosition = [2, 0]
    var ret: [String] = []
    for row in moves {
        for move in row {
            switch move {
                case .right:
                switch currentPosition[0] {
                    case 1, 3:
                    if currentPosition[1] == 1 || currentPosition[1] == 2 {
                        currentPosition[1] += 1
                    }
                    case 2:
                    if currentPosition[1] >= 0 && currentPosition[1] <= 3 {
                        currentPosition[1] += 1
                    }
                    default: break
                }
                case .left:
                switch currentPosition[0] {
                    case 1, 3:
                    if currentPosition[1] == 2 || currentPosition[1] == 3 {
                        currentPosition[1] -= 1
                    }
                    case 2:
                    if currentPosition[1] >= 1 && currentPosition[1] <= 4 {
                        currentPosition[1] -= 1
                    }
                    default: break
                }
                case .up:
                switch currentPosition[1] {
                    case 1, 3:
                    if currentPosition[0] == 2 || currentPosition[0] == 3 {
                        currentPosition[0] -= 1
                    }
                    case 2:
                    if currentPosition[0] >= 1 && currentPosition[0] <= 4 {
                        currentPosition[0] -= 1
                    }
                    default: break
                }
                case .down:
                switch currentPosition[1] {
                    case 1, 3:
                    if currentPosition[0] == 1 || currentPosition[0] == 2 {
                        currentPosition[0] += 1
                    }
                    case 2:
                    if currentPosition[0] >= 0 && currentPosition[0] <= 3 {
                        currentPosition[0] += 1
                    }
                    default: break
                }
            }
        }
        ret.append(keypad[currentPosition[0]][currentPosition[1]])
    }
    return ret.reduce("") { (acc: String, item: String) -> String in
        return acc + item
    }
}
