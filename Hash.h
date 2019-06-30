#pragma once
#include <vector>
#include <list>
#include <iostream>

class Hash
{
	static constexpr int TABLE_SIZE = 10;

	struct hashItem {
		int index;
		int value;
	};

	std::vector<std::list<hashItem>> hashTable;

public:
	Hash();
	~Hash();

	int get(int index);
	void put(int index, int value);

private:
	int hash(int index);
	bool isTableFull();
};

