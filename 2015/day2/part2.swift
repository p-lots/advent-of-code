import Foundation

func part2(_ input: String) -> Int {
	let inputSplit = input.components(separatedBy: "\n")
	let result = inputSplit.map { (line: String) -> Int in
		let dimensions = line.components(separatedBy: "x").map { Int(String($0)) ?? 0 }.sorted()
		// perimeter of smallest side (2 * w + 2 * h) + volume (l * w * h)
		return 2 * dimensions[0] + 2 * dimensions[1] +
			dimensions[0] * dimensions[1] * dimensions[2]
	}.reduce(0, +)
}