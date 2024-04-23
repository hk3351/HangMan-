/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream> 
#include <ctime> 
using namespace std;
const int tries = 5;
int letterFill (char, string, string&);
void instructions ();
int main ()
{
    string name; 
    char letter;
    int wrongGuess = 0;
    string word;
    string words []= {
        "japan","turkey", "nepal", "malaysia", "philippines", "australia",
"america","ethiopia","oman","indonesia"
    };
    srand (time (NULL));
    int n = rand () % 10;
    word = words [n];
    string unknown(word. length(),'*');
    instructions ();
    while(wrongGuess < tries)
    {
        cout << unknown << endl << endl; 
        cout << "Guess a letter:" ;
        cin >> letter;
        if (letterFill(letter, word, unknown) == 0)
        {
            cout << endl << "Whoops! That letter isn't in there!" << endl; 
            wrongGuess++;
            
        }
        else
        {
            cout << endl << "You found a letter! Isn't that exciting!" << endl;
        }
        cout << "You have " << tries - wrongGuess << " guesses left." << endl;
        if (word == unknown)
        {
            cout << word << endl; 
            cout <<"Yeah! You got it!";
            break;
        }
    }
    if (wrongGuess == tries)
    {
        cout << "Sorry, you lose...you've been hanged." << endl; 
        cout << "The word was: " << word << endl;
    }
    cin.ignore();
    cin.get ();
    return 0;
}
void instructions () {
    cout << "Welcome to hangman...Guess a country Name" << endl << endl; 
    cout << "Each letter is represented by a star." << endl << endl;
    cout << "You have to type only one letter in one try" << endl << endl;
    cout << "You have" << tries << " tries to try and guess the word." << endl <<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}
int letterFill(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword. length();
    for (i = 0; i < len; i++)
    {
        if (guess == guessword[i])
        return 0;
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
            
        }
    }
    return matches;
}
