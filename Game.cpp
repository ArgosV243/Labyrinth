#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Functions
void startGame();
void exploreRoom(int room);
void gameOver();
void saveGame(int room);
int loadGame();
void resetGame();

int main() {
//Game Start
    cout << "Labyrinth" << endl;
    cout << "Veins of the Earth" << endl;

    int choice;
    cout << "\n1. New Game\n2. Load Game";
    cin >> choice;

    if (choice == 1) {
        startGame();
    } else if (choice == 2) {
        int savedRoom = loadGame();
        if (savedRoom != -1) {
            cout << "\nLoaded saved game...\n";
            exploreRoom(savedRoom);
        } else {
            cout << "\nNo saved game found. Starting new game...\n";
            startGame();
        }
     } else if (choice == 3) {
        resetGame();
        startGame();
     } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;

}

    
void startGame() {
    string choice;

    cout << "\nYou find yourself in a room of stone brick walls with no windows, lit by torches.\n";
    cout << "1. Go Forward\n";
    cout << "2. Go Right\n";
    cout << "3. Go Left\n";
    cout << "The choice is yours: ";
    cin >> choice;

    if (choice == "1") {
        cout << "\nYou step forward into a damp stone brick hallway at the end you see a wooden door.\n";
        saveGame(1);
        exploreRoom(1);
    } else if (choice == "2") {
        cout << "\nYou stub your toe on a stone and die immediately of syphilis! :(\n";
        gameOver();
    } else {
        cout << "\nYou have entered a small room with a chest in the middle.\n";
        saveGame(2);
        exploreRoom(2);
    }
}


void exploreRoom(int room) {
    string choice;

    cout << "\nYou are in the hallway.\n";
    cout << "1. Enter the door.\n";
    cout << "2. Go back.\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == "1") {
        cout << "\nYou enter the door. To your left is a chest, and to the right a skeleton.\n";
        saveGame(room); // still save progress
    } else if (choice == "2") {
        cout << "\nYou are back where you started.\n";
        startGame();
    }
}

void gameOver() {
    string choice;
    cout << "\nWould you like to try again? (y/n): ";
    cin >> choice;

    if (choice == "y" || choice == "Y") {
        startGame();
    } else {
        cout << "\nSee you again... Goodbye.\n";
    }
}

void saveGame(int room) {
    ofstream saveFile("save.txt");
    if (saveFile.is_open()) {
        saveFile << room;
        saveFile.close();
        cout << "\nGame saved!\n";
    }
}

int loadGame() {
    ifstream saveFile("save.txt");
    int room;
    if (saveFile.is_open()) {
        saveFile >> room;
        saveFile.close();
        return room;
    }
    return -1; // no save found
}

void resetGame() {
    ofstream saveFile("save.txt", ios::trunc); // clear file
    saveFile.close();
    cout << "\nSave reset!\n";
}