#ifndef TemplateMetaprogramming_Identity_HeaderPlusPlus
#define TemplateMetaprogramming_Identity_HeaderPlusPlus

#include <type_traits>

template<typename T>
using identity = std::common_type<T>;

#endif
