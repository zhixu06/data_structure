#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int u, v, w;
};

vector<edge> edges(200004);
vector<int> group(5005);

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (group[x] == x)
        return x;
    else
        return group[x] = find(group[x]);
}

bool Union(int a, int b)
{
    int aroot = find(a);
    int broot = find(b);
    if (aroot == broot)
    {
        return false;
    }
    else
    {
        group[aroot] = broot;
        return true;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    for (int i = 1; i <= n; i++)
    {
        group[i] = i;
    }
    sort(edges.begin() + 1, edges.begin() + 1 + m, cmp);
    int numedge = 0;
    long long vale = 0;
    for (int i = 1; i <= m; i++)
    {
        if (Union(edges[i].u, edges[i].v))
        {
            numedge++;
            vale += edges[i].w;
        }
        if (numedge == n - 1)
            break;
    }
    if (numedge < n - 1)
    {
        cout << "orz";
    }
    else
    {
        cout << vale;
    }

    return 0;
}