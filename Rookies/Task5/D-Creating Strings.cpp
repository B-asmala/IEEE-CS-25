#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<string> res;
int n;

void strings(string s, unordered_multiset<char> chars){
    string news;
    
    if(s.size() == n){
        res.insert(s);
        return;
    }
    
    for(auto c : chars){
        news = s;
        unordered_multiset<char> newchars = chars;
        news.push_back(c);
        newchars.erase(newchars.find(c));
        strings(news, newchars);
    }  
}


int main(){
    // freopen("lepus.in", "r", stdin);
    // freopen("lepus.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    unordered_multiset<char> chars;
    cin >> s;

    n = s.size();
    for(int i = 0; i < n; i ++){
        chars.insert(s[i]);
    }

    strings("", chars);

    cout << res.size() << endl;

    for(auto s : res){
        cout << s << '\n';
    }

    
}
 
