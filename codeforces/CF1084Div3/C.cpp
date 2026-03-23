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
    ll t;
    cin >> t;
    while(t--){
        ll n;cin >> n;
        string s;cin >> s;
        stack<ll> st;
        rep(i,n){
            st.push(s[i]);
            if(i==n-1 || s[i]!=s[i+1]){
                if(st.empty())continue;
                ll cur = st.top();
                st.pop();
                if(st.empty()){
                    st.push(cur);
                    continue;
                }
                bool push_back = true;
                while(!st.empty() && cur == st.top()){
                    st.pop();
                    if(st.empty()){
                        push_back = false;
                        break;
                    }
                    cur = st.top();
                    st.pop();
                }
                if(push_back) st.push(cur);
            }
        }
        if(st.empty()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}