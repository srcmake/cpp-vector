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

	std::cout << "Checking on element of the array: ";
	// vec3 has 10 members.
	std::cout << vec3[5] << std::endl;

	std::cout << "Printing the entire vector so far: \n";
	PrintVector(vec3);

	std::cout << "Changing the all of the elements to the first natural numbers.\n";
	// Change the values of the first 10 elements to the first 10 numbers.
	for(int i = 0; i < vec3.size(); i++)
		{
		vec3[i] = i+1;
		}
	PrintVector(vec3);
	
	// Add 11 more items.
	std::cout << "Adding ten more numbers to the vector.\n";
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

	std::cout << "Adding one more number.\n";
	vec3.push_back(21); // Will double the array to 40


	// Remove 1 item.
	std::cout << "Erasing the beginning number.\n";
	vec3.erase(0); // Will resize the array from 40 to 20.
	PrintVector(vec3);
	
	// Insert one item.
	std::cout << "Inserting a number into the index 5.\n";
	vec3.insert(5, 90210);
	PrintVector(vec3);

	// Remove 11 items.
	std::cout << "Erasing the first 11 elements.\n";
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
	std::cout << "Erasing the final 10 elements.\n";
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