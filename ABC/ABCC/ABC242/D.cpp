#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<P> tk(Q);
    ll tkmax = 0;
    rep(i,Q){
        cin >> tk[i].first >> tk[i].second;
    }
    rep(i,Q){
        ll o = tk[i].second;
        while(o > S.size()){
            if(o%2 > 0){
                o /= 2;
                o++;
            }else{
                o/=2;
            }
        }
    }
}