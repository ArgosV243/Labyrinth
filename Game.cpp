#include <iostream>
#include <string>

using namespace std;

//Functions
void startGame();
void exploreRoom();
void gameOver();

int main() {
//Game Start
    cout << "Labyrinth" << endl;
    cout << "Veins of the Earth" << endl;
    
    startGame();

    return 0;
}

void startGame () {
    string choice;

    cout <<"\nYou Find yourself in a room of stone brick walls with no windows and is only lit by tourches.\n";
    cout <<"1. Go Forward\n";
    cout <<"2. Go Right\n";
    cout <<"3. Go Left\n";
    cout <<"The Choice is yours.";
    cin >> choice;

    if (choice == "1") {
        cout << "\nYou Step forward into a damp stone brick hallway at the end you see a wooden door.\n";
        exploreRoom();
    } else if (choice == "2") {
        cout << "\nYou Stub your toe on a bit of the stone floor that was jutting out and you die immmediately of syphilis! :(\n";
        gameOver();
    } else {
        cout << "\nYou have entered a small room with a chest in the middle.\n";
        exploreRoom();
    }
}

void exploreRoom() {
    string choice;

    cout << "\nYou are in the hallway.\n";
    cout << "\n1. You enter the door.\n";
    cout << "\n2. Go back.\n";
    cin >> choice;

    if (choice == "1") {
        cout << "\nYou have enterd the door you see a chest to your left and to the Right you see a skeleton\n";
    } else if (choice == "2") {
        cout << "\nYou are back where you have started.\n";
        startGame();
    }
}

void gameOver() {
    string choice;
    cout << "\nWould you Like to try again? (y/n): ";
    cin >> choice;

    if (choice == "y" || choice == "Y") {
        startGame();
    } else {
        cout << "\nSee you again... Goodbye.\n";
    }
}
