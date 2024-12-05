#include <bits/stdc++.h>
using namespace std;
 


long long fast_pow(long long a, long long p, long long mod){
    long long res = 1;
    while (p > 0){
        if (p % 2 == 0){
            a = (a * a) % mod;
            p /= 2;
        }else{
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
 
 
bool comp (long long a, long long b){
    return a > b;
}
 
 

 
 
 
int main(){
    // freopen("lepus.in", "r", stdin);
    // freopen("lepus.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    
 
    long long  n, q, a, high, low, mid, res;
    cin >> n;
    vector<long long> v(n + 1);
    
    for(int i = 1; i <= n; i ++){
        cin >> v[i];

    }

    sort(v.begin(), v.end());

    cin >> q;

    while (q --){
        cin >> a;
        res = 0;
        low = 0;
        high = n;

        while(low <= high){
            mid = (low + high) / 2;

            if(v[mid] <= a){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        cout << res << '\n';
    }
    

 
    
}

