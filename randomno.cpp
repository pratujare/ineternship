#include <iostream>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));
    int min= 0;
    int max = 200;
    
    // Generate a random number between 0 and 200
    int random_no = rand() %(max-min +1) + min ;
    int guess = 0;

    cout << "Heyy !! Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 0 and 200 . Can you guess it?" << endl;

    // Loop until the user guesses the correct number
    while (guess != random_no) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < random_no) {
            cout << "Too low! Try again." << endl;
        } else if (guess > random_no) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number!" << endl;
        }
    }

    return 0;
}
