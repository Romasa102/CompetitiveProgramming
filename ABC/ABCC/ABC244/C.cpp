#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    set<ll> st;
    rep(i,2 *N + 1){
        st.insert(i + 1);
    }
    while(true){
        cout << *st.begin() << flush;
        st.erase(st.begin());
        ll  K;
        cin >> K;
        if(K == 0){
            break;
        }
        st.erase(K);
    }return 0;
}