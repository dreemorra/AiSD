#include <iostream>
#include <vector>

using namespace std;

vector<int> used(100001);
vector <vector<int>> g(100001);
int ans = 0;

void dfs (int v) {
	used[v] = 1;
        for (int i = 0; i < g[v].size(); ++i)
            if (!used[g[v][i]])
                dfs(g[v][i]);
            else ans++;
}


int main() {
    int vertex, edge = 0;
    cin >> vertex >> edge;

    for(int i = 0, a, b; i < edge; i++) 
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(int i = 1; i < vertex + 1; i++)
    if(!used[i])
    {
        cout << -1;
        return 0;
    }

    cout << ans - edge;
    return 0;
}