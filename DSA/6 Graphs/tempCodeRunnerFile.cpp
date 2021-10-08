bool *visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    // queue for BFS
    list<int> queue;

    // Mark current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()) {

        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }