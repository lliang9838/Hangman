#include <iostream> ///for input/output
#include <cstdlib> //dynamic memory management, random number generator
#include<ctime> //for using time function which is used for random generator
#include <string> //for being able to use strings
using namespace std;

int MAX=6; //maximum 6 tries
int turn = 1; //intial turn is zero

int fill_letter (char guess, string secretword, string &guessword);

int main ()
{
	//initilizations
	string name;
	char letter;
	int wrongGuesses=0;
	string secret_word;
	string words[] =
	{
		"rumman",
		"abdullah",
		"amy",
		"kevin",
		"max",
		"tracy",
		"tyler",
		"lilit",
		"ilcias",
		"earl"
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL)); //to change the seed of values (to truly randomize everything)
	int n=rand()% 10;
	secret_word=words[n];

	// Initialize the secret word with the * character.
	string unknown(secret_word.length(),'*'); //intialize that length of *'s'

	// welcome the user
	cout << "\n\nWelcome to hangman...Guess one of my friend's name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX << " total tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
		while (wrongGuesses < MAX)
		{

			cout << "\nTURN "<< turn;
			cout << "\n------\n\n";


			// Tell user how many guesses has left.

			cout << "You now have " << MAX - wrongGuesses << " guesses left." << endl;
			//cout << " guesses left." << endl;

			cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (fill_letter(letter, secret_word, unknown)==0)
			{
				cout << endl << "Wrong letter/Duplicate letter. Please try again!" << endl;
				wrongGuesses++;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

			}
			else
			{
				cout << endl << "You found a letter! Nice job! " << endl;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			}

			// Check if user guessed the word.
			if (secret_word==unknown) //called string library to be able to do this
			{
				cout << secret_word << endl;
				cout << "BINGO!";
				break;
			}
			turn = turn + 1;
		}
	if(wrongGuesses == MAX)
	{
		cout << "\nSorry, you have now been hanged" << endl;
		cout << "The word was : " << secret_word << endl;
	}
	cin.ignore(); //ignore next character in the buffer
	cin.get();
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int fill_letter(char guess, string word, string &myword)
{
	int i;
	int matches=0;
	int size=myword.length();
	for (i = 0; i< size; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == myword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == word[i])
		{
			myword[i] = guess;
			matches++;
		}
	}
	return matches;
}
//get leaves delimiter in the queue, getline doesn't
//ignore() will flush the input stream, just like C fflush(stdin), which is great for removing the annoying new lines stored at the end of the stream :P
