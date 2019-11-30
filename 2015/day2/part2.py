def part2(dimensions):
    ret = 0
    for line in dimensions.split('\n'):
        line_sorted = sorted(list(map(int, line.split('x'))))
        ret += line_sorted[0] * 2 + line_sorted[1] * 2 + \
            line_sorted[0] * line_sorted[1] * line_sorted[2]
    return ret
