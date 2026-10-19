#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>>vis;
vector<char>ans;
vector<string>v;
int n;

char f(char c){
    if(c=='l')return 'r';
    if(c=='r')return 'l';
    if(c=='u')return 'd';
    if(c=='d')return 'u';
}

void dfs(int x,int y){
    for(auto[dx,dy,c]:vector<tuple<int,int,char>>{{0,-1,'r'},{0,1,'l'},{-1,0,'d'},{1,0,'u'}}){
        if(x+dx<0||x+dx>=n||y+dy<0||y+dy>=n)continue;
        if(vis[x+dx][y+dy])continue;
        if(v[x+dx][y+dy]!=c)continue;
        vis[x+dx][y+dy]=true;
        ans.push_back(c);
        dfs(x+dx,y+dy);
        ans.push_back(f(c));
    }
}

int main(){
    cin>>n;
    pair<int,int>p;
    cin>>p.first>>p.second;
    p.first--,p.second--;
    v.assign(n,"");
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool flag=false;
            for(auto[dx,dy,c]:vector<tuple<int,int,char>>{{0,-1,'r'},{0,1,'l'},{-1,0,'d'},{1,0,'u'}}){
                if(i+dx<0||i+dx>=n||j+dy<0||j+dy>=n)continue;
                if(c!=v[i][j])continue;
                if(c==v[i+dx][j+dy]){
                    flag=true;
                    vis=vector<vector<bool>>(n,vector<bool>(n,0));
                    ans.clear();
                    vis[i][j]=true;
                    vis[i+dx][j+dy]=true;
                    ans.push_back(v[i][j]);
                    dfs(i+dx,j+dy);
                    ans.push_back(f(v[i][j]));
                }
            }
            if(!flag)continue;
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    if(!vis[x][y])flag=false;
                }
            }
            if(!flag)continue;
            if(i>p.first){
                for(int k=0;k<i-p.first;k++){
                    ans.push_back('d');
                }
            }else{
                for(int k=0;k<p.first-i;k++){
                    ans.push_back('u');
                }
            }
            if(j>p.second){
                for(int k=0;k<j-p.second;k++){
                    ans.push_back('r');
                }
            }else{
                for(int k=0;k<p.second-j;k++){
                    ans.push_back('l');
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<'\n';
            for(char c:ans){
                cout<<1<<' '<<c<<'\n';
            }
            return 0;
        }
    }
    cout<<"impossible\n";
}