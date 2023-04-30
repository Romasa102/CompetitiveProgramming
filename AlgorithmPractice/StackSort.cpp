#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int top;
int A[1000];
void push(int x){
    top++;
    A[top] = x;
}
int pop(){
    top--;
    return(A[top+1]);
}
int main(){
    top = 0;
    char l[1];
    int a,b;
    while(scanf("%s",l) != EOF){
        if(l[0] == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }else if(l[0] == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }else if(l[0] == '-'){
            b = pop();
            a = pop();
            push(a-b);
        }else{
            push(atoi(l));
        }
    }
    cout << pop() << endl;
}