func part1(_ input: String) -> Int {
	return input.reduce(0) { (currentFloor: Int, nextInstruction: Character) -> Int in
		switch nextInstruction {
			case "(": return currentFloor + 1
			case ")": return currentFloor - 1
			default: return currentFloor
		}
	}
}