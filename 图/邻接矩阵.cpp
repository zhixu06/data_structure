#include<iostream>
using namespace std;

int g[10005][10005];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin >> u >> v >>w;
        g[u][v]=w;
        g[v][u]=w;
    }


    return 0;
}