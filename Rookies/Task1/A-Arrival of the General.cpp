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
    
    int n, a, h = 0, l = 101, hp = 0, lp = 0, res;

    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a;
        if(a > h){
            h = a;
            hp = i;
        }

        if(a <= l){
            l = a;
            lp = i + 1;
        }
    }


    res = hp + n - lp;

    if(lp <= hp)res --;
    cout << res;
    



    

    
    
    
    
    

    
}

