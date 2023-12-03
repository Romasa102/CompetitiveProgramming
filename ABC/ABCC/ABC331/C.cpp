#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    vector<ll> sortA(N);
    rep(i,N){
        cin >> A[i];
        sortA[i]=A[i];
    }
    sort(sortA.begin(),sortA.end());
    vector<ll> cumS(N+1);
    cumS[0]=0;
    rep(i,N){
        cumS[i+1]=cumS[i]+sortA[i];
    }
    rep(i,N){
        cout << cumS[N]-cumS[upper_bound(sortA.begin(),sortA.end(),A[i])-sortA.begin()] << " ";
    }cout << endl;
}