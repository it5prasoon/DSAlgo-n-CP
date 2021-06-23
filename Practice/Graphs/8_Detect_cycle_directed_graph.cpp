#include <iostream>
#include <vector>
    
int main() {
    int V, E;
    int x, y, w;
    std::cin >> V >> E;
    std::vector <std::vector <std::pair <int, int> > > graph_directed(V);
    std::vector <std::vector <std::pair <int, int> > > graph_undirected(V);
    
    for(int i = 0; i < E; i++) {
        std::cin >> x >> y >> w;
        graph_directed[x].push_back({y, w});	// adding a single edge in directed
    
        graph_undirected[x].push_back({y, w});
        graph_undirected[y].push_back({x, w});	// adding both the edges in undirected
    }
    
    // Printing graph (showing only undirected but the code is same for both)
    for(int i = 0; i < graph_undirected.size(); i++) {
        std::cout << i << ": ";
        for(int j = 0; j < graph_undirected[i].size(); j++)
            std::cout << "{" << graph_undirected[i][j].first << ", " << graph_undirected[i][j].second << "} ";
        std::cout << std::endl;
    }
    return 0;
}