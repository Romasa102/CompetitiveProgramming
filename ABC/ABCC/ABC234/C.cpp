#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll K;
    cin >> K;
    ll o = 0;
    vector<int> ans;

    while(K > 0){
        if(K%2 == 1){
            ans.push_back(2);
        }else{
            ans.push_back(0);
        }
        K /= 2;
        o++;
    }
    for (ll i = (ans.size() - 1); i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    
}