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
    ll N,K;
    cin >> N >> K;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll left = 0;
    ll right = 2000000000000000000;
    ll mid=(left+right+1)/2;
    while(left != mid){

        cout << left << " " << right << " mid" << mid << endl;
        bool valid=true;
        ll cost = 0;
        rep(i,N){
            if(A[i]>=mid)continue;
            if(((mid-A[i])/(i+1)) > K)valid = false;
            if(cost > K - ((mid-A[i])/(i+1))){
                valid = false;
            }
            if((mid-A[i])%(i+1)==0){
                cost += ((mid-A[i])/(i+1));
            }else{
                cost += ((mid-A[i])/(i+1));
                cost ++;
            }
            if(cost > K){
                valid = false;
                break;
            }
        }
        if(valid){
            left = mid;
        }else{
            right = mid-1;
        }
        mid = (left + right + 1)/2;
    }
    cout << left << endl;
}