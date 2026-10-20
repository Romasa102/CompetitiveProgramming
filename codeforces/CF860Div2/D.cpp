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
    ll T;
    cin >> T;
    rep(_,T){
        ll n;cin >> n;
        ll a[n];rep(i,n)cin >> a[i];
        stack<ll> high;
        stack<ll> low;
        ll ind = n-1;
        sort(a,a+n);
        ll bound = a[n-1]-a[0];
        while(ind>0&&a[ind]>0){
            high.push(a[ind]);ind--;
        }
        rep(i,ind+1){
            low.push(a[i]);
        }
        if(a[0]>=0){
            cout << "No" << endl;
            continue;
        }
        vector<ll> ans;
        ll curSum = high.top();
        ans.push_back(high.top());
        high.pop();
        bool work = true;
        repp(i,1,n){
            if(curSum > 0 && !low.empty()){
                curSum+=low.top();
                ans.push_back(low.top());
                low.pop();
            }else if(!high.empty()){
                curSum+=high.top();
                ans.push_back(high.top());
                high.pop();
            }else{
                curSum+=low.top();
                ans.push_back(low.top());
                low.pop();
            }
            if(abs(curSum)>bound){
                work = false;break;
            }
        }
        if(work){
            cout << "Yes" << endl;
            rep(i,n){
                cout << ans[i] << " ";
            }cout << endl;

        }else{
            cout << "No" << endl;
            continue;
        }
    }
}