#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE
int n, m;
vector<int> v; // visited
vector<vector<int>> adj; //adjacency list

void bfs(int s){
    int n;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        n = q.front();
        q.pop();
        for(int i = 0; i < adj[n].size(); i ++){
            if(!v[adj[n][i]]){
                v[adj[n][i]] = 1;
                q.push(adj[n][i]);

            }
        }

    }



}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    vector<int> res;
    cin >> n >> m;
    adj.resize(n + 1);
    v.resize(n + 1);

    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i ++){
        if(v[i])continue;

        v[i] = 1;
        bfs(i);
        res.push_back(i);
    }

    cout << res.size() - 1 << endl;

    for(int i = 0; i < res.size() - 1; i ++){
        cout << res[i] << ' ' << res[i + 1] << endl;
    }

}
