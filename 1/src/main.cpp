#include <iostream>
#include <vector>

using namespace std;

vector<char> used;
vector <vector<int>> g;

void dfs (int v) {
	used[v] = true;
        for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
            if (!used[*i])
                dfs(*i);
}

int findComp(int m) {
    int c = 0;
    used.resize(m, false);
    for(int i = 0; i < m; i++) {
        if(!used[i]) {
            dfs(i);
            c++;
        }
    }
    return c;
}

int main() {
    int vertex, edge = 0;
    cin >> vertex >> edge;
    g.resize(vertex); // граф
    
    for(int i = 0; i < edge; i++) {
        int a, b = 0;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    cout << findComp(vertex) - 1;
    return 0;
}