#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    ll maxlen = 0;
    ll len = 0;
    cin >> S;
    rep(i,S.length()){
        if(S[i] == 'A'||S[i] == 'C'||S[i] == 'G'||S[i] == 'T'){
            len++;
            maxlen = max(maxlen,len);
        }else{
            len = 0;
        }
    }
    cout << maxlen << endl;
}