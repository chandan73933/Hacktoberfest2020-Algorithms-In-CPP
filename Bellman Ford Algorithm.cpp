#include<iostream>
#include<vector>
#include<map>

using namespace std;

#define inf 1e9
#define NIL -1

struct Graph{
    int vertices;
    vector<vector<int>> adj;
    map<pair<int, int>, int> edges;
    bool directed;

    Graph(int size, bool isDirected);

    void add_edge(int u, int v, int w){
        edges[make_pair(u, v)] = w;
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
            edges[make_pair(v, u)] = w;
        }
    }
};


Graph::Graph(int size, bool isDirected=true){
    /***
     * Creates a graph of the given size(0-(size-1)).
     * 
     * @param size number of node of the graph.
     * @param isDirected boolean values true if graph is directed.
    */
    vertices = size;
    directed = isDirected;
    for(int i=0;i<size;i++){
        vector<int> v;
        adj.push_back(v);
    }
}

struct BFNode{
    int d;
    int parent;
};

void initialize_single_source(Graph &g, int source, vector<BFNode> &info){
    /***
     * Initialize the shortest-path estimates and predecessors by the 
     * following O(V)-time procedure. After initialization, we have 
     * v.π = NIL for all v ∈ V, s.d=0, and v.d = ∞ for v ∈ V - {s}.
     * 
     * @param g Graph.
     * @param source the source of the single source problem.
     * @param info BFNode type vector which store all the processing 
     *             information of the graph.
    */
    for(int i=0;i<g.vertices;i++){
        info[i].d=inf;
        info[i].parent=NIL;
    }
    info[source].d=0;
}

void relax(Graph &g, int u, int v, vector<BFNode> &info){
    /***
     * Performs a relaxation step on edge(u, v) in O(1) time.
     * 
     * @param g Graph.
     * @param u first node.
     * @param v second node.
     * @param info BFNode type vector which store all the processing 
     *             information of the graph.
    */
    if(info[v].d > info[u].d + g.edges[make_pair(u, v)]){
        info[v].d = info[u].d + g.edges[make_pair(u, v)];
        info[v].parent = u;
    }
}

bool bellmanFord(Graph &g, int source, vector<BFNode> &info){
    /***
     * The Bellman-Ford algorithm solves the single-source shortest-paths 
     * problem in the general case in which edge weights may be negative.
     * 
     * @param g Graph.
     * @param source the source of the single source problem.
     * @param info BFNode type vector which store all the processing 
     *             information of the graph.
     * 
     * @return returns TRUE if and only if the graph contains no negative-weight 
     *         cycles that are reachable from the source.
    */
   initialize_single_source(g, source, info);
    for(int i=0;i<g.vertices-1;i++){
        for(pair<pair<int, int>, int> edge : g.edges)
            relax(g, edge.first.first, edge.first.second, info);
    }
    for(pair<pair<int, int>, int> edge : g.edges)
        if(info[edge.first.second].d > info[edge.first.first].d + edge.second)
            return false;
    return true;

}

int main(){
    int size=5;
    Graph g = Graph(size);
    vector<BFNode> info(size);
    g.add_edge(0, 1, 6);
    g.add_edge(0, 2, 7);
    g.add_edge(1, 3, 5);
    g.add_edge(1, 4, -4);
    g.add_edge(1, 2, 8);
    g.add_edge(2, 3, -3);
    g.add_edge(2, 4, 9);
    g.add_edge(3, 1, -2);
    g.add_edge(4, 3, 7);
    g.add_edge(4, 0, 2);

    cout<<bellmanFord(g, 0, info)<<endl;
    for(int i=0;i<info.size();i++)
        cout<<i<<"::"<<info[i].d<<endl;
    
    int target=1;
    vector<int> path;
    while (target!=NIL){
        path.push_back(target);
        target=info[target].parent;
    }
    
    for(int i=path.size()-1;i>0;i--)
        cout<<path[i]<<"->";
    cout<<path.front()<<endl;
    
    return 0;
}
