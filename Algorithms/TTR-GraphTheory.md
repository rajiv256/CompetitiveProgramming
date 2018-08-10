1. Matching is a set of edges which doesn't have a common vertex.
2. A Maximal matching is a matching which stops being a matching by adding one more edge.
3. A vertex cover is the set of vertices which cover all the edges.
4. A Minimum vertex cover is the smallest vertex cover.
5. According to Konig's theorem, Maximal matching in a graph is equal to Minimum vertex cover.
6. Maxflow = Min cut (Maxflow Min cut theorem)
7. Alternating path : A path that starts from an unmatched vertex and alternates btw matched and unmatched edges.
8. Augmented Path : An alternating path that ends at an unmatched vertex.
9. Cut : A cut is just a partition of vertices into two disjoint subsets.
10. Cut set : Suppose _S_ and _T_ are the two disjoint partitions of a cut **C**. Then the edges that originate from a vertex in S and end at a vertex in T is called the **cut-set** of the Cut and the cut is defined by its Cut-Set more often.
11. The weight of the cut is the sum of weights of the edges in the **cut-set**.
12. A cut is a **min-cut** if the weight of the cut is no larger than the weight of any other cut.
13. Minimum-k-cut is the cut which divides the graph into atleast k-connected components by removing as many few edges as possible.
This can be solved using Stoer-Wagner algorithm.
14. 
