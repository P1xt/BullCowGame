#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}



bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram, return an error
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
	
}


// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = GetHiddenWordLength();
	int32 GuessLength = Guess.length();


	// loop through all letters in the guess
	for (int32 GChar = 0; GChar < GuessLength; GChar++)
	{
		// compare letters against the hidden word
		for (int32 MWHChar = 0; MWHChar < HiddenWordLength; MWHChar++)
		{
			// if they match
			if (Guess[GChar] == MyHiddenWord[MWHChar])
			{
				// if they're in the same position
				if (MWHChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				// else
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString) const
{
	return false;
}
