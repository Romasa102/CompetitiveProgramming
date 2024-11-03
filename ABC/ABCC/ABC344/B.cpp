#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    vector<ll> A;
    ll a;
    while(cin){
        cin >> a;
        A.push_back(a);
    }
    //std::reverse(A.begin(), A.end());
    rep(i,A.size()){
        cout << A[i] << endl;
    }
}