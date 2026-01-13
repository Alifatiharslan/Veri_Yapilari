Tamam knk. PDF’deki **her soru için**: **Soru → Cevap → C++ Kodu** formatında aynısını yaptım. (Şekiller Figure D/E dâhil.)

---

# 1) Figure D

## 1A) Adjacency matrix \(A\)

### Soru
Figure D’deki graf için (uygun etiketlerle) adjacency matrix \(A\)’yı doldur.

### Cevap
Figure D’deki yönlü kenarlar (resimden okunur):
- Sol parça: \(1\to2,\; 1\to3,\; 2\to4,\; 3\to4,\; 3\to5\)
- Sağ parça (3’lü döngü): \(7\to6,\; 6\to8,\; 8\to7\)

Düğüm sırası: \(1,2,3,4,5,6,7,8\)

Adjacency matrix \(A\) (satır = from, sütun = to):

|   |1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|---|
|**1**|0|1|1|0|0|0|0|0|
|**2**|0|0|0|1|0|0|0|0|
|**3**|0|0|0|1|1|0|0|0|
|**4**|0|0|0|0|0|0|0|0|
|**5**|0|0|0|0|0|0|0|0|
|**6**|0|0|0|0|0|0|0|1|
|**7**|0|0|0|0|0|1|0|0|
|**8**|0|0|0|0|0|0|1|0|

### C++ Kodu
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 8;
    vector<vector<int>> A(N, vector<int>(N, 0));

    auto add = [&](int u, int v){ A[u-1][v-1] = 1; };

    // Figure D edges:
    add(1,2); add(1,3);
    add(2,4);
    add(3,4); add(3,5);
    add(7,6); add(6,8); add(8,7);

    cout << "Adjacency matrix A (vertices 1..8):\n   ";
    for(int j=1;j<=N;j++) cout << j << " ";
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << (i+1) << ": ";
        for(int j=0;j<N;j++) cout << A[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
1B) Transitive closure adjacency matrix (Floyd–Warshall)
Soru
Floyd–Warshall ile transitive closure (erişilebilirlik) grafını hesapla; çıkan grafın adjacency matrix’ini doldur.

Cevap
Transitive closure: Bir düğümden diğerine en az 1 kenarlı bir yol varsa 1 yazılır.

Erişilebilirlik:

1 → {2,3,4,5}

2 → {4}

3 → {4,5}

4 → {}

5 → {}

6 → {8,7,6} (çünkü 6→8→7→6 döngüsü var, kendine dönüş mümkün)

7 → {6,8,7}

8 → {7,6,8}

Düğüm sırası yine: 1..8

1	2	3	4	5	6	7	8
1	0	1	1	1	1	0	0	0
2	0	0	0	1	0	0	0	0
3	0	0	0	1	1	0	0	0
4	0	0	0	0	0	0	0	0
5	0	0	0	0	0	0	0	0
6	0	0	0	0	0	1	1	1
7	0	0	0	0	0	1	1	1
8	0	0	0	0	0	1	1	1

C++ Kodu (Floyd–Warshall transitive closure)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 8;
    vector<vector<int>> R(N, vector<int>(N, 0)); // reachability

    auto add = [&](int u, int v){ R[u-1][v-1] = 1; };

    // Figure D edges:
    add(1,2); add(1,3);
    add(2,4);
    add(3,4); add(3,5);
    add(7,6); add(6,8); add(8,7);

    // Floyd-Warshall for reachability
    for (int k=0;k<N;k++)
        for (int i=0;i<N;i++)
            if (R[i][k])
                for (int j=0;j<N;j++)
                    R[i][j] = R[i][j] || (R[i][k] && R[k][j]);

    cout << "Transitive closure reachability matrix (1..8):\n   ";
    for(int j=1;j<=N;j++) cout << j << " ";
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << (i+1) << ": ";
        for(int j=0;j<N;j++) cout << R[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
1C) 
𝐴
3
A 
3
  (adjacency matrix küpü)
Soru
Figure D’nin adjacency matrix’i 
𝐴
A olsun. 
𝐴
3
A 
3
 ’ü doldur.

Cevap
Standart matris çarpımıyla 
𝐴
3
[
𝑖
]
[
𝑗
]
A 
3
 [i][j], i’den j’ye uzunluğu 3 olan yürüyüş (walk) sayısını verir.

Bu graf için:

Sol parçada 3 adımlık yürüyüşler “bitiyor” (4 ve 5 çıkışsız), dolayısıyla 3 adımda yeni yerlere gidilemiyor.

Sağ parçada 3’lü döngü var: 6→8→7→6, 7→6→8→7, 8→7→6→8.
Bu yüzden 
𝐴
3
A 
3
 ’te sadece:

(6,6)=1, (7,7)=1, (8,8)=1
diğer tüm hücreler 0.

C++ Kodu (
𝐴
3
A 
3
  hesap)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 8;
    vector<vector<long long>> A(N, vector<long long>(N, 0));

    auto add = [&](int u, int v){ A[u-1][v-1] = 1; };

    // Figure D edges:
    add(1,2); add(1,3);
    add(2,4);
    add(3,4); add(3,5);
    add(7,6); add(6,8); add(8,7);

    auto mul = [&](const vector<vector<long long>>& X,
                   const vector<vector<long long>>& Y) {
        vector<vector<long long>> Z(N, vector<long long>(N, 0));
        for(int i=0;i<N;i++)
            for(int k=0;k<N;k++) if (X[i][k])
                for(int j=0;j<N;j++)
                    Z[i][j] += X[i][k] * Y[k][j];
        return Z;
    };

    auto A2 = mul(A,A);
    auto A3 = mul(A2,A);

    cout << "A^3 (vertices 1..8):\n   ";
    for(int j=1;j<=N;j++) cout << j << " ";
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << (i+1) << ": ";
        for(int j=0;j<N;j++) cout << A3[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
2) Figure E – Traversal Order
2A) Depth-first traversal (DFT), start A, neighbors in alphabetic order
Soru
Figure E’de, bir düğümün komşuları alfabetik sırayla gezilecek şekilde; başlangıç A iken DFT sırası nedir?

Cevap
Şekilden okunan (yönsüz) kenarlar:

A–B, B–C, C–F

A–D, D–G, D–E

A–E, E–G, E–H, E–I

H–I

Komşular alfabetik gezilirse DFS/DFT sırası:
A, B, C, F, D, E, G, H, I

C++ Kodu (DFS alfabetik)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

void dfs(const string& u,
         unordered_map<string, vector<string>>& adj,
         unordered_set<string>& vis,
         vector<string>& order) {
    vis.insert(u);
    order.push_back(u);
    for (auto &v : adj[u]) {
        if (!vis.count(v)) dfs(v, adj, vis, order);
    }
}

int main() {
    unordered_map<string, vector<string>> adj;
    auto addUnd = [&](string a, string b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    // Figure E edges:
    addUnd("A","B"); addUnd("B","C"); addUnd("C","F");
    addUnd("A","D"); addUnd("D","G"); addUnd("D","E");
    addUnd("A","E"); addUnd("E","G"); addUnd("E","H"); addUnd("E","I");
    addUnd("H","I");

    // sort neighbors alphabetically
    for (auto &kv : adj) sort(kv.second.begin(), kv.second.end());

    unordered_set<string> vis;
    vector<string> order;
    dfs("A", adj, vis, order);

    cout << "DFT/DFS order: ";
    for (auto &x: order) cout << x << " ";
    cout << "\n";
    return 0;
}
2B) Breadth-first traversal (BFT), start A, neighbors alphabetic order
Soru
Aynı koşullarla BFT/BFS sırası nedir?

Cevap
BFS (enqueue ederken alfabetik komşu sırası):
A, B, D, E, C, G, H, I, F

C++ Kodu (BFS alfabetik)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, vector<string>> adj;
    auto addUnd = [&](string a, string b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    addUnd("A","B"); addUnd("B","C"); addUnd("C","F");
    addUnd("A","D"); addUnd("D","G"); addUnd("D","E");
    addUnd("A","E"); addUnd("E","G"); addUnd("E","H"); addUnd("E","I");
    addUnd("H","I");

    for (auto &kv : adj) sort(kv.second.begin(), kv.second.end());

    queue<string> q;
    unordered_set<string> vis;
    vector<string> order;

    vis.insert("A");
    q.push("A");

    while(!q.empty()){
        string u=q.front(); q.pop();
        order.push_back(u);
        for (auto &v : adj[u]) {
            if(!vis.count(v)){
                vis.insert(v);
                q.push(v);
            }
        }
    }

    cout << "BFT/BFS order: ";
    for (auto &x: order) cout << x << " ";
    cout << "\n";
    return 0;
}
3) Incidence matrix → Adjacency matrix
3) Corresponding adjacency matrix + açıklama
Soru
Verilen incidence matrix’e karşılık gelen adjacency matrix’i yaz ve kısaca nasıl bulduğunu açıkla.

Cevap
Verilen incidence tablosunda her “edge” satırında yalnızca tek bir 1 var (başka sütunda 1 yok). Bu, klasik undirected incidence matrisindeki “iki uç” durumuna uymuyor; bu formatta en doğal yorum: her satır bir “loop” (self-edge) gösteriyor (edge yalnızca o vertex’e incident).

Satırlardan görülen loop’lar:

Vertex 1: b

Vertex 2: a, e → iki loop

Vertex 3: c

Vertex 4: d

Vertex 5: h

Vertex 6: yok

Vertex 7: f, i → iki loop

Adjacency matrix’i (count’lu) yazarsak diagonal:

𝐴
[
1
,
1
]
=
1
A[1,1]=1

𝐴
[
2
,
2
]
=
2
A[2,2]=2

𝐴
[
3
,
3
]
=
1
A[3,3]=1

𝐴
[
4
,
4
]
=
1
A[4,4]=1

𝐴
[
5
,
5
]
=
1
A[5,5]=1

𝐴
[
6
,
6
]
=
0
A[6,6]=0

𝐴
[
7
,
7
]
=
2
A[7,7]=2
Diğer tüm hücreler 0.

C++ Kodu (incidence → adjacency)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Vertices: 1..7
    // Incidence rows (edge -> which vertex has 1)
    // a->2, b->1, c->3, d->4, e->2, f->7, h->5, i->7
    vector<pair<char,int>> edges = {
        {'a',2},{'b',1},{'c',3},{'d',4},{'e',2},{'f',7},{'h',5},{'i',7}
    };

    const int N = 7;
    vector<vector<int>> A(N, vector<int>(N, 0));

    // Interpreting each edge row with a single 1 as a loop at that vertex
    for (auto [name, v] : edges) {
        A[v-1][v-1] += 1; // count loops
    }

    cout << "Adjacency matrix (counts), vertices 1..7:\n   ";
    for(int j=1;j<=N;j++) cout << j << " ";
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << (i+1) << ": ";
        for(int j=0;j<N;j++) cout << A[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
4) Warshall generalized (max travel time paths) + Big-O
4) Longest (maximum travel time) path all-pairs
Soru
Warshall’ın genelleştirilmiş ⊕ ve ⊗ operatörlü sürümüyle “maximum travel time path” all-pairs nasıl hesaplanır? Adjacency matrix’te ne veri olmalı, algoritmada ne değişmeli? Big-O nedir?

Cevap
Amaç: Her (j,p) çifti için “en uzun (max) toplam seyahat süresi” yolunu bulmak.

Adjacency matrix içeriği

Eğer 
𝑗
→
𝑝
j→p kenarı varsa: 
𝑃
[
𝑗
,
𝑝
]
=
𝑤
(
𝑗
,
𝑝
)
P[j,p]=w(j,p) (seyahat süresi)

Kenar yoksa: 
𝑃
[
𝑗
,
𝑝
]
=
−
∞
P[j,p]=−∞ (ulaşılmaz)

Diagonal için genelde: 
𝑃
[
𝑗
,
𝑗
]
=
0
P[j,j]=0 (boş yol)

Operatör seçimi

⊕
=
max
⁡
⊕=max

⊗
=
+
⊗=+

COND (koşul)

“P[j,k] ve P[k,p] ulaşılabilir mi?” kontrolü:

𝑃
[
𝑗
,
𝑘
]
>
−
∞
P[j,k]>−∞ ve 
𝑃
[
𝑘
,
𝑝
]
>
−
∞
P[k,p]>−∞

Update

𝑃
[
𝑗
,
𝑝
]
=
max
⁡
(
𝑃
[
𝑗
,
𝑝
]
,
  
𝑃
[
𝑗
,
𝑘
]
+
𝑃
[
𝑘
,
𝑝
]
)
P[j,p]=max(P[j,p],P[j,k]+P[k,p])

Big-O

Üçlü döngü: O(N³)

Not: Pozitif döngüler varsa “en uzun yol” teorik olarak sonsuza gidebilir. Sınav tipi soru genelde “cycle yok / problem uygun” varsayar.

C++ Kodu (All-pairs longest via Floyd-Warshall style)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long NEG_INF = -(1LL<<60);
    int N; 
    cin >> N; // number of vertices
    vector<vector<long long>> P(N, vector<long long>(N, NEG_INF));

    // init diagonal
    for(int i=0;i<N;i++) P[i][i] = 0;

    int M; 
    cin >> M; // edges
    for(int i=0;i<M;i++){
        int u,v; long long w;
        cin >> u >> v >> w; // 0-based u,v
        P[u][v] = max(P[u][v], w);
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            if (P[i][k] <= NEG_INF/2) continue;
            for(int j=0;j<N;j++){
                if (P[k][j] <= NEG_INF/2) continue;
                P[i][j] = max(P[i][j], P[i][k] + P[k][j]);
            }
        }
    }

    cout << "All-pairs maximum travel time matrix:\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (P[i][j] <= NEG_INF/2) cout << "X ";
            else cout << P[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
5) Directed graph representations + degrees (multi-list)
5A) Multi-list representation (edge name + distance, vertex name)
Soru
Bu özelliklerde directed graph işleyeceksin:
a) vertex name var
b) edge distance var
c) edge name var
Multi-list representation’ı (struct + diagram) detaylı anlat. Alan (space) maliyeti nedir?

Cevap
Multi-list (orthogonal list) fikri: Her edge tek kez saklanır ama hem “outgoing” hem “incoming” listelere bağlanır.

Vertex node:

name

firstOut (bu vertex’ten çıkan kenarların bağlı listesi)

firstIn (bu vertex’e giren kenarların bağlı listesi)

Edge node (tek kopya):

edgeName

distance

from, to pointer/indeks

nextOut (aynı from vertex’in bir sonraki outgoing edge’i)

nextIn (aynı to vertex’in bir sonraki incoming edge’i)

Space:

Vertexler: O(V)

Edgeler: O(E) (her edge tek node)
Toplam: O(V + E)

C++ Kodu (struct şablonu)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

struct EdgeNode;

struct VertexNode {
    string name;
    EdgeNode* firstOut = nullptr;
    EdgeNode* firstIn  = nullptr;
};

struct EdgeNode {
    string edgeName;
    int distance;

    VertexNode* from = nullptr;
    VertexNode* to   = nullptr;

    EdgeNode* nextOut = nullptr; // next edge with same "from"
    EdgeNode* nextIn  = nullptr; // next edge with same "to"
};
5B) Adjacency list representation + space
Soru
Aynı graf için adjacency list representation’ı anlat; space maliyeti nedir?

Cevap
Adjacency list: Her vertex için “outgoing edge list” tutulur. Her listedeki edge kaydı:

to (hedef vertex index/pointer)

edgeName

distance

Space:

Vertex head’leri: O(V)

Edge kayıtları: O(E)
Toplam: O(V + E)

C++ Kodu (adjacency list)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

struct EdgeRec {
    int to;
    string edgeName;
    int dist;
};

int main() {
    int V = 5;
    vector<string> vertexName = {"A","B","C","D","E"};
    vector<vector<EdgeRec>> adj(V);

    // Example add edge: u -> v
    adj[0].push_back({1, "e1", 12});
    adj[0].push_back({2, "e2", 5});
    return 0;
}
5C) Multi-list ile out-degree (vertex name input)
Soru
Part A’daki multi-list temsilini kullanarak: input graph + vertex name → output out-degree. Pseudo-code yaz.

Cevap
Algoritma:

Vertex’i adına göre bul (lineer arama ya da hash-map)

firstOut listesini dolaş, say

Time:

Vertex bulma O(V) (hash-map varsa O(1) ortalama)

Sayma O(outDegree)
Toplam: O(V + outDegree) ⊆ O(V+E)

C++ Kodu
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

struct EdgeNode;
struct VertexNode {
    string name;
    EdgeNode* firstOut=nullptr;
    EdgeNode* firstIn=nullptr;
};
struct EdgeNode {
    VertexNode* from=nullptr;
    VertexNode* to=nullptr;
    EdgeNode* nextOut=nullptr;
    EdgeNode* nextIn=nullptr;
};

int outDegree(VertexNode* v){
    int cnt=0;
    for (EdgeNode* e=v->firstOut; e!=nullptr; e=e->nextOut) cnt++;
    return cnt;
}

int main(){
    // Demo skeleton only: building omitted
    return 0;
}
5D) Multi-list ile in-degree (vertex name input) + complexity
Soru
Part A’yı kullanarak input graph + vertex name → in-degree hesapla. Complexity nedir?

Cevap
Vertex’i bul

firstIn listesini dolaş, say

Time: O(V + inDegree) ⊆ O(V+E)

C++ Kodu
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

struct EdgeNode;
struct VertexNode {
    string name;
    EdgeNode* firstOut=nullptr;
    EdgeNode* firstIn=nullptr;
};
struct EdgeNode {
    VertexNode* from=nullptr;
    VertexNode* to=nullptr;
    EdgeNode* nextOut=nullptr;
    EdgeNode* nextIn=nullptr;
};

int inDegree(VertexNode* v){
    int cnt=0;
    for (EdgeNode* e=v->firstIn; e!=nullptr; e=e->nextIn) cnt++;
    return cnt;
}

int main(){
    return 0;
}
6) Path finding using adjacency matrix
6) Find a single path between two different vertices (matrix)
Soru
Adjacency matrix verilen bir graf için, iki farklı vertex arasında bir path varsa tek bir path bul (pseudo-code).

Cevap
En standart çözüm: BFS + parent[]

BFS ile hedefe ulaşınca dur

parent ile yolu geri sar

Adjacency matrix ile komşu taraması: her düğüm için 
1..
𝑁
1..N sütun taranır.
Time: O(N²)

C++ Kodu (matrix BFS path)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];

    int s,t; cin >> s >> t; // 0-based
    vector<int> parent(N, -1);
    vector<char> vis(N,false);
    queue<int> q;

    vis[s]=true;
    q.push(s);

    while(!q.empty()){
        int u=q.front(); q.pop();
        if (u==t) break;
        for(int v=0; v<N; v++){
            if (A[u][v] && !vis[v]){
                vis[v]=true;
                parent[v]=u;
                q.push(v);
            }
        }
    }

    if(!vis[t]){
        cout << "No path\n";
        return 0;
    }

    vector<int> path;
    for(int cur=t; cur!=-1; cur=parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for(int x: path) cout << x << " ";
    cout << "\n";
    return 0;
}
7) Path finding using multi-list representation
7) Find a single path between two different vertices (multi-list)
Soru
Multi-list representation ile iki vertex arasında bir path varsa tek bir path bul (pseudo-code).

Cevap
Yine BFS/DFS yapılır; fark sadece komşu erişimi firstOut üzerinden olur.

BFS + parent ile tek path

Time: O(V + E) (çünkü her edge en fazla bir kez işlenir)

C++ Kodu (multi-list BFS path – iskelet)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

struct EdgeNode;
struct VertexNode {
    int id;
    string name;
    EdgeNode* firstOut=nullptr;
    EdgeNode* firstIn=nullptr;
};

struct EdgeNode {
    VertexNode* from=nullptr;
    VertexNode* to=nullptr;
    EdgeNode* nextOut=nullptr;
    EdgeNode* nextIn=nullptr;
};

vector<int> bfs_path(VertexNode* start, VertexNode* goal, vector<VertexNode*>& vertices){
    int n = (int)vertices.size();
    vector<int> parent(n, -1);
    vector<char> vis(n,false);
    queue<VertexNode*> q;

    vis[start->id]=true;
    q.push(start);

    while(!q.empty()){
        VertexNode* u=q.front(); q.pop();
        if (u==goal) break;

        for(EdgeNode* e=u->firstOut; e!=nullptr; e=e->nextOut){
            VertexNode* v = e->to;
            if(!vis[v->id]){
                vis[v->id]=true;
                parent[v->id]=u->id;
                q.push(v);
            }
        }
    }

    if(!vis[goal->id]) return {}; // empty => no path

    vector<int> path;
    for(int cur=goal->id; cur!=-1; cur=parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    // Build omitted (needs allocator + linking nextOut/nextIn).
    return 0;
}
8) Describe a multi-list data structure for storing a graph
8) Multi-list data structure
Soru
Bir grafı saklamak için multi-list veri yapısını anlat.

Cevap
Multi-list (orthogonal list) özeti:

Vertex node: name, firstOut, firstIn

Edge node (tek kopya): from, to, edgeName, distance, nextOut, nextIn

Outgoing traversal: vertex.firstOut üzerinden nextOut ile

Incoming traversal: vertex.firstIn üzerinden nextIn ile

Space: O(V+E)

C++ Kodu (özet struct)
cpp
Kodu kopyala
#include <bits/stdc++.h>
using namespace std;

struct EdgeNode;

struct VertexNode {
    string name;
    EdgeNode* firstOut = nullptr;
    EdgeNode* firstIn  = nullptr;
};

struct EdgeNode {
    string edgeName;
    int distance;
    VertexNode* from = nullptr;
    VertexNode* to   = nullptr;
    EdgeNode* nextOut = nullptr;
    EdgeNode* nextIn  = nullptr;
};
Kodu kopyala






