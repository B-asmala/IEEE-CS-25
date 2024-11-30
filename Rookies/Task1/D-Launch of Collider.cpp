#include <bits/stdc++.h>
using namespace std;


bool check (int n){
    int x;
    

    while(n){
        x = n % 10;
        if(x != 4 && x != 7){
            return false;
        }
        n /= 10;
    }

    return true;
}


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
    
    int n, res = -1, a, al;
    string s;
    cin >> n >> s >> al;
    for(int i = 1; i < n; i ++){
        cin >> a;

        if(s[i] == 'L' && s[i - 1] == 'R'){
            if(res == -1)res = (a - al) / 2;

            res = min(res, (a - al) / 2);
        }

        al = a;
    }

    cout << res;







    

    
    
    
    
    

    
}

