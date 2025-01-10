#include <iostream>
using namespace std;

void mainMenu(void);
void teamManagement(void);
void playerManagement(void);
void managersManagement(void);
void matchSimulation(void);
void reports(void);

struct Player
{
    string name;
    int age;
    int power;

};

struct Team
{
    string teamName;
    Player playerArray[11];
};

int main(){
    mainMenu();

    cout << "Game Over!";
}

void mainMenu(void){
    cout<<"===== Football League Management ====="<<endl
    <<"1. Manage Teams"<<endl
    <<"2. Manage Players"<<endl
    <<"3. Manage Managers"<<endl
    <<"4. Simulate Match"<<endl
    <<"5. View Reports"<<endl
    <<"6. Exit"<<endl
    <<"Enter your choice: ";

    do{
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        teamManagement();
        break;
    case 2:
        playerManagement();
        break;
    case 3:
        managersManagement();
        break;
    case 4:
        matchSimulation();
        break;
    case 5:
        reports();
        break;
    case 6:
        break;
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);
}

void teamManagement(void){
    cout<<"===== Team Management =====\n"
    <<"1. Add a New Team\n"
    <<"2. Edit an Existing Team\n"
    <<"3. Delete a Team\n"
    <<"4. View All Teams\n"
    <<"5. Back to Main Menu\n"
    <<"Enter your choice: ";
    int n;
    cin>>n;


}

void playerManagement(void){
    cout<<"===== Player Management =====\n"
    <<"1. Add a New Player\n"
    <<"2. Edit Player Information\n"
    <<"3. Delete a Player\n"
    <<"4. View All Players in a Team\n"
    <<"5. Back to Main Menu\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}

void managersManagement(void){
    cout<<"===== manager management =====\n"
    <<"1. add manager\n"
    <<"2. show manager information\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}

void matchSimulation(void){
    cout<<"===== Match Simulation =====\n"
    <<"1. Select Two Teams for a Match\n"
    <<"2. Back to Main Menu\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}

void reports(void){
    cout<<"===== Reports =====\n"
    <<"1. View All Teams and Players\n"
    <<"2. View Match Results\n"
    <<"3. View League Standings\n"
    <<"4. Back to Main Menu\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}