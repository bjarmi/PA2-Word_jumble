//
// Created by Sande on 10/02/2021.
//

#include "List.h"
#include <iostream>
#include <cstring>

class List
{

private:
	char* payload;
	int size = 0;
	int capacity = 0;

	// Resize the payload.
	void resize()
	{
		capacity *= 2;
		char* new_payload = new char[capacity];
		memcpy(new_payload, payload, size);
		delete[] payload;
		payload = new_payload;
	}

public:

	// Initialize an instance of List.
	explicit List(int size)
	{
		payload = new char[size];
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

		payload[index] = value;
	}

	// Get value at index.
	char get(int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::runtime_error("Index out of bounds!");
		}

		return payload[index];
	}

	// Append a value to the end of the List.
	void append(char value)
	{
		if (size + 1 > capacity)
		{
			resize();
		}
		payload[size + 1] = value;
		size++;
	}

};
