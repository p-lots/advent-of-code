func part2(_ input: String) -> Int {
	var currentFloor = 0
	var ret: Int = 0
	for (i, ch) in input.enumerated() {
		switch ch {
			case "(": currentFloor += 1
			case ")": currentFloor -= 1
			default: break
		}
		if currentFloor == -1 {
			ret = i + 1
			break
		}
	}
	return ret
}