// hw 12 ex 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <int n>

    static const int Fibonacci = Fibonacci <n - 1>::value + Fibonacci<n - 2>::value;


template<>
struct Fibonacci <0>
{
    static const int Fibonacci<0> = 1;
};

template<>

    static const int Fibonacci<1> = 1;





int main(int argc, int * argv)
{

    constexpr int result = Fibonacci<4>;
    std::cout << result << std::endl;
    system("pause");
}
