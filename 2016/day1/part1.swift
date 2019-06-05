import Foundation

class AdventOfCodeDay1 {
    var currentPosition: [Int]
    var bearing: Orientation
    private let turnLookupTable: [Character: Turn] = ["L": .left, "R": .right]
    enum Orientation {
        case north, south, east, west, errorOrientation
    }
    enum Turn {
        case left, right, errorTurn
    }
    struct Instruction {
        let turn: Turn
        let distance: Int
        init(givenTurn: Turn, givenDistance: Int) {
            self.turn = givenTurn
            self.distance = givenDistance
        }
    }
    init() {
        self.currentPosition = [0, 0]
        self.bearing = .north
    }
    func advance(steps: Int) {
        for _ in (0..<steps) {
            switch self.bearing {
                case .north:
                    currentPosition[1] += 1
                case .south:
                    currentPosition[1] -= 1
                case .west:
                    currentPosition[0] -= 1
                case .east:
                    currentPosition[0] += 1
                default: break
            }
        }
    }
    func turnRight() {
        let dirs: [Orientation] = [.north, .east, .south, .west]
        executeTurn(orientations: dirs)
    }
    func turnLeft() {
        let dirs: [Orientation] = [.north, .west, .south, .east]
        executeTurn(orientations: dirs)
    }
    func executeTurn(orientations: [Orientation]) {
        if let currentOrientationIndex = orientations.index(of: self.bearing) {
            let nextOrientationIndex = (currentOrientationIndex + 1) % orientations.count
            self.bearing = orientations[nextOrientationIndex]
        }
        else {
            self.bearing = .errorOrientation
        }
    }
    func parseInput(_ input: String) -> Instruction {
        let turn: Turn = turnLookupTable[input[input.startIndex]] ?? .errorTurn
        let secondIndex = input.index(input.startIndex, offsetBy: 1)
        let steps = Int(input[secondIndex...]) ?? 0
        return Instruction(givenTurn: turn, givenDistance: steps)
    }
    func instructions(_ insts: String) -> [Instruction] {
        return insts.components(separatedBy: ", ").map { parseInput($0) }
    }
    func evaluate(_ directions: String) {
        let _ = self.instructions(directions).forEach { inst in
            switch inst.turn {
            case .left:
                self.turnLeft()
            case .right:
                self.turnRight()
            default: break
            }
            self.advance(steps: inst.distance)
        }
    }
}

func part1(_ input: String) -> Int {
    let aocDay1 = AdventOfCodeDay1()
    aocDay1.evaluate(input)
    return aocDay1.currentPosition[0] + aocDay1.currentPosition[1]
}