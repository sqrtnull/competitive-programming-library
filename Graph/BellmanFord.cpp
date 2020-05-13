using lnt = long long;
/* <BellmanFord> */

struct Graph
{
    struct Edge
    {
        int a,b; lnt c;
        Edge(int a, int b, lnt c) : a(a), b(b), c(c) {}
    };
    int size;
    std::vector<Edge> edges;
    Graph(int n) : size(n) {}
};

struct BellmanFord
{
    constexpr lnt INF = 2e18;
    std::vector<lnt> dist;
    std::vector<int> prev;
    bool closed_negative_loop = false;
    std::vector<bool> negative;
    BellmanFord(Graph graph, lnt s, lnt t) :
        dist(graph.size, INF),
        prev(graph.size, -1),
        negative(graph.size, false)
    {
        dist[s] = 0;
        for(int i=1; i<=graph.size; i++) {
            for(auto e: graph.edges) {
                if(dist[e.a] + e.c < dist[e.b]) {
                    if(i==graph.size) {
                        closed_negative_loop = true;
                    }
                    dist[e.b] = dist[e.a] + e.c;
                    prev[e.b] = e.a;
                }
            }
        }
        if(closed_negative_loop) {
            for(int i=1; i<=graph.size; i++) {
                for(auto e: graph.edges) {
                    if(dist[e.a] + e.c < dist[e.b]) {
                        negative[e.b] = true;
                        dist[e.b] = dist[e.a] + e.c;
                        prev[e.b] = e.a;
                    }
                    if(negative[e.a]) negative[e.b] = true;
                }
            }
        }
    }
};

/* <BellmanFord> */