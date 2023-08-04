#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P ref;
    cin >> ref.first >> ref.second;
    vector<P> star(N-1);
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        star[i].first = a-ref.first;
        star[i].second = b - ref.second;
    }
    ll m;
    cin >> m;
    map<P,bool> sky;
    vector<P> skystar(m);
    ll c,d;
    rep(i,m){
        cin >> c >> d;
        sky[{c,d}] = true;
        skystar[i] = {c,d};
    }
    rep(i,m){
        bool Done = true;
        rep(j,N-1){
            if(sky.find({skystar[i].first+star[j].first,skystar[i].second+star[j].second}) == sky.end()){
                Done = false;
                break;
            }
        }
        if(Done == true){
            cout << skystar[i].first - ref.first << " " << skystar[i].second - ref.second << endl;
            return 0;
        }
    }
}