def part1():
    fpIn = open("input.txt", "r")
    dialPos = 50
    res = 0

    for line in fpIn.readlines():
        sign = 1 if line[0]=='R' else -1
        step = int(line[1:])
        dialPos = (dialPos + sign*step) % 100
        res += 1 if dialPos==0 else 0
    return res

def part2():
    fpIn = open("input.txt", "r")
    dialPos = 50
    res = 0

    for line in fpIn.readlines():
        sign = 1 if line[0]=='R' else -1
        step = int(line[1:])
        res += (dialPos+sign*step)//100 if sign == 1 else (dialPos-1)//100 - (dialPos-1+sign*step)//100
        dialPos = (dialPos + sign*step) % 100
    return res

def main():
    print(f"Part 1: {part1()}")
    print(f"Part 2: {part2()}")
    
if __name__ == "__main__":
    main()