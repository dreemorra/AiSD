#include <iostream>
#include <vector>

using namespace std;
long long MAX = 100000000000001;
vector <vector<pair<long long,long long>>> g;

long long dijkstra(long long n, long long start, long long fin) {
    vector<bool> used(n);
    vector<long long> dest(n, MAX);

    dest[start] = 0;
    for (long long i = 0; i < n; ++i) {
		long long curr_v = -42;
		for (long long j = 0; j < n; ++j)
			if ((curr_v == -42 or dest[j] < dest[curr_v]) and !used[j])
				curr_v = j;
		
        if (dest[curr_v] == MAX)
			break;
		used[curr_v] = true;

		for (long long k = 0; k < g[curr_v].size(); ++k) {
			long long to_v = g[curr_v][k].first, edge_len = g[curr_v][k].second;
			if (dest[curr_v] + edge_len < dest[to_v])
				dest[to_v] = dest[curr_v] + edge_len;
		}
    }
    return dest[fin];
}

int main() {
    long long vertex, edges, start_v, fin_v;
    cin >> vertex;
    cin >> edges;
    g.resize(vertex+1);
    for (long long i = 0, a, b, c; i < edges; ++i) {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }

    cin >> start_v;
    cin >> fin_v;
    cout << dijkstra(vertex+1, start_v, fin_v);
    return 0;
}