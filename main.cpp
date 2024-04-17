#include <bits/stdc++.h>
using namespace std; //shhhhh

int board[6][7];
int turn = 0;

void place_tile(int x){
    int tile, h=5;--x;
    (turn%2 == 0) ? tile = 1 : tile = 2;

    while(board[h][x] != 0)--h;
    board[h][x] = tile;
    ++turn;
}

bool check_win(){
    //check all vertical positions
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<7; ++j){
            if(board[i][j] == 0)continue;
            if(board[i][j] == board[i+1][j] &&
                 board[i+1][j] == board[i+2][j] &&
                board[i+2][j] == board[i+3][j]){
                return true;
            }
        }
    }
    //check all horizontal positions
    for(int i = 0; i<6; ++i){
        for(int j = 0; j<4; ++j){
            if(board[i][j] == 0)continue;
            if(board[i][j] == board[i][j+1] &&
                 board[i][j+1] == board[i][j+2] &&
                board[i][j+2] == board[i][j+3]){
                return true;
            }
        }
    }
    //check all forward diagonal positions
    for(int i = 0; i<3; ++i){
        for(int j = 3; j<7; ++j){
            if(board[i][j] == 0)continue;
            if(board[i][j] == board[i+1][j+1] &&
                 board[i+1][j+1] == board[i+2][j+2] &&
                board[i+2][j+2] == board[i+3][j+3]){
                return true;
            }
        }
    }
    //check all backward diagonal positions
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<4; ++j){
            if(board[i][j] == 0)continue;
            if(board[i][j] == board[i+1][j-1] &&
                 board[i+1][j-1] == board[i+2][j-2] &&
                board[i+2][j-2] == board[i+3][j-3]){
                return true;
            }
        }
    }
    
    return false;
}

void print_board(){
    for(int i = 0; i<6; ++i){
        for(int j = 0; j<7; ++j){
            cout << board[i][j] << ' ';
        }cout << '\n';
    }
    if(check_win()){
        cout << "Player " << (--turn)%2 + 1 << " Wins!\n";
    }
}

int main(){
    int x;

    place_tile(2);
    place_tile(3);
    place_tile(3);
    place_tile(4);
    place_tile(4);
    place_tile(5);

    print_board();
    
    return 0;
}
