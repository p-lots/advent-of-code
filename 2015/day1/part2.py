def part2(floors):
    curr_floor = 0
    ret = 0
    for i, ch in enumerate(floors):
        if ch == '(':
            curr_floor += 1
        elif ch == ')':
            curr_floor -= 1
        if curr_floor == -1:
            ret = i + 1
            break
    return ret

print(part2(')')) # 1
print(part2('()())')) # 5