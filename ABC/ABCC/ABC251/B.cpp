#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    ll A[N+100];
    A[0] = 0;
    A[1] = 0;
    A[2] = 0;
    rep(i,N){
        cin >> A[i+3];
    }
    set<int> st;
    rep(i,N+3){
        for(int j = i;j <N+3;j++){
            for(int l = j;l<N+3;l++){
                if(i!=j&&j!=l&&i!=l){
                  if(A[i]+A[j]+A[l]<=W){
                    st.insert(A[i]+A[j]+A[l]);
                  }
                }
            }
        }
    }
    cout << st.size()-1 << endl;
}