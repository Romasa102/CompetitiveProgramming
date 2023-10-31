#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N][N];
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
        }
    }
    ll M;
    cin >> M;
    map<P,bool> rift;
    rep(i,M){
        ll X,Y;
        cin>>X>>Y;
        X--;Y--;
        rift[{X,Y}]=true;
        rift[{Y,X}]=true;
    }
    vector<ll> order;
    rep(i,N){
        order.push_back(i);
    }
    ll ans = 1LL<<40;
    do{
        bool accept=true;
        ll ansT = 0;
        rep(i,N-1){
            if(rift.find({order[i],order[i+1]})!=rift.end()){
                accept= false;
                break;
            }
        }
        rep(i,N){
            ansT+=A[order[i]][i];
        }
        if(accept)ans=min(ans,ansT);
    } while (next_permutation(order.begin(),order.end()));
    if(ans==1LL<<40){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}