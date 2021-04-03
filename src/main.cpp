#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class login_manager
{
    public:

        void startUp()
        {
            cout << "do you have an account with us (y/n)?\n";
            cin >> answer;

            if (answer[0] == 'y')
            {
                login();
            }

            else if (answer[0] == 'n')
            {
                newUser();
            }
        
            else
            {
                cout << "invalid answer.\n";
                startUp();
            }
        }
        int newUser()
        {
            userFile.open("../resources/usernames.dat", ios::out | ios::in);
            passFile.open("../resources/passwords.dat", ios::out);
        
            cout << "Enter a username: ";
            cin >> newUsername;
            
            while (getline(userFile, checkName))
            {
                if (newUsername == checkName)
                {
                    cout << "There is already a user with the same name." << endl;
                    return 1;
                }
            }

            cout << "Enter a password: ";
            cin >> newPassword; 
            
            cout << "Re-type password: ";
            cin >> newPasswordConfirm;

            if (newPassword == newPasswordConfirm)
            {
                if (newPassword.size() > 16)
                {
                    cout << "Password must be <= 16" << endl;

                    return 1;
                }
            
            }
            return 0;
        }

        void login()
        {
            userFile.open("../resources/usernames.dat", ios::in);
            passFile.open("../resources/passwords.dat", ios::in);
            
            cout << "Username: ";
            cin >> usernameAttempt;
            
            while (getline(userFile, username)) 
            {
                line_nu++;
                
                if(username == usernameAttempt)
                {
                    break;
                }
            } 

            if (usernameAttempt == username)
            {
                cout << "Password: ";
                cin >> passwordAttempt;
                
                while (line_nu2 != line_nu && getline(passFile, password)) 
                {
                    line_nu2++;
                }
                
                if (passwordAttempt == password)
                {
                    cout << "Welcome!\n";
                }

                else 
                {
                    cout << "incorrect password. remember: usernames and passwords are case-sensitive.\n";
                }
            }

            else
            {
                cout << "user not found in our records. remember: usernames and passwords are case-sensitive.\n";
            }

        }

    private:
        fstream userFile;
        fstream passFile;
        
        int line_nu = 0;
        int line_nu2 = 0;

        string username;
        string usernameAttempt;
        string password;
        string passwordAttempt;
        
        string newUsername;
        string checkName;
        string newPassword;
        string newPasswordConfirm;
        
        string answer;

};


int main()
{
    login_manager login_app;
    login_app.startUp();
}


