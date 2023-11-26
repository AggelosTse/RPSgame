#include <iostream>
#include <unistd.h>
#include "rps.hpp"

using std::cin,std::cout;


void clearscreen()  
{
  #ifdef _WIN32     //checks if the program is running from a Windows operating system.
    system("cls");  //if it does, it runs this command, which clears old data from the screen (runs only on windows).
  #else
    system("clear");  //if it is running from unix or macOS, it runs this command that does the same thing.
  #endif
}
    

string validinput(string x)     //checks for valid input and returns it to the main function.
    {
        while(x != "N" && x != "Y" && x != "n" && x != "y")
            {
                cout << "invalid input, try again.\n";
                cin >> x;
            }
        return x;
    }


int main()
    {
        game g(0,0);    //Creates the object and initializes values in it.
        string USinput,COinput,answer,s;
        sleep(1);
        cout << "Do you want to play? (Y/N)\n";
        cin >> answer;
        s = validinput(answer);
        while(s == "y" || s == "Y")     //keeps looping until the user types "n or N".
        {
            clearscreen();
            sleep(1);
            cout << "Rock, paper or scissors?\n";
            USinput = g.userinput();
            sleep(1);
            clearscreen();
            cout << "Loading..\n";
            sleep(1);
            clearscreen();
            COinput = g.compinput();
            g.result(USinput,COinput);
            sleep(2);
            clearscreen();
            cout << "Play Again? (Y/N)\n";
            cin >> answer;
            s = validinput(answer);
            clearscreen();
            if(s == "N" || s == "n")       //when the user types "n" or "N", it breaks from the loop and prints score.
                {
                    g.printfinalscore();
                    break;
                }
        }
        return 0;
    }