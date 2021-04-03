#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class login_manager
{
    public:
        string username = "ansh";
        string usernameAttempt;
        string password = "maru";
        string passwordAttempt;

        void login()
        {
            cout << "Username: ";
            cin >> usernameAttempt;

            if (usernameAttempt == username)
            {
                cout << "Password: ";
                cin >> passwordAttempt;

                if(passwordAttempt == password)
                {
                    cout << "Welcome!\n";
                }
            }

        }
};


int main()
{
    login_manager login_app;
    login_app.login();
}


