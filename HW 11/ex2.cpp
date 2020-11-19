﻿#include <iostream>
#include <type_traits>

template <typename T>
struct remove_const
{
	using type = T;
};

template <typename T>
struct remove_const<const T> 
{
	using type = T;
};

template <typename T>
using remove_const_t = typename remove_const<T>::type;

template < typename T >
struct add_const
{
	using type = const T;
};

template <typename T>
using add_const_t = typename add_const<T>::type; 

template <typename T1, typename T2>
bool is_same_v = std::is_same<T1, T2>::value; 

int main()
{
	const int x = 0;
	int y = 0;

	remove_const_t<const int> a = y;
	add_const_t<int> b = x;

	std::cout << std::boolalpha;

	std::cout << is_same_v<decltype(a), int> << '\n';
	std::cout << is_same_v<decltype(b), const int> << '\n';

	return 0;
}