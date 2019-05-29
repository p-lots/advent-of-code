import Foundation

func partOne(_ input: [String]) -> Int {
	return input.map { Int(String($0)) ?? 0 }.reduce(0, +)
}

print(partOne(input))