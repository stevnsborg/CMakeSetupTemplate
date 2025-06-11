#pragma once
//#ifdef _WIN32
#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#else
#define MYLIB_API __declspec(dllimport)
#endif
//#else
//#define MYLIB_API
//#endif


/**
 * @brief Adds two integers.
 *
 * @param a First operand.
 * @param b Second operand.
 * @return Sum of a and b.
 */
MYLIB_API int addValues(int a, int b);