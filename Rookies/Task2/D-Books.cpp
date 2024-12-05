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

    long long t, n, high, low, mid, res = 0, ans;
    vector<long long> v;
    cin >> n >> t;
    v.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }


    for(int i = n - 2; i >= 0; i --){
        v[i] += v[i + 1];
    }
    v.push_back(0);

    for(int i = 0; i < n; i ++){
        low = i;
        high = v.size() - 1;
        ans = 0;
        while(low <= high){
            mid = (high + low ) / 2;

            if(v[i] - v[mid] <= t){
                ans = max(ans, mid - i);
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        res = max(res, ans);
    }

    cout << res;

   

   


    


}


