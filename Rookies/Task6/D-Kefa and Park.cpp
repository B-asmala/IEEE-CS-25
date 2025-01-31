#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

vector<int> c;
vector<vector<int>> t;
vector<int> vis;
int n, m, res = 0;

void dfs(int i, int a){   
    int v = 1;
    if(a > m){
        return;
    }

    if(!t[i].size()){
        res ++;
        return;
    }

    vis[i] = 1;

    for(auto x : t[i]){
        if(!vis[x]){
            v = 0;
            if(!c[x]){
                dfs(x, 0);
            }else{
                dfs(x, a + 1);
            }
        }
        
    }

    if(v){
        res ++;
    }
    
    
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int  x, y;
    cin >> n >> m;
    c.resize(n + 1);
    t.resize(n + 1);
    vis.resize(n + 1);

    for(int i = 1; i <= n; i ++){
        cin >> c[i];
    }

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }

    dfs(1, c[1]);

    cout << res;
 
    
 
 
}
