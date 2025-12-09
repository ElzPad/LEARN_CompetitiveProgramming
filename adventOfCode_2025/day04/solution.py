def roll_is_accessible(grid, i, j):
    rolls = -1                  # since it will add +1 for the center roll, which does not count
    grid_w, grid_h = len(grid[0]), len(grid)
    for di in range(-1, 2):
        for dj in range(-1, 2):
            x, y = j+dj, i+di
            if 0 <= x < grid_w and 0 <= y < grid_h and grid[y][x] == '@':
                rolls += 1
    return rolls < 4

def solution_part1(grid):
    res = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            res += 1 if grid[i][j] == '@' and roll_is_accessible(grid, i, j) else 0
    return res

def solution_part2(grid):
    res = 0
    keep_removing = True
    while keep_removing:
        keep_removing = False
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '@' and roll_is_accessible(grid, i, j):
                    res += 1
                    grid[i][j] = 'x'
                    keep_removing = True
    return res

def part1():
    fpIn = open("input.txt")
    res = solution_part1([list(line) for line in fpIn.read().splitlines()])
    return res

def part2():
    fpIn = open("input.txt")
    res = solution_part2([list(line) for line in fpIn.read().splitlines()])
    return res

def main():
    print(part1())
    print(part2())

if __name__ == "__main__":
    main()