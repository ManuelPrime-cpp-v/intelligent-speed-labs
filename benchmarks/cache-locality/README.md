# Benchmark: Row-Major vs. Column-Major Cache Locality

> *"Measure. Understand. Optimize."* — **RAVENSBJORN**

## Hypothesis
Traversing a contiguous 2D matrix in **Row-Major order** (`matrix[row * N + col]`) will execute significantly faster than **Column-Major order** (`matrix[row * N + col]` with `row` in the inner loop), even though both loops perform the exact same number of additions ($8192 \times 8192 = 67,108,864$ operations).

## Test Environment
* **CPU:** Intel Core i5 (3rd Gen)
* **RAM:** 6 GB DDR3
* **OS:** Linux (CachyOS)
* **Compiler:** `g++ -std=c++20 -O2 -Wall -Wextra`
* **Workload:** $8192 \times 8192$ matrix of `int64_t` ($\approx 512\text{ MB}$, exceeding CPU L3 cache capacity)

## Measured Results

| Traversal Strategy | Memory Access Pattern | Execution Time | Relative Speed |
| :--- | :--- | :---: | :---: |
| **Row-Major** | Sequential (`stride = 8 bytes`) | **`100.87 ms`** | **`9.00x` faster** |
| **Column-Major** | Strided (`stride = 64 KB`) | **`908.35 ms`** | `1.00x` (baseline) |

## Architectural Takeaway
1. **Cache Line Utilization:** Modern CPUs fetch memory into L1/L2/L3 caches in **64-byte cache lines** (holding eight `int64_t` values at once). Row-major traversal uses every value loaded into a cache line before evicting it, and triggers hardware prefetchers.
2. **Cache Thrashing & TLB Misses:** Column-major traversal jumps $8192 \times 8\text{ bytes} = 64\text{ KB}$ on every single iteration. Because the $512\text{ MB}$ matrix cannot fit inside the CPU cache, nearly every read triggers a cache miss and stalls the CPU waiting on main RAM.

## How to Reproduce
```bash
g++ -std=c++20 -O2 -Wall -Wextra row_vs_col_major.cpp -o /tmp/cache_bench && /tmp/cache_bench
```
