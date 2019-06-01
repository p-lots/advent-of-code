func part1(_ input: String) -> Int {
    var xCount = 1, yCount = 1
    for dir in input {
        switch dir {
            case "<":
            fallthrough
            case ">":
            xCount += 1
            case "^":
            fallthrough
            case "v":
            yCount += 1
            default: break
        }
    }
    var grid = (0..<xCount).map { _ in return Array<Int>(repeating: 0, count: yCount) }
    var currX = (grid[0].count % 2 == 0 ? grid[0].count / 2 + 1 : grid[0].count / 2)
    var currY = (grid.count % 2 == 0 ? grid.count / 2 + 1 : grid.count / 2)
    grid[currY][currX] = 1
    for dir in input {
        switch dir {
            case "^":
            currY += 1
            case "v":
            currY -= 1
            case "<":
            currX += 1
            case ">":
            currX -= 1
            default: break
        }
        grid[currY][currX] += 1
    }
    let ret = grid.reduce(0) { (acc: Int, row: [Int]) -> Int in
        return acc + row.reduce(0) { (innerAcc: Int, house: Int) -> Int in
            return innerAcc + (house > 0 ? 1 : 0)
        }
    }
    return ret
}