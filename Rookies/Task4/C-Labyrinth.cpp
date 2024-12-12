#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE
int n, m;
vector<string> mp;
vector<vector<char>> p; //direction of parent

pair<int, int> bfs(int sy, int sx){
    int i, j;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if(mp[i][j] == 'B'){
            return {i, j};
        }else if(mp[i][j] == '.' || mp[i][j] == 'A'){

            //for each direction check if inside map and not visited
            if(i > 0 && p[i - 1][j] == 'O'){
                q.push({i-1, j});
                p[i - 1][j] = 'U';
            }

            if(i < n - 1 && p[i + 1][j] == 'O'){
                q.push({i + 1, j});
                p[i + 1][j] = 'D';
            }

            if(j > 0 && p[i][j - 1] == 'O'){
                q.push({i, j - 1});
                p[i][j - 1] = 'L';
            }

            if(j < m - 1 && p[i][j + 1] == 'O'){
                q.push({i, j + 1});
                p[i][j + 1] = 'R';
            }
        }

        

        

        

        



        


    }

    return {-1, -1}; //not found

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ax, ay, i, j;
    string res = "";
    pair<int, int> d;
    cin >> n >> m;
    mp.resize(n);
    p.resize(n); 
    for(int i = 0; i < n; i ++){
        cin >> mp[i];
        for(int j = 0; j < m; j ++){
            if(mp[i][j] == 'A'){
                ay = i;
                ax = j;
        
            }

        }
        p[i].resize(m, 'O'); //initially
    }


    d = bfs(ay, ax);

    if(d.first == -1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        i = d.first;
        j = d.second;
        while(mp[i][j] != 'A'){

            res.push_back(p[i][j]);
            //move to parent
            if(p[i][j] == 'U'){
                i ++;
                continue;
            }
            if(p[i][j] == 'D'){
                i --;
                continue;
            }
            if(p[i][j] == 'L'){
                j ++;
                continue;
            }
            if(p[i][j] == 'R'){
                j --;
                continue;
            }
        }

        reverse(res.begin(), res.end());

        cout << res.size() << endl << res << endl;

    }


}
