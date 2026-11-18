#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int comp(P x,P y){
    if(x.first > y.first){
        return true;
    }else if(x.first < y.first){
        return false;
    }else if(x.second < y.second){
        return true;
    }else{
        return false;
    }
}
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M];
    map<ll,vector<P>> mp;
    rep(i,M){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
        mp[A[i]].push_back({B[i],1});
    }
    rep(i,N){
        map<ll,ll> cnt;
        rep(j,mp[i].size()){
            cnt[mp[i][j].first]++;
        }
        mp[i].clear();
        for(auto j : cnt){
            mp[i].push_back({j.first,j.second});
        }
    }
    vector<ll> vote(N);
    vector<P> voteOrder(N);
    rep(i,M){
        vote[A[i]]++;
    }
    rep(i,N){
        voteOrder[i] = {vote[i],i};
    }
    sort(voteOrder.begin(),voteOrder.end(),comp);
    rep(i,N){
        ll curMax = 0;
        ll curMaxInd = 0;
        if(voteOrder[0].second != i){
            curMax = voteOrder[0].first;
            curMaxInd = voteOrder[0].second;
        }else{
            curMax = voteOrder[1].first;
            curMaxInd = voteOrder[1].second;
        }
        for(auto j : mp[i]){
            //cout << "curMax is " << curMax <<"  from " << curMaxInd + 1 << endl;

            //cout << i+1 << " donated to " << j.first+1 << " and the new value is " << vote[j.first] + j.second << endl;
            
            if(vote[j.first] + j.second > curMax || (vote[j.first]+j.second==curMax && j.first < curMaxInd)){
                //cout << "updated ! " << endl;
                curMax = vote[j.first]  +j.second;
                curMaxInd = j.first;
            }
        }
        cout << curMaxInd  + 1<< endl;
    }

}