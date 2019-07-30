import Foundation

func parseLine(_ line: String) -> (Int, Int, Int, Int) {
    let atIdx = line.firstIndex(of: "@")!
    let beginXIdx = line.index(atIdx, offsetBy: 2)
    let endXIdx = line.firstIndex(of: ",")!
    let xCoord = Int(String(line[beginXIdx..<endXIdx]))!
    let beginYIdx = line.index(after: endXIdx)
    let endYIdx = line.firstIndex(of: ":")!
    let yCoord = Int(String(line[beginYIdx..<endYIdx]))!
    let beginWidthIdx = line.index(endYIdx, offsetBy: 2)
    let endWidthIdx = line.firstIndex(of: "x")!
    let width = Int(String(line[beginWidthIdx..<endWidthIdx]))!
    let beginHeightIdx = line.index(after: endWidthIdx)
    let height = Int(String(line[beginHeightIdx..<line.endIndex]))!
    return (xCoord, yCoord, width, height)
}

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n").map { parseLine($0) }
    var grid = [[Int]]()
    for _ in 0..<1024 {
        let tempLine = Array(repeating: 0, count: 1024)
        grid.append(tempLine)
    }
    for claim in inputSplit {
        for i in claim.0..<(claim.0 + claim.2) {
            for j in claim.1..<(claim.1 + claim.3) {
                grid[i][j] += 1
            }
        }
    }
    var ret = 0
    for i in 0..<grid.count {
        for j in 0..<grid[0].count {
            if grid[i][j] > 1 { ret += 1 }
        }
    }
    return ret
}
