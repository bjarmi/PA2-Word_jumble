//
// Created by Sande on 10/02/2021.
//

#include "List.h"
#include <iostream>
#include <cstring>


// Resize the payload.
void List::resize()
{
	capacity *= 2;
	char* new_payload = new char[capacity];
	memcpy(new_payload, payload, size);
	delete[] payload;
	payload = new_payload;
}

// Initialize an instance of List.
List::List(int size)
{
	payload = new char[size];
	size = size;
	capacity = size;
}

// Set value at index.
void List::set(int index, char value)
{
	if (index < 0 || index >= size)
	{
		throw std::runtime_error("Index out of bounds!");
	}

	payload[index] = value;
}

// Get value at index.
char List::get(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::runtime_error("Index out of bounds!");
	}

	return payload[index];
}

// Append a value to the end of the List.
void List::append(char value)
{
	if (size + 1 > capacity)
	{
		resize();
	}
	payload[size + 1] = value;
	size++;
}

