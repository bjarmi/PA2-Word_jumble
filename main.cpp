#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <array>
#include <cstring>

const int MAX_WORD_SIZE = 45;

void write(std::array<char, MAX_WORD_SIZE> word,
           std::array<char, MAX_WORD_SIZE> memory)
{
	for (auto i = 0; i < word.size(); i++)
	{
		memory[i] = word[i];
	}
}


struct WordBank
{
	static char wordbank[13];

	static std::array<char, MAX_WORD_SIZE> fetch_word()
	{
		std::array<char, MAX_WORD_SIZE> word{};

		std::ifstream file;
		file.open(wordbank, std::ios::in);
	}
};


class Scramble
{
private:

	std::array<char, MAX_WORD_SIZE> unscrambled_word{};
	std::array<char, MAX_WORD_SIZE> scrambled_word{};

	void display_status()
	{
		printf("Scrambled word:\n\t");
		for (auto letter : scrambled_word)
		{
			std::cout << letter;
		}
	}

	static std::array<char, MAX_WORD_SIZE> get_guess()
	{
		std::array<char, MAX_WORD_SIZE> guess{};

		printf("Hit me with your best shot!\n");
		std::cin.read(guess.data(), MAX_WORD_SIZE);

		return guess;
	}

	std::array<char, MAX_WORD_SIZE>
	scramble_word(std::array<char, MAX_WORD_SIZE> word)
	{
		return nullptr;
	}


public:

	explicit Scramble(std::array<char, MAX_WORD_SIZE> word)
	{
		unscrambled_word = word;
		scrambled_word = scramble_word(word);
	}


	void start()
	{
		std::array<char, MAX_WORD_SIZE> guess{};

		do
		{
			display_status();
			write(get_guess(), guess);
		}
		while (guess != unscrambled_word);
	}
};


int main()
{
	const std::string WB = "wordbank.txt";  // Wordbank to use.

	std::array<char, 13> wordbank =
			reinterpret_cast<const std::array<char, 13>&> (WB);
	std::array<char, MAX_WORD_SIZE> word = WordBank::fetch_word();

	Scramble scramble(word);
	scramble.start();

	return 0;
}


// TODO: Version B.

// User can ask for a hint, word shown as dashes.

// User starts with 10 points, decreased by one for every hint.

// Game is eiter;
// How many words guessed before 0 points,
// or, how many points remaining after 7 words.
