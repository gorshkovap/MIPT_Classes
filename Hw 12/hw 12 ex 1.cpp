// hw 12 ex 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <int n, int k>  //c

constexpr int Combinations = Combinations<n-1, k> +Combinations<n-1, k - 1>;



template<int n>
constexpr int Combinations<n, 0> = 1;


template <int n>


constexpr int Combinations<n, n> = 1;


int main(int argc, char** argv)
{
	constexpr int result = Combinations<10, 2>;
	std::cout << result << std::endl;

	system("pause");
}
