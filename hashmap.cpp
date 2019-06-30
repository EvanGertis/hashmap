// hashmap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Hash.h"

int main()
{
	Hash hashTable;

	hashTable.put(11, 1);
	hashTable.put(21, 10);
	hashTable.put(31, 100);
	std::cout << hashTable.get(11) << std::endl;
	std::cout << hashTable.get(21) << std::endl;
	std::cout << hashTable.get(31) << std::endl;
}

