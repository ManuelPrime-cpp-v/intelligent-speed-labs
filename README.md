# INTELLIGENT SPEED LABS

> *"Measure. Understand. Optimize."* — **RAVENSBJORN**

A practical repository for hands-on experiments in **C**, **C++**, and **Python** focused on understanding how code interacts with memory, data structures, and compiler optimizations.

Rather than guessing what makes code fast, each experiment isolates a specific programming concept, benchmarks different approaches, and documents the measured difference.

---

## Repository Structure

| Directory | Purpose |
| :--- | :--- |
| **`benchmarks/`** | Small C/C++ programs comparing execution speed across different access patterns and implementations. |
| **`data-structures/`** | From-scratch implementations of core data structures tested for memory usage and lookup speed. |
| **`compiler-flags/`** | Experiments comparing how optimization levels (`-O0`, `-O2`, `-O3`) affect runtime and binary size. |
| **`scripts/`** | Python helper scripts for automating benchmark runs and summarizing timing results. |

---

## Workflow

1. **Write a clean baseline** implementation in C or C++.
2. **Measure execution time** using standard timing utilities (`<chrono>`, `time`, or Python runners).
3. **Test an alternative approach** (e.g., contiguous memory layout, reduced allocations, or compiler flags).
4. **Document the results** clearly alongside the source code.
