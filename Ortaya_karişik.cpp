Soru 1 (10p) – Min-Heap Trace (Insert + DeleteMin)

Boş bir Min-Heap’e sırayla ekle: 12, 4, 18, 2, 9, 7

Son heap’in array gösterimini yaz.

1 kez DeleteMin sonrası array’i yaz.

Cevap

Insert sonrası: [2, 4, 7, 12, 9, 18]

DeleteMin sonrası: min=2 silinir → [4, 9, 7, 12, 18]

Soru 2 (10p) – Heap Kod (DecreseKey)

Min-Heap a[1..n] dizisiyle tutuluyor. decreaseKey(i,newVal) yaz (newVal daha küçük).

void decreaseKey(int a[], int n, int i, int newVal) {
    // TODO
}


Cevap

void decreaseKey(int a[], int n, int i, int newVal) {
    if (i < 1 || i > n) return;
    a[i] = newVal;
    int hole = i;
    int x = a[hole];

    while (hole > 1 && x < a[hole/2]) {
        a[hole] = a[hole/2];
        hole /= 2;
    }
    a[hole] = x;
}

Soru 3 (10p) – Hash (Linear Probing) Tablo Doldurma

M=11, h(x)=x%11, Linear Probing.
Sırayla ekle: 22, 33, 44, 12, 1
Tablonun son halini (index→değer) yaz.

Cevap

22→0, 33→0 dolu→1, 44→0 dolu→1 dolu→2, 12→1 dolu→2 dolu→3, 1→1 dolu→2 dolu→3 dolu→4
Son tablo:

0:22, 1:33, 2:44, 3:12, 4:1, diğerleri boş

Soru 4 (10p) – Hash Silme Tuzağı (DELETED)

Open addressing kullanan tabloda silinen hücreyi boş (-1) yapmak neden hatalıdır?
1–2 cümleyle açıklayın ve küçük örnek verin.

Cevap
Linear probing’de arama, “boş hücre görünce durur”. Silinen hücreyi -1 yapmak, zinciri kırar ve arkadaki elemanlar “yok” sanılır.
Örn: 22(0), 33(1), 44(2). 33’ü -1 yaparsan 44 araması 0→1(-1 görür) durur ve 44 bulunamaz. Çözüm: -2 (DELETED) ile işaretlemek.

Soru 5 (10p) – BFS Traversal (Çıktı)

Yönsüz graf, başlangıç 0, komşular küçükten büyüğe:
Kenarlar: 0-1, 0-2, 1-3, 1-4, 2-5, 4-6, 5-7
BFS sırasını yaz.

Cevap
0 1 2 3 4 5 6 7

Soru 6 (10p) – DFS Traversal (Çıktı)

Aynı graf için DFS (recursive) sırasını yaz.

Cevap
0 1 3 4 6 2 5 7

Soru 7 (10p) – Dijkstra Mesafe (Çıktı)

Ağırlıklı yönlü graf (negatif yok), src=0:
0->1(2), 0->2(6), 1->2(1), 1->3(5), 2->3(2), 3->4(1), 2->4(7)
dist[0..4]?

Cevap
[0, 2, 3, 5, 6]

Soru 8 (10p) – Topological Sort (Çıktı / Kahn)

DAG, düğümler 0..5
Kenarlar: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
Kahn ile topo sıra bulun. (Indegree=0 olanları kuyruğa küçükten büyüğe ekle)

Cevap
4 5 0 2 3 1

Soru 9 (10p) – Hibrit Soru: Graf Üzerinde “En Kısa Yol” ve Heap Kullanımı

Ağırlıksız graf için en kısa yol BFS ile bulunur. Peki ağırlıklı (negatifsiz) graf için neden Dijkstra’da min-heap (priority_queue) kullanılır?
2–3 cümleyle açıklayın.

Cevap
Dijkstra’da her adımda “şu an bilinen en küçük mesafeli düğümü” seçmek gerekir. Min-heap bu seçimi hızlı yapar: her extract-min O(log V), relax sonrası push O(log V). Böylece toplam maliyet tipik olarak O((V+E) log V) olur.

Soru 10 (10p) – Kaliteli Kod: Dijkstra (Hedefe Kadar)

adj[u] = {v,w} (yönlü), src’den dst’ye en kısa mesafeyi döndür. Ulaşılamazsa -1.

#include <bits/stdc++.h>
using namespace std;

long long shortestDist(int n, vector<vector<pair<int,int>>>& adj, int src, int dst) {
    // TODO
}


Cevap

long long shortestDist(int n, vector<vector<pair<int,int>>>& adj, int src, int dst) {
    const long long INF = (1LL<<60);
    vector<long long> dist(n, INF);

    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (u == dst) return dist[u];

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}