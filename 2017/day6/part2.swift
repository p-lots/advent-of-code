import Foundation

func part2(_ input: String) -> Int {
    var inputSplit = input.components(separatedBy: CharacterSet.whitespaces).compactMap { Int(String($0)) }
    var ret = 0
    var finished = false, seenStateBefore = false
    var combinationSet = Set<[Int]>(), secondSeen = Set<[Int]>()
    while !finished {
        var maxElem = inputSplit.max()!
        var innerFinished = false
        let maxElemIdx = inputSplit.firstIndex(of: maxElem)!
        var innerIter = maxElemIdx + 1 == inputSplit.count ? 0 : maxElemIdx + 1
        inputSplit[maxElemIdx] = 0
        while !innerFinished {
            inputSplit[innerIter] += 1
            maxElem -= 1
            innerIter += 1
            if innerIter == inputSplit.count {
                innerIter = 0
            }
            if maxElem == 0 {
                innerFinished = true
            }
        }
        if !combinationSet.contains(inputSplit) && !seenStateBefore {
            combinationSet.insert(inputSplit)
        } else if combinationSet.contains(inputSplit) {
            seenStateBefore = true
            if !secondSeen.contains(inputSplit) {
                secondSeen.insert(inputSplit)
                ret += 1
            } else {
                finished = true
            }
        }
    }
    return ret
}
