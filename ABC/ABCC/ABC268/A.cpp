#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll A,B,C,D,E;
    cin >> A >> B >> C >> D >> E;
    set<int> st;
    st.insert(A);
    st.insert(B);
    st.insert(C);
    st.insert(D);
    st.insert(E);
    cout << st.size() << endl;
}