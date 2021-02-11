#include <iostream>
#include <array>
#include "List.h"
#include <cstring>


struct WordBank
{
	static char wordbank[13];

	// Todo: Fetch word from a wordbank.
	static List fetch_word();
};


class Scramble
{
private:

	static const int max_word_size = 45;
	List unscrambled_word;
	List scrambled_word;

	// Display game status.
	void display_status()
	{
		printf("Scrambled word:\n\t");
		for (auto i = 0; i < scrambled_word.size(); i++)
			std::cout << scrambled_word.get(i);
	}

	// Get a word guess from user.
	static List get_guess()
	{
		List guess;

		printf("Hit me with your best shot!\n");
		std::cin.read(guess.payload, max_word_size);

		return guess;
	}

	// Todo: Scramble a word's letters.
	List scramble_word(List word)
	{
		return List(word.size());
	};


public:

	explicit Scramble(List& word)
	{
		for (auto i = 0; i < word.size(); i++)
			unscrambled_word.append(word.get(i));

		scrambled_word = scramble_word(word);
	}


	void start()
	{
		List* guess = new List();

		do
		{
			display_status();
			std::memcpy(guess->payload, get_guess().payload, guess->size());
		}
		while (guess != &unscrambled_word);
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
