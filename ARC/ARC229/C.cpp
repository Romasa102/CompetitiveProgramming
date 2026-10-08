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
        ll N;
        cin >> N;
        ll A[N];
        rep(i,N)cin >> A[i];
        vector<ll> odd;
        vector<ll> even;
        ll sum = 0;
        rep(i,N){
            if(A[i]%2 == 0){
                even.push_back(A[i]);
            }else{
                odd.push_back(A[i]);
            }
        }
        if(even.size() < odd.size())swap(even,odd);
        sort(even.begin(),even.end(),greater<ll>());
        sort(odd.begin(),odd.end());
        vector<ll> ordered;
        ll evenI = 0;
        ll oddI = 0;
        while(evenI != even.size() || oddI != odd.size()){
            if(evenI != even.size()){
                ordered.push_back(even[evenI]);
                evenI++;
            }
            if(oddI != odd.size()){
                ordered.push_back(odd[oddI]);
                oddI++;
            }
        }
        ll ans  = 0;
        rep(i,ordered.size()-1){
            cout << ordered[i] << " ";
            ans += (ordered[i] +  ordered[i+1])/2;
        }cout << ordered[ordered.size()-1] << "   : ";
        cout << ans << endl;
    }
}