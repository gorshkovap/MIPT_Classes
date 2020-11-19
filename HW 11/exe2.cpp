
#include <iostream>
#include <functional>

template <typename T >
struct Is_function : std::false_type {};

template <typename F, typename ... Args> 
struct Is_function<F(Args...)> : std::true_type {};

template <typename T>
inline const bool is_function = Is_function<T>::value;

void f() {}

int g(int i) { return 8; }

int main()
{
	struct X {};
	std::function <int(int, int)> lambda_1;
	auto lambda_2 = []() {};

	std::cout << std::boolalpha;

	std::cout << is_function<X> << '\n';                  
	std::cout << is_function<int)> << '\n'; 
	std::cout << is_function<decltype(lambda_2)> << '\n'; 
	std::cout << is_function<int> << '\n';                
	std::cout << is_function<decltype(f)> << '\n';        
	std::cout << is_function<decltype(g)> << '\n';        
	std::cout << is_function<int(int, int)> << '\n';      
	std::cout << is_function<int()> << '\n';              

	return 0;
}
