#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    bool con1 = false;
    bool con2 = false;
    bool con3 = false;
    set<char> st;
    rep(i,S.size()){
        if(S[i] >= 'a' && S[i] <= 'z'){
            con1 = true;
        }
        if(S[i] >= 'A' && S[i] <= 'Z'){
            con2 = true;
        }
        st.insert(S[i]);
    }
    if(st.size() == S.size()){
        con3 = true;
    }
    if(con1 == true && con2 == true && con3 == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}