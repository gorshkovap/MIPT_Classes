// hw 12 ex 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <int n, int k>  //c

	static const int comb = Combinations<k - 1, n - 1> + Combinations<k, n - 1>;



template<int n>

	static const int comb<0,n> = 1;


template <int n>


	static const int comb<n,n> = 1;


int main(int argc, char** argv)
{
	constexpr int result = Combinations<4, 1>::value;
	std::cout << result << std::endl;

	system("pause");
}
