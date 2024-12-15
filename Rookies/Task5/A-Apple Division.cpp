#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE
int n;
vector<long long>  w;

long long apples(int i, long long x, long long y){
    if(i == n){
        return abs(y - x);
    }

    return min(apples(i + 1, x + w[i], y), apples(i + 1, x, y + w[i]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n; 
    w.resize(n);
 
    for(int i = 0; i < n; i ++){
        cin >> w[i];
    }

    cout << apples(0, 0, 0);
}
