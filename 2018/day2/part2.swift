import Foundation

func hamming(_ first: String, _ second: String) -> Int {
    guard first.count == second.count else { return -1 }
    let firstArr = first.map { String($0) }, secondArr = second.map { String($0) }
    var ret = 0
    for i in 0..<first.count {
        if firstArr[i] != secondArr[i] {
            ret += 1
        }
    }
    return ret
}

func part2(_ input: String) -> String {
    let inputSplit = input.components(separatedBy: "\n")
    var ret = ""
    var breakAll = false
    for i in 0..<inputSplit.count {
        for j in (i + 1)..<inputSplit.count {
            let diff = hamming(inputSplit[i], inputSplit[j])
            if diff == 1 {
                let firstArr = inputSplit[i].map { String($0) }, secondArr = inputSplit[j].map { String($0) }
                for k in 0..<firstArr.count {
                    if firstArr[k] == secondArr[k] { ret.append(firstArr[k]) }
                }
                breakAll = true
                break
            }
        }
        if breakAll { break }
    }
    return ret
}

func main() {
    let dir = URL(string: "file:///path/to/inputFile")
    let fileName = "input"
    if let fileURL = dir?.appendingPathComponent(fileName).appendingPathExtension("txt") {
        var input = ""
        do {
            input = try String(contentsOf: fileURL)
        } catch {
            print("Error: \(error.localizedDescription)")
        }
        print(part2(input))
    }
}

let _ = main()
