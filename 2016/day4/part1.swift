import Foundation

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    var ret = 0
    for word in inputSplit {
        let wordSplit = word.components(separatedBy: "-")
        var charCounts: [Character: Int] = [:]
        for i in 0..<(wordSplit.count - 1) {
            for ch in wordSplit[i] {
                if let currChCount = charCounts[ch] {
                    charCounts[ch] = currChCount + 1
                } else {
                    charCounts.updateValue(1, forKey: ch)
                }
            }
        }
        let lastWordSplit = wordSplit[wordSplit.count - 1]
        let endingValueToAddIdx = lastWordSplit.firstIndex(of: "[") ?? lastWordSplit.endIndex
        let valueToAdd = Int(String(lastWordSplit[lastWordSplit.startIndex..<endingValueToAddIdx])) ?? 0
        let charCountsSorted = charCounts.sorted(by: {(arg0, arg1) -> Bool in
            if arg0.value == arg1.value {
                return arg0.key < arg1.key
            }
            return arg0.value > arg1.value
        })
        var compStr: String = ""
        for i in 0..<5 {
            compStr.append(charCountsSorted[i].key)
        }
        let startingChecksumIdx = word.index(after: word.firstIndex(of: "[")!)
        let endingChecksumIdx = word.firstIndex(of: "]") ?? word.endIndex
        let checksum = String(word[startingChecksumIdx..<endingChecksumIdx])
        if checksum == compStr {
            ret += valueToAdd
        }
    }
    return ret
}