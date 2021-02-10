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

	void resize();

public:
	char* payload;

	explicit List(int size);

	List();

	~List();

	void set(int index, char value) const;

	char get(int index) const;

	void append(char value);

	int size() const;

	bool operator == (const List& other) const;
};

#endif //PA2_LIST_H
