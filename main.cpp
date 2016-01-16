#include <iostream>
#include <cstdlib>
#include <ctime>

std::string greeting();
bool wantToPlay(std::string name);
int playGame(std::string name);


int main ()
{
    std::string name  = "";


    name = greeting();

    if (wantToPlay(name))
    {
     playGame(name);
    }
}

std::string greeting()
{
    std::cout << "Lets start by getting your name: ";

    std::string name = "";
    getline(std::cin, name);

    return name;
}

bool wantToPlay(std::string name)
{
    std::string game = "";
    std::cout << "Hello " << name << ", ";
    do
    {
        std::cout << "do you want to play a game?(y/n)";
        std::cin >> game;

       if (game == "y")
       {
           std::cout << "Ok, lets play the number guessing game!" << std::endl;
           return true;
       }
       else if (game == "n")
       {
           std::cout << "Come back when you want to play a game!" << std::endl;
           return false;
       }
       else
       {
           std::cout << "Invalid selection, try again." << std::endl;
       }



    } while (game != "y" && game != "n");
    return false;
}

int playGame(std::string name)
{
    int secretNumber = 0;
    int guess = 0;
    int lastGuess = 0;
    int highestGuess = 100;
    int lowestGuess = 1;

    srand (time(NULL));
    secretNumber = rand() % 100 + 1;

    for ( int guesses = 10; guesses >0; guesses --)
    {
        if (guesses == 10)
        {
            std::cout << "You have 10 guesses, try to guess the secret number!" << std::endl;
            lastGuess = rand() % 100 + 1;
            std::cout << "The computer guesses " << lastGuess << "." << std::endl;
            guess = lastGuess;
            if (guess > secretNumber)
            {
                highestGuess = lastGuess;
            }
            else if ( guess < secretNumber)
            {
                lowestGuess = lastGuess;
            }
        }
        else if (guess > secretNumber)
        {
            highestGuess = guess;
            std::cout << guess << " is too high" << std::endl;
            std::cout << "You have " << guesses << " guesses left, try again!" << std::endl;
            guess = (highestGuess - lowestGuess) / 2 + lowestGuess;
        }
        else if (guess < secretNumber)
        {
            lowestGuess = guess;
            std::cout << guess << " is too low, try again." << std::endl;
            std::cout << "You have " << guesses << " guesses left, try again!" << std::endl;
            guess = (highestGuess - lowestGuess) / 2 + lowestGuess;
        }

        else if (guess == secretNumber)
        {
            std::cout << "Nice, " << name << " you guess, " << guess <<  ". Thats the number!" << std::endl;
            std::cout << "You guessed it with  " << guesses << " guesses left!" << std::endl;
            std::cout << "You guessed the secret number!" << std::endl;
            break;
        }
    }
    if (guess != secretNumber)
    std::cout << "You ran out of guesses, the secret number was " << secretNumber << ". better luck next time!";

    return 0;
}
