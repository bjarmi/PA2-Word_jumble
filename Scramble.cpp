#include <iostream>
#include "Scramble.h"
#include <algorithm>
#include <chrono>
#include <random>

// Display the game's status.
void Scramble::display_status()
{
	std::cout << "Scrambled word: ";
	for (auto i = 0; i < scrambled_word.size(); ++i)
		std::cout << scrambled_word.get(i);

	std::cout << std::endl << "Hint: ";
	for (auto i = 0; i < hint_status.size(); ++i)
		std::cout << hint_status.get(i);

	std::cout << std::endl;
}

// Prompt the user for a guess.
void Scramble::get_guess()
{
	std::cout << "Guess the word!" << std::endl;
	std::cout << "Enter 0 to get a hint!" << std::endl;

	guess.clear();
	std::cout << "Guess: ";
	std::cin >> guess;
	std::cout << std::endl;

	if (guess.get(0) == '0')
		hint();
}

Scramble::Scramble(List& word, int points)
{
	hints = points;

	for (auto i = 0; i < word.size(); ++i)
	{
		unscrambled_word.append(word.get(i));
		scrambled_word.append(word.get(i));
		hint_status.append('-');
	}

	scramble_word();
}

// Start the guessing sequence.
int Scramble::start()
{
	while (guess != unscrambled_word && hints > 0)
	{
		display_status();
		get_guess();
	}

	return hints;
}

// Scramble the word to be guessed.
void Scramble::scramble_word()
{
	unsigned seed = std::chrono::system_clock::now()
			.time_since_epoch()
			.count();

	shuffle(
			scrambled_word.begin(),
			scrambled_word.end(),
			std::default_random_engine(seed)
	);
}

// TODO: Can be broken if word shorter than 10 characters.
void Scramble::hint()
{
	srand(time(nullptr));
	int index = std::rand() % hint_status.size();

	while (hint_status.get(index) != '-')
	{
		if (index == hint_status.size())
		{
			index = 0;
		}

		if (hint_status.get(index) == '-')
		{
			hint_status.set(index, unscrambled_word.get(index));
			break;
		}

		++index;
	}

	--hints;
}
