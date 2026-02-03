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
    
}

class Solution {
public:
    #define repp(i, c, n) for (ll i = c; i < (n); ++i)
    using ll = long long;
    #define rep(i,n) for(ll i = 0; i < (n); ++i)
    
    int longestAlternating(vector<int>& nums) {
        ll N = nums.size();

        vector<bool> big(N-1);
        vector<bool> big2(N-2);
        
        rep(i,N-1){
            big[i] = (nums[i] < nums[i+1]);
        }
        
        rep(i,N-2){
            big2[i] = (nums[i] < nums[i+2]);
        }

        vector<ll> left(N-1, 0);
        vector<ll> right(N-1, 0);

        rep(i, N-1) {
            if (nums[i] != nums[i+1]) {
                left[i] = 1;
                if (i > 0 && big[i] != big[i-1]) {
                    left[i] += left[i-1];
                }
            }
        }

        for (ll i = N-2; i >= 0; --i) {
            if (nums[i] != nums[i+1]) {
                right[i] = 1;
                if (i < N-2 && big[i] != big[i+1]) {
                    right[i] += right[i+1];
                }
            }
        }

        ll ans = 0;
        rep(i, N-1) ans = max(ans, left[i]);
        rep(i, N-2) {
            if (nums[i] != nums[i+2]) {
                ll currentLen = 1;
                if (i > 0 && big2[i] != big[i-1] && left[i-1] > 0) {
                    currentLen += left[i-1];
                }
            
                if (i < N-3 && big2[i] != big[i+2] && right[i+2] > 0) {
                    currentLen += right[i+2];
                }
                ans = max(ans, currentLen);
            }
        }
        
        return ans + 1;
    }
};