#include <iostream>
#include <type_traits>

template <bool B, typename T = void> 
struct enable_if
{
	using type = T;
};

template <typename T>
struct enable_if<false, T> {}; 

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type; 

template <typename T1, typename T2>
bool is_same_v = std::is_same<T1, T2>::value; 

template <typename T>
enable_if_t<is_same_v<T, int>, T> f(T t)
{
	return t;
}

int f(double d)
{
	return 2;
}

int main()
{
	std::cout << std::boolalpha;
	std::cout << is_same_v <enable_if_t<(1 > 0), int>, int> << '\n';

	if (f('c') == 2)
	{
		std::cout << "All right";
	}

	return 0;
}
