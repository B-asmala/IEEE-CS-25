#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE
int n, m;
vector<string> mp;
vector<vector<char>> p; //direction of parent
vector<vector<int>> monmp; //monsters time map
vector<vector<int>> memp; //my time map
queue<pair<int, int>> mq; //used for monster bfs


bool validMon(int i, int j){
    return i < n && i >= 0 && j < m && j >= 0 && mp[i][j] != '#' && monmp[i][j] == -1;
}

bool valid(int i, int j, int t){
    return i < n && i >= 0 && j < m && j >= 0 && (t + 1 < monmp[i][j] || monmp[i][j] == -1) && p[i][j] == 'O' && mp[i][j] == '.';
}

void monbfs(){ //check when the nearest monster will arrive for each cell by bfsing every monster
    int i, j;
    while(!mq.empty()){
        i = mq.front().first;
        j = mq.front().second;

        mq.pop();

        if(validMon(i + 1, j)){
            mq.push({i + 1, j});
            monmp[i + 1][j] = monmp[i][j] + 1;
        }
        if(validMon(i - 1, j)){
            mq.push({i - 1, j});
            monmp[i - 1][j] = monmp[i][j] + 1;
        }
        if(validMon(i, j + 1)){
            mq.push({i, j + 1});
            monmp[i][j + 1] = monmp[i][j] + 1;
        }
        if(validMon(i, j - 1)){
            mq.push({i, j - 1});
            monmp[i][j - 1] = monmp[i][j] + 1;
        }

    }
}

pair<int, int> bfs(int sy, int sx){
    int i, j;
    queue<pair<int, int>> q;

    q.push({sy, sx});
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if(i == 0 || i == n - 1 || j == 0 || j == m -1){ //reached an exit
            return {i, j};
        }

            //for each direction check if valid, update time and parent direction maps
            if(valid(i - 1, j, memp[i][j])){
                q.push({i-1, j});
                p[i - 1][j] = 'U';
                memp[i - 1][j] = memp[i][j] + 1;
            }

            if(valid(i + 1, j, memp[i][j])){
                q.push({i + 1, j});
                p[i + 1][j] = 'D';
                memp[i + 1][j] = memp[i][j] + 1;
            }

            if(valid(i, j - 1, memp[i][j])){
                q.push({i, j - 1});
                p[i][j - 1] = 'L';
                memp[i][j - 1] = memp[i][j] + 1;
            }

            if(valid(i, j + 1, memp[i][j])){
                q.push({i, j + 1});
                p[i][j + 1] = 'R';
                memp[i][j + 1] = memp[i][j] + 1;
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
    monmp.resize(n);
    memp.resize(n);
    for(int i = 0; i < n; i ++){
        monmp[i].resize(m, -1);
        memp[i].resize(m, -1);
        cin >> mp[i];
        for(int j = 0; j < m; j ++){
            if(mp[i][j] == 'A'){
                ay = i;
                ax = j;
                memp[i][j] = 0;
            }

            if(mp[i][j] == 'M'){
                mq.push({i, j}); 
                monmp[i][j] = 0;
        
            }


        }
        p[i].resize(m, 'O'); //initially
    }

    monbfs(); 

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
