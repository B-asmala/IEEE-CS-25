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
    
    int n, f = 0;

    cin >> n;

    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(check(i) || check(n / i)){
                f = 1;
                break;
            }
        }
    }


    if(f){
        cout << "YES";
    }else{
        cout << "NO";
    }



    

    
    
    
    
    

    
}

