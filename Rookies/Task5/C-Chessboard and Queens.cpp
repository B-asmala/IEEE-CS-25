#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

long long res = 0;

void chess(int i, vector<vector<int>> v){
    
    if(i == 8){ //all 8 queens can be placed, that's 1 possible way!
        res ++;
        return;
    }
     

    for(int j = 0; j < 8; j ++){
        if(v[i][j]){ // a queen can be placed here
            vector<vector<int>> nb = v; // create new board with new queen 
            for(int k = 0; k < 8; k ++){
                nb[k][j] = 0;
                nb[i][k] = 0;

                if(i + k < 8 && j + k < 8)nb[i + k][j + k] = 0;
                if(i + k < 8 && j - k >= 0)nb[i + k][j - k] = 0;
            }

            chess(i + 1, nb); //do the same for next rows

        }
        



    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    char c;
    vector<vector<int>> board(8);

    for(int i = 0; i < 8; i ++){
        board[i].resize(8);
        for(int j = 0; j < 8; j ++){
            cin >> c;
            board[i][j] = (c == '.');
        }
    }

    chess(0, board);

    cout << res << endl;
    
}
 
