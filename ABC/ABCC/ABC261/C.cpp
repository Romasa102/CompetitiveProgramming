#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    map<string,int> M;
    rep(i,N){
        cin >> S[i];
    }
    auto itr = S.begin();
    while(itr != S.end()) {
        cout << *itr;
        M[*itr]++;
        if(M[*itr] != 1){
            cout << "(" << M[*itr]- 1 << ")";
        }
        cout << endl;
        itr++;
    }
}