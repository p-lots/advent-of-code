import Foundation

func part2(_ input: String) -> Int {
    let arr = input
        .components(separatedBy: "\n")
        .map { $0.components(separatedBy: " ")
            .compactMap { Int(String($0)) } }
    let result = arr.map { row -> Int in
        let re = row.map { i -> Int in
            let res = row.filter { j -> Bool in
                return i != j && i % j == 0 }
            return res.isEmpty ? 0 : i / res[0] }
            .filter { $0 != 0 }[0]
        return re
        }
        .reduce(0, +)
    return result
}
