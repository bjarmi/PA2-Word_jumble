//
// Created by Sande on 10/02/2021.
//

#include "List.h"

class List
{

private:
	char* container;
	int size = 0;
	int capacity = 0;

public:

	explicit List(int size)
	{
		container = new char[size];
		size = size;
		capacity = size;
	}

	void set()
	{

	}

	char get()
	{
		return 'a';
	}

	void append()
	{

	}

};
