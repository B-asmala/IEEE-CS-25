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
 




int main(){
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n ,a, c = 0, res = 0;
    
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a;

        if(a < 0 && c < 1){
            res ++;
            continue;
        }
        c += a;
        
    }

    cout << res;



    

    
    
    
    
    

    
}

