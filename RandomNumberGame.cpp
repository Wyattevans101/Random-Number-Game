#include <iostream>
#include <cstdlib>
using namespace std;

int main() 
{
    //Step  1: Define your constants (if any) and your variables
    int minValue = 100, maxValue = 999, tries = 10, wins = 0,  userGuess, randNum;
    bool again = true, userCorrection = false, repeatGame = false;
    char userAnswer;
    
    //Step  3: Generate a random number between 100 and 999 srand(time(NULL));

    srand (time(NULL));
    randNum = (rand() % (maxValue - minValue + 1 )) + minValue;

    //step 13
    do 
    {
        
        
        
        do
        {
            
            //Step  2: Output game instructions
            cout << "\n*********************************************" << endl;
            cout << "*    Guess a number between 100 and 999!    *" << endl;
            cout << "*********************************************" << endl; 
        
            cout << "\n\nTest number: " << randNum << endl << endl;
            
            //Step  5: Output the number of tries available
            cout << "You have " << tries << " left and " << wins << " win(s)" << endl << endl;
            
            //Step  6: Read a guess from the user
            cout << "Please enter your guess: ";
            cin >> userGuess;
        
            //Step  7: Validate the input (must be between 100 and 999)
            while(userGuess > 999 || userGuess < 100)
            {
                if(userGuess > 999 || userGuess < 100)
                {
                    cout << "\n\nYou have entered an invalid number, Please re-enter: ";
                    cin >> userGuess;
                    
                }  
            }
            
            if(userGuess > randNum)
            {
                cout << "\n\n*Please guess lower* " << endl;
            }
            else if (userGuess < randNum)
            {
                cout << "\n\n*Please guess higher*" << endl;
            }
            //step 8
            tries--;
            
            //step 9
            if(userGuess == randNum)
            {
                wins++;
                
                cout << "\nCongratulations! You have guessed the correct number!" << endl << endl;
                //step 11
                cout << "Would you like to replay? (Y/N) ";
                cin >> userAnswer;
                do 
                {
                    //step 12
                    switch(userAnswer)
                    {
                        case 'y':
                        case 'Y':
                        tries = 10;
                        randNum = (rand() % (maxValue - minValue + 1 )) + minValue;
                        again = false;
                        userCorrection = false;
                        repeatGame = true;
                        break;
                        case 'n':
                        case 'N':
                        cout << "\n\nGoodbye!";
                        return 0;
        
                        default: 
                        cout << "You have entered something other then Y/N please re-enter your choice: ";
                        cin >> userAnswer;
                        userCorrection = true;
                    }    
                }
                while(userCorrection);
                
                     
            }

            //if user runs out of tries
            if(tries == 0)
            {
                cout << "\n\nYou have used all of your tries, would you like to restart? (Y/N) ";
                cin >> userAnswer;
                do 
                {
                    switch(userAnswer)
                    {
                        case 'y':
                        case 'Y':
                        tries = 10;
                        //regenerates random number!
                        randNum = (rand() % (maxValue - minValue + 1 )) + minValue;
                        again = false;
                        userCorrection = false;
                        repeatGame = true;
                        break;
                        
                        case 'n':
                        case 'N':
                        cout << "\n\nGoodbye!";
                        return 0;
        
                        default: 
                        cout << "\n\nYou have entered something other then Y/N please re-enter your choice: ";
                        cin >> userAnswer;
                        userCorrection = true;
                    }    
                }
                while(userCorrection);
                
            }
            
        }
        while(again);

    }
    while(repeatGame);
    

}