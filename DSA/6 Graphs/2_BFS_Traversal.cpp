#include <bits/stdc++.h>
using namespace std;

class Solution {

  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool *visited = new bool[V];
        for(int i=0; i<V; i++) {
            visited[i] = false;
        }
    
        list<int> queue;
        int s=0;
        vector<int> v;
        
        visited[s] = true;
        queue.push_back(s);
        // v.push_back(s);
        
        list<int>::iterator i;
    
        while(!queue.empty()) {
    
            s = queue.front();
            // cout << s << " ";
            v.push_back(s);
            queue.pop_front();
    
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        
        return v;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 