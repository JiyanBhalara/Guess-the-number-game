// Including all the neccessary header files for our program.
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{

    // Decalring variables and enumeration constant needed for the program.
    int Score = 100;
    int LeftBound = -1, RightBound = -1;
    enum Menu
    {
        DisplayLeft = 1,
        DisplayRight = 2,
        Guess = 3,
        Change = 4,
        Exit = 5
    };
    Menu MenuChoice;
    string UserName;
    int Choice;
    bool ValidUserName;
    int SuffixIndex;
    int FirstRandomNum, SecondRandomNum;
    int GuessNum;

    // Displaying the default message
    cout << "+-------------------------------------------------+" << endl;
    cout << "|                 Guess the number                |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    // Asking user to input name using cout, cin and getline
    cout << "Enter your name: ";
    getline(cin, UserName);

    /*
      Writing a do-while and for loop to check whether the name entered by user is in alphabets or whitespace?
      We will also use if-else statement to verify the username is valid or not using isalpha and isspace methods.
    */
    do
    {
        for (int i = 0; i < UserName.size(); i++)
        {
            if ((isalpha(UserName.at(i))) || (isspace(UserName.at(i))))
            {
                ValidUserName = true;
            }
            else
            {
                ValidUserName = false;
                break;
            }
        }

        if (ValidUserName == false)
        {
            cout << "Your name can only have alphabets or spaces. Enter again." << endl;
            cout << "Enter your name: ";
            getline(cin, UserName);
        }

    } while (ValidUserName != true);

    /*
    As we get a valid username from user, We will convert all the characters to lowercase using for loop and tolower().
    Then, will change intial to uppercase using toupper().
    Also, We will change suffix as directed if we found "Senior" or "Junior" in name.
    */
    for (int i = 0; i < UserName.size(); i++)
    {
        UserName.at(i) = tolower(UserName.at(i));
    }

    // Converting intials to uppercase.
    for (int i = 0; i < UserName.size(); i++)
    {
        UserName.at(0) = toupper(UserName.at(0));
        if (UserName.at(i) == ' ')
        {
            UserName.at(i + 1) = toupper(UserName.at(i + 1));
        }
    }

    // Converting suffix, if found, to ,Sr. or ,Jr. as directed.
    if ((UserName.find("Senior")) < UserName.size())
    {
        // Changing Suffix "Senior" to ", Sr."
        SuffixIndex = UserName.find("Senior");
        UserName.replace(SuffixIndex - 1, SuffixIndex + 4, ", Sr.");
    }
    else if ((UserName.find("Junior")) < UserName.size())
    {
        // Changing Suffix "Junior" to ", Jr."
        SuffixIndex = UserName.find("Junior");
        UserName.replace(SuffixIndex - 1, SuffixIndex + 4, ", Jr.");
    }

    // Displaying Welcome message once username is valid as directed.
    cout << "Welcome " << UserName << endl;
    cout << LeftBound << "      " << RightBound << endl;
    cout << endl;

    /*
    Generating seeded random number between range 150 to 250 (inclusive) as directed
    until the FirstRandomNum is less than SecondRandomNum, using do-while loop.
    */
    srand(time(0));
    do
    {
        FirstRandomNum = rand() % 101 + 150;
        SecondRandomNum = rand() % 101 + 150;

        if (FirstRandomNum < SecondRandomNum)
        {
            break;
        }

    } while (FirstRandomNum < SecondRandomNum);
    

    while ((Choice != 5) && (Score >= 0))
    {
        // Displaying Menu for user to select from.
        cout << "Menu:" << endl;
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in the range (inclusive)" << endl;
        cout << "4. Change numbers" << endl;
        cout << "5. Exit" << endl;

        // Asking user to input any one of the choices.
        cout << "Your choice: ";
        cin >> Choice;

        // Casting User choice to the enum decalred to write our switch cases.
        MenuChoice = static_cast<Menu>(Choice);

        // Writing switch cases for user-inputted choice over MenuChoice
        switch (MenuChoice)
        {

        // Display Left Bound
        case 1:

            if (RightBound == SecondRandomNum)
            {
                cout << "You have already displayed the right boundary, you cannot display both." << endl;
            }
            else
            {
                cout << "You will only get 1 point for guessing correctly and lose 10 points for guessing incorrectly, now." << endl;
                LeftBound = FirstRandomNum;
            }
            cout << LeftBound << "      " << RightBound << endl;
            cout << endl;
            break;


        // Display Right Bound
        case 2:

            if (LeftBound == FirstRandomNum)
            {
                cout << "You have already displayed the left boundary, you cannot display both." << endl;
            }
            else
            {
                cout << "You will only get 1 point for guessing correctly and lose 10 points for guessing incorrectly, now." << endl;
                RightBound = SecondRandomNum;
            }
            cout << LeftBound << "      " << RightBound << endl;
            cout << endl;
            break;


        // Asking user to guess the number
        case 3:
            cout << "Enter your guess: ";
            cin >> GuessNum;
            
            if ((GuessNum >= FirstRandomNum) && (GuessNum <= SecondRandomNum))
            {
                if ((LeftBound == FirstRandomNum) || (RightBound == SecondRandomNum))
                {
                    Score = Score + 1;
                    cout << "You guessed correctly. You get 1 points." << endl;
                }
                else
                {
                    Score = Score + 5;
                    cout << "You guessed correctly. You get 5 points." << endl;
                }
            }
            else
            {

                if ((LeftBound == FirstRandomNum) || (RightBound == SecondRandomNum))
                {
                    Score = Score - 10;
                    cout << "You guessed incorrectly. You lose 10 points." << endl;
                }
                else
                {
                    Score = Score - 5;
                    cout << "You guessed incorrectly. You lose 5 points." << endl;
                }
            }

            cout << "Your remaining points = " << Score << endl;

            if (Score >= 0)
            {
                cout << LeftBound << "      " << RightBound << endl;
                cout << endl;
                
            }else{
                cout << "You are out of points." << endl;
                cout << "Bye " <<  UserName << "!!!" << endl;
            }
            break;
            

        // Score Updation as directed
        case 4:
            Score = Score - 1;
            do
            {
                FirstRandomNum = rand() % 101 + 150;
                SecondRandomNum = rand() % 101 + 150;

                if (FirstRandomNum < SecondRandomNum)
                {
                    LeftBound = -1;
                    RightBound = -1;
                    cout << "Your remaining points = " << Score << endl;
                    cout << "Generating new boundaries" << endl;
                    cout << LeftBound << "      " << RightBound << endl;
                    cout << endl;
                    break;
                }
            } while (FirstRandomNum < SecondRandomNum);

            

            break;

        // If exit is selected
        case 5:
            cout << "Bye " << UserName << " !!!" << endl;
            cout << "Your final points balance = " << Score << endl;
            break;

        // If users enter any wrong choice
        default:
            cout << "Wrong choice. Enter again.";
            cout << endl;
            break;
        }
    }

    return 0;
}