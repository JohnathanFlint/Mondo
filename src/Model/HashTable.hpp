/*
 * HashTable.hpp
 *
 *  Created on: Jun 4, 2017
 *      Author: Arron
 */

#ifndef MODEL_HASHTABLE_HPP_
#define MODEL_HASHTABLE_HPP_

#include <cmath>
#include <assert.h>
#include "HashNode.hpp"

using namespace std;
template <class Type>
class HashTable
{
private:
	long capacity;
	long size;
	double efficiencyPerc;
	HashNode<Type> * * hashTableStorage;
	bool isPrime(long sampleNumber);
	void resize();
	long nextPrime();
	long findPos(HashNode<Type> * data);
	long handleColl(HashNode<Type> * data);

public:
	HashTable();
	~HashTable();
	void add(Type data);
	bool remove(Type data);
	void displayContents();
	long getSize();
};

template <class Type>
long HashTable<Type> :: getSize()
{

}

template <class Type>
HashTable<Type> :: HashTable()
{
	this->capacity = 101;
	this->efficiencyPerc = .667;
	this->size = 0;
	this->hashTableStorage = new HashNode<Type> * [capacity];
	std :: fill_n(hashTableStorage, capacity, nullptr);
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
	delete [] hashTableStorage;
}

template <class Type>
long HashTable<Type> :: nextPrime()
{
	long nextPrime = (this->capacity /8 2) + 1;

	while(!isPrime(nextPrime))
	{
		nextPrime += 2;
	}

	return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(long candidateNumber)
{
	if(candidateNumber <= 1)
	{
		return false;
	}

	else if(candidateNumber == 2 || candidateNumber == 3)
	{
		return true;
	}

	else if(candidateNumber % 2 == 0)
	{
		for(int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
		{
			if(candidateNumber % next == 0)
			{
				return false;
			}
		}

		return true;
	}
}

template <class Type>
long HashTable<Type> :: findPos(HashNode<Type> * data)
{
	long insertPos = data->getKey() % this->capacity;
	return insertPos;
}

template <class Type>
long HashTable<Type> :: handleCollision(HashNode<Type> * data,long currentPos)
{
	long shift = 17;

	for(long position = currentPos + shift; position != currentPos; position += shift)
		{
			if(position >= capacity)
			{
				position = position % capacity;
			}

			if(hashTableStorage[position] == nullptr)
			{
				return position;
			}
		}
	return - 1;
}

template <class Type>
bool HashTable<Type> :: remove(Type data)
{
	bool removed = false;

	HashNode<Type> * find(data);
	long hashIndex = findPos(find);

	if(hashTableStorage[hashIndex] != nullptr)
	{
		hashTableStorage[hashIndex] = nullptr;
		removed = true;
		this->size--;
	}

	return removed;
}

template <class Type>
void HashTable<Type> :: displayContents()
{
	for(long index= 0; index < capacity; index++)
	{
		if(hashTableStorage[index] != nullptr)
		{
			cout << index << ": " << hashTableStorage[index]->getData() << endl;
		}
	}
}

template <class Type>
void HashTable<Type> :: resize()
{
	long updatedCapacity = nextPrime();
	HashNode<Type> * * tempStorage = new HashNode<Type> * [updatedCapacity];

	std :: fill_n(tempStorage, updatedCapacity, nullptr);

	long oldCapacity = this->capacity;
	this->capacity = updatedCapacity;

	for(long index = 0; index < oldCapacity; index++)
	{
		if(hashTableStorage[index] !=nullptr)
		{
			HashNode<Type> * temp =hashTableStorage[index];

			long position = findPos(temp);
			if(tempStorage[position] == nullptr)
			{
				tempStorage[position] = temp;
			}
			else
			{
				long updatedPos = handleCollision(temp, position);
				tempStorage[updatedPos] = temp;
			}
		}

		hashTableStorage = tempStorage;
	}
}

template <class Type>
void HashTable<Type> :: add(Type data)
{
	this->size++;
	if(((this->size * 1.000) / this->capacity) > this->efficiencyPerc)
	{
		resize();
	}

	HashNode<Type> * temp = newHashNode<Type>(data);
	long index = findPos(temp);

	if(hashTableStorage[index] == nullptr)
	{
		hashTableStorage[index] = temp;
	}
	else
	{
		long updatedPos = handleCollision(temp, index);
		hashTableStorage[updatedPos] = temp;
	}
}


#endif /* MODEL_HASHTABLE_HPP_ */
