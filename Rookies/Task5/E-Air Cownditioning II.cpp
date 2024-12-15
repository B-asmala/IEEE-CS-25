#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

int n, m;
long long res = LONG_LONG_MAX;
vector<long long> stalls(101);
vector<vector<long long>> conds; //available conditioners
void air(int i, vector<long long> v, long long cost){
    
    if(i == m){
        for(int j = 1; j <= 100; j ++){
            if(stalls[j] > v[j])return;
        }

        res = min(res, cost);
        return;
    }

    vector<long long> altered = v;
    for(int j = conds[i][0]; j <= conds[i][1]; j++){
        altered[j] += conds[i][2];
    }

    //either take it or not
    air(i + 1, altered, cost + conds[i][3]);
    air(i + 1, v, cost);
     
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int s, t, c;
    vector<long long> v(101, 0);
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        cin >> s >> t >> c;

        for(int j = s; j <= t; j ++){
            stalls[j] += c;
        }
    }

    conds.resize(m);

    for(int i = 0; i < m; i ++){
        conds[i].resize(4);
        for(int j = 0; j < 4; j ++){
            cin >> conds[i][j];
        } 
    }

    air(0, v, 0);
 
    cout << res << endl;
    
}
 
