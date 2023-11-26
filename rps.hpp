#include <string>
using std::string;

class game
{
    public:
    game(int x,int y);
    string userinput();
    string compinput();
    void result(const string user,const string computer);
    void printfinalscore();
    ~game();
    
    private:
    int userscore;
    int computerscore;
};