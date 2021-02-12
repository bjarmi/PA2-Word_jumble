#include <iostream>

#ifndef PA2_LIST_H
#define PA2_LIST_H

class List
{
private:
	int _size;
	int _capacity;
	char* payload;

	void reserve();

public:

	List(const List& other);

	explicit List(int size);

	List();

	~List();

	void set(int index, char value) const;

	char get(int index) const;

	void append(char value);

	int size() const;

	bool operator==(const List& other) const;

	bool operator!=(const List& other) const;

	void clear();

	char* begin();

	char* end();
};

std::istream& operator>>(std::istream& input, List& list);

#endif //PA2_LIST_H
