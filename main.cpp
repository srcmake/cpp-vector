// Copyright srcmake.com 2018.
#include <iostream>
#include "srcmakevector.hpp"

template<class T>
void PrintVector(srcmake::vector<T> &vec)
	{
	for(int i = 0; i < vec.size(); i++)
		{
		std::cout << vec[i] << " ";
		}
	std::cout << std::endl;
	}

int main()
	{
	std::cout << "Program started.\n";
	
	srcmake::vector<int> vec1;
	srcmake::vector<bool> vec2(5);
	srcmake::vector<int> vec3(10, 1);

	// vec3 has 10 members.
	std::cout << vec3[5] << std::endl;
	PrintVector(vec3);
	vec3.push_back(20);	// Will double the array to 20.
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	vec3.push_back(2);
	PrintVector(vec3);
	vec3.push_back(2); // Will double the array to 40
	std::cout << vec3[10] << std::endl;


	std::cout << "Program ended.\n";
	return 0;
	}