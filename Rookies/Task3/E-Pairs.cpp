#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    long long t, n, i, j, res = 0, k, a, b;
    vector<long long> v;

    cin >> n >> k;

    v.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());


    i = j = 0;


    while(i <= j && j < n){
        

        if(v[j] - v[i] == k){
            a = b = 1;
            while(j < n - 1 && v[j] == v[j + 1]){//count equal elements
                j ++; 
                a ++;
            }
            while(i < n - 1 && v[i] == v[i + 1]){//count equal elements
                i ++; 
                b ++;
            }

            
            i ++;
            j ++;
            if(!k){//same element
                res += a * (a - 1) / 2;
            }else{
                res += a * b;
            }


            
        }else if(v[j] - v[i] > k){
            i ++;
        }else{
            j ++;
        }
        

    }
    cout << res << endl;

}
