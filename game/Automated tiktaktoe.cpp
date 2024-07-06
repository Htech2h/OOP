//
// Created by htech2 on 2024/07/06.
#include <iostream>
using namespace std;

class Board {
private:
    char grid[3][3];
public:
    Board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
    }
    void display() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << "  " << grid[i][j] << "  ";
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----|-----|-----\n";
        }
    }

    bool isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    bool makeMove(int row, int col, char player) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
            grid[row][col] = player;
            return true;
        }
        return false;
    }

    bool checkWin(char player) {
        for (int i = 0; i < 3; i++) {
            if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) ||
                (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)) {
                return true;
            }
        }
        if ((grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) ||
            (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)) {
            return true;
        }
        return false;
    }
};

class Game {
private:
    char currPlayer;
    char comp;
    char player;
    Board bd;
public:
    Game() : comp('X'), player('O'), currPlayer('O') {}

    void choosePlayer() {
        char p;
        cout << "Choose Your Player (X or O): ";
        cin >> p;
        if (player != p) {
            comp = 'O';
            player = 'X';
            currPlayer = 'X';
        }
    }

    void changePlayer() {
        currPlayer = (currPlayer == comp) ? player : comp;
    }

    void makeCompMove() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (bd.makeMove(i, j, comp)) {
                    return;
                }
            }
        }
    }

    void play() {
        choosePlayer();
        while (true) {
            bd.display();
            if (currPlayer == player) {
                int row, col;
                cout << "Player " << player << ", enter your move (row and col): "<<endl;
                cin >> row >> col;
                if (bd.makeMove(row, col, player)) {
                    if (bd.checkWin(player)) {
                        cout << player << " won the game!" << endl;
                        bd.display();
                        break;
                    } else if (bd.isFull()) {
                        cout << "It's a draw!" << endl;
                        bd.display();
                        break;
                    }
                    changePlayer();
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            } else {
                // Computer's turn
                makeCompMove();
                if (bd.checkWin(comp)) {
                    cout << "The computer won!" << endl;
                    bd.display();
                    break;
                } else if (bd.isFull()) {
                    cout << "It's a draw!" << endl;
                    bd.display();
                    break;
                }
                changePlayer();
            }
        }
    }
};

int main() {
    Game g;
    g.play();
    return 0;
}

