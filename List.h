#include <iostream>

#ifndef PA2_LIST_H
#define PA2_LIST_H

class List
{
private:
	int _size;
	int _capacity;

	void reserve();

public:
	char* payload;

	List(const List& other);

	List();

	~List();

	void set(int index, char value) const;

	char get(int index) const;

	void append(char value);

	int size() const;

	bool operator==(const List& other) const;

	bool operator!=(const List& other) const;

	void clear();
};

std::istream& operator>>(std::istream& input, List& list);

#endif //PA2_LIST_H
