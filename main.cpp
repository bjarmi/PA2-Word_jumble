#include <iostream>
#include <array>
#include "List.h"
#include "Scramble.h"


struct WordBank
{
	static char wordbank[13];

	// Todo: Fetch word from a wordbank.
	static List fetch_word();
};


int main()
{

	const std::string WB = "wordbank.txt";  // Wordbank to use.
	List word = WordBank::fetch_word();

	Scramble scramble(word);
	scramble.start();

	return 0;
}
