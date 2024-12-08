#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    long long t, n, i, j, res = 1;
    vector<long long> v;

    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());


    i = j = 0;

    while(v[j] - v[i] <= 5 && j < n)j ++;//find largest element that works
    j --;

    while(i <= j && j < n){
        

        if(v[j] - v[i] <= 5){
            j ++;
            res = max(res, j - i);
        }else{
            i ++;
        }
        

    }
    cout << res << endl;

}
