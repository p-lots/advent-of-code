import Foundation

func isABBA(_ input: String) -> Bool {
    let secondIdx = input.index(input.startIndex, offsetBy: 1)
    return input[input.startIndex] != input[secondIdx] && input == String(input.reversed())
}

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    var ret = 0
    for line in inputSplit {
        var abbaWithinBrackets = false, currPosWithinBrackets = false, abbaFound = false
        for i in (0..<(line.count - 3)) {
            let beginIdx = line.index(line.startIndex, offsetBy: i)
            if let endIdx = line.index(beginIdx, offsetBy: 4, limitedBy: line.endIndex) {
                if String(line[beginIdx..<endIdx]).contains("[") {
                    currPosWithinBrackets = true
                } else if line[beginIdx] == "]" {
                    currPosWithinBrackets = false
                    continue
                }
                if isABBA(String(line[beginIdx..<endIdx])) {
                    if currPosWithinBrackets {
                        abbaWithinBrackets = true
                        abbaFound = false
                        break
                    }
                    abbaFound = true
                }
            }
        }
        if !abbaWithinBrackets && abbaFound {
            ret += 1
        }
    }
    return ret
}
