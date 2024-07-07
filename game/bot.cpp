//
// Created by htech2 on 2024/07/07.
#include <iostream>
using namespace std;

class Board{
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

    void overRide(int r, int c, char player)
    {
        grid[r][c] = player;
    }
    void overRide2(int r, int c)
    {
        grid[r][c] = ' ';
    }

    void display()
    {
        cout << "       " << endl;
        for (int i = 0; i < 3; i++) {
            cout  << "  ";
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -----" << endl;
        }
        cout << endl;
    }

    bool makeMove(int row, int col, char player){
        if(row >=0 && row < 3 && col >= 0 && col<3 && grid[row][col] == ' '){
            grid[row][col] = player;
            return true;
        }
        return  false;
    }

    bool isFull()
    {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    bool checkWin(char player){
        for(int i=0; i<3; i++) {
            if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
                || (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)) {
                return true;
            }
        }
        if((grid[0][2]==player && grid[1][1]==player && grid[2][0]==player) ||
           (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)){
            return true;
        }

        return false;
    }
};

class Game{
private:
    Board board;
    char human;
    char bot;
    char player;
public:
    Game():human('X'),bot('O'),player('X'){}
    void changePlayers()
    {
        player = (player == human)? bot:human;
    }
    void botPlay()
    {
        // CHECK IF BOT CAN MAKE WINNING MOVE
        for(int i=0; i<3; i++)
        {
            for(int j=0; j <3; j++)
            {
                if(board.makeMove(i,j,bot)){
                    if(board.checkWin(bot)){
                        return;
                    }
                    board.overRide2(i,j);
                }
            }
        }
        // CHECK IF BOT CAN PREVENT HUMAN FROM WINNING
        for(int i=0; i<3; i++)
        {
            for(int j=0; j <3; j++)
            {
               if(board.makeMove(i,j,human)){
                   if(board.checkWin(human)){
                       board.overRide(i,j,bot);
                       return;
                   }
                   board.overRide2(i,j);
               }
            }
        }

        //play any empty position
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board.makeMove(i,j,bot)){
                    return;
                }
            }
        }
    }

    void play(){
        board.display();
        while (true) {
            //board.display();
            if (player == human) {
                int row, col;
                cout << "Player " << player << ", enter your move (row and col): "<<endl;
                cin >> row >> col;
                if (board.makeMove(row, col, player)) {
                    if (board.checkWin(player)) {
                        cout << player << " won the game!" << endl;
                        board.display();
                        break;
                    } else if (board.isFull()) {
                        cout << "It's a draw!" << endl;
                        board.display();
                        break;
                    }
                    changePlayers();
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            }else{
                botPlay();
                if(board.checkWin(bot)){
                    cout<<"The Bot won"<<endl;
                    board.display();
                    break;
                }else if(board.isFull()){
                    cout<<"Draw"<<endl;
                    board.display();
                    break;
                }
                board.display();
                changePlayers();
            }
        }
        }
};

int main()
{
    Game game;
    game.play();
    return 0;
}
