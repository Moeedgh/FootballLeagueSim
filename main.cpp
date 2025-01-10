#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Team;

struct Player
{
    string name;
    int age;
    int strength;
    Team* team;
};

struct Manager {
    string name;
    string yearsExperience;
    Team* team;
};

struct Team {
    string name;
    Manager coach;
    vector<Player> players;
    int wins = 0;
    int losses = 0;
    int points = 0;
};

struct MatchResult {
    Team* team1;
    Team* team2;
    Team* winner;
};

vector<Team> teams;
vector<MatchResult> matchResults;

void addTeam() {
    system("cls");
    cout << "===== Add a New Team =====\n";
    Team newTeam;
    cout << "Enter team name: ";
    cin.ignore();
    getline(cin, newTeam.name);
    cout << "Enter coach name: ";
    getline(cin, newTeam.coach.name);
    cout << "Enter coach's years of experience: ";
    getline(cin, newTeam.coach.yearsExperience);
    newTeam.coach.team = &newTeam;
    teams.push_back(newTeam);
    cout << "Team added successfully!\n";
    system("pause");
}

void editTeam() {
    system("cls");
    cout << "===== Edit an Existing Team =====\n";
    cout << "Enter the team name to edit: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout << "Editing team: " << team.name << "\n";
            cout << "Enter new team name (Press enter to keep current): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                team.name = newName;
            }
            cout << "Enter new coach name (Press enter to keep current): ";
            string newCoachName;
            getline(cin, newCoachName);
            if (!newCoachName.empty()) {
                team.coach.name = newCoachName;
            }
            cout << "Enter new coach's years of experience (Press enter to keep current): ";
            string newYearsExperience;
            getline(cin, newYearsExperience);
            if (!newYearsExperience.empty()) {
                team.coach.yearsExperience = newYearsExperience;
            }
            cout << "Team updated successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void deleteTeam() {
    system("cls");
    cout << "===== Delete a Team =====\n";
    cout << "Enter the team name to delete: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto it = teams.begin(); it != teams.end(); ++it) {
        if (it->name == teamName) {
            teams.erase(it);
            cout << "Team deleted successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void viewTeams() {
    system("cls");
    cout << "===== View All Teams =====\n";
    for (const auto& team : teams) {
        cout << "Team Name: " << team.name << "\n";
        cout << "Coach Name: " << team.coach.name << "\n";
        cout << "Coach's Years of Experience: " << team.coach.yearsExperience << "\n";
        cout << "Wins: " << team.wins << ", Losses: " << team.losses << ", Points: " << team.points << "\n";
        cout << "Players:\n";
        for (const auto& player : team.players) {
            cout << "  Name: " << player.name << ", Age: " << player.age << ", Strength: " << player.strength << "\n";
        }
        cout << "-------------------------\n";
    }
    system("pause");
}

void addPlayer() {
    system("cls");
    cout << "===== Add a New Player =====\n";
    cout << "Enter team name to add player to: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            Player newPlayer;
            cout << "Enter player name: ";
            getline(cin, newPlayer.name);
            cout << "Enter player age: ";
            cin >> newPlayer.age;
            cout << "Enter player strength: ";
            cin >> newPlayer.strength;
            newPlayer.team = &team;
            team.players.push_back(newPlayer);
            cout << "Player added successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void editPlayer() {
    system("cls");
    cout << "===== Edit Player Information =====\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout << "Enter player name to edit: ";
            string playerName;
            getline(cin, playerName);

            for (auto& player : team.players) {
                if (player.name == playerName) {
                    cout << "Editing player: " << player.name << "\n";
                    cout << "Enter new player name (Press enter to keep current): ";
                    string newName;
                    getline(cin, newName);
                    if (!newName.empty()) {
                        player.name = newName;
                    }
                    cout << "Enter new player age (Press enter to keep current): ";
                    string newAge;
                    getline(cin, newAge);
                    if (!newAge.empty()) {
                        player.age = stoi(newAge);
                    }
                    cout << "Enter new player strength (Press enter to keep current): ";
                    string newStrength;
                    getline(cin, newStrength);
                    if (!newStrength.empty()) {
                        player.strength = stoi(newStrength);
                    }
                    cout << "Player updated successfully!\n";
                    system("pause");
                    return;
                }
            }
            cout << "Player not found!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void deletePlayer() {
    system("cls");
    cout << "===== Delete a Player =====\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout << "Enter player name to delete: ";
            string playerName;
            getline(cin, playerName);

            for (auto it = team.players.begin(); it != team.players.end(); ++it) {
                if (it->name == playerName) {
                    team.players.erase(it);
                    cout << "Player deleted successfully!\n";
                    system("pause");
                    return;
                }
            }
            cout << "Player not found!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void viewPlayers() {
    system("cls");
    cout << "===== View All Players in a Team =====\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (const auto& team : teams) {
        if (team.name == teamName) {
            cout << "Team Name: " << team.name << "\n";
            cout << "Players:\n";
            for (const auto& player : team.players) {
                cout << "  Name: " << player.name << ", Age: " << player.age << ", Strength: " << player.strength << "\n";
            }
            cout << "-------------------------\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void addManager() {
    system("cls");
    cout << "===== Add a New Manager =====\n";
    cout << "Enter team name to add manager to: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout << "Enter manager name: ";
            getline(cin, team.coach.name);
            cout << "Enter manager's years of experience: ";
            getline(cin, team.coach.yearsExperience);
            team.coach.team = &team;
            cout << "Manager added successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void editManager() {
    system("cls");
    cout << "===== Edit Manager Information =====\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout << "Editing manager for team: " << team.name << "\n";
            cout << "Enter new manager name (Press enter to keep current): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                team.coach.name = newName;
            }
            cout << "Enter new manager's years of experience (Press enter to keep current): ";
            string newYearsExperience;
            getline(cin, newYearsExperience);
            if (!newYearsExperience.empty()) {
                team.coach.yearsExperience = newYearsExperience;
            }
            cout << "Manager updated successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void deleteManager() {
    system("cls");
    cout << "===== Delete Manager =====\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            team.coach.name = "";
            team.coach.yearsExperience = "";
            team.coach.team = nullptr;
            cout << "Manager deleted successfully!\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void showManagerInfo() {
    system("cls");
    cout << "===== Show Manager Information =====\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (const auto& team : teams) {
        if (team.name == teamName) {
            cout << "Manager Name: " << team.coach.name << "\n";
            cout << "Years of Experience: " << team.coach.yearsExperience << "\n";
            cout << "-------------------------\n";
            system("pause");
            return;
        }
    }
    cout << "Team not found!\n";
    system("pause");
}

void mainMenu(void){
    system("cls");
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
    system("cls");
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
    system("cls");
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
    system("cls");
    cout<<"===== manager management =====\n"
    <<"1. add manager\n"
    <<"2. show manager information\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}

void matchSimulation(void){
    system("cls");
    cout<<"===== Match Simulation =====\n"
    <<"1. Select Two Teams for a Match\n"
    <<"2. Back to Main Menu\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}

void reports(void){
    system("cls");
    cout<<"===== Reports =====\n"
    <<"1. View All Teams and Players\n"
    <<"2. View Match Results\n"
    <<"3. View League Standings\n"
    <<"4. Back to Main Menu\n"
    <<"Enter your choice: ";

    int n;
    cin>>n;
}

int main(){
    mainMenu();

    cout << "Game Over!";
}