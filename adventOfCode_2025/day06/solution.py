def parser1(fpIn):
    nums = [[int(x)] for x in fpIn.readline().strip().split()]

    not_op = True
    while not_op:
        line = fpIn.readline().strip('\n')
        if line[0] in "+*":
            not_op = False
            continue
        line_split = line.split()
        for i in range(len(line_split)):
            nums[i].append(int(line_split[i]))
    ops = line.split()

    prior_part2 = []
    for c in line:
        if c in '+*':
            prior_part2.append(0)
        else:
            prior_part2[-1] += 1
    prior_part2[-1] += 1

    return zip(ops, nums), prior_part2

def parser2(fpIn, prior):
    nums = [[0]*p for p in prior]

    not_op = True
    while not_op:
        line = fpIn.readline().strip('\n')
        if line[0] in "+*":
            not_op = False
            continue
        
        idx = 0
        for i, p in enumerate(prior):
            for j in range(p):
                if line[idx].isdigit():
                    nums[i][j] *= 10
                    nums[i][j] += int(line[idx])
                idx += 1
            idx += 1
    ops = line.split()

    return zip(ops, nums)

def eval_operation(op, nums):
    if len(nums)==0:
        return 0
    
    res = nums[0]
    for i in range(1, len(nums)):
        res = res+nums[i] if op=='+' else res*nums[i]
    return res

def part1():
    with open("input.txt") as fpIn:
        problems, prior_part2 = parser1(fpIn)
    return sum(eval_operation(op, nums) for op, nums in problems), prior_part2

def part2(prior):
    with open("input.txt") as fpIn:
        problems = parser2(fpIn, prior)
    return sum(eval_operation(op, nums) for op, nums in problems)

def main():
    res_part1, prior_part2 = part1()
    print(res_part1)
    print(part2(prior_part2))

if __name__ == "__main__":
    main()