#include <iostream>
#include <vector>

using namespace std;

vector <vector<pair<long long,long long>>> g;
long long sum = 0;

void sub_dfs (vector<long long>& subtree_vertices, long long v, long long prev_v) {
    for (auto edge : g[v]) {
        if(edge.first != prev_v) {
            sub_dfs(subtree_vertices, edge.first, v);
            subtree_vertices[v] += subtree_vertices[edge.first];
        }
    }
    subtree_vertices[v] += 1;
}

void dfs (vector<long long>& subtree_vertices, long long v, long long prev_v) {
    for (auto edge : g[v]) {
        if(edge.first != prev_v) {
            dfs(subtree_vertices, edge.first, v);
            sum += edge.second*(subtree_vertices[edge.first]*(g.size()-1 - subtree_vertices[edge.first]));
        }
    }
}

vector<long long> CalculateSubtrees() {
    vector<long long> subtree_vertices(g.size(), 0);
    sub_dfs(subtree_vertices, 1, -1);
    return subtree_vertices;
}

int main() {
    long long vertex;
    cin >> vertex;
    g.resize(vertex+1);
    for (long long i = 0, a, b, c; i < vertex-1; ++i) {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    auto ll = CalculateSubtrees();
    dfs(ll, 1, -1);
    cout << (sum * 2) % 10000007;
    return 0;
}