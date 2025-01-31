#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

vector<vector<pair<int, int>>> t;
vector<int> vis;
int res = 0;

void dfs(int i, int a){   
    int v = 1; 

    vis[i] = 1; //mark as visited

    for(auto x : t[i]){
        if(!vis[x.first]){
            v = 0;
            dfs(x.first, a + x.second);
            
        }
        
    }

    if(v){ //nothing more to visit, leaf node
        res = max(res, a);
        return;
    }
    
    
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, x, y, c;
    cin >> n;
    t.resize(n);
    vis.resize(n);

    
    for(int i = 1; i < n; i ++){
        cin >> x >> y >> c;
        t[x].push_back({y, c});
        t[y].push_back({x, c});
    }

    dfs(0, 0);

    cout << res;
 
    
 
 
}
