#include <iostream>

using namespace std;

int player = 0;
int enemy = 0;

enum SELECTION{
    ROCK = 1,
    PAPER = 2,
    SCISSOR = 3,
};

void score(int p, int e) {
    player += p;
    enemy += e;
    cout << "Score: " << player << " : " << enemy << " (enemy)\n\n";
}

void menu() {
    int selection;
    bool exitMenu = false;

    while (!exitMenu) {
        cout << "\n--- Please Select a Number ---\n";
        cout << "\t1. Rock\n\t2. Paper\n\t3. Scissor\n\t4. EXIT\n";
        cout << "Enter number: ";

        while (!(cin >> selection)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }

        if (selection == 4) return;

        int enemySelection = rand() % 3 + 1;
        if (enemySelection == SELECTION::ROCK) cout << "\nEnemy throws ROCK!\n";
        else if (enemySelection == SELECTION::PAPER) cout << "\nEnemy throws PAPER!\n";
        else if (enemySelection == SELECTION::SCISSOR) cout << "\nEnemy throws SCISSOR!\n";

        if (selection == enemySelection) {
            cout << "Result: DRAW!\n";
            score(0, 0);
        }
        else if (selection == SELECTION::PAPER && enemySelection == SELECTION::SCISSOR) {
            cout << "Result: YOU LOSE!\n";
            score(0, 1);
        }
        else if (selection == SELECTION::PAPER && enemySelection == SELECTION::ROCK) {
            cout << "Result: YOU WIN!\n";
            score(1, 0);
        }
        else if (selection == SELECTION::SCISSOR && enemySelection == SELECTION::PAPER) {
            cout << "Result: YOU WIN!\n";
            score(1, 0);
        }
        else if (selection == SELECTION::SCISSOR && enemySelection == SELECTION::ROCK) {
            cout << "Result: YOU LOSE!\n";
            score(0, 1);
        }
        else if (selection == SELECTION::ROCK && enemySelection == SELECTION::SCISSOR) {
            cout << "Result: YOU WIN!\n";
            score(1, 0);
        }
        else if (selection == SELECTION::ROCK && enemySelection == SELECTION::PAPER) {
            cout << "Result: YOU LOSE!\n";
            score(0, 1);
        }

    }
}

int main()
{
    cout << "Welcome to C++ Game!\n";
    menu();
    system("pause");
}

