import bisect

def parse_input(fpIn):
    intervals = []
    ingredients = []

    line = fpIn.readline()
    while line != "\n":
        start, end = line.strip().split("-")
        interval = (int(start), int(end))
        intervals.append(interval)

        line = fpIn.readline()

    for line in fpIn.readlines():
        ingredient = int(line.strip())
        ingredients.append(ingredient)

    return intervals, ingredients

def merge_intervals(intervals):
    if not intervals:
        return []
    
    intervals.sort()
    merged = [list(intervals[0])]
    for s, e in intervals:
        last_s, last_e = merged[-1]
        if s <= last_e+1:
            merged[-1][1] = max(e, last_e)
        else:
            merged.append([s, e])

    return [(s,e) for s,e in merged]

def solution_part1(intervals, ingredients):
    merged = merge_intervals(intervals)
    starts = [s for s,_ in merged]
    
    res = 0
    for ing in ingredients:
        k = bisect.bisect_right(starts, ing) - 1
        if k >= 0:
            s, e = merged[k]
            if s <= ing <= e:
                res += 1
    return res

def solution_part2(intervals):
    merged = merge_intervals(intervals)
    res = 0

    for s, e in merged:
        res += e-s+1

    return res

def part1():
    fpIn = open("input.txt")

    intervals, ingredients = parse_input(fpIn)
    res = solution_part1(intervals, ingredients)

    fpIn.close()
    return res

def part2():
    fpIn = open("input.txt")

    intervals, _ = parse_input(fpIn)
    res = solution_part2(intervals)

    fpIn.close()
    return res

def main():
    print(part1())
    print(part2())

if __name__ == "__main__":
    main()