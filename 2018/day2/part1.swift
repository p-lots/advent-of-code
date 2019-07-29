import Foundation

func makeLetterCounts(_ word: String) -> [Character: Int] {
    var ret = [Character: Int]()
    for ch in word {
        if let chCount = ret[ch] {
            ret[ch] = chCount + 1
        } else {
            ret[ch] = 1
        }
    }
    return ret
}

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n").map { makeLetterCounts($0) }
    var twoCount = 0, threeCount = 0
    for dict in inputSplit {
        var foundTwo = false, foundThree = false
        for (_, count) in dict {
            if count == 2 && !foundTwo {
                twoCount += 1
                foundTwo = true
            } else if count == 3 && !foundThree {
                threeCount += 1
                foundThree = true
            }
        }
    }
    return twoCount * threeCount
}
