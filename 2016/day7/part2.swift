import Foundation

func isABA(_ input: String) -> Bool {
    let firstIdx = input.index(input.startIndex, offsetBy: 1)
    let secondIdx = input.index(after: firstIdx)
    return input[input.startIndex] != input[firstIdx] && input[input.startIndex] == input[secondIdx]
}

func abaEqualsBAB(_ aba: String, _ bab: String) -> Bool {
    let abaFirstIdx = aba.index(aba.startIndex, offsetBy: 1)
    let babFirstIdx = bab.index(bab.startIndex, offsetBy: 1)
    return ((aba[aba.startIndex] == bab[babFirstIdx]) && aba[abaFirstIdx] == bab[bab.startIndex]) && aba[aba.startIndex] != aba[abaFirstIdx]
}

func part2(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    var ret = 0
    for line in inputSplit {
        var currPosWithinBrackets = false
        var abaArr = [String](), babArr = [String]()
        for i in (0..<(line.count - 2)) {
            let beginIdx = line.index(line.startIndex, offsetBy: i)
            if let endIdx = line.index(beginIdx, offsetBy: 3, limitedBy: line.endIndex) {
                if String(line[beginIdx..<endIdx]).contains("[") {
                    currPosWithinBrackets = true
                    continue
                } else if line[beginIdx] == "]" {
                    currPosWithinBrackets = false
                }
                if isABA(String(line[beginIdx..<endIdx])) {
                    if currPosWithinBrackets {
                        babArr.append(String(line[beginIdx..<endIdx]))
                    } else {
                        abaArr.append(String(line[beginIdx..<endIdx]))
                    }
                }
            }
        }
        for aba in abaArr {
            var breakAll = false
            for bab in babArr {
                if abaEqualsBAB(aba, bab) {
                    ret += 1
                    breakAll = true
                    break
                }
            }
            if breakAll {
                break
            }
        }
    }
    return ret
}
