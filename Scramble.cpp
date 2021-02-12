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
	std::cout << std::endl;
}

// Prompt the user for a guess.
void Scramble::get_guess()
{
	std::cout << "Hit me with your best shot!" << std::endl;
	guess.clear();
	std::cout << "Guess: ";
	std::cin >> guess;
	std::cout << std::endl;
	if (guess.begin())
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

void Scramble::hint()
{

	--hints;
}
