//
// Created by Sande on 10/02/2021.
//

#ifndef PA2_LIST_H
#define PA2_LIST_H

class List
{
private:
	char* payload;
	int size{};
	int capacity;

	void resize();

public:
	explicit List(int size);

	void set(int index, char value);

	char get(int index);

	void append(char value);
};

#endif //PA2_LIST_H
