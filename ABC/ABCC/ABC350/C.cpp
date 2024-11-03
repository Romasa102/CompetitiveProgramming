#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N){
        cin >> A[i];
        A[i]--;
    }
    map<ll,ll> pos;
    rep(i,N){
        pos[A[i]]=i;
    }
    std::vector<P> move;
    rep(i,N){
        if(pos[i]!=i){
            move.push_back({min(pos[i],i),max(pos[i],i)});
            pos[A[i]]=pos[i];
            A[pos[i]]=A[i];
            pos[i]=i;
            A[i]=i;
        }
    }
    cout << move.size() << endl;
    
    rep(i,move.size()){
        cout << move[i].first + 1 << " " << move[i].second + 1 << endl;
    }
}