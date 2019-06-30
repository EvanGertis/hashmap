#include "pch.h"
#include "Hash.h"


Hash::Hash()
{
	hashTable.resize(TABLE_SIZE);
}


Hash::~Hash()
{
}

int Hash::get(int index)
{
	//transform the index into the hashed index
	int hashArrayIndex = hash(index);

	std::list<hashItem> &items = hashTable[hashArrayIndex];

	//if there isn't a value stored in this index then just return
	if (hashTable[hashArrayIndex].empty()) {
		return -1;
	}

	for (hashItem const &item : items) {
		if (item.index == index) {
			return item.value;
		}
	}

	// default
	return -1;
}

void Hash::put(int index, int value)
{
	//the hash function transforms the key -> into an array index.
	int hashArrayIndex = hash(index);

	//there might be an item with this index
	std::list<hashItem> &items = hashTable[hashArrayIndex];

	//if the list is empty this means that this is the first item to be stored in this index
	if (items.empty())
	{
		std::cout << "no collision" << std::endl;
	}
	else {
		// the list is not empty, we have a collision
		std::cout << "collision occured" << std::endl;

		for (hashItem const &item : items) {
			if (item.index == index) {
				std::cout << "item already inserted" << std::endl;
			}
		}
	}

	items.push_back(hashItem{ index, value });
}

int Hash::hash(int index)
{
	return index % TABLE_SIZE;
}

bool Hash::isTableFull()
{
	return hashTable.size() == TABLE_SIZE;
}
