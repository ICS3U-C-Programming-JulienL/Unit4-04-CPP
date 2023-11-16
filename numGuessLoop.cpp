// Copyright (c) 2023 Julien Lamoureux All rights reserved.
// .
// Created by: Julien Lamoureux
// Date: November 8, 2023
// This program is a number guessing game using a loop

#include <cstdlib>
#include <iostream>

int main() {
    // declare variables
    std::string userGuessString;
    int userGuessInt, correctGuess;

    // initialize random seed
    srand((unsigned)time(NULL));

    // generate the correct guess to a number between 0 and 9
    correctGuess = rand() % 9 + 0;

    do {
        // get the user guess
        std::cout << "\nA random number has been chosen between 0 and 9.";
        std::cout << "Guess the number. \nEnter an integer: ";
        std::cin >> userGuessString;

        try {
            // convert  the user guess to an integer
            userGuessInt = std::stoi(userGuessString);

            // if guess < 0 or > 9, tell user to enter int between 0 and 9
            if (userGuessInt < 0 || userGuessInt > 9) {
                std::cout << userGuessInt <<
                " is not a positive integer between 0 and 9.\n";
            } else {
                // otherwise : if guess != to correct guess, then break
                if (userGuessInt != correctGuess) {
                    std::cout << userGuessInt << " is not the answer.";
                } else {
                    // otherwise, break out of the loop
                    break;
                }
            }
        } catch (std::invalid_argument) {
            // if the guess is not an int, then tell them their input is invalid
            std ::cout << userGuessString << " is not a valid integer.\n";
        }
    } while (userGuessInt != correctGuess);

    // once the user gets the right answer, say they got it right
    std::cout << correctGuess << " is right!" << std::endl;
}
