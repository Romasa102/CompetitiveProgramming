#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    set<string> st;
    rep(i,S.size()){
        repp(j,1,S.size()-i+1){
            st.insert(S.substr(i,j));
        }
    }
    cout << st.size() << endl;
}