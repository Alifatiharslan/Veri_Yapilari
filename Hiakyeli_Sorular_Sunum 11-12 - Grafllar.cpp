Soru 1 (20p) – Kampüs Haritası: BFS ile En Az Adım

Kampüste binalar düğüm, yollar kenar. Graf yönsüz ve ağırlıksız.
start binasından tüm binalara en az kaç adım ile gidildiğini bulan BFS kodunu yazınız. Ulaşılamayanlara -1 yazınız.

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsDist(int n, vector<vector<int>>& adj, int start) {
    // TODO
}

Cevap
vector<int> bfsDist(int n, vector<vector<int>>& adj, int start) {
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

Soru 2 (20p) – Labirent Güvenliği: DFS ile Döngü Tespiti (Undirected)

Bir bina içi geçiş ağı yönsüz. Güvenlik ekibi, geçiş ağında döngü olup olmadığını kontrol edecek.
Aşağıdaki fonksiyonları DFS ile tamamlayınız.

bool dfsCycle(int u, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    // TODO
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    // TODO
}

Cevap
bool dfsCycle(int u, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfsCycle(v, u, adj, vis)) return true;
        } else if (v != parent) {
            return true; // visited ve parent değil => cycle
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsCycle(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

Soru 3 (20p) – Ders Önkoşulları: Topological Sort (Kahn / Indegree)

Dersler 0..n-1. u -> v demek “u bitmeden v alınamaz”.
DAG olduğu varsayımıyla topolojik sıralamayı bulunuz. Döngü varsa boş vektör döndürünüz.

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    // TODO
}

Cevap
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            indeg[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) return {}; // cycle
    return order;
}

Soru 4 (20p) – Kurye Rotası: Dijkstra ile En Kısa Yol (Weighted, Non-negative)

Kuryenin teslimat ağı yönlü/ağırlıklı olabilir, ağırlıklar negatif değildir.
src düğümünden tüm düğümlere en kısa mesafeyi bulunuz. Ulaşılamayanlar INF kalsın.

const long long INF = (1LL<<60);

vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    // adj[u] = {v, w}
    // TODO
}

Cevap
vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<long long> dist(n, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // stale

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

Soru 5 (20p) – İnternet Kablolama: MST Mantığı + Prim (Kod Tamamlama)

Üniversite binalarını en düşük toplam kablo maliyetiyle bağlamak istiyoruz (yönsüz, ağırlıklı).
Prim algoritmasıyla MST toplam ağırlığını döndüren fonksiyonu yazınız. Graf bağlı kabul ediniz.

long long primMST(int n, vector<vector<pair<int,int>>>& adj) {
    // TODO
}

Cevap
long long primMST(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> inMST(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // pq: {edgeWeight, node}

    long long total = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;

        inMST[u] = 1;
        total += w;

        for (auto [v, cost] : adj[u]) {
            if (!inMST[v]) pq.push({cost, v});
        }
    }
    return total;
}
