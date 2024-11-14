#include <iostream>
using namespace std;
int main()
{
    string S,T;
    cin >> S;
    cin >> T;
    if(S==T)
    {
        cout << "0" << endl;
        return 0;
    }
    else
    {
       for(int i=0;i<S.length()||i<T.length();i++)
       {
           if(S[i]!=T[i])
           {
               cout << i+1 << endl;
               break;
           }
       }
    }
    return 0;
}