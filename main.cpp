/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame Class
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// FString is mutable
// FText - used for user output

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuess(FText);
bool AskToPlayAgain();
FBullCowGame BCGame;

// the entry point for our application
int main() 
{
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we validate guess
	for (int32 Count = 0; Count < MaxTries; Count++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid guess
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		}
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";

		// repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarize game
	//
}

// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
}

FText GetGuess() // TODO change to GetValidGuess
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get a guess from the player
	std::cout << "Try: " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}