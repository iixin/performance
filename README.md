# C++ Performance Testing Library

## Introduction

This is a lightweight C++ library designed to measure the execution time of functions and member functions. It provides a simple and efficient way to benchmark code performance.

## Requirements
C++11 or later

## Usage

To use this library, include the header file in your project:

```cpp
#include "performance.hpp"
```

## examples

### 1. calc_run_time

```cpp
class Solution
{
public:
    int f1(std::vector<int> &nums)
    {
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
    static int f2(std::vector<int> &nums)
    {
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};

int f3(std::vector<int> &nums)
{
    return std::accumulate(nums.begin(), nums.end(), 0);
}

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5};

    auto [result1, duration1] = performance::calc_run_time(&Solution::f1, solution, nums);
    auto [result2, duration2] = performance::calc_run_time(&Solution::f2, nums);
    auto [result3, duration3] = performance::calc_run_time(&f3, nums);

    std::cout << "Result1: " << result1 << ", Duration1: " << duration1 << " seconds" << std::endl;
    std::cout << "Result2: " << result2 << ", Duration2: " << duration2 << " seconds" << std::endl;
    std::cout << "Result3: " << result3 << ", Duration3: " << duration3 << " seconds" << std::endl;

    return 0;
}
```