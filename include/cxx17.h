#pragma once

#if __cplusplus >= 201703L
#define CXX17_STATIC_CONDITION constexpr
#define IsCXX17
#else
#define CXX17_STATIC_CONDITION
#endif
