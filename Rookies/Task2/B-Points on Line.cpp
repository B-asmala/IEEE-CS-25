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
    
    
    
 
    long long  n, x, high, low, mid, res = 0, ans = 0;
    cin >> n >> x;
    vector<long long> v(n);
    
    for(int i = 0; i < n; i ++){
        cin >> v[i];

    }

    for(int i = 0; i < n; i ++){
        ans = 0;
        low = 0;
        high = n - 1;

        while(low <= high){
            mid = (low + high) / 2;

            if(v[mid] <= v[i] + x){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        
        if(ans - i < 2) continue;
        res += (ans - i) * (ans - i - 1) / 2;
    }

    cout << res << '\n';


     
        
    
    

 
    
}

