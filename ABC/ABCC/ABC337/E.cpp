#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    double N;
    cin >> N;
    ll peopleN = ceil(log2(N));
    cout << peopleN << endl;
    vector<vector<ll>> drink(peopleN);
    rep(bit,N){
        rep(j,peopleN){
            if((1LL<<j) & bit){
                drink[j].push_back(bit);
            }
        }
    }
    rep(i,peopleN){
        cout << drink[i].size() << " ";
        for(ll j:drink[i]){
            cout << j + 1 << " ";
        }
        cout << endl;
    }
    string S;
    cin >> S;
    ll fans = 0;
    rep(i,S.size()){
        if(S[i] == '1'){
            fans += (1LL<<i);
        }
    }
    cout << fans + 1 << endl;
}