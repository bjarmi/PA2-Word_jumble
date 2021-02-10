//
// Created by Sande on 10/02/2021.
//

#include "List.h"
#include <iostream>
#include <cstring>


// Resize the payload.
void List::resize()
{
	_capacity *= 2;
	char* new_payload = new char[_capacity];
	memcpy(new_payload, payload, _size);
	delete[] payload;
	payload = new_payload;
}

// Initialize an instance of List.
List::List(int size)
{
	payload = new char[size];
	_size = size;
	_capacity = size;
}

// Set value at index.
void List::set(int index, char value) const
{
	if (index < 0 || index >= _size)
	{
		throw std::runtime_error("Index out of bounds!");
	}

	payload[index] = value;
}

// Get value at index.
char List::get(int index) const
{
	if (index < 0 || index >= _size)
	{
		throw std::runtime_error("Index out of bounds!");
	}

	return payload[index];
}

// Append a value to the end of the List.
void List::append(char value)
{
	if (_size + 1 > _capacity)
	{
		resize();
	}
	payload[_size + 1] = value;
	_size++;
}

List::~List()
{
	delete[] payload;
}

int List::size() const
{
	return _size;
}

List::List()
{
	_size = 8;
	_capacity = 8;
	payload = new char[8];
}

bool List::operator==(const List& other) const
{
	if (_size != other.size())
		return false;

	for (auto i = 0; i < _size; i++)
		if (payload[i] != other.get(i))
			return false;

	return true;
}
