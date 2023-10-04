#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    map<ll,set<ll>> M;
    ll isolate = N;
    rep(i,Q){
        ll que;
        cin >> que;
        if(que == 1){
            ll a,b;
            cin >> a >> b;
            if(M.find(a) == M.end()){
                isolate--;
            }
            if(M.find(b) == M.end()){
                isolate--;
            }
            M[a].insert(b);
            M[b].insert(a);
        }else{
            ll v;
            cin >> v;
            if(M.find(v) != M.end()){
                for(int j : M[v]){
                    if(M[j].size() == 1){
                        isolate++;
                        M.erase(j);
                    }else{
                        M[j].erase(v);
                    }
                }
                isolate++;
                M.erase(v);
            }
        }
        cout << isolate << endl;
    }
}