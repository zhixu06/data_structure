#include<iostream>
#include<cstring>
using namespace std;
int head[100];
int nxt[100];
int to[100];
int weight[100];
int pos=1;

void addEdge(int u,int v,int w){
    to[pos]=v;
    nxt[pos]=head[u];
    head[u]=pos++;
    weight[pos]=w;
}

int main(){
    int n,m;
    cin >> n >> m;

    memset(head,-1,sizeof(head));
    int u;
    cin >> u;
    for(int i=head[u];i!=-1;i=nxt[i]){
        int v=to[i];
        int w=weight[i];
    }


    return 0;
}