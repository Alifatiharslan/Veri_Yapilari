SHORT ANSWERS
S1) Directed graph: 5 vertex, 7 edge; 1 loop; no multiple edges
Soru

Beş düğümlü ve yedi kenarlı yönlü bir graf çiz. Kenarlardan tam olarak biri loop olsun, multiple edge olmasın.

Cevap

Örnek çözüm:

Düğümler: 0,1,2,3,4

Kenarlar (7 adet, 1 loop):

0→1, 1→2, 2→3, 3→4, 4→0, 0→2, 3→3 (loop)

C++ Kodu
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V = {0,1,2,3,4};
    vector<pair<int,int>> E = {
        {0,1},{1,2},{2,3},{3,4},{4,0},{0,2},{3,3} // loop: 3->3
    };

    cout << "Vertices: ";
    for (int v: V) cout << v << " ";
    cout << "\nEdges:\n";
    for (auto [u,v]: E) cout << u << " -> " << v << "\n";
    return 0;
}

S2) Undirected graph: 4 vertex, 5 edge; path length 3 from v1 to v4
Soru

Dört düğüm (v1,v2,v3,v4) ve beş kenarlı yönsüz graf çiz; v1’den v4’e uzunluğu 3 olan bir yol olsun; bu yolun üstünü işaretle.

Cevap

Örnek çözüm (yönsüz):

Kenarlar: v1—v2, v2—v3, v3—v4 (bu yol uzunluk 3), ek olarak v1—v3 ve v2—v4

C++ Kodu
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> V = {"v1","v2","v3","v4"};
    vector<pair<string,string>> E = {
        {"v1","v2"}, {"v2","v3"}, {"v3","v4"}, {"v1","v3"}, {"v2","v4"}
    };

    cout << "Vertices: ";
    for (auto &v: V) cout << v << " ";
    cout << "\nUndirected edges:\n";
    for (auto &e: E) cout << e.first << " -- " << e.second << "\n";

    cout << "\nPath length 3 (marked): v1 ~~~ v2 ~~~ v3 ~~~ v4\n";
    return 0;
}

S3) Draw directed graph from adjacency matrix
Soru

Verilen adjacency matrix’in karşılığı olan yönlü grafı çiz.

Cevap

true olan her hücre (i,j) için kenar i→j vardır.

Kenarlar:

0→0, 0→2

1→0

2→3

3→0, 3→2

C++ Kodu
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> M = {
        {true,  false, true,  false},
        {true,  false, false, false},
        {false, false, false, true },
        {true,  false, true,  false}
    };

    int n = (int)M.size();
    cout << "Edges (i -> j where M[i][j] = true):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (M[i][j])
                cout << i << " -> " << j << "\n";
    return 0;
}

S4) Draw edge lists for the graph in previous question
Soru

Bir önceki sorudaki grafın edge list’lerini çiz.

Cevap

Outgoing edge list:

0: [0,2]

1: [0]

2: [3]

3: [0,2]

C++ Kodu
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> M = {
        {true,  false, true,  false},
        {true,  false, false, false},
        {false, false, false, true },
        {true,  false, true,  false}
    };

    int n = (int)M.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (M[i][j]) adj[i].push_back(j);

    cout << "Edge lists (outgoing):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
    return 0;
}

S5) Benefits of external iterator vs internal iterator
Soru

External iterator kullanmanın internal iterator’a göre avantajları nelerdir?

Cevap

Dolaşım kontrolü kullanıcıdadır (pause/continue/early exit).

Aynı yapı üzerinde birden fazla eşzamanlı dolaşım yapılabilir.

Filtreleme, kısmi traversal, adım adım debug daha kolaydır.

Callback zorunluluğu yoktur; traversal state’i iterator objesinde tutulur.

C++ Kodu (external iterator örneği)
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to; };

class Graph {
public:
    explicit Graph(int n): adj(n) {}
    void add_edge(int u, int v) { adj[u].push_back({v}); }
    const vector<Edge>& neighbors(int u) const { return adj[u]; }
private:
    vector<vector<Edge>> adj;
};

class NeighborIterator {
public:
    NeighborIterator(const Graph& g, int u) : g(g), u(u), idx(0) {}
    bool has_next() const { return idx < g.neighbors(u).size(); }
    Edge next() { return g.neighbors(u)[idx++]; }
    void reset() { idx = 0; }
private:
    const Graph& g;
    int u;
    size_t idx;
};

int main() {
    Graph g(4);
    g.add_edge(0,2);
    g.add_edge(0,0); // loop
    g.add_edge(1,0);

    NeighborIterator it(g, 0);
    cout << "Manually iterating neighbors of 0:\n";
    while (it.has_next()) {
        auto e = it.next();
        cout << "0 -> " << e.to << "\n";
        // user can break/continue/skip here freely
    }
    return 0;
}

S6) Modify Dijkstra to determine reachability from one vertex to all others
Soru

Dijkstra, verilen bir düğümden tüm diğer düğümlere gidilebiliyor mu kontrolü için nasıl değiştirilir?

Cevap

Dijkstra çalıştırılır; sonuçta herhangi bir düğüm için dist[v] = INF kalıyorsa ulaşılmaz → “tüm düğümlere gidilemez”. Hepsi sonluysa gidilebilir.

C++ Kodu
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to; int w; };

vector<long long> dijkstra(const vector<vector<Edge>>& adj, int s) {
    const long long INF = (1LL<<60);
    int n = (int)adj.size();
    vector<long long> dist(n, INF);
    dist[s] = 0;

    using P = pair<long long,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : adj[u]) {
            if (e.w < 0) throw runtime_error("Negative weight not allowed in Dijkstra");
            long long nd = d + e.w;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<Edge>> adj(n);
    auto add = [&](int u, int v, int w){ adj[u].push_back({v,w}); };

    add(0,1,2); add(1,2,3); add(2,3,1); add(0,4,10); // directed

    int s = 0;
    auto dist = dijkstra(adj, s);

    bool ok = true;
    const long long INF = (1LL<<60);
    for (int i = 0; i < n; ++i) if (dist[i] >= INF/2) ok = false;

    cout << "Reach all from " << s << "? " << (ok ? "YES" : "NO") << "\n";
    return 0;
}

S7) In Dijkstra, how choose the next vertex to process?
Soru

Dijkstra’da sıradaki düğüm seçimi hangi teknikle yapılır?

Cevap

Henüz kesinleşmemiş düğümler arasından geçici mesafesi (tentative distance) en küçük olan düğüm seçilir; pratikte min-heap (priority_queue with greater) kullanılır.

C++ Kodu (seçim mekanizmasını gösteren minimal örnek)
#include <bits/stdc++.h>
using namespace std;

int main() {
    // (distance, vertex) -> min-heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({10, 3});
    pq.push({2,  1});
    pq.push({7,  2});

    auto [d, v] = pq.top(); pq.pop();
    cout << "Next vertex chosen by smallest tentative distance: v=" << v << " dist=" << d << "\n";
    return 0;
}

S8) DFS and BFS order starting at v0 (given graph)
Soru

Verilen graf için v0’dan başlayan DFS ve BFS ziyaret sırası nedir?

Cevap

Komşu işleme sırasını “artan numara” varsayımıyla:

DFS: v0, v1, v3, v5, v6, v4

BFS: v0, v1, v4, v3, v5, v6

C++ Kodu (grafı adjacency list olarak kurup DFS/BFS çıktısı alan)
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int s) {
    int n = (int)adj.size();
    vector<char> vis(n,false);
    queue<int> q;
    vector<int> order;

    vis[s]=true; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(int v: adj[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
    return order;
}

void dfs_rec(int u, const vector<vector<int>>& adj, vector<char>& vis, vector<int>& order){
    vis[u]=true;
    order.push_back(u);
    for(int v: adj[u]){
        if(!vis[v]) dfs_rec(v, adj, vis, order);
    }
}

vector<int> dfs(const vector<vector<int>>& adj, int s){
    int n=(int)adj.size();
    vector<char> vis(n,false);
    vector<int> order;
    dfs_rec(s, adj, vis, order);
    return order;
}

int main() {
    // We'll map v0..v6 => 0..6
    int n = 7;
    vector<vector<int>> adj(n);

    auto add = [&](int u, int v){
        adj[u].push_back(v);
    };

    // Based on the picture interpretation:
    // v0 -> v1, v0 -> v4
    // v1 -> v3
    // v3 -> v5
    // v3 -> v6
    // (Edges like v2->v0 are not reachable from v0, but we can add anyway.)
    add(0,1);
    add(0,4);
    add(1,3);
    add(3,5);
    add(3,6);
    add(2,0); // from picture: v2 -> v0

    // Sort neighbors ascending to match assumption
    for (auto &lst : adj) sort(lst.begin(), lst.end());

    auto d1 = dfs(adj, 0);
    auto b1 = bfs(adj, 0);

    cout << "DFS from v0: ";
    for(int x: d1) cout << "v" << x << " ";
    cout << "\nBFS from v0: ";
    for(int x: b1) cout << "v" << x << " ";
    cout << "\n";
    return 0;
}

MULTIPLE CHOICE

Aşağıda her MC sorusu için: Soru + doğru şık + kısa gerekçe + küçük C++ kod (uygunsa).
(Bazıları teorik; kod kısmında “hesap” olanları kodla gösterdim.)

MC1) Which statement is true?
Soru

Hangisi doğrudur?
A) Graf tek şekilde çizilir
B) Düğümler herhangi bir biçimde bağlanabilir
C) Graf en az bir düğüm içerir
D) Graf en az bir kenar içerir

Cevap

✅ C

C++ Kodu (trivial kontrol – konsept)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int vertexCount = 0;
    cout << "Graph valid? " << (vertexCount >= 1 ? "YES" : "NO") << "\n";
}

MC2) 5 coin state graph vertex count?
Soru

5 bozuk para; her biri H/T. State graph kaç vertex?
A 7, B 10, C 25, D 32

Cevap

✅ D (32) çünkü
2
5
2
5

C++ Kodu
#include <bits/stdc++.h>
using namespace std;
int main() {
    int coins = 5;
    cout << (1 << coins) << "\n"; // 2^5 = 32
}

MC3) Why tic-tac-toe state graph is directed?
Soru

Tic-tac-toe neden directed?
A hamle geri alınamaz
B vertex sayısı tek
C edge sayısı tek
D oyuncu sayısı 1’den fazla

Cevap

✅ A

C++ Kodu (concept)
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Moves create irreversible state transitions => directed edges.\n";
}

MC4) Simple graph: no loops. Other property?
Soru

Simple graph loop içermez. Başka hangi özellik?
A directed, B undirected, C at least one vertex, D no multiple edges

Cevap

✅ D

C++ Kodu (concept)
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Simple graph: no loops and no multiple edges.\n";
}

MC5) Airline flights directed graph: best connections algorithm?
Soru

Uçuş bağlantılarında en iyi connection sırası?
A BFS, B DFS, C cycle-finding, D shortest-path

Cevap

✅ D (shortest path)

C++ Kodu (Dijkstra çağrısı konsepti)
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Use shortest-path algorithm (e.g., Dijkstra) for best connections.\n";
}

MC6) Directed graph 20 vertices: adjacency matrix booleans?
Soru

20 düğüm directed graph adjacency matrix kaç boolean?
A 20, B 40, C 200, D 400

Cevap

✅ D (400) çünkü 20×20

C++ Kodu
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=20;
    cout << n*n << "\n";
}

MC7) Edge list representation: how many linked lists?
Soru

n düğüm, m edge; edge list representation kaç linked list?
A m, B n, C m+n, D m*n

Cevap

✅ B (n) (genelde her düğüm için bir liste)

C++ Kodu (allocate n lists)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=5;
    vector<vector<int>> edgeLists(n);
    cout << "Lists: " << edgeLists.size() << "\n";
}

MC8) Loops in edge-list representation?
Soru

Loop edge list’te nasıl gösterilir?
A vertex kendi listesinde görünür
B liste circular olur
C liste boş olur
D liste dolu olur

Cevap

✅ A (u->u, u’nun listesinde u)

C++ Kodu
#include <bits/stdc++.h>
using namespace std;
int main() {
    int u=3;
    vector<vector<int>> adj(5);
    adj[u].push_back(u); // loop
    cout << "Loop stored as " << u << " in adjacency list of " << u << "\n";
}

MC9) Most efficient representation to test existence of an edge?
Soru

Bir edge var mı yok mu en hızlı?
A adjacency matrix, B edge lists

Cevap

✅ A (O(1) lookup)

C++ Kodu
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<bool>> M(5, vector<bool>(5,false));
    M[1][4] = true;
    cout << (M[1][4] ? "Edge exists\n" : "No edge\n");
}

MC10) Operations to loop through all edges terminating at a vertex with adjacency matrix?
Soru

Adjacency matrix ile belirli vertex’te sonlanan edge’leri dolaşmak kaç işlem?
A O(m), B O(n), C O(m^2), D O(n^2)

Cevap

✅ B (O(n)) çünkü bir sütunu (ya da satırı) tamamen tararsın.

C++ Kodu
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=1000;
    // Incoming edges to v: scan column v across all rows => n checks
    cout << "Incoming edge scan cost ~ O(n) = " << n << " checks\n";
}

MC11) Which traversal uses a queue?
Soru

Queue kullanan traversal hangisi?
A BFS, B DFS

Cevap

✅ A (BFS)

C++ Kodu (BFS queue)
#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    q.push(0);
    cout << "BFS uses queue.\n";
}
