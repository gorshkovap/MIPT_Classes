

#include <iostream>
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

template <typename T>
struct remove_reference
{
	using type = T;
};

template < typename T >
struct remove_reference < T& >
{
	using type = T;
};

template <typename T>
struct remove_reference < T&& >
{
	using type = T;
};

template <typename T>
using remove_reference_t = typename remove_reference<T>::type;

template < bool C, typename True_Type, typename False_Type >
struct if_then_else
{
	using type = True_Type;
};

template < typename True_Type, typename False_Type >
struct if_then_else < false, True_Type, False_Type >
{
	using type = False_Type;
};

template < bool C, typename TT, typename FT >
using if_then_else_t = typename if_then_else < C, TT, FT >::type;

template < typename T >
struct Is_array : std::false_type
{};

template < typename T, std::size_t N >
struct Is_array < T[N] > : std::true_type
{
	using type = T;
};

template < typename T >
struct Is_array < T[] > : std::true_type
{
	using type = T;
};

template <typename T>
const bool is_array = Is_array<T>::value;

template <typename T>
using is_array_t = typename Is_array<T>::type;

template <typename T >
struct Is_function : std::false_type {};

template <typename F, typename ... Args>
struct Is_function<F(Args...)> : std::true_type {};

template <typename T>
const bool is_function = Is_function<T>::value;

template <typename T>
struct decay
{
	using T1 = remove_reference_t<T>;
    using type = if_then_else_t <is_array<T1>, is_array_t<T1>*, if_then_else_t<is_function<T1>, std::add_pointer_t<T1>, remove_const_t<T1> > >;
};

template <typename T>
using decay_t = typename decay<T>::type;

template <typename T1, typename T2>
bool is_same_v = std::is_same<T1, T2>::value;

void f() {}
int g(int i) { return 4; }

int main()
{
	const int x = 0;
	auto& y = x;
	int a[] = { 2, 5 };
	const int b[] = { 7, 8 };
	auto& c = a;

	std::cout « std::boolalpha;
	std::cout « is_same_v<decay_t<int(int)>, int(*)(int)> « '\n';
	std::cout « is_same_v<decay_t<void()>, void(*)()> « '\n';
	std::cout « is_same_v<decay_t<int &&>, int> « '\n';
	std::cout « is_same_v<decay_t<int &>, int> « '\n';
	std::cout « is_same_v<decay_t<const int&>, int> « '\n';
	std::cout « is_same_v<decay_t<const int&&>, int> « '\n';
	std::cout « is_same_v<decay_t<const int>, int> « '\n';
	std::cout « is_same_v<decay_t<const int[]>, const int*> « '\n';

	return 0;
}
