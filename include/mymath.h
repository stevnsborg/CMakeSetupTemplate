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

MYLIB_API int addValues(int a, int b);