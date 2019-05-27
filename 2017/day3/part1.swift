/*
	Day 3 Part 1
	Helper for solution.
	It basically calculates the values of each of the "corners" of the spiral. "Corners"
	meaning where the values change direction. As you can see, it goes through the spiral until it
	finds a "corner" greater than the puzzle input (368078). steps represents how far we go until
	we change direction. For this problem, we end up in the up direction, or on the right side of
	the spiral. The value in the top-right "corner" is 368450. The value in the bottom-right
	"corner" is 367843. Difference between these is 607, so the midpoint is at
	(367843 + (607 / 2 + 1)) = 368147. So we know the target value is in roughly the lower-right
	side of the spiral. Difference between the midpoint and the target value is 69, and the
	distance from the current side of the spiral to the center is 302, so the answer is 371.
*/

enum Direction {
	case U
	case D
	case L
	case R
}

var n = 1, steps = 0, currDir = Direction.R, target = 368078

while (n < target) {
	switch (currDir) {
		case Direction.U:
		currDir = Direction.L
		case Direction.D:
		currDir = Direction.R
		case Direction.L:
		steps += 1
		currDir = Direction.D
		case Direction.R:
		steps += 1
		currDir = Direction.U
	}
	n += steps
	print(n)
}
print(currDir)
print(steps)