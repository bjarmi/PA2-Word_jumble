#include <iostream>
#include <array>
#include "List.h"
#include "Scramble.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>


struct WordBank
{
	static char wordbank[13];
    static int word_count;

    static void count_words()
    {
        std::ifstream file;
        file.open(wordbank, std::ios::in);
        if (file.is_open())
        {
            word_count = std::count(
                    std::istreambuf_iterator<char>(file),
                    std::istreambuf_iterator<char>(), '\n'
            );
        }

        word_count = -1;
    }

	static List fetch_word()
	{
        int line_number = std::rand() % word_count + 1;

        std::ifstream file(wordbank, std::ios::in);

        std::string line;
        int count = 0;
        while (std::getline(file, line))
        {
            if (count == line_number)
            {
                List word_list;

                for(char i : line)
                    word_list.append(i);

                return word_list;
            }
            ++count;
        }
        file.close();
        List empty;
        return empty;
	}
};


int main()
{

	const std::string WB = "wordbank.txt";  // Wordbank to use.
	List word = WordBank::fetch_word();

	Scramble scramble(word);
	scramble.start();

	return 0;
}
