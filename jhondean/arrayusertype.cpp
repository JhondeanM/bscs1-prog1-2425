#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;
    string userType;
    

public:
    User(string uname, string pword, string utype) {
        username = uname;
        password = pword;
        userType = utype;
        
    }

    bool login(string uname, string pword) {
        return (username == uname && password == pword);
    }

    void displayRole() {
        cout << endl;
        cout << "Welcome, " << userType << "!" << endl;
    }
};

int main() {
    
    User student[] = {
        User("student1", "STUD1", "Student"),
        User("student2", "STUD2", "Student")
       
    };
    User faculty[] = {
        User("faculty1", "FAC1", "Faculty"),
        User("faculty2", "FAC2", "Faculty")
       
    };
    User admin[] = {
        User("admin1", "AD1", "Administrator"),
        User("admin2", "AD2", "Administrator")
    };

    string uname, password;
    
    
    int size = 4;
    bool loggedIn = false;

    
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> password;

    
    for (int i = 0; i < size; i++) {
        if (student[i].login(uname, password)) {
            student[i].displayRole();
            loggedIn = true;
            break;
        }
    }

    if (!loggedIn) {
        for (int i = 0; i < size; i++) {
            if (faculty[i].login(uname, password)) {
                faculty[i].displayRole();
                loggedIn = true;
                break;
            }
        }
    }

    if (!loggedIn) {
        for (int i = 0; i < size; i++) {
            if (admin[i].login(uname, password)) {
                admin[i].displayRole();
                loggedIn = true;
                break;
            } 
        }
    }

    
    if (!loggedIn) {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}
