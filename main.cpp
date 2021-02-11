#include <iostream>
#include <array>
#include "List.h"
#include "Scramble.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>


struct WordBank
{
	static std::string wordbank;

	static int count_words()
	{
		std::ifstream file;
		file.open(wordbank, std::ios::in);
		if (file.is_open())
		{
			return std::count(
					std::istreambuf_iterator<char>(file),
					std::istreambuf_iterator<char>(), '\n'
			);
		}

		throw std::runtime_error("Could not open file!");
	}

	static List fetch_word()
	{
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
	WordBank::wordbank = "wordbank.txt";
	List word = WordBank::fetch_word();

	Scramble scramble(word);
	scramble.start();

	return 0;
}
