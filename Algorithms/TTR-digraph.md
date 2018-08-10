Directed graphs are everywhere to be seen. The internet is the biggest Digraph.

A DAG is a directed acyclic graph.

1. Graph Search
2. Transitive closure
3. Topological sort
4. Strongly connected components

- Graph search
    - A general DFS would do. But the graph may be disconnected and you might have to run a DFS loop.
- Transitive Closure
    - Floyd Warshall algorithm applies here to. At kth step it calculates if a path of maximum length k exists between any two pairs of vertices.
- Topological sort.
    - This is a bit tricky, but it only applicable for DAGs.
    - Regular DFS but we read the visited vertices in a post order way so that the parent vertex will always come before the children vertices.
- Cycle Detection
    - We use DFS here too. But We use two arrays for book keeping. One for noting down the visited vertices and the other to store the vertices in the recursion stack.
    - If a vertex in recursion stack appears again while DFS, then the graph contains a cycle.

- Karp's Minimum mean Cycle
    - To find the cycle with least minimum, when there are no negative cycles.
    - The value is `minV { maxK { (F(n,v)-F(k,v))/(n-k))}}`
    - Check in the problem for more.


- Strongly Connected Components
    - Read more about it in the notes above the solution in the code.
    - Strongly connected :- It is possible to reach from every node in that component to every other node.
    - First DFS the reverse graph, note the finish times of each vertex and then DFS the actual graph in descending order of finish times of each vertex.
