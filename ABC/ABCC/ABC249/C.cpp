#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    char ah = 'a';
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }
    ll maxans = 0;       
    vector<set<char>> st; 
    rep(i,N){
        rep(j,S[i].size()){
            st[i].insert(S[i][j]); 
        }
    }
    do{
    for(ll now = K; now <= N; now++){
        multiset<char> ast;
        ll ans = 0;
        rep(i,now){
            for(auto itr = st[i].begin(); itr != st[i].end(); ++itr) {
                ast.insert(*itr); 
            }
        }
        rep(i,26){
            if(ast.count(ah+i) >= K){
                ans++;
            }
        }
        if(ans > maxans){
            cout << ans << endl;
            maxans = ans;
        }
    }
    }while(next_permutation(st.begin(),st.end()));
    cout << maxans << endl;
}