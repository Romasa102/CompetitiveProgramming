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
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){

    //define variables
    ll N;
    cin >> N;
    ll p[N];
    ll dis[N];
    ll numNow = 0;
    ll positiveCount = 0;
    ll negativeCount = 0;
    ll nomove = 0;
    vector<ll> negativeEnd(N+20);
    vector<ll> positiveEnd(N+20);
    vector<ll> negativeStart(N+20);
    vector<ll> positiveStart(N+20);

    //use loop to get input
    rep(i,N){
        cin >> p[i];
    }

    //use loop to get the distance for each person
    rep(i,N){
        if(i-p[i] >= 0){
            dis[p[i]] = i-p[i];
        }else{
            dis[p[i]] = i-p[i]+N;
        }
    }

    
    rep(i,N){
        numNow+=min(dis[p[i]], N - dis[p[i]]);
        if(N%2==0){
            if(dis[p[i]] <  N/2)//positive
            {
                positiveCount++;
                positiveEnd[N/2 - dis[p[i]]]++;
                negativeStart[N/2 - dis[p[i]]]++;
                if(dis[p[i]] == 0){
                    negativeEnd[0]++;
                    positiveStart[0]++;
                }else{ 
                    negativeEnd[N - dis[p[i]]]++;
                    positiveStart[N - dis[p[i]]]++;
                }
            }else{
                negativeCount++;
                negativeEnd[N - dis[p[i]]]++;
                positiveStart[N - dis[p[i]]]++;
                positiveEnd[N - dis[p[i]] + N/2]++;
                negativeStart[N - dis[p[i]] + N/2]++;
            }
        }else{
            if(dis[p[i]] <  N/2)//positive
            {
                positiveCount++;
                if(dis[p[i]] == 0){
                    negativeEnd[0]++;
                    positiveStart[0]++;
                }else{
                    negativeEnd[N - dis[p[i]]]++;
                    positiveStart[N - dis[p[i]]]++;
                }
                positiveEnd[N/2 - dis[p[i]]]++;
                negativeStart[N/2 - dis[p[i]] + 1]++;
            }else if(dis[p[i]] > N/2){
                negativeCount++;
                negativeEnd[N - dis[p[i]]]++;
                positiveStart[N - dis[p[i]]]++;
                positiveEnd[N - dis[p[i]] + N/2]++;
                negativeStart[N - dis[p[i]] + N/2 + 1]++;
            }else{
                negativeEnd[N/2 + 1]++;
                positiveStart[N/2+1]++;
                negativeStart[1]++;
            }
        }
    }
    ll ans = numNow;
    rep(i,N){
        if(numNow <= ans){
            ans = numNow;
        }
        numNow += (positiveCount - negativeCount);
        positiveCount -= positiveEnd[i+1];
        positiveCount += positiveStart[i+1];
        negativeCount -= negativeEnd[i+1];
        negativeCount += negativeStart[i+1];
    }
    cout << ans <<endl;
}