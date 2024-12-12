#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE
int n, m;
vector<vector<int>> d;
vector<int> mov = {2, -2, 1, -1};

int bfs(int sy, int sx, int ey, int ex){
    int i, j;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if(i == ey && j == ex){
            return d[i][j];
        }

        for(int l = 0; l < 4; l ++){
            for(int k = 0; k < 4; k ++){
                if(abs(mov[l]) != abs(mov[k])){ //ensure an L shape
                    if(i + mov[l] >= 0 && i + mov[l] < 8 && j + mov[k] >= 0 && j + mov[k] < 8 && d[i + mov[l]][j + mov[k]] == 0){ //ensure it is inside the board  & not visited
                        q.push({i + mov[l], j + mov[k]});
                        d[i + mov[l]][j + mov[k]] = d[i][j] + 1;
                        //cout << "prev: " << i << ' ' << j << endl;
                        //cout << i + mov[l] << ' ' << j + mov[k] << endl;
                    }
                }
            }
        }

        



        


    }

    return -1; //impossible
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin >> t;
    vector<int> v(8);
    string ss, se;
    while(t --){
        cin >> ss >> se;
        d.resize(8, v);

        cout << bfs(ss[0] - 'a', ss[1] - '1', se[0] - 'a', se[1] - '1') << '\n';

        d.clear();
        

    }



}
