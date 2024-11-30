function createCounter(n: number): () => number {
  let val = n;
  return function () {
    return val++;
  };
}

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
