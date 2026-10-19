#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i,x,n) for(int i = x; i < n; i++)
using ll =long long;
using P = pair<ll,ll>;
ll n,m;
stack<pair<bool,pair<ll,char>>> ans;
map<pair<ll,pair<bool,char>>,set<pair<ll,pair<bool,char>>>> dependencies;
map<pair<ll,pair<bool,char>>,bool> visited;
vector<vector<char>> gridVisited;


//index ,bool,character

bool dfs(pair<ll,pair<bool,char>> cur){
    if(visited[cur] == true)return true;
    for(auto i : dependencies[cur]){
        if(visited[i])continue;
        dfs(i);
    }
    visited[cur]=true;
    if(cur.second.first == true){
        rep(i,m){
            gridVisited[cur.first][i] = '.';    
        }
    }else{
        rep(i,n){
            gridVisited[i][cur.first] = '.';
        }
    }
    ans.push({cur.second.first,{cur.first,cur.second.second}});
    return true;
}
int main(){
    cin >> n >> m;
    string s[n];
    rep(i,n)cin >> s[i];
    gridVisited.resize(n,vector<char>(m,' '));
    rep(i,n){
        rep(j,m){
            gridVisited[i][j] = s[i][j];
        }
    }
    priority_queue<pair<P,pair<bool,char>>> pq; //size, index ,bool,character

    map<pair<ll, char>,ll> vmp;  //map<index,bool,character> size;
    rep(i,n){
        rep(j,m){
            vmp[{i,s[i][j]}]++;
        }
    }
    for(auto i : vmp){
        pq.push({{i.second,i.first.first},{true,i.first.second}});
        rep(j,m){
            if(s[i.first.first][j] != i.first.second) {
                dependencies[{i.first.first,{true,i.first.second}}].insert({j,{false,s[i.first.first][j]}});
            }
        }
    }


    map<pair<ll, char>,ll> hmp;  //map<index,bool,character> size;
    rep(i,n){
        rep(j,m){
            hmp[{j,s[i][j]}]++;
        }
    }
    for(auto i : hmp){
        pq.push({{i.second,i.first.first},{false,i.first.second}});
        rep(j,n){
            if(s[j][i.first.first] != i.first.second){
                dependencies[{i.first.first,{false,i.first.second}}].insert({j,{true,s[j][i.first.first]}});
            }
        }
    }//pair<ll,pair<bool,char>
    //cout << "init work" << endl;
    //size, index ,bool,character
    //cout <<" size was " << pq.size() << endl;;;
    while(!pq.empty()){
        auto cur = pq.top();
        //cout << "running pq with " << cur.first.second << endl;;
        ll o_size = cur.first.first;
        ll nsize = 0;
        
        if(cur.second.first == true){ //check that the size is still same
            rep(i,m){
                if(gridVisited[cur.first.second][i] == cur.second.second)nsize++;
            }
        }else{
            rep(i,n){
                if(gridVisited[i][cur.first.second] == cur.second.second)nsize++;
            }
        }
        if(nsize==0){
            pq.pop();
            continue;
        }
        if(o_size != nsize){
            pq.pop();
            pq.push({{nsize,cur.first.second},cur.second});
            continue;
        }
        //cout << "no error until here" << endl;
        if(dfs({cur.first.second,cur.second}) == false){
            return 0;
        }
        pq.pop();
    }
    cout << ans.size() << endl;
    while(!ans.empty()){
        auto cur = ans.top();
        if(!cur.first){
            cout  << 'x';
        }else{
            cout << 'y';
        }
        cout <<"=" << cur.second.first+1 << " " << cur.second.second << endl;
        ans.pop();
    }
}