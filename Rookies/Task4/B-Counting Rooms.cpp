#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE
int n, m;
vector<string> mp;

void bfs(int y, int x){
    int i, j;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(!q.empty()){

        
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if(mp[i][j] == '.'){
            mp[i][j] = '#';
            if(i > 0)q.push({i - 1, j});
            if(i < n - 1)q.push({i + 1, j});
            if(j > 0)q.push({i, j - 1});
            if(j < m - 1)q.push({i, j + 1});
        }

        


    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c = 0;
    cin >> n >> m;
    mp.resize(n);

    for(int i = 0; i < n; i ++){
        cin >> mp[i];
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(mp[i][j] == '.'){
                c ++;
                bfs(i, j);
            }
        }
    }

    cout << c << endl;

}
