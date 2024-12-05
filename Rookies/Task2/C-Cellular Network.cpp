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

    int n, m;
    long long r = 0, rp, l, h, mid;
    vector<long long> a, b;

    cin >> n >> m;
    a.resize(n);
    b.resize(m);

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i ++){
        cin >> b[i];
    }


    for(int i = 0; i < n; i ++){
        if(i > 0 && a[i] == a[i - 1]){
            continue;
        }

        l = 0;
        h = m - 1;
        rp = LONG_LONG_MAX;
        while(l <= h){
            mid = (l + h ) / 2;
            if(abs(a[i] - b[mid]) < rp){
                //cout << i << " " << b[mid] << " " <<abs(a[i] - b[mid]) << endl;
                rp = abs(a[i] - b[mid]);
            }
            if(b[mid] == a[i]){
                break;
            }else if(b[mid] > a[i]){
                h = mid - 1;
            }else{
                l = mid + 1;

            }
            
            
            }

        if(rp > r){
                r = rp;
        }
        

        


    }

    cout << r;


    


}


