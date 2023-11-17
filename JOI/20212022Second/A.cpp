#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;
    stack<string> s;
    rep(i,Q){
        string a;
        cin >> a;
        if(a=="READ"){
            cout << s.top() << endl;
            s.pop();
        }else{
            s.push(a);
        }
    }
}