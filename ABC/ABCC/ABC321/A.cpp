#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string N;
    cin >> N;
    bool ok = true;
    rep(i,N.size()-1){
        if(N[i]-'0' <= N[i+1]-'0'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}