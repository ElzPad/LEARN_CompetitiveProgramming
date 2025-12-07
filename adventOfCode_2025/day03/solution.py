def solution_part1(bank):
    if len(bank) <= 2:
        return int(bank)
    
    max_idx1, max_idx2 = 0, 0
    for i in range(len(bank)-1):
        if bank[i] > bank[max_idx1]:
            max_idx1 = i

    max_idx2 = max_idx1+1
    for i in range(max_idx1+2, len(bank)-1):
        if bank[i] > bank[max_idx2]:
            max_idx2 = i

    if bank[-1] > bank[max_idx2]:
        max_idx2 = -1

    return int(bank[max_idx1] + bank[max_idx2])

def solution_part2(bank):
    if len(bank) <= 12:
        return int(bank)
    
    res = ""
    left, right = 0, len(bank)-12+1
    for i in range(12):
        curr_max_idx = left
        for j in range(left+1, right):
            if bank[j] > bank[curr_max_idx]:
                curr_max_idx = j
        left = curr_max_idx+1
        right += 1
        res += bank[curr_max_idx]

    return int(res)

def part1():
    fpIn = open("input.txt")
    res = 0
    
    for line in fpIn:
        res += solution_part1(line.strip())
    return res

def part2():
    fpIn = open("input.txt")
    res = 0
    
    for line in fpIn:
        res += solution_part2(line.strip())
    return res

def main():
    print(part1())
    print(part2())

if __name__ == "__main__":
    main()