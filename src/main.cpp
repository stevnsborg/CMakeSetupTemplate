#include <iostream>
#include "a.h"
#include "math.h"

// working prototype for loading the CMakeList variable
#ifdef PRODUCTION_BUILD
	#define STRINGIFY(x) #x
	#define TOSTRING(x) STRINGIFY(x)
	const char* isProduction = TOSTRING(PRODUCTION_BUILD);
#else
	const char* isProduction = "Not a production build";
#endif


// load the CMakeList variable 
bool isProductionBuild;

int main() {
	std::cout << "Hello, World!\n" << "Production: " << isProduction << std::endl;
	std::cout << addValues(1,41) << std::endl;
	return 0;
}