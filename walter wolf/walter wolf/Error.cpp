#include "Error.h"

void error(std::string errorString) {
	std::printf("Error occurred: %s", errorString.c_str());
	exit(EXIT_FAILURE);
	system("pause");
}