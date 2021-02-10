#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <array>

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
	static int word_count;

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
	}

	static std::array<char, MAX_WORD_SIZE> fetch_word()
	{
		std::array<char, MAX_WORD_SIZE> word{};

		std::ifstream file;
		file.open(wordbank, std::ios::in);

		int line = std::rand() % word_count + 1; // NOLINT(cert-msc50-cpp).

		int new_line_count, char_count = 0;
		0;
		char c;
		while (file.get(c) && new_line_count <= line)
		{
			if (new_line_count == line)
			{
				auto lala = line;
			}
		}
		if (c == '\n')
		{
			new_line_count++;
		}
	}
};


class Scramble
{
private:

	std::array<char, MAX_WORD_SIZE> unscrambled_word{};
	std::array<char, MAX_WORD_SIZE> scrambled_word{};

	void display_status()
	{
		printf("Unscrambled word:\n\t");
		for (auto letter : scrambled_word)
		{
			std::cout << letter;
		}
	}

	std::array<char, MAX_WORD_SIZE> get_guess()
	{
		std::cin.gcount()
		return nullptr;
	}

	std::array<char, MAX_WORD_SIZE>
	scramble_word(std::array<char, MAX_WORD_SIZE> word)
	{
		return nullptr;
	}

	bool check_win()
	{
		return true;
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
	std::array<char, 13> wordbank =
			(const std::array<char, 13>&) "wordbank.txt";
	WordBank::word_count = WordBank::count_words();
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
