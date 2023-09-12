#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,A;
    cin >> N >> A;
    string S;
    cin >> S;
    deque<ll> rightS;
    deque<ll> leftS;
    rep(i,S.size()){
        if(S[i] == '#'){
            if(i >= A-1){
                rightS.push_back(i-A+1);
            }else{
                leftS.push_back(abs(A-i-1));
            }
        }
    }
    sort(rightS.begin(),rightS.end());
    sort(leftS.begin(),leftS.end());
    bool leftside = true;
    ll before = 0;
    ll ans = 0;
    while(!rightS.empty() || !leftS.empty()){
        if(leftside){
            if(rightS.empty()){
                ans += N-A+before+1;
                before = N-A+1;
            }else {
                ll o = rightS.front();
                rightS.pop_front();
                ans += before + o;
                before = o;
            }
        }else{
            if(leftS.empty()){
                ans += before+A;
                before = A;
            }else {
                ll o = leftS.front();
                leftS.pop_front();
                ans += before + o;
                before = o;
            }
        }
        leftside = !leftside;
    }
    cout << ans << endl;
}