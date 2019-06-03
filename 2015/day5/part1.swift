import Foundation

func hasForbiddenStrings(_ input: String) -> Bool {
    if input.contains("ab") || input.contains("cd") || input.contains("pq") || input.contains("xy") {
        return true
    }
    return false
}

func hasDoubleLetter(_ input: String) -> Bool {
    for i in 0..<(input.count - 1) {
        let firstIndex = input.index(input.startIndex, offsetBy: i)
        let secondIndex = input.index(input.startIndex, offsetBy: i + 1)
        if input[firstIndex] == input[secondIndex] {
            return true
        }
    }
    return false
}

func hasAtLeastThreeVowels(_ input: String) -> Bool {
    let numVowels = input.reduce(0) { (acc: Int, ch: Character) -> Int in 
        if ch == "a" || ch == "e" || ch == "i" || ch == "o" || ch == "u" {
            return acc + 1
        }
        return acc
    }
    return numVowels >= 3
}

func isNice(_ input: String) -> Bool {
    return !hasForbiddenStrings(input) && hasDoubleLetter(input) && hasAtLeastThreeVowels(input)
}

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    return inputSplit.reduce(0) { acc, line in return acc + (isNice(line) ? 1 : 0) }
}
