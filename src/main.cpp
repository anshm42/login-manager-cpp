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
        
            cout << "Enter a username: ";
            cin >> newUsername;
            
            while (getline(userFile, checkName))
            {
                if (newUsername == checkName)
                {
                    cout << "There is already a user with the same name." << endl;
                    userFile.close();
                    return 1;
                }
            }

            cout << "Enter a password: ";
            cin >> newPassword; 
            
            cout << "Re-type password: ";
            cin >> newPasswordConfirm;

            if (newPassword != newPasswordConfirm)
            {
                
                cout << "Passwords must match.\n";
                return 1;

            }

            else if (newPassword.size() > 16)
            {
                cout << "Password must be <= 16" << endl;
                return 1;
            }
            
            userFile.open("../resources/usernames.dat", ios::app | ios::in);
            passFile.open("../resources/passwords.dat", ios::app);
            userFile << newUsername << "\n";
            passFile << newPassword << "\n";

            userFile.close();
            passFile.close();

            cout << "Your user has been created!\n";
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

        int spaceCount = 0;

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


