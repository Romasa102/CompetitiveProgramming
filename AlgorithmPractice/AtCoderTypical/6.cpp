#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

int main(){
    ll N,K;
    string S;
    cin >> N >> K >> S;
    auto next = calcNext(S);
    map<ll,ll> used;
    ll currentLeft = K;
    ll currentPos = 0;
    string ans = "";
    rep(i,N){
        rep(j,26)cout << next[i][j] << " ";
        cout << endl;
    }
    rep(i,N){
        if(i<=currentPos)continue;
        rep(j,26){
            if(next[i][j]+1<=N-currentLeft){
                currentPos = next[i][j];
                cout << currentPos << endl;
                currentLeft--;
                ans += char(j+'a');
                if(currentLeft==0){

                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
}