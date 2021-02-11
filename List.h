//
// Created by Sande on 10/02/2021.
//

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

	List();

	~List();

	void set(int index, char value) const;

	char get(int index) const;

	void append(char value);

	int size() const;

	bool operator==(const List& other) const;
};

#endif //PA2_LIST_H
