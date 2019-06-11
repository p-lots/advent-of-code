import Foundation

enum lightInstruction {
    case turnOn, toggle, turnOff, errorLightInstruction
}

struct Instruction {
    let lightInst: lightInstruction
    let x1: Int
    let y1: Int
    let x2: Int
    let y2: Int
    init(givenLightInst: lightInstruction, givenX1: Int, givenY1: Int, givenX2: Int, givenY2: Int) {
        self.lightInst = givenLightInst
        self.x1 = givenX1
        self.y1 = givenY1
        self.x2 = givenX2
        self.y2 = givenY2
    }
}

func parseCoordinates(_ input: String) -> (Int, Int) {
    let inputSplit = input.components(separatedBy: ",")
    if let x = Int(inputSplit[0]), let y = Int(inputSplit[1]) {
        return (x, y)
    } else {
        return (-1, -1)
    }
}

func parseLine(_ line: String) -> Instruction {
    let lineSplit = line.components(separatedBy: " ")
    var lightInst: lightInstruction
    var firstCoords: (Int, Int), secondCoords: (Int, Int)
    if lineSplit.count == 4 { // "toggle 0,0 through 999,0" split on spaces produces an array of length 4
        lightInst = .toggle
        firstCoords = parseCoordinates(lineSplit[1])
        secondCoords = parseCoordinates(lineSplit[3])
    } else { // "turn on 0,0 through 999,999"
        if lineSplit[1] == "on" {
            lightInst = .turnOn
        } else if lineSplit[1] == "off" {
            lightInst = .turnOff
        } else {
            lightInst = .errorLightInstruction
        }
        firstCoords = parseCoordinates(lineSplit[2])
        secondCoords = parseCoordinates(lineSplit[4])
    }
    return Instruction(givenLightInst: lightInst, givenX1: firstCoords.0, givenY1: firstCoords.1, givenX2: secondCoords.0, givenY2: secondCoords.1)
}

func part2(_ input: String) -> Int {
    let instructions: [Instruction] = input.components(separatedBy: "\n").map { parseLine($0) }
    var board: [[Int]] = []
    for _ in (0...999) {
        board.append(Array<Int>(repeating: 0, count: 1000))
    }
    for instruction in instructions {
        for x in (instruction.x1...instruction.x2) {
            for y in (instruction.y1...instruction.y2) {
                switch instruction.lightInst {
                    case .turnOn:
                    board[x][y] += 1
                    case .toggle:
                    board[x][y] += 2
                    case .turnOff:
                    if board[x][y] > 0 { board[x][y] -= 1 }
                    default: break
                }
            }
        }
    }
    var count = 0
    for x in (0...999) {
        for y in (0...999) {
            count += board[x][y]
        }
    }
    return count
}

print(part2("toggle 0,0 through 999,999"))