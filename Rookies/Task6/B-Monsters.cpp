#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

int n, m;
vector<string> mp;
vector<vector<int>> monmp; //monsters time map
vector<vector<int>> memp; //my time map
pair<int, int> d = {-1, -1}; //exit 
string res = "";
int f = 0;

bool validMon(int i, int j, int c){
    return i < n && i >= 0 && j < m && j >= 0 && mp[i][j] != '#' && (monmp[i][j] == -1 || monmp[i][j] >= c);
}
 
bool valid(int i, int j, int t){
    return i < n && i >= 0 && j < m && j >= 0 && (t < monmp[i][j] || monmp[i][j] == -1) && (mp[i][j] == '.' || mp[i][j] == 'A');
}
 
void mondfs(int i, int j, int c){ //check when the nearest monster will arrive for each cell by dfsing every monster
    if(!validMon(i, j, c)){
        return;
    }
 
    monmp[i][j] = c;
    mondfs(i + 1, j, c + 1);
    mondfs(i - 1, j, c + 1);
    mondfs(i, j + 1, c + 1);
    mondfs(i, j - 1, c + 1);
}
 
void dfs(int i, int j, int t, string r){   
    
    if(!valid(i, j, t)){
        return;
    }

    if(i == 0 || i == n - 1 || j == 0 || j == m - 1){ //reached an exit
        f = 1;
        res = r;
        return;
    }
 
    

    memp[i][j] = t;
    mp[i][j] = '#';
    dfs(i + 1, j, t + 1, r + 'D');
    dfs(i - 1, j, t + 1, r + 'U');
    dfs(i, j + 1, t + 1, r + 'R');
    dfs(i, j - 1, t + 1, r + 'L');
    

    mp[i][j] = '.';
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int ax, ay;
    cin >> n >> m;
    mp.resize(n); 
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
                monmp[i][j] = 0;
            }
 
 
        }
    }
 
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(monmp[i][j] == 0){ //for every monster, do dfs
                mondfs(i, j, 0);
            }
        }
    }
 
    dfs(ay, ax, 0, "");
    if(!f){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
        cout << res.size() << endl << res << endl;
    }
    
 
    
 
 
}
