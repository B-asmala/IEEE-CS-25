#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    long long t, n, i, j, res = 0;
    vector<long long> v;

    cin >> n >> t;

    v.resize(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> v[i];
        v[i] += v[i - 1];
    }

    i = 0;
    j = n;

    while(v[j] - v[i] > t)j --; //reach first acceptable sum starting from index 0 ending at j

    while(j <= n){
        if(v[j] - v[i] <= t){
            res = max(res, j - i);
            j ++;


        }else{
            i ++;
                
        }
        if(i == j){ // if one element fails the rest doesn't have to
            j ++;
        }

    }
    cout << res << endl;

}
