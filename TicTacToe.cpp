#include <iostream>

using namespace std;

void chooseCharacter(char &player, char &computer) {
    while (true) {
        cout << "1 - X \n2 - O\n";
        cout << "Choose character: " << endl;
        cin >> player;
        if (player == 'x' || player == 'X') {
            player = 'X';
            computer = 'O';
            break;
        } else if (player == 'o' || player == 'O') {
            player = 'O';
            computer = 'X';
            break;
        }
    }
}
void drawTable(char spaces[]) {
    cout << "     |     |     \n";
    cout << "  " << spaces[0] << "  |  " << spaces[1] <<  "  |  " << spaces[2] << endl;
    cout << "------------------\n";
    cout << "  " << spaces[3] << "  |  " << spaces[4] <<  "  |  " << spaces[5] << endl;
    cout << "------------------\n";
    cout << "  " << spaces[6] << "  |  " << spaces[7] <<  "  |  " << spaces[8] << endl;
    cout << "     |     |     \n";
}
void choicePlayer(char spaces[], char player) {
    while (true) {
        int choice;
        cout << "Choose position of your character (1-9): ";
        cin >> choice;
        if (spaces[choice - 1] == ' ') {
            spaces[choice - 1] = player;
            break;
        } else if (spaces[choice - 1] == 'X' || spaces[choice - 1] == 'O') {
            cout << "That position currently occupied.\n";
        } else {
            cout << "Incorrect choice!!!\n";
        }
    }
}
void choiceComputer(char spaces[], char computer) {
    srand(time(0));
    while (true) {
        int freeSpaces = 0;
        for (int i = 0; i < sizeof(spaces)/sizeof(spaces[0]); i++) {
            if (spaces[i] == ' ') freeSpaces += 1;
        }
        if (!freeSpaces) break;
        int choice = rand() % 8;
        if (spaces[choice] == ' ') {
            spaces[choice] = computer;
            break;
        }
    }
}
void checkWinner(char spaces[], char player, char computer, bool &running) {
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
       running = false;
       spaces[0] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
       running = false;
       spaces[3] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
       running = false;
       spaces[6] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
       running = false;
       spaces[0] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
       running = false;
       spaces[0] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
       running = false;
       spaces[1] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
       running = false;
       spaces[2] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
       running = false;
       spaces[0] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
       running = false;
       spaces[2] == player ? cout << "YOU WIN!!!" : cout << "YOU LOST!!!";
    }
    else {
        int freeSpaces = 0;
        for (int i = 0; i < sizeof(spaces)/sizeof(spaces[0]); i++) {
            if (spaces[i] == ' ') {
                freeSpaces += 1;
            }
        }
        if (freeSpaces == 0) {
            running = false;
            cout << "Draw!!!" << endl;
        }
    }
}

int main () {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
    bool running = true;
    char player;
    char computer;
    chooseCharacter(player, computer);
    drawTable(spaces);
    while (running) {
        choicePlayer(spaces, player);
        choiceComputer(spaces, computer);
        drawTable(spaces);
        checkWinner(spaces, player, computer, running);
    }

    return 0;
}