import Foundation

func part2(_ input: String) -> Int {
    let inputSplit = input.components(separatedBy: "\n").map { $0.components(separatedBy: CharacterSet.whitespaces) }
    var registers = [String: Int]()
    var maxValueSeen = Int.min
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
            if let prevValue = registers[registerToChange] {
                registers[registerToChange] = incOrDec == "inc" ? prevValue + valToIncOrDec : prevValue - valToIncOrDec
            }
            if let newValue = registers[registerToChange] {
                maxValueSeen = newValue > maxValueSeen ? newValue : maxValueSeen
            }
        }
    }
    return maxValueSeen
}
