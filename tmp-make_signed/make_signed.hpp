#ifndef TemplateMetaprogramming_MakeSigned_HeaderPlusPlus
#define TemplateMetaprogramming_MakeSigned_HeaderPlusPlus

#include <type_traits>
#include "identity.hpp" //see ../tmp-identity/

#include <type_traits>

template<typename T>
using make_signed = typename std::conditional
<
	std::is_integral<T>::value,
	std::make_signed<T>,
	identity<T>
>::type;

#endif
