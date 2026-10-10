#include<queue>
std::vector<bool> vis(100); 
std::vector<int> g[100];
int main(){
    std::queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i : g[u]){
            if(!vis[i]){
                q.push(i);
                dist[i]=dist[u]+1;
            }
        }
    }

}
