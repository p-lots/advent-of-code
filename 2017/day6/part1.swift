import Foundation

func part1(_ input: String) -> Int {
    var inputSplit = input.components(separatedBy: CharacterSet.whitespaces).compactMap { Int(String($0)) }
    var ret = 1
    var finished = false
    var combinationSet = Set<[Int]>()
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
        if combinationSet.contains(inputSplit) {
            finished = true
        } else {
            print(inputSplit)
            combinationSet.insert(inputSplit)
            ret += 1
        }
    }
    return ret
}
