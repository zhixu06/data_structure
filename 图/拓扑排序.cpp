#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> p(n + 1);
    vector<int> indegree(n + 1, 0);

    // 建图，统计入度
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        p[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // 入度为 0 的顶点入队
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans.push_back(u);

        for (int v : p[u]) {
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 判断是否存在环
    if (ans.size() != n) {
        cout << "存在环\n";
    } else {
        for (int u : ans) {
            cout << u << " ";
        }
        cout << "\n";
    }

    return 0;
}