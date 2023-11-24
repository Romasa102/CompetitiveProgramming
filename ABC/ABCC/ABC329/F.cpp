#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    ll C[N];
    vector<set<ll>> type(N);
    map<ll,vector<ll>> nums;
    rep(i,N){
        cin >> C[i];
        type[i].insert(C[i]);
    }
    rep(i,Q){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        //move all a to b and count the type in b;
        if(type[a].size()>type[b].size()){
            for(ll j:type[b]){
                type[a].insert(j);
            }
            cout << type[a].size() << endl;
            type[b].clear();
            swap(type[a],type[b]);
        }else{
            for(ll j:type[a]){
                type[b].insert(j);
            }
            cout << type[b].size()   << endl;
            type[a].clear();
        }
    }
}