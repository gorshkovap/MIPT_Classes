// hw 12 ex 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <int n>
struct Fibonacci
{
    static const int value = Fibonacci <n - 1>::value + Fibonacci<n - 2>::value;
};

template<>
struct Fibonacci <0>
{
    static const int value = 1;
};

template<>
struct Fibonacci <1>
{
    static const int value = 1;
};




int main(int argc, int * argv)
{

    constexpr int result = Fibonacci<4>::value;
    std::cout << result << std::endl;
    system("pause");
}
