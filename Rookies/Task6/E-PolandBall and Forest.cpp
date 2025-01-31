#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

vector<vector<int>> t;
vector<int> vis;

void dfs(int i){   
    if(vis[i]){
        return;
    }

    vis[i] = 1;
    for(auto e : t[i]){
        dfs(e);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, x, res = 0;
    cin >> n;
    t.resize(n + 1);
    vis.resize(n + 1);

    for(int i = 1; i <= n; i ++){
        cin >> x;
        t[x].push_back(i);
        t[i].push_back(x);
    }

    for(int i = 1; i <= n; i ++){
        if(!vis[i]){
            dfs(i);
            res ++;
        }
    }


    cout << res;
 

}
