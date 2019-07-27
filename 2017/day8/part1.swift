import Foundation

func part1(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n").map { $0.components(separatedBy: CharacterSet.whitespaces) }
    var registers = [String: Int]()
    for line in inputSplit {
        registers[line[0]] = 0
    }
    for line in inputSplit {
        let registerToChange = line[0]
        let incOrDec = line[1]
        let valToIncOrDec = Int(String(line[2]))!
        let registerToCompare = line[4]
        let oper = line[5]
        let valueToCompare = Int(String(line[6]))!
        var shouldChangeRegister: Bool = false
        let valueAtRegisterToCompare = registers[registerToCompare]!
        switch oper {
        case "<":
            shouldChangeRegister = valueAtRegisterToCompare < valueToCompare
        case ">":
            shouldChangeRegister = valueAtRegisterToCompare > valueToCompare
        case "<=":
            shouldChangeRegister = valueAtRegisterToCompare <= valueToCompare
        case ">=":
            shouldChangeRegister = valueAtRegisterToCompare >= valueToCompare
        case "!=":
            shouldChangeRegister = valueAtRegisterToCompare != valueToCompare
        case "==":
            shouldChangeRegister = valueAtRegisterToCompare == valueToCompare
        default: break
        }
        if shouldChangeRegister {
            if incOrDec == "inc" {
                if let prevValue = registers[registerToChange] {
                    registers[registerToChange] = prevValue + valToIncOrDec
                }
            } else {
                if let prevValue = registers[registerToChange] {
                    registers[registerToChange] = prevValue - valToIncOrDec
                }
            }
        }
    }
    if let ret = registers.max(by: { $0.1 < $1.1 }) {
        return ret.1
    }
    return 0
}