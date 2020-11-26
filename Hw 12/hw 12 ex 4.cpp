// hw 12 ex 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>

template <int size>
constexpr bool NoDivisors(const int N, const int number, const std::array<int, size>& prime_numbers)
{
    for (int i = 0; i < N; i++)
    {
        if (number % prime_numbers.at(i) == 0)
        {
            return false;
        }
        if (prime_numbers.at(i) * prime_numbers.at(i) > number)
        {
            return true;
        }
    }
        return true;
}

template <int N>
constexpr int PrimeNumber() {
    std::array<int, N> prime_numbers = {};
    prime_numbers.at(0) = 2;
    for (int number = 5, index = 1; index < N; number += 2)
    {
        if (NoDivisors<N>(index, number, prime_numbers))
        {
            prime_numbers.at(index++) = number;
        }
    }
    return prime_numbers.at(N - 1);
}

int main(int argc, char ** argv) {
    constexpr int N = 3;
    std::cout << PrimeNumber<N>() << std::endl;
    return 0;
}
