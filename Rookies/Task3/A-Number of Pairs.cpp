#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    long long t, l, r, n, i, j, c;
    vector<long long> v;

    cin >> t;

    while(t --){
        cin >> n >> l >> r;
        c = 0; //count pairs > r or < l

        v.resize(n);
        for(int i = 0; i < n; i ++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        i = 0;
        j = n - 1;

        while(i < j){
            if(v[i] + v[j] > r){
                c += j - i; // all pairs in between also > r
                j --;

            }else{
                i ++;
                
            }
        }

        i = 0;
        j = n - 1;

        while(i < j){
            if(v[i] + v[j] < l){
                c += j - i; // all pairs in between also < l
                i ++;
                
            }else{
                j --;
                
            }
        }

        cout << (n * n - n ) / 2 - c << '\n'; // all possible pairs - pairs that are not >= l && <= r

    }
}
