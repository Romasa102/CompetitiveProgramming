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
    rep(_,t){
        ll n;cin >> n;
        ll a[n],b[n];
        rep(i,n)cin >> a[i];
        rep(i,n)cin >> b[i];
        ll ansL[n+1];
        ll ansR[n+1];
        ll ans = 0;
        ansL[0]=0;ansR[0]=0;
        repp(i,1,n+1){
            ll cur = 1;
            if(a[i-1]==b[i-1])cur = 2;
            if(i==n){
                ansR[i]=ansR[i-1]+cur;
                ansL[i]=ansL[i-1]+cur;
                continue;
            }
            //cout << i << "th straight road was cost of " << cur << " the a,b is " << a[i-1] << b[i-1] << endl;
            if(a[i] == b[i-1]){
                ansR[i] = ansR[i-1] + cur + 2;
                //cout << i << "th R to L road was cost of " << 2 << endl;
            }else{
                ansR[i] = ansR[i-1] + cur + 1;

                //cout << i << "th R to L road was cost of " << 1 << endl;
            }
            if(a[i-1]==b[i]){
                ansL[i] = ansL[i-1] + cur + 2;

               // cout << i << "th L to R road was cost of " << 2 << endl;
            }else{
                ansL[i] = ansL[i-1] + cur + 1;
               // cout << i << "th L to R road was cost of " << 2 << endl;
            }
        }
        ll ansC[n+1];
        ansC[n]=1;
        if(a[n-1]==b[n-1])ansC[n]=2;
        for(int i = n-1; i >= 1; i--){
            ll cur = 2;
            if(a[i]==b[i-1])cur++;
            if(a[i-1]==b[i])cur++;
            ansC[i]=ansC[i+1]+cur;
        }
        if(a[0]==b[0]){
            ansC[0]=ansC[1]+2;
        }else{
            ansC[0]=ansC[1]+1;
        }
        /*cout << "ansL : ";
        rep(i,n+1)cout << ansL[i] << " ";
        cout << endl;

        cout << "ansR : ";
        rep(i,n+1)cout << ansR[i] << " ";
        cout << endl;

        cout << "ansC : ";
        rep(i,n+1)cout << ansC[i] << " ";
        cout << endl;*/
        rep(i,n){
            //ans = max(ans, ansL[i]+ansC[i+1]);
            ans = max(ans, ansR[i]+ansC[i+1]);
            ll cur = 1;

            //cout << "ans at " << i << "th is " << ans << endl;
            // if(a[i]==b[i])cur=2;
            //ans = max(ans, (ansC[0]-ansC[i]) + (ansL[n]-ansL[i])-cur);
            //ans = max(ans,(ansC[0]-ansC[i]) + (ansR[n]-ansR[i])-cur);
            //cout << "ans at " << i << "th is " << ans << endl;
        }
        cout << ans << endl;
    }
}