#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> p(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        p[u].push_back({v, w});
        p[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < p[1].size(); i++)
    {
        q.push({p[1][i].second, p[1][i].first});
    }
    vis[1] = true;
    int cnt = 1;
    long long ans = 0;
    while (!q.empty())
    {
        int val = q.top().first;
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        ans += val;
        cnt++;
        for (int i = 0; i < p[x].size(); i++)
        {
            int v = p[x][i].first;
            int w = p[x][i].second;
            if (!vis[v])
                q.push({w, v});
        }
    }
    if (cnt < n)
    {
        cout << "orz";
    }
    else
    {
        cout << ans;
    }
}