import Foundation

func parseLine(_ input: String) -> Bool {
    let sides = input.components(separatedBy: " ").compactMap { Int(String($0)) }.sorted(by: <)
    return sides[0] + sides[1] > sides[2]
}

func part1(_ input: String) -> Int {
    return input.components(separatedBy: "\n").filter { parseLine($0) == true }.count
}
