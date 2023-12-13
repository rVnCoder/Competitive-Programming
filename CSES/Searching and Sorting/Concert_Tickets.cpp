/*BY-------VAMSHI*/
#include <bits/stdc++.h>
using namespace std;
#define int                         long long
#define rep(i, a, b)                for(int i = a; i < b; i++)
#define repr(i,a,b)                 for(int i=a;i>=b;i--)
#define endl                        "\n"
#define all(x)                      x.begin(), x.end()
void sol(){
    int n,k;
    cin>>n>>k;
    multiset<int> ms;
    rep(i,0,n){
        int x;
        cin>>x;
        ms.insert(x);
    }
    rep(i,0,k){
        int x;
        cin>>x;
        auto it=(ms.upper_bound(x));
        if(it==ms.begin()) cout<<-1<<endl;
        else {cout<<*(--it)<<endl;
        ms.erase(it);}
    }
}
int32_t main(){
    int T  = 1;
    while(T--){
        sol();
    }
    return 0;
}
