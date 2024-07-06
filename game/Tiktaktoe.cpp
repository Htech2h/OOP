//
// Created by htech2 on 2024/07/04.
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

    void Display()
    {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
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
    char currPlayer;
public:
    Game():currPlayer('X'){}
    void switchPlayer()
    {
        currPlayer = (currPlayer == 'X') ? 'O':'X';
    }
    void play()
    {
        int row,col;
        while(true){
            board.Display();
            cout<<"player "<<currPlayer<<" Enter Move(row and col)"<<endl;
            cin>>row>>col;
            if(board.makeMove(row,col,currPlayer)){
                if(board.checkWin(currPlayer)){
                    cout<<"player "<<currPlayer<<" Won!!!!!!!"<<endl;
                    board.Display();
                    break;
                }else if(board.isFull()){
                    cout<<"Its draw"<<endl;
                    board.Display();
                    break;
                }
                switchPlayer();

            }else{
                cout<<"invalid move"<<endl;
            }
        }

    }

};


int main()
{
    Game game;
    game.play();
    return  0;
}
