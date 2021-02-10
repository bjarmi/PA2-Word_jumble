//
// Created by Sande on 10/02/2021.
//

#include "List.h"
#include <iostream>

class List
{

private:
	char* container;
	int size = 0;
	int capacity = 0;

	// Write a word to some memory.
	void write(const char* old, char* new_) const
	{
		for (auto i = 0; i < size; i++)
		{
			new_[i] = old[i];
		}
	}

	// Resize the container.
	void resize()
	{
		char* new_container = new char[capacity * 2];
		write(container, new_container);
		delete[] container;
		container = new_container;
		capacity *= 2;
	}

public:

	// Initialize an instance of List.
	explicit List(int size)
	{
		container = new char[size];
		size = size;
		capacity = size;
	}

	// Set value at index.
	void set(int index, char value)
	{
		if (index < 0 || index >= size)
		{
			throw std::runtime_error("Index out of bounds!");
		}

		container[index] = value;
	}

	// Get value at index.
	char get(int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::runtime_error("Index out of bounds!");
		}

		return container[index];
	}

	// Append a value to the end of the List.
	void append(char value)
	{
		if (size + 1 > capacity)
		{
			resize();
		}
		container[size + 1] = value;
		size++;
	}

};
