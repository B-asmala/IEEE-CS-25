#include <iostream>
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
 
 

vector<int> mv;
int main(){
    // freopen("lepus.in", "r", stdin);
    // freopen("lepus.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long k, n, high, low, mid, ans = LONG_LONG_MAX, x, j;
    cin >> n >> k;

    low = 1;
    high = n;

    while(low <= high){
        mid = (low + high) / 2;
        j = 1;
        x = 0;

        while(mid / j > 0){
            x += mid / j;
            j *= k;
        }

        if(x >= n){
            high = mid - 1;
            ans = min(ans, mid);
        }else{
            low = mid + 1;
        }

    }
    

    cout << ans;

   

   


    


}


