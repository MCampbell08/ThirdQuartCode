#include <iostream>;

enum GuessResult {low, high, correct, quit};

using std::cout;
using std::cin;
using std::endl;

int totalOfGuesses = 1;

const int minNum = 1;
const int maxNum = 10000;

void GuessYourNumber();
bool PlayAgain();

bool PlayAgain()
{
	cout << "Would you like to play again? Press 'y' or 'n' then hit enter: ";
	char answer = 0;
	cin >> answer;
	if (answer == 'y')
		return true;
	else
		cout << "See ya later!";
		return false;
}

GuessResult ShowGuessAndGetResponse(int guess, int numGuesses)
{
	char answer = 0;
	cout << numGuesses << ": " << guess << "? 'H' if too high, 'L' if too low, 'C' if I guessed correctly, or 'Q' to quit!";
	cin >> answer;
	if (answer == 'H' || answer == 'h')
	{
		return GuessResult::high;
	}
	else if (answer == 'L' || answer == 'l')
	{
		return GuessResult::low;
	}
	else if (answer == 'C' || answer == 'c')
	{
		return GuessResult::correct;
	}
	else
	{
		return GuessResult::quit;
	}

}

void GuessYourNumber() 
{

	int guessMin = minNum;
	int guessMax = maxNum;
	char answer = 0;

	cout << "Please think of a number between 1 and 10,000. Press 'R' when you're ready or 'Q' to quit.";
	cin >> answer;

	if (answer == 'R' || answer == 'r')
	{
		for (;;)
		{
			int currentGuess = ((guessMin + guessMax) / 2);
			GuessResult result = ShowGuessAndGetResponse(currentGuess, totalOfGuesses);

			if (result == GuessResult::high)
			{
				totalOfGuesses += 1;
				guessMax = currentGuess;
			}
			else if (result == GuessResult::low)
			{
				totalOfGuesses += 1;
				guessMin = currentGuess;
			}
			else if (result == GuessResult::correct)
			{
				totalOfGuesses += 1;
				cout << "Awesome! I guessed your number, " << currentGuess << " in " << totalOfGuesses << " tries." << endl;
				if (PlayAgain())
				{
					GuessYourNumber();
				}
			}
			else if (result == GuessResult::quit)
			{
				cout << "Oh, I see how it is! Bye." << endl;
				break;
			}
		}
	}
	else 
	{
		cout << "Thanks for coming by!" << endl;
	}
}

int main()
{
	GuessYourNumber();
	return 0;
}