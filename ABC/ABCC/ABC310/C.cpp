#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S;
    map<string,bool> map;
    ll ans = 0;
    rep(i,N){
        cin >> S;
        if(map.find(S)==map.end()){
            ans++;
      		map[S] = true;
            reverse(S.begin(),S.end());
      		map[S] = true;
        }
    }
    cout << ans << endl;
}