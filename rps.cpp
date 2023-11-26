#include <iostream>
#include <limits>
#include "rps.hpp"

using std::cout,std::cin,std::string;


game::game(int x,int y)     //initializes classe's variables.
    {
        userscore = x;
        computerscore = y;
    }


game::~game() {};           //destroys the object.


string game::userinput()    //Gets user's input and checks if its valid .
{
    string answer;
    do 
    {
        std::cin >> answer;
        
        if (answer != "rock" && answer != "paper" && answer != "scissors") 
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input, try again\n";
        }
    } while (answer != "rock" && answer != "paper" && answer != "scissors");
    
    return answer;
}


string game::compinput()        //gives random values from 1 to 3. (1 = rock, 2 = paper, 3 = scissors)
    {
        int r = std::rand() % 3 + 1;;
        string answer;
        switch(r)
        {
            case 1: {answer = "rock"; cout << "I chose rock.\n"; break;}
            case 2: {answer = "paper";cout << "I chose paper.\n"; break;}
            case 3: {answer = "scissors";cout << "I chose scissors.\n"; break;}
        }
        return answer;
    }


void game::result(const string user,const string computer)      //Prints result and changes values depending on user's and computer's choise.
    {
        if((user=="rock" && computer=="rock")||(user=="paper" && computer=="paper")||(user=="scissors" && computer == "scissors"))
        {
            cout << "Its a draw.\n";
            userscore++;
            computerscore++;
        }
        else if((user=="rock" && computer=="scissors")||(user=="paper" && computer=="rock")||(user=="scissors" && computer=="paper"))
        {
            cout << "You won!\n";
            userscore++;
        } 
        else if((user=="rock" && computer=="paper")||(user=="paper" && computer=="scissors")||(user=="scissors" && computer=="rock"))
        {
            cout << "You lost.\n";
            computerscore++;
        }

    }


void game::printfinalscore()    //prints the final score before the user quits the app.
    {
        if(userscore > computerscore) {cout << "You won with score: " << userscore << "-" << computerscore << "\n";}
        else if(userscore < computerscore) {cout << "You lost with score: " << userscore << "-" << computerscore << "\n";}
        else if(userscore = computerscore) {cout << "Its a Draw with score: " << userscore << "-" << computerscore << "\n";}
    }     