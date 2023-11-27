#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,L,R;
    cin >> N >> L >> R;
    ll A[N];
    rep(i,N)cin >> A[i];
    rep(i,N){
        ll AN = 0;
        if(A[i] < L){
            AN = abs(A[i]-L);
        }else if(A[i]>R){
            AN = abs(A[i]-R);
        }else{
            AN = 0;
        }
        if(AN+A[i]>=L && AN+A[i]<=R){
            AN+=A[i];
        }else{
            AN=A[i]-AN;
        }
        cout << AN << " ";
    }cout << endl;
}