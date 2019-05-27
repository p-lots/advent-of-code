import Foundation

func partOne(_ input: [String]) -> Int {
	return input.map { Int(String($0)) ?? 0 }.reduce(0, +)
}

print(partOne(input))

func partTwo(_ input: [String]) {
	let inputFixed = input.map { Int(String($0)) ?? 0 }
	var alreadySeen = Set<Int>()
	var freq = 0
	var foundRepeat = false
	while !foundRepeat {
		for val in inputFixed {
			freq += val
			let (insertWasSuccessful, insertedValue) = alreadySeen.insert(freq)
			if !insertWasSuccessful {
				print(insertedValue)
				foundRepeat = !insertWasSuccessful
				break
			}
		}
	}
}

partTwo(input)