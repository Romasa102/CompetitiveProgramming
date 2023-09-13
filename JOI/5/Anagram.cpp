#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s;
    cin >> s;
    map<char,P> order;
    order[s[0]] = {0,1};
    ll counter = 0;
    repp(i,1,s.size()){
        if(s[i] == s[i-1]){
            order[s[i]] = {counter,order[s[i]].second+1};
        }else{
            counter++;
            order[s[i]] = {counter,1};
        }
    }
    ll ans = 0;
    rep(i,s.size()){
        ans += (s.size() - 1 - i)
    }
}