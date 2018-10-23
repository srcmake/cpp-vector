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

	// Change the values of the first 10 elements to the first 10 numbers.
	for(int i = 0; i < vec3.size(); i++)
		{
		//vec3[i] = i+1;
		}
	
	// Add 11 more items.
	vec3.push_back(11);	// Will double the array to 20.
	vec3.push_back(12);
	vec3.push_back(13);
	vec3.push_back(14);
	vec3.push_back(15);
	vec3.push_back(16);
	vec3.push_back(17);
	vec3.push_back(18);
	vec3.push_back(19);
	vec3.push_back(20);
	PrintVector(vec3);
	vec3.push_back(21); // Will double the array to 40

	// Remove 1 item.
	vec3.erase(0); // Will resize the array from 40 to 20.
	PrintVector(vec3);
	
	// Insert one item.
	vec3.insert(5, 90210);
	PrintVector(vec3);

	// Remove 11 items.
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	vec3.erase(0);
	PrintVector(vec3);

	// Erase the final 10 elements in the array.
	vec3.erase(9);
	vec3.erase(8);
	vec3.erase(7);
	vec3.erase(6);
	vec3.erase(5);
	vec3.erase(4);
	vec3.erase(3);
	vec3.erase(2);
	vec3.erase(1);
	vec3.erase(0);
	vec3.erase(0);
	PrintVector(vec3);	


	std::cout << "Program ended.\n";
	return 0;
	}