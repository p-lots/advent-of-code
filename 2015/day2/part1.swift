import Foundation

func part1(_ input: String) -> Int {
	let inputSplit = input.components(separatedBy: "\n")
	let result = inputSplit.map { (line: String) -> Int in
		let dimensions = line.components(separatedBy: "x").map { Int(String($0)) ?? 0 }.sorted()
		// surface area (2 * l * w + 2 * w * h + 2 * h * l) + area of smallest side
		return 2 * dimensions[0] * dimensions[1] +
			2 * dimensions[1] * dimensions[2] +
			2 * dimensions[2] * dimensions[0] +
			dimensions[0] * dimensions[1]
	}.reduce(0, +)
	return result
}