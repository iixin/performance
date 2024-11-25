#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP

#include <chrono>
#include <utility>

namespace performance
{
    /**
     * @brief 计算类的成员函数的运行时间并返回结果和持续时间
     *
     * @tparam ClassType 成员函数所属的类类型
     * @tparam ReturnType 成员函数的返回类型
     * @tparam Args 成员函数的参数类型列表
     *
     * @param func 成员函数指针
     * @param obj 类的实例对象
     * @param args 成员函数的参数列表
     *
     * @return 一个包含成员函数返回值和执行时间（秒）的 pair
     *
     * example
     *
     * Solution solution;
     *
     * auto [result, duration] = calc_run_time(&Solution::f1, solution, strs);
     */
    template <typename ClassType, typename ReturnType, typename... Args>
    auto calc_run_time(ReturnType (ClassType::*func)(Args...), ClassType &obj, Args &&...args) -> std::pair<ReturnType, double>
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto res = (obj.*func)(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return {res, duration.count()};
    }

    /**
     * @brief 计算函数的运行时间并返回结果和持续时间
     *
     * @tparam ReturnType 返回类型
     * @tparam Args 参数类型列表
     *
     * @param func 类的静态函数/普通函数指针
     * @param args 参数列表
     *
     * @return 一个包含成员函数返回值和执行时间（秒）的 pair
     *
     * example
     *
     * auto [result, duration] = calc_run_time(&Solution::f1, strs);
     *
     * auto [result, duration] = calc_run_time(&f1, strs);
     *
     */
    template <typename ReturnType, typename... Args>
    auto calc_run_time(ReturnType (*func)(Args...), Args &&...args) -> std::pair<ReturnType, double>
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto res = func(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return {res, duration.count()};
    }
}

#endif // PERFORMANCE_HPP