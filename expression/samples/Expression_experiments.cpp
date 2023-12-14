#include <iostream>
#include <chrono>
#include <random>
#include <map>
#include "MyExpression.h"
#include "../../stack/include/MyStack.h"

auto average_test(size_t size, size_t iterations = 10) {
    int max_random = 10000;
    int min_random = -10000;
    long long average_time_add = 0;
    long long average_time_del = 0;
    for (size_t i = 0; i < iterations; i++) {
        TStack<int> stack(size);

        std::cout << "#" << i << " Adding" << std::endl;
        for (size_t j = 0; j < size; j++) {
            int c1 = min_random + std::rand() % static_cast<int>(max_random - min_random + 1);

            std::chrono::steady_clock::time_point begin, end;

            begin = std::chrono::steady_clock::now();
            stack.Push(c1);
            end = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            average_time_add += elapsed_ms.count();
            std::cout << i + 1 << '\t' << elapsed_ms.count() << std::endl;
        }
        std::cout << std::endl << "#" << i << " Delliting" << std::endl;
        for (size_t j = 0; j < size; j++) {

            std::chrono::steady_clock::time_point begin, end;

            begin = std::chrono::steady_clock::now();
            stack.Pop();
            end = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            average_time_add += elapsed_ms.count();
            std::cout << i + 1 << '\t' << elapsed_ms.count() << std::endl;
        }
    }

    std::cout << "Average time add: " << average_time_add / static_cast<double>(iterations * size) << std::endl;
    std::cout << "Average time del: " << average_time_add / static_cast<double>(iterations * size) << std::endl;

    return;
}

int main(int argc, char** arhv)
{

    average_test(150);

    auto begin = std::chrono::steady_clock::now();

    std::string expr = "(4+11-8/2*(7*3+4-7))*3";
    TArithmeticExpression expression(expr);

    std::map<std::string, double> values;
    expression.Calculate(values);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Execution time: " << elapsed_ms.count();

}
