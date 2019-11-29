def part1(dimensions):
    ret = 0
    for line in dimensions.split('\n'):
        line_split = list(map(int, line.split('x')))
        ret += 2 * line_split[0] * line_split[1] \
            + 2 * line_split[1] * line_split[2] \
            + 2 * line_split[0] * line_split[2] \
            + min(line_split)
    return ret
