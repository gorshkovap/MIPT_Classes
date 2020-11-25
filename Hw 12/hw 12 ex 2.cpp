// hw 12 ex 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <int n>


    static const int Fibonacci = Fibonacci <n - 1> + Fibonacci<n - 2>;

template<>


    static const int Fibonacci<0> = 1;


template<>

    static const int Fibonacci<1> = 1;





int main(int argc, char * argv)
{

    std::cout << Fibonacci<5> << std::endl;
    system("pause");
}
