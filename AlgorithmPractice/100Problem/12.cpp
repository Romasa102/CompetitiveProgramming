#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    map<P,bool> relationShip;
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        if(a>b)swap(a,b);
        relationShip[{a,b}] = true;
    }
    int maxS = 0;
    for(ll bit = 0;bit < 1<<N; bit++){
        bool possible = true;
        for(ll i = 0;i < N; i++){
            for(ll j = 0;j < N; j++){
                if(bit & 1<<i && bit & 1<<j && i != j){
                    if(i>j){
                        if(relationShip.find({j,i}) == relationShip.end()){
                            possible = false;
                            break;
                        }
                    }else{
                        if(relationShip.find({i,j}) == relationShip.end()){
                            possible = false;
                            break;
                        }
                    }
                }
            }
        }
        if(possible)maxS = max(maxS,__builtin_popcount(bit));
    }
    cout << maxS << endl;
}
