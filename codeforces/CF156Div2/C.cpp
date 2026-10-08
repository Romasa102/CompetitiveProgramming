#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t;cin >> t;
    rep(_,t){
        string s;
        ll n;
        cin >> s >> n;
        ll cumS[s.size()+1];
        cumS[0]=0;
        repp(i,1,s.size()+1){
            cumS[i] = cumS[i-1]+(s.size()-i+1);
        }
        //rep(i,s.size()+1)cout << cumS[i] << " ";
        //cout << endl;
        ll numD = 0;
        if(lower_bound(cumS,cumS+s.size()+1,n)-cumS >= 1){
            numD = lower_bound(cumS,cumS+s.size()+1,n)-cumS-1;
        }
        //cout<< "numD is :" << numD << endl;
        ll numDcpy = numD;
        stack<char> cur;
        rep(i,s.size()){
            while(!cur.empty() && cur.top() > s[i] && numD>0){
                cur.pop();
                numD--;
            }
            cur.push(s[i]);
        }
        string sn;
        while(!cur.empty()){
            sn+=cur.top();
            cur.pop();
        }
        rep(i,sn.size()){
            while(!cur.empty() && cur.top() > sn[i] && numD>0){
                cur.pop();
                numD--;
            }
            cur.push(sn[i]);
        }
        rep(i,n-cumS[numDcpy]-1){
            if(cur.size()<=1)break;
            cur.pop();
        }
        cout << cur.top();
    }
}