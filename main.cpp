#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>

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
    string team1;
    string team2;
    string winner;
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
    for (const auto& team : teams) {
        if (team.name == newTeam.name) {
            cout << "Team already exists!\n";
            system("pause");
            break;
        }
    }
    teams.push_back(newTeam);
    cout << "Team added successfully!\n";
    system("pause");
}

void editTeam() {
    system("cls");
    cout << "===== Edit an Existing Team =====\n";
    cout << "===== list of Teams =====\n";
    if (teams.empty()) {
        cout << "No teams available!\n";
        system("pause");
        return;
    }
    int count=1;
    for (const auto& team : teams) {
        cout << count << ". " << team.name << "\n";
        count++;
    }
    cout << "-------------------------\n";
    cout << "Enter the team name to edit: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout<<"Team Name: "<<teamName<<endl;
            cout << "Enter new team name (Press enter to keep current): ";
            string newName;
            getline(cin, newName);
            if(!newName.empty()){
                for (const auto& team : teams) {
                    if (team.name == newName) {
                        cout << "This team name already exists!\n";
                        system("pause");
                        return;
                    }

                }
            }
            if (!newName.empty()) {
                team.name = newName;
            }
            if (team.coach.name.empty()) {
            cout << team.name << " does not have a manager.\n";
            system("pause");
            return;
            }
            cout<<"Coach Name: "<<team.coach.name<<endl;
            cout << "Enter new coach name (Press enter to keep current): ";
            string newCoachName;
            getline(cin, newCoachName);

            if (!newCoachName.empty()) {
                team.coach.name = newCoachName;
            }
            cout<<"coach's years of experience: "<<team.coach.yearsExperience<<endl;
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
    cout << "===== list of Teams =====\n";
    if (teams.empty()) {
        cout << "No teams available!\n";
        system("pause");
        return;
    }
    int count=1;
    for (const auto& team : teams) {
        cout << count << ". " << team.name << "\n";
        count++;
    }
    cout << "-------------------------\n";
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
    if (teams.empty()) {
        cout << "No teams available!\n";
        system("pause");
        return;
    }
    for (const auto& team : teams) {
        cout << "Team Name: " << team.name << "\n";
    }
    cout << "-------------------------\n";
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
            do {
                cout << "Enter player strength (0-100): ";
                cin >> newPlayer.strength;
                if (newPlayer.strength < 0 || newPlayer.strength > 100) {
                    cout << "Invalid strength. Please enter a value between 0 and 100.\n";
                }
            } while (newPlayer.strength < 0 || newPlayer.strength > 100);
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
    cout << "===== list of Teams =====\n";
    if (teams.empty()) {
        cout << "No teams available!\n";
        system("pause");
        return;
    }
    int count=1;
    for (const auto& team : teams) {
        cout << count << ". " << team.name << "\n";
        count++;
    }
    cout << "-------------------------\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            if (team.players.empty()) {
                cout << team.name << " does not have any players.\n";
                system("pause");
                return;
            }
            cout << "Players of " << team.name << ":\n";
            int count = 1;
            for (const auto& player : team.players) {
                cout << count << ". " << player.name << "\n";
                count++;
            }
            cout << "-------------------------\n";
            cout << "Enter player name to edit: ";
            string playerName;
            getline(cin, playerName);

            for (auto& player : team.players) {
                if (player.name == playerName) {
                    cout<<"Player Name: "<<playerName<<endl;
                    cout << "Enter new player name (Press enter to keep current): ";
                    string newName;
                    getline(cin, newName);
                    if (!newName.empty()) {
                        player.name = newName;
                    }
                    cout<<"Player age: "<<player.age<<endl;
                    cout << "Enter new player age (Press enter to keep current): ";
                    string newAge;
                    getline(cin, newAge);
                    if (!newAge.empty()) {
                        player.age = stoi(newAge);
                    }
                    cout<<"Player strenghth: "<<player.strength<<endl;
                    string newStrength;
                    do {
                        cout << "Enter new player strength (0-100, Press enter to keep current): ";
                        getline(cin, newStrength);
                        if (newStrength.empty()) {
                            break;
                        }
                        player.strength = stoi(newStrength);
                        if (player.strength < 0 || player.strength > 100) {
                            cout << "Invalid strength. Please enter a value between 0 and 100.\n";
                        }
                    } while (player.strength < 0 || player.strength > 100);
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
    cout << "===== list of Teams =====\n";
    if (teams.empty()) {
        cout << "No teams available!\n";
        system("pause");
        return;
    }
    int count=1;
    for (const auto& team : teams) {
        cout << count << ". " << team.name << "\n";
        count++;
    }
    cout << "-------------------------\n";
    cout << "Enter team name: ";
    cin.ignore();
    string teamName;
    getline(cin, teamName);

    for (auto& team : teams) {
        if (team.name == teamName) {
            cout << "Players of " << team.name << ":\n";
            int count = 1;
            for (const auto& player : team.players) {
                cout << count << ". " << player.name << "\n";
                count++;
            }
            cout << "-------------------------\n";
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
void saveTeams() {
    ofstream outFile("teams.txt");
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    for (const auto& team : teams) {
        outFile << team.name << "\n";
        outFile << team.coach.name << "\n";
        outFile << team.coach.yearsExperience << "\n";
        outFile << team.wins << " " << team.losses << " " << team.points << "\n";
        for (const auto& player : team.players) {
            outFile << player.name << "\n";
            outFile << player.age << "\n";
            outFile << player.strength << "\n";
        }
        outFile << "-----\n";
    }
    outFile.close();
}

void loadTeams() {
    ifstream inFile("teams.txt");
    if (!inFile) {
        cout << "Error opening file for reading!\n";
        return;
    }

    teams.clear();
    string line;
    while (getline(inFile, line)) {
        if (line == "-----") continue;

        Team team;
        team.name = line;
        getline(inFile, team.coach.name);
        getline(inFile, team.coach.yearsExperience);
        inFile >> team.wins >> team.losses >> team.points;
        inFile.ignore();

        while (getline(inFile, line) && line != "-----") {
            Player player;
            player.name = line;
            inFile >> player.age >> player.strength;
            inFile.ignore();
            player.team = &team;
            team.players.push_back(player);
        }
        teams.push_back(team);
    }
    inFile.close();
}

void saveMatchResults() {
    ofstream outFile("match_results.txt");
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    for (const auto& result : matchResults) {
        outFile << result.team1 << "\n";
        outFile << result.team2 << "\n";
        outFile << result.winner << "\n";
        outFile << "-----\n";
    }
    outFile.close();
}

void loadMatchResults() {
    ifstream inFile("match_results.txt");
    if (!inFile) {
        cout << "Error opening file for reading!\n";
        return;
    }

    matchResults.clear();
    string line;
    while (getline(inFile, line)) {
        if (line == "-----") continue;

        MatchResult result;
        result.team1 = line;
        getline(inFile, result.team2);
        getline(inFile, result.winner);
        matchResults.push_back(result);
    }
    inFile.close();
}
void match() {
    string team1Name, team2Name;
    cout << "===== list of Teams =====\n";
    if (teams.empty()) {
        cout << "No teams available!\n";
        system("pause");
        return;
    }
    int count = 1;
    for (const auto& team : teams) {
        cout << count << ". " << team.name << "\n";
        count++;
    }
    cout << "-------------------------\n";

    cout << "Enter first team name : ";
    cin.ignore();
    getline(cin, team1Name);
    Team* team1 = nullptr, * team2 = nullptr;
    for (auto& team : teams) {
        if (team.name == team1Name)
            team1 = &team;
    }
    if (!team1) {
        cout << team1Name << " not found.\n";
        system("pause");
        return;
    }
    if (team1->coach.name.empty()) {
        cout << team1->name << " does not have a manager.\n";
        system("pause");
        return;
    }
    if (team1->players.empty()) {
        cout << team1->name << " does not have any players.\n";
        system("pause");
        return;
    }
    cout << "Enter second team name : ";
    getline(cin, team2Name);
    for (auto& team : teams) {
        if (team.name == team2Name)
            team2 = &team;
    }
    if (!team2) {
        cout << team2Name << " not found.\n";
        system("pause");
        return;
    }
    if (team2->coach.name.empty()) {
        cout << team2->name << " does not have a manager.\n";
        system("pause");
        return;
    }

    if (team2->players.empty()) {
        cout << team2->name << " does not have any players.\n";
        system("pause");
        return;
    }

    double avg1 = 0, avg2 = 0;
    for (auto& p : team1->players)
        avg1 += p.strength;
    for (auto& p : team2->players)
        avg2 += p.strength;

    avg1 /= team1->players.size();
    avg2 /= team2->players.size();

    srand(time(0));
    double chance1 = avg1 / (avg1 + avg2);
    double chance2 = 1 - chance1;
    double randomNum = (1 + rand() % 99) / 100.0;
    string winner = (chance1 >= randomNum) ? team1->name : team2->name;
    cout << "Winner: " << winner << "\n";

    matchResults.push_back({ team1->name, team2->name, winner });
    if (winner == team1->name) {
        team1->wins++;
        team1->points += 3;
        team2->losses++;
    }
    else {
        team2->wins++;
        team2->points += 3;
        team1->losses++;
    }
    saveTeams();
    system("pause");
}





void viewAllTeamsandPlayers(){
    system("cls");
    cout << "===== View All Teams and Players =====\n";
    for (const auto& team : teams) {
        cout << "Team Name: " << team.name << "\n";
        cout << "Players:\n";
        int i=1;
        for (const auto& player : team.players) {
            cout << i <<". " << player.name << "\n";
            i++;
        }
        if(i==1){
            cout<<"there are no players on this team!";
        }
        cout << "-------------------------\n";
    }
    system("pause");
}

void viewMatchResults(){
    system("cls");
    cout << "===== View Match Results =====\n";
    for (const auto& result : matchResults) {
        cout << "Match: " << result.team1 << " vs " << result.team2 << "\n";
        cout << "Winner: " << result.winner << "\n";
        cout << "-------------------------\n";
    }
    system("pause");
}

void ViewLeagueStandings(){
    vector<Team> sortedTeams = teams;
    for (size_t i = 0; i < sortedTeams.size() - 1; ++i) {
        for (size_t j = 0; j < sortedTeams.size() - i - 1; ++j) {
            if (sortedTeams[j].points < sortedTeams[j + 1].points) {
                swap(sortedTeams[j], sortedTeams[j + 1]);
            }
        }
    }

    cout << "===== League Standings =====\n";
    cout << setw(8) << left << "Rank" << setw(20) << left << "Team" << setw(10) << left << "Wins" 
         << setw(10) << left << "Losses" << setw(10) << left << "Points" << "\n";
    int rank = 1;
    for (const auto& team : sortedTeams) {
        cout << setw(8) << left << rank << setw(20) << left << team.name << setw(10) << left << team.wins 
        << setw(10) << left << team.losses << setw(10) << left << team.points << "\n";
        rank++;
    }
    cout << "-------------------------\n";
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
            cout << "Players of " << team.name << ":\n";
            int count = 1;
            for (const auto& player : team.players) {
                cout << count << ". " << player.name << "\n";
                count++;
            }
            if (count == 1){
                cout << "there are no players on this team!\n";
            }
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


void mainMenu();
void teamManagement(void){
    system("cls");
    cout<<"===== Team Management =====\n"
    <<"1. Add a New Team\n"
    <<"2. Edit an Existing Team\n"
    <<"3. Delete a Team\n"
    <<"4. View All Teams\n"
    <<"5. Back to Main Menu\n"
    <<"Enter your choice: ";
    do{
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        addTeam();
        saveTeams();
        teamManagement();
        return;
    case 2:
        editTeam();
        saveTeams();
        teamManagement();
        return;
    case 3:
        deleteTeam();
        saveTeams();
        teamManagement();
        return;
    case 4:
        viewTeams();
        teamManagement();
        return;
    case 5:
        mainMenu();
        return;
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);


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

    do{
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        addPlayer();
        saveTeams();
        playerManagement();
        return;
    case 2:
        editPlayer();
        saveTeams();
        playerManagement();
        return;
    case 3:
        deletePlayer();
        saveTeams();
        playerManagement();
        return;
    case 4:
        viewPlayers();
        playerManagement();
        return;
    case 5:
        mainMenu();
        return;
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);
}

void managersManagement(void){
    system("cls");
    cout<<"===== manager management =====\n"
    <<"1. add manager\n"
    <<"2. show manager information\n"
    <<"3. Back to Main Menu\n"
    <<"Enter your choice: ";

    do{
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        addManager();
        saveTeams();
        managersManagement();
        return;
    case 2:
        showManagerInfo();
        managersManagement();
        return;
    case 3:
        mainMenu();
        return; 
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);
}

void matchSimulation(void){
    system("cls");
    cout<<"===== Match Simulation =====\n"
    <<"1. Select Two Teams for a Match\n"
    <<"2. Back to Main Menu\n"
    <<"Enter your choice: ";

    do{
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        match();
        saveTeams();
        saveMatchResults();
        matchSimulation();
        return;
    case 2:
        mainMenu();
        return;
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);
}

void reports(void){
    system("cls");
    cout<<"===== Reports =====\n"
    <<"1. View All Teams and Players\n"
    <<"2. View Match Results\n"
    <<"3. View League Standings\n"
    <<"4. Back to Main Menu\n"
    <<"Enter your choice: ";

    do{
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
        viewAllTeamsandPlayers();
        reports();
        return;
    case 2:
        viewMatchResults();
        reports();
        return;
    case 3:
        ViewLeagueStandings();
        reports();
        return;
    case 4:
        mainMenu();
        return;
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);
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
        return;
    case 2:
        playerManagement();
        return;
    case 3:
        managersManagement();
        return;
    case 4:
        matchSimulation();
        return;
    case 5:
        reports();
        return;
    case 6:
        return;
    default:
        cout<<"wrong number, please enter again: ";
    }}while(true);
}
int main(){
    loadTeams();
    loadMatchResults();
    mainMenu();

    cout << "Game Over!";
}