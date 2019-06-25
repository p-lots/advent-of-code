import Foundation

func parseParens(_ input: String) -> (Int, Int) {
    let secondIdx = input.index(input.startIndex, offsetBy: 1)
    let endParenIdx = input.index(of: ")")!
    let inputNoParens = input[secondIdx..<endParenIdx]
    let inputSeparatedByX = inputNoParens.components(separatedBy: "x")
    if let len = Int(inputSeparatedByX[0]), let reps = Int(inputSeparatedByX[1]) {
        return (len, reps)
    }
    return (0, 0)
}

func part2(_ input: String) -> Int {
    var ret = 0
    var i = 0
    while i < input.count {
        let currIdx = input.index(input.startIndex, offsetBy: i)
        let currCh = input[currIdx]
        if CharacterSet.whitespacesAndNewlines.contains(currCh.unicodeScalars.first!) {
            i += 1
        } else if currCh == "(" {
            let parenString = input[currIdx...]
            let endParenIdx = parenString.index(of: ")")!
            let (len, reps) = parseParens(String(parenString[...endParenIdx]))
            let afterEndParenIdx = parenString.index(after: endParenIdx)
            let endParenStr = String(parenString[afterEndParenIdx...])
            if let _ = endParenStr.index(of: "(") {
                let afterEndParenIdxLen = parenString.index(afterEndParenIdx, offsetBy: len)
                let strAfterParenStr = String(parenString[afterEndParenIdx..<afterEndParenIdxLen])
                ret += reps * part2(strAfterParenStr)
            } else {
                ret += len * reps
            }
            let parenDistance = parenString.distance(from: parenString.startIndex, to: endParenIdx)
            i += parenDistance + 1 + len
        } else {
            ret += 1
            i += 1
        }
    }
    return ret
}
