// hw 12 ex3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>



constexpr double is_e(double epsilon = 0.0001)
{
    unsigned int n = 1;
    double x = 1;
    double result = 0;
    while (epsilon < x)
    {
        result = result + x;
        x = x / n;
        n++;
    }
    return result;
}

int main(int argc, char ** argv)
{
    constexpr double result = is_e(0.0005);
        std::cout << result << std::endl;
        system("pause");
}

