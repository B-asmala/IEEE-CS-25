#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//IEEE


long long fib(int i){
    
    if(i == 0 || i == 1){
        return i;
    }

    return fib(i - 1) + fib(i - 2);  
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    
    cin >> n;

    cout << fib(n);

    
}
 
