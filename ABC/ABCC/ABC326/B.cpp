#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> A;
    repp(i,1,10){
        rep(j,10){
            if(i*j<10){
                A.push_back(i*100+j*10+i*j);
            }
        }
    }
    sort(A.begin(),A.end());
    cout << *lower_bound(A.begin(),A.end(),N) << endl;
}