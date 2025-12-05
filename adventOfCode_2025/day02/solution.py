from bisect import bisect_left, bisect_right

def parse_ranges(path="input.txt"):
    with open(path, "r") as f:
        text = f.read().strip()
    ranges = []
    for token in text.split(","):
        token = token.strip()
        if not token:
            continue
        lo, hi = map(int, token.split("-"))
        ranges.append((lo, hi))
    return ranges

def sum_invalid_in_ranges(ranges, invalid_numbers):
    total = 0
    for lo, hi in ranges:
        i = bisect_left(invalid_numbers, lo)
        j = bisect_right(invalid_numbers, hi)
        total += sum(invalid_numbers[i:j])
    return total

def generate_invalid_part1(max_value: int) -> list[int]:
    invalid = set()
    max_len = len(str(max_value))

    for n in range(2, max_len+1, 2):
        k = n//2
        start = 10 ** (k-1)
        end = 10 ** k 

        for base in range(start, end):
            s = str(base)
            num = int(s+s)
            if num > max_value:
                break
            invalid.add(num)

    return sorted(invalid)

def generate_invalid_part2(max_value: int) -> list[int]:
    invalid = set()
    max_len = len(str(max_value))

    for n in range(2, max_len+1):
        for base_len in range(1, n//2 + 1):
            k = n//base_len
            start = 10 ** (base_len-1)
            end = 10 ** base_len

            if n % base_len != 0 or k < 2:
                continue

            for base in range(start, end):
                s = str(base) * k
                num = int(s)
                if num > max_value:
                    break
                invalid.add(num)

    return sorted(invalid)

def part1(ranges):
    max_hi = max(hi for _, hi in ranges)
    invalid = generate_invalid_part1(max_hi)
    return sum_invalid_in_ranges(ranges, invalid)


def part2(ranges):
    max_hi = max(hi for _, hi in ranges)
    invalid = generate_invalid_part2(max_hi)
    return sum_invalid_in_ranges(ranges, invalid)

def main():
    ranges = parse_ranges()
    print(part1(ranges))
    print(part2(ranges))

if __name__ == "__main__":
    main()