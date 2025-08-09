#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main()
{
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(0)));

    int randomNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess = 0;

    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Keep asking until the user guesses correctly
    while (guess != randomNumber)
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > randomNumber)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < randomNumber)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "🎉 Congratulations! You guessed it right!" << endl;
        }
    }

    return 0;
}
