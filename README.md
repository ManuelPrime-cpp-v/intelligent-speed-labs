# intelligent-speed-labs
Empirical systems experiments, memory hierarchy benchmarks, and low-level C/C++ performance investigations.
# INTELLIGENT SPEED LABS

> *"Measure. Understand. Optimize."* — **RAVENSBJORN**

An empirical engineering laboratory dedicated to investigating how computation behaves across software, compilers, memory hierarchies, and hardware architectures. 

Rather than treating performance as guesswork, every experiment in this repository isolates a specific computational bottleneck, measures its baseline behavior, analyzes the underlying machine mechanics, and documents the resulting optimization.

---

## Repository Architecture

| Directory | Domain | Focus Areas |
| :--- | :--- | :--- |
| **`01-memory-and-cache/`** | Memory Systems | Cache line alignment, spatial/temporal locality, false sharing, and bandwidth limits |
| **`02-cpp-low-latency/`** | Systems C / C++ | Data-oriented design, branch prediction, SIMD intrinsics, and zero-overhead abstractions |
| **`03-hardware-and-fpga/`** | Architecture & Logic | Digital logic modules, `Verilog` / `SystemVerilog` designs, and hardware-software co-design |
| **`04-profiling-notes/`** | Telemetry & Analysis | Assembly inspection, `perf` counter breakdowns, and compiler optimization logs (`-O0` vs `-O3`) |

---

## Experimental Methodology

Every benchmark and systems study follows a strict four-stage protocol:

1. **Hypothesis:** Define the expected architectural behavior or bottleneck.
2. **Baseline Measurement:** Capture deterministic latency, throughput, and cache-miss telemetry.
3. **Root-Cause Inspection:** Examine generated assembly, memory layout, or hardware utilization.
4. **Targeted Optimization:** Apply minimal, architecture-aligned changes and verify the delta.

---

## Build & Run Environment

* **Languages:** `C17` · `C++20` · `Python` · `SystemVerilog`
* **Compilers & Tooling:** `gcc` / `clang` · `CMake` · `perf` · `valgrind` · `objdump`
* **OS:** Linux (Arch / CachyOS)
