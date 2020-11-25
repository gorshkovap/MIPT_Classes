// hw 12 ex 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <int n, int k>  //c
struct Combinations
{
	static const int value = Combinations<k - 1, n - 1>::value + Combinations<k, n - 1>::value;

};

template<int n>
struct Combinations<0, n>
{
	static const int value = 1;
};

template <int n>
struct Combinations<n, n>
{
	static const int value = 1;
};

int main(int argc, char** argv)
{
	constexpr int result = Combinations<4, 1>::value;
	std::cout << result << std::endl;

	system("pause");
}