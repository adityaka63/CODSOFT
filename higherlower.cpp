#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int randomNumber = rand() % 20 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    while (true) {
        cout << "Guess the number between 1 and 20: ";
        cin >> guess;
        attempts++;

        if (guess < 1 || guess > 20) {
            cout << "Please enter a number between 1 and 20." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
