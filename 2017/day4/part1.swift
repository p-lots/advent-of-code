import Foundation

func makeLetterCounts(for word: String) -> [Character: Int] {
    var ret = [Character: Int]()
    for ch in word {
        if let currChCount = ret[ch] {
            ret[ch] = currChCount + 1
        } else {
            ret[ch] = 1
        }
    }
    return ret
}

func parseLine(_ line: String) -> Int {
    var alreadySeen = Set<[Character: Int]>()
    let lineSplit = line.components(separatedBy: " ")
    for word in lineSplit {
        let letterCounts = makeLetterCounts(for: word)
        if alreadySeen.contains(letterCounts) {
            return 0
        } else {
            alreadySeen.insert(letterCounts)
        }
    }
    return 1
}

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    return inputSplit.map { parseLine($0) }.reduce(0, +)
}
