#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N,A,B,P,Q,R,S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    string str = "";
    vector<string> ans;
    for (int i = 0; i < S - R + 1; i++)
    {
        str += '.';
    }
    for (int i = 0; i < Q - P + 1; i++)
    {
        ans.push_back(str);
    }
    
    ll Mink = max(P - A,R - B);
    ll Maxk = min(Q - A,S - B);
    for (ll i = Mink; i <= Maxk; i++)
    {
        ans[A + i - P][B + i - R] = '#';
    }
    Mink = max(P - A,R - B);
    Maxk = min(Q - A,S - B);
    for (ll i = Mink; i <= Maxk; i++)
    {
        ans[A + i - P][B - i - R] = '#';
    }
    for (ll i = 0; i < (Q - P + 1); i++)
    {
        cout << ans[i] << endl;
    }
    
}