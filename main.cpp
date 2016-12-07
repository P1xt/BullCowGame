#include <iostream>
#include <string>

using namespace std;
void PrintIntro();
string GetAndPrintGuess();

// the entry point for our application
int main() 
{
	PrintIntro();
	string Guess= "";
	constexpr int NUMBER_OF_TURNS = 5;

	// loop for the number of turns asking for guesses
	for (int Count = 0; Count < NUMBER_OF_TURNS; Count++)
	{
		Guess = GetAndPrintGuess();
	}


	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	cout << endl;
}


string GetAndPrintGuess() 
{
	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	
	// repeat the guess back to them
	cout << "You guess was: " << Guess << endl;
	cout << endl;
	return Guess;
}