#include <iostream>
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

#include <vector>

template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

void func(const std::vector<int> &vi)
{
	auto ci=vi.begin();
	std::cout << "decltype(ci) is " << type_name<decltype(ci)>() << '\n';
	// use decltype, which returns the type of an expression, to create a type definition
	typedef decltype(vi.begin()) CIT;

	CIT another_const_iterator;
	std::cout << "decltype(another_const_iterator) is " << type_name<decltype(another_const_iterator)>() << '\n';
}

int main(int argc, char* argv[])
{
	auto x=0; // x has type int because 0 is int
	auto c='a'; // char
	auto d=0.5; // double
	auto national_debt=14400000000000LL;//long long

	std::vector<int> v = { 1, 2, 3, 4 };

	std::cout << "decltype(x) is " << type_name<decltype(x)>() << '\n';
	std::cout << "decltype(c) is " << type_name<decltype(c)>() << '\n';
	std::cout << "decltype(x) is " << type_name<decltype(d)>() << '\n';
	std::cout << "decltype(national_debt) is " << type_name<decltype(national_debt)>() << '\n';
	std::cout << "decltype(v) is " << type_name<decltype(v)>() << '\n';

	func(v);

	return 0;

}
