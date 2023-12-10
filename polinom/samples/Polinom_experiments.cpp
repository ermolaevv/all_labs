#include <iostream>
#include <chrono>
#include <random>
#include "../include/Polinom.h"

enum operations {
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	COPY,
	COMPARE
};

auto average_test(size_t size, operations op, size_t iterations = 10) {
	int max_random = 10000;
	int min_random = -10000;
	long long average_time = 0;
	for (size_t i = 0; i < iterations; i++) {
		TPolinom param1(size), param2(size);
		
		for (size_t i1 = 0; i1 < size; i1++) {
            double c1 = min_random + std::rand() % static_cast<int>(max_random - min_random + 1);
            double c2 = min_random + std::rand() % static_cast<int>(max_random - min_random + 1);
            std::vector<int> deg;
			for (size_t j1 = 0; j1 < size; j1++) {
                deg.push_back(std::rand() % static_cast<int>(max_random - min_random + 1));
			}
            param1.AddMonom(TMonom(c1, (int)size, &deg[0]));
            param2.AddMonom(TMonom(c2, (int)size, &deg[0]));
		}

		std::chrono::steady_clock::time_point begin, end;

		switch (op)
		{
		case PLUS:
			begin = std::chrono::steady_clock::now();

			param1 + param2;

			end = std::chrono::steady_clock::now();
			break;
		case MINUS:
			begin = std::chrono::steady_clock::now();

			param1 - param2; 

			end = std::chrono::steady_clock::now();
			break;
		case COPY:
			begin = std::chrono::steady_clock::now();

			param1 = param2; 

			end = std::chrono::steady_clock::now();
			break;
		case COMPARE:
			begin = std::chrono::steady_clock::now();

			param1 == param2; 

			end = std::chrono::steady_clock::now();
			break;
		case MULTIPLY:
			begin = std::chrono::steady_clock::now();

			param1 * param2; 

			end = std::chrono::steady_clock::now();
			break;
		default:
			break;
		}

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		average_time += elapsed_ms.count();
		std::cout << i + 1 << '\t' << elapsed_ms.count() << std::endl;
	}

	std::cout << "Average time: " << average_time / static_cast<double>(iterations) << std::endl;
	return average_time / static_cast<double>(iterations);
}

int main(int argc, char** arhv)
{
	auto begin = std::chrono::steady_clock::now();

	average_test(150, MULTIPLY);

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "Execution time: " << elapsed_ms.count();

}
