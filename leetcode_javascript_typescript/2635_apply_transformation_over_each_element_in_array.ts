function map(arr: number[], fn: (n: number, i: number) => number): number[] {
  return arr.map((el, i) => fn(el, i));
}
