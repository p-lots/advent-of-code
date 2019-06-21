import Foundation

func part1(_ input: String) -> String {
    let inputSplit = input.components(separatedBy: "\n")
    var charPlaceCounts: [[Character: Int]] = []
    var firstTime = true
    for line in inputSplit {
        if firstTime {
            for ch in line {
                var counts: [Character: Int] = [:]
                if let currChCount = counts[ch] {
                    counts[ch] = currChCount + 1
                } else {
                    counts.updateValue(1, forKey: ch)
                }
                charPlaceCounts.append(counts)
            }
            firstTime = false
        } else {
            for i in (0..<line.count) {
                let currIdx = line.index(line.startIndex, offsetBy: i)
                let currCh = line[currIdx]
                if let currChCount = charPlaceCounts[i][currCh] {
                    charPlaceCounts[i][currCh] = currChCount + 1
                } else {
                    charPlaceCounts[i].updateValue(1, forKey: currCh)
                }
            }
        }
    }
    var sortedCharPlaceCounts: [[(Character, Int)]] = []
    for dict in charPlaceCounts {
        let tempSorted = dict.sorted(by: { $0.value > $1.value })
        sortedCharPlaceCounts.append(tempSorted)
    }
    var ret: String = ""
    for dict in sortedCharPlaceCounts {
        ret.append(dict.first!.0)
    }
    return ret
}
