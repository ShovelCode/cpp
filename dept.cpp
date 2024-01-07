#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>

typedef std :: vector < std :: vector < int > > List;

void shortestPath(const List& adj, std :: vector < int >& nodeCosts, int node){
    std :: bitset < 301 > flag;

    nodeCosts[node] = 0;

    for(int i = 0 ; i < adj.size() - 1 ; i++) {
        int min = 0x7FFFFFFF;
        int idx;

        for(int j = 0 ; j < adj.size() ; j++) {
            if(nodeCosts[j] <= min && !flag[j]){
                min = nodeCosts[j];
                idx = j;
            }
        }

        flag[idx] = true;

        //std :: cerr << idx << '\n';

        for(int j = 0 ; j < adj.size() ; j++) {
            //std :: cerr << std :: boolalpha;
            //std :: cerr << idx << ' ' << !flag[j] << ' ' << adj[idx][j] << ' ';
            //std :: cerr << nodeCosts[idx] << ' ' << nodeCosts[idx] + adj[idx][j] << ' ' << nodeCosts[j] << '\n';
            if(!flag[j] && adj[idx][j] &&
            nodeCosts[idx] != 0x7FFFFFFF &&
            nodeCosts[idx] + adj[idx][j] < nodeCosts[j]) {
                //std :: cerr << "init\n";
                nodeCosts[j] = nodeCosts[idx] + adj[idx][j];
            }
        }
    }
}

int main() {
    int n;
    int e;

    std :: cin >> n >> e;

    List adj(n , std :: vector <int>(n, 0));
    List costs(n , std :: vector <int>(n, 0x7FFFFFFF));

    while(e--) {
        int u , v , c;
        std :: cin >> u >> v >> c;

        if(adj[u][v] == 0) adj[u][v] = c;
        if(adj[v][u] == 0) adj[v][u] = c;
        adj[u][v] = std :: min(adj[u][v] , c);
        adj[v][u] = std :: min(adj[v][u] , c);
    }

    for(int i = 0 ; i < n ; i++)
        shortestPath(adj , costs[i] , i);

    int64_t sum = 0;
    std :: cin >> e;

    while(e--) {
        int u , v;
        std :: cin >> u >> v;

        if(costs[u][v] == 0x7FFFFFFF) continue;

        //std :: cerr << u << ' ' << v << ' ' << costs[u][v] << '\n';

        sum += costs[u][v];
    }

    std :: cout << sum << '\n';
}
