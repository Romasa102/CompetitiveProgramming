#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll N,D;
bool Inf[100000];
vector<P> pos(100000);
void Infection(int O){
    if(Inf[O]){
        return;
    }
    Inf[O] = true;
    rep(i,N){
        if(sqrt(pow(pos[O].first - pos[i].first,2) + pow(pos[O].second - pos[i].second,2)) <= D){
            Infection(i);
        }
    }
    return;
}
int main(){
    cin >> N >> D;
    rep(i,N){
        cin >> pos[i].first >> pos[i].second;
    }
    Infection(0);

    rep(i,N){
        if(Inf[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}