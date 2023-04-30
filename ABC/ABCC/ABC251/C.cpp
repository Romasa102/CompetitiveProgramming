#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<pair<string,int>> S;
    vector<ll> T;
    set<string> st;
    rep(i,N){
        string str;
        cin >> str;
        ll num;
        cin >> num;
        if(st.find(str)==st.end()){
            S.insert(str,i);
            T.insert(num);
            st.insert(str);
        }
    }
    ll max =0;
    rep(i,S.size()){
        if(max <= T[i]){
            max = T[i];
        }
    }
    rep(i,S.size()){
        if(T[i] == max){
            cout << S[i].second + 1 << endl;
            return 0;
        }
    }
}