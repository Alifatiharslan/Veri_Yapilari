1️⃣ Heap (Yığın Ağacı) Algoritmaları
🔹 Binary Heap (İkili Heap)

Amaç: Öncelikli işlemleri hızlı yapmak (Priority Queue).

Türler:

Min-Heap: Kök = en küçük

Max-Heap: Kök = en büyük

Yapı:

Complete Binary Tree (soldan sağa dolu)

Genelde dizi ile tutulur.

Dizi İlişkileri

Parent → (i-1)/2

Sol çocuk → 2i+1

Sağ çocuk → 2i+2

🔹 Heap’e Ekleme (Insert / Percolate Up)

Elemanı dizinin sonuna ekle

Parent ile karşılaştır

Kural bozuluyorsa yukarı doğru swap

Kök ya da kural sağlanana kadar devam

⏱ Zaman Karmaşıklığı: O(log N)

🔹 Heap’ten Silme (DeleteMin / DeleteMax – Percolate Down)

Kök silinir

Son eleman köke alınır

Çocuklarla karşılaştır

Gerekirse aşağı doğru swap

⏱ Zaman Karmaşıklığı: O(log N)

🔹 Heap Neden Kullanılır?

Öncelikli kuyruklar

CPU scheduling

k. en küçük elemanı bulma

Sıralama: O(N log N)

Heap ile: O(N log k) ✅

2️⃣ Hash Table (Karma Tablo) Algoritmaları
🔹 Hash Table

Amaç: Veriye ortalama O(1) sürede erişmek

Mantık:
index = hash(key) % tableSize

🔹 Collision (Çakışma)

Farklı key’lerin aynı index’e düşmesi

Kaçınılmaz, yönetilmesi gerekir

🔹 Çakışma Çözüm Yöntemleri
1️⃣ Separate Chaining (Ayrı Zincirleme)

Her hücrede Linked List / vector

Aynı index’e düşenler listeye eklenir

⏱ Ortalama: O(1 + λ)
📌 λ = eleman sayısı / tablo boyutu

2️⃣ Open Addressing (Açık Adresleme)
🔸 Linear Probing

Doluysa → +1, +2, +3 …

Sorun: Primary Clustering (bloklaşma)

🔸 Quadratic Probing

Doluysa → +1², +2², +3² …

Clustering daha az

📌 Şart:

Tablo boyutu asal

Yük faktörü < 0.5

🔹 Rehashing

Tablo çok dolarsa yapılır

Tablo boyutu büyütülür (genelde 2 kat, asal)

Tüm elemanlar yeniden hashlenir

⏱ Maliyet: O(N) (ama nadir)

3️⃣ Graph (Graf) Algoritmaları
🔹 Graf Türleri

Directed / Undirected

Weighted / Unweighted

🔹 Gösterim Yöntemleri

Adjacency Matrix

Kenar kontrolü O(1)

Bellek O(V²)

Adjacency List ✅

Bellek O(V+E)

Pratikte en yaygın

4️⃣ Graph Traversal (Gezinme)
🔹 BFS – Breadth First Search

Queue (FIFO)

Katman katman ilerler

Ağırlıksız graf için en kısa yol

⏱ O(V + E)

🔹 DFS – Depth First Search

Stack / Recursion

Derine in, yol bitince geri dön (backtracking)

Kullanım:

Döngü tespiti

Bağlantılı bileşenler

Labirent çözümü

⏱ O(V + E)

5️⃣ Topological Sort

Sadece DAG (Directed Acyclic Graph)

Ön koşullu işler (dersler gibi)

Indegree = 0 olan düğümlerle başlar

6️⃣ Shortest Path Algoritmaları
🔹 Dijkstra

Greedy

Negatif ağırlık yok

Priority Queue (Heap) kullanır

⏱ O((V+E) log V)

🔹 Bellman-Ford

Negatif kenarları destekler

Daha yavaş

7️⃣ Minimum Spanning Tree (MST)
🔹 Amaç

Tüm düğümleri en düşük toplam maliyetle

Döngüsüz bağlamak

🔹 Prim

Dijkstra’ya benzer

Bir düğümden başlar

Heap kullanır

🔹 Kruskal

Kenar tabanlı

Kenarları sırala

Döngü kontrolü → Union-Find