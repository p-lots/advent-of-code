import Foundation

func parseLine(_ line: String) -> Bool {
    let words = line.components(separatedBy: " ")
    var wordSet = Set<String>()
    for word in words {
        if wordSet.contains(word) {
            return false
        } else {
            wordSet.insert(word)
        }
    }
    return true
}

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    return inputSplit.filter { parseLine($0) }.count
}
