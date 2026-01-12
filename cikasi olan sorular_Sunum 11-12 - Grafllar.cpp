Soru 1 (10p) – BFS Traversal (Çıktı Sorusu)

Aşağıdaki yönsüz graf için BFS dolaşım sırasını yazınız.
Başlangıç: 0 — Komşular küçükten büyüğe işlenecek.

Kenarlar:
0-1, 0-2, 1-3, 1-4, 2-5, 4-6, 5-7

Cevap:
BFS: 0 1 2 3 4 5 6 7

Soru 2 (10p) – DFS Traversal (Çıktı Sorusu)

Aynı graf için DFS (recursive) dolaşım sırasını yazınız.
Başlangıç: 0 — Komşular küçükten büyüğe.

Cevap:
DFS: 0 1 3 4 6 2 5 7

Soru 3 (10p) – BFS ile En Kısa Yol (Path Çıktısı)

Yönsüz, ağırlıksız graf:
Kenarlar: 0-1, 0-2, 1-3, 2-3, 3-4, 4-5
src=0, dst=5. BFS ile bulunan en kısa yol (düğüm listesi) nedir?
Komşular küçükten büyüğe.

Cevap:
En kısa yol: 0 1 3 4 5
(Not: 0-2-3-4-5 de aynı uzunlukta; ama komşu sırası nedeniyle BFS parent zinciri 1 üzerinden gelir.)

Soru 4 (10p) – DFS ile Connected Components Sayısı (Çıkabilir)

Yönsüz graf, düğümler 0..7
Kenarlar: 0-1, 1-2, 3-4, 5-6
Kaç tane connected component vardır?

Cevap:
Bileşenler: {0,1,2}, {3,4}, {5,6}, {7} → 4 bileşen

Soru 5 (10p) – Directed Cycle Var mı? (Çıktı + Mantık)

Yönlü graf, düğümler 0..4
Kenarlar: 0->1, 1->2, 2->3, 3->1, 3->4
Bu graf döngü içeriyor mu?

Cevap:
Evet. Döngü: 1 -> 2 -> 3 -> 1

Soru 6 (10p) – Topological Sort (Çıktı Sorusu)

Yönlü graf (DAG), düğümler 0..5
Kenarlar: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
Kahn (indegree) algoritmasıyla topolojik sıra bulunuz.
Kuyruğa indegree=0 gelenleri küçükten büyüğe ekleyiniz.

Cevap (bir geçerli sıra):
İndegree=0 başlangıç: 4,5 (küçükten büyüğe)
Sıra: 4 5 0 2 3 1
(Not: Topo sort tek değildir; ama bu kural setinde bu sıra çıkar.)

Soru 7 (10p) – Dijkstra Mesafeleri (Çıkabilir ve Net)

Ağırlıklı yönlü graf, 0..4, negatif yok.
Kenarlar:
0->1(2), 0->2(6), 1->2(1), 1->3(5), 2->3(2), 3->4(1), 2->4(7)
src=0 için dist[0..4] değerlerini yazınız.

Cevap:

dist[0]=0

dist[1]=2

dist[2]=3 (0->1->2 = 2+1)

dist[3]=5 (0->1->2->3 = 2+1+2)

dist[4]=6 (0->1->2->3->4 = 2+1+2+1)

Sonuç: [0, 2, 3, 5, 6]

Soru 8 (10p) – Bipartite (2-Renk) Kontrol (Çıktı Sorusu)

Yönsüz graf, düğümler 0..5
Kenarlar: 0-1, 1-2, 2-3, 3-0, 3-4, 4-5
Graf bipartite mı?

Cevap:
0-1-2-3-0 bir çift uzunluklu cycle (4) → bipartite olmayı bozmaz.
Uygun renkleme var → Evet, bipartite.
Örnek: A={0,2,4} B={1,3,5}

Soru 9 (10p) – BFS Kod Tamamlama (Çıkabilir Kod)

Aşağıdaki fonksiyon, start’tan ulaşılabilen düğüm sayısını döndürecek. Eksik yeri tamamlayınız.

int reachableCount(int n, vector<vector<int>>& adj, int start) {
    vector<int> vis(n, 0);
    queue<int> q;
    int cnt = 0;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;

        for (int v : adj[u]) {
            // TODO
        }
    }
    return cnt;
}


Cevap (eksik kısım):

if (!vis[v]) {
    vis[v] = 1;
    q.push(v);
}

Soru 10 (10p) – Directed Cycle Kod (State=0/1/2) (Çıkabilir Kod)

Yönlü graf için cycle kontrolü yapan DFS fonksiyonunu tamamlayınız.
state: 0=unvisited, 1=visiting, 2=done

bool dfsCycleDir(int u, vector<vector<int>>& adj, vector<int>& state) {
    state[u] = 1; // visiting
    for (int v : adj[u]) {
        // TODO
    }
    state[u] = 2; // done
    return false;
}


Cevap (eksik kısım):

if (state[v] == 0) {
    if (dfsCycleDir(v, adj, state)) return true;
} else if (state[v] == 1) {
    return true; // back-edge
}