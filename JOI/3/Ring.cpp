#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll N;
    cin >> N;
    ll result=0;
    rep(i,N){
        string X;
        cin >> X;
        X+=X;
        if(X.find(S)!=std::string::npos){
            result++;
            continue;
        }
    }
    cout << result << endl;
}