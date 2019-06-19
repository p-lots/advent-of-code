import Foundation

func doCaesarDecode(_ input: String, _ shift: Int) -> String {
    let shiftMod = shift % 26
    let scalars = input.compactMap { UnicodeScalar(String($0)) }
    return scalars.map { (unisca: UnicodeScalar) -> Character in
        var uniscaval: Int = (Int(unisca.value) + shiftMod)
        if uniscaval > 122 {
            uniscaval -= 26
        }
        return Character(UnicodeScalar(uniscaval)!)
    }.map { String($0) }.joined()
}

func getSectorID(_ input: String) -> Int {
    let lastIdx = input.firstIndex(of: "[") ?? input.endIndex
    return Int(String(input[input.startIndex..<lastIdx])) ?? 0
}

func part2(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n")
    for line in inputSplit {
        let lineSplit = line.components(separatedBy: "-")
        let sectorID = getSectorID(lineSplit[lineSplit.count - 1])
        let inputDecoded = lineSplit.map { doCaesarDecode($0, sectorID) }.joined(separator: " ")
        if inputDecoded == "northpole object storage" {
            return sectorID
        }
    }
    return 0
}
