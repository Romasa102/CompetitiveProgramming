#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    ll B[N];
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    ll NO;
    ll NT;
    rep(i,N){
        rep(j,N){
            if(A[i] == B[j] && i != j){
                NT++;
            }
            else if(A[i] == B[j] && i == j){
                NO++;
            }
        }
    }
    cout << NO << endl;
    cout << NT << endl;
}