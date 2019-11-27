def part1(levels):
    return sum(1 if ch == '(' else -1 for ch in levels)
