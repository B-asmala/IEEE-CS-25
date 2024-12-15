#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long n;
void threenone(long long n){

    cout << n << ' ';
 
    if(n == 1){
        return;
    }
 
    if((n & 1) == 0){
        threenone(n / 2);
    }else{
        threenone(3 * n + 1);
    }
    
    
}


int main(){
    // freopen("lepus.in", "r", stdin);
    // freopen("lepus.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
  
    cin >> n;
    threenone(n);

}
 
