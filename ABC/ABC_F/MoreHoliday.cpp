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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K;//N<(2*10^5) M<10^9
    cin >> N >> M >> K;
    string S;
    cin >> S;
    ll xcount = 0;
    rep(i,N){
        if(S[i] == 'x'){
            xcount++;
        }
    }
    ll continuousNum = ((K-xcount*2)/xcount)*xcount;
    //Fisrst get whether K is bigger than the count of x * 2 if not we can subtract the xcount until it'll reach count x * 2
    K -= ((K-xcount*2)/xcount)*xcount;
    //now we only have to consider about length of N*3
    //if we want to bruteforce, we have to calculate  2^2*10^10 so its not realistic
    //Get the number of continuous o and change the value as we move the x range
    string StimeThree = S+S+S;
    ll ans = 0;
    ll firstxP = 0;
    ll lastxP = 0;
    ll cash = K;
    rep(i,3*N){
        if(StimeThree[i] == 'o'){
            continuousNum++;
        }else{
            if(K > 0){
                cash--;
                continuousNum++;
            }else{
                break;
            }
        }
    }
    lastxP = continuousNum;
    //now we got the continuous number by 6*10^5 we'll move this range 3 * N - K which could be 6*10^5 as well
    rep(i,xcount*3-K){
        firstxP++;
        while (StimeThree[firstxP] == 'o'){
            firstxP++;
        }
        firstxP++;
        while(StimeThree[lastxP] == 'o'){
            lastxP++;
        }
        lastxP++;
    }
}
