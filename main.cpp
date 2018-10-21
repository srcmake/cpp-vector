// Copyright srcmake.com 2018.
#include <iostream>
#include "srcmakevector.hpp"

int main()
	{
	std::cout << "Program started.\n";
	
	srcmake::vector<int> vec1;
	srcmake::vector<bool> vec2(5);
	srcmake::vector<int> vec3(10, 1);


	std::cout << "Program ended.\n";
	return 0;
	}