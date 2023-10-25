#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[N];
    map<string,bool> done;
    rep(i,N){
        cin >> S[i];
        if(done.find(S[i])==done.end()){
            done[S[i]]=true;
            cout << i+1 << endl;
        }
    }
}