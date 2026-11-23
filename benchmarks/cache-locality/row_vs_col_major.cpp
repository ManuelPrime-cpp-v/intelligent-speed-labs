#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

// 8192 x 8192 matrix of 64-bit integers = 512 MB (exceeds CPU L3 cache)
constexpr std::size_t N = 8192;

int main() {
    std::cout << "=== RAVENSBJORN // INTELLIGENT SPEED LABS ===\n";
    std::cout << "Benchmark: Row-Major vs. Column-Major Matrix Traversal (" << N << "x" << N << ")\n\n";

    // Allocate a contiguous 1D vector representing a 2D N x N matrix
    std::vector<std::int64_t> matrix(N * N, 1);

    // Prevent the compiler from optimizing away the summation loops
    volatile std::int64_t sink = 0;

    // 1. Row-Major Traversal (Cache-Friendly: sequential memory access)
    auto start_row = std::chrono::high_resolution_clock::now();
    std::int64_t sum_row = 0;
    for (std::size_t row = 0; row < N; ++row) {
        for (std::size_t col = 0; col < N; ++col) {
            sum_row += matrix[row * N + col];
        }
    }
    auto end_row = std::chrono::high_resolution_clock::now();
    sink = sum_row;

    // 2. Column-Major Traversal (Cache-Hostile: strided jumps across memory)
    auto start_col = std::chrono::high_resolution_clock::now();
    std::int64_t sum_col = 0;
    for (std::size_t col = 0; col < N; ++col) {
        for (std::size_t row = 0; row < N; ++row) {
            sum_col += matrix[row * N + col];
        }
    }
    auto end_col = std::chrono::high_resolution_clock::now();
    sink = sum_col;

    double time_row_ms = std::chrono::duration<double, std::milli>(end_row - start_row).count();
    double time_col_ms = std::chrono::duration<double, std::milli>(end_col - start_col).count();
    double speedup = time_col_ms / time_row_ms;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "[1] Row-Major Time    : " << time_row_ms << " ms\n";
    std::cout << "[2] Column-Major Time : " << time_col_ms << " ms\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Spatial Locality Speedup: " << speedup << "x faster\n";

    return 0;
}
