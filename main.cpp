#include <iostream>
#include "List.h"
#include "Scramble.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <string>


struct WordBank
{
	std::string wordbank;

	int count_words() const
	{
		std::ifstream file(wordbank, std::ios::in);

		if (file.is_open())
		{
			return std::count(
					std::istreambuf_iterator<char>(file),
					std::istreambuf_iterator<char>(), '\n'
			);
		}

		throw std::runtime_error("Could not open file!");
	}

	List fetch_word() const
	{
		srand(time(nullptr));
		int line_number = std::rand() % count_words() + 1;
		std::ifstream file(wordbank, std::ios::in);

		if (file.is_open())
		{
			std::string line;
			int count = 0;
			while (std::getline(file, line))
			{
				if (count == line_number)
				{
					List word_list;

					for (char i : line)
						word_list.append(i);

					return word_list;
				}
				++count;
			}
		}
		throw std::runtime_error("Could not open file!");
	}
};


int main()
{
	WordBank wb;
	wb.wordbank = "wordbank.txt";
	List word = wb.fetch_word();

	Scramble scramble(word);
	scramble.start();

	return 0;
}
