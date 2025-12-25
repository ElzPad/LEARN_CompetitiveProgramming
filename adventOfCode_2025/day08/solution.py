import heapq

class UnionFindStructure:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.size = [1] * n
        self.components = n

    def find(self, a):
        while self.parent[a] != a:
            self.parent[a] = self.parent[self.parent[a]]
            a = self.parent[a]
        return a
    
    def union(self, a, b):
        ra, rb = self.find(a), self.find(b)

        if ra == rb:
            return False

        if self.size[ra] < self.size[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        self.size[ra] += self.size[rb]
        self.components -= 1
        return True

def parser(fpIn):
    points = []
    for line in fpIn.readlines():
        x, y, z = line.strip().split(",")
        points.append((int(x), int(y), int(z)))
    return points

def sorted_closest_pairs(points, k=0):
    n = len(points)
    pairs = []

    for i in range(n-1):
        xi, yi, zi = points[i]
        for j in range(i+1, n):
            xj, yj, zj = points[j]
            d2 = (xi-xj)**2 + (yi-yj)**2 + (zi-zj)**2

            pairs.append((d2, i, j))

    pairs.sort(key=lambda t: t[0])
    return pairs

def solution_part1(points, k_connections):
    n = len(points)
    max_pairs = n * (n-1) // 2
    k = min(max_pairs, k_connections)

    closest_pairs = sorted_closest_pairs(points)[:k]

    union_find = UnionFindStructure(n)
    for _d2, i, j in closest_pairs:
        union_find.union(i, j)

    circuits_sizes = {}
    for i in range(n):
        r = union_find.find(i)
        circuits_sizes[r] = union_find.size[r]

    sorted_circuits_sizes = sorted(circuits_sizes.values(), reverse=True)
    prod = 1
    for s in sorted_circuits_sizes[:3]:
        prod *= s

    return prod

def solution_part2(points):
    n = len(points)
    max_pairs = n * (n-1) // 2

    closest_pairs = sorted_closest_pairs(points)

    union_find = UnionFindStructure(n)
    
    last_i, last_j = 0, 0
    for _d2, i, j in closest_pairs:
        if union_find.union(i, j):
            last_i, last_j = i, j
            if union_find.components == 1:
                break

    return points[last_i][0] * points[last_j][0]

def part1():
    with open("input.txt") as fpIn:
        points = parser(fpIn)
    return solution_part1(points, k_connections=1000)

def part2():
    with open("input.txt") as fpIn:
        points = parser(fpIn)
    return solution_part2(points)

def main():
    print(part1())
    print(part2())

if __name__ == "__main__":
    main()