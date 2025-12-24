def parser(fpIn):
    grid = []
    for line in fpIn.readlines():
        grid.append(line.strip())
    return grid

def solution_part1(grid):
    res = 0
    laser_pos = set([grid[0].index("S")])
    
    for idx in range(1, len(grid)):
        updated_laser_pos = set()
        for pos in laser_pos:
            if grid[idx][pos] == "^":
                res += 1
                if pos-1 >= 0:
                    updated_laser_pos.add(pos-1)
                if pos+1 <= len(grid[0])-1:
                    updated_laser_pos.add(pos+1)
            else:
                updated_laser_pos.add(pos)
        laser_pos = updated_laser_pos
    return res

def solution_part2(grid):
    laser_pos = [0] * len(grid[0])
    laser_pos[grid[0].index("S")] = 1
    
    for idx in range(1, len(grid)):
        updated_laser_pos = [0] * len(grid[0])
        for pos in range(len(laser_pos)):
            if laser_pos[pos] > 0:
                if grid[idx][pos] == "^":
                    if pos-1 >= 0:
                        updated_laser_pos[pos-1] += laser_pos[pos]
                    if pos+1 <= len(grid[0])-1:
                        updated_laser_pos[pos+1] += laser_pos[pos]
                else:
                    updated_laser_pos[pos] += laser_pos[pos]
        laser_pos = updated_laser_pos

    res = sum(laser_pos)
    return res    

def part1():
    with open("input.txt") as fpIn:
        grid = parser(fpIn)
    return solution_part1(grid)

def part2():
    with open("input.txt") as fpIn:
        grid = parser(fpIn)
    return solution_part2(grid)

def main():
    print(part1())
    print(part2())

if __name__ == "__main__":
    main()