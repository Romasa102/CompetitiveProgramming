#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll T[N];
    rep(i,N)cin >> T[i];
    ll curM=0;
    rep(i,N){
        ll curN = 1LL<<T[i];
        ll c = 1;
        while(curN<=curM){
            curN += 1LL<<(T[i]+c);
            c++;
        }
        curM = curN;
    }
    cout << curM << endl;
}