import Foundation

func part1(_ input: String) -> Int {
    var inputSplit = input.components(separatedBy: "\n").compactMap { Int(String($0)) }
    var currPos = 0, jumps = 0
    while true {
        jumps += 1
        let jumpDist = inputSplit[currPos]
        if currPos + jumpDist >= inputSplit.count {
            break
        }
        inputSplit[currPos] += (jumpDist >= 3 ? -1 : 1)
        currPos += jumpDist
    }
    return jumps
}
