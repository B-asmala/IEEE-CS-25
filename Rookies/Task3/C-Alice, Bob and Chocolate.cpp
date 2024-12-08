#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    long long t, n, i, j, a = 0, b = 0, x;
    vector<long long> v;

    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }

    i = 0;
    j = n - 1;

    while(i <= j){
        if(i == j){
            a ++; //bob leaves it to alice
            break;
        }
        x = min(v[i], v[j]);
        v[i] -= x;
        v[j] -= x;

        if(v[i] == 0){
            a ++;
            if(j == i + 1 && v[j] > 0){
                b ++; //already started the last one
                break;
            }

            i ++;
        
        }

        if(v[j] == 0){
            b ++;
            if(j == i + 1 && v[i] > 0){
                a ++; //already started the last one
                break;
            }
            j --;
        }

    }
    cout << a << ' ' << b << endl;

}
