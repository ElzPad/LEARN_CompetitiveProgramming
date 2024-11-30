type Counter = {
  increment: () => number;
  decrement: () => number;
  reset: () => number;
};

function createCounter(init: number): Counter {
  let val = init;
  const increment = () => {
    return ++val;
  };
  const decrement = () => {
    return --val;
  };
  const reset = () => {
    val = init;
    return val;
  };
  return { increment, decrement, reset };
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
