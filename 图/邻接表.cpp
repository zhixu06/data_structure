#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> p(n+1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >>w;
        p[u].push_back({v,w});
    }

    return 0;
}