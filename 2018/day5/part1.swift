import Foundation

func part1(_ input: String) -> Int {
    var inputSplit = input.map { String($0) }
    var finished = false
    let upperCase = CharacterSet.uppercaseLetters
    while !finished {
        var queue = inputSplit
        var foundMatch = false
        var nextInput = [String]()
        while queue.count > 0 {
            var currCh = queue.removeFirst()
            if upperCase.contains(currCh.unicodeScalars.first!) {
               currCh = currCh.lowercased()
                if let qFirst = queue.first {
                    if currCh == qFirst {
                        let _ = queue.removeFirst()
                        foundMatch = true
                    } else {
                        nextInput.append(currCh)
                    }
                } else {
                    nextInput.append(currCh)
                }
            } else {
                currCh = currCh.uppercased()
                if let qFirst = queue.first {
                    if currCh == qFirst {
                        let _ = queue.removeFirst()
                        foundMatch = true
                    } else {
                        nextInput.append(currCh)
                    }
                } else {
                    nextInput.append(currCh)
                }
            }
        }
        inputSplit = nextInput
        finished = !foundMatch
    }
    return inputSplit.count
}
