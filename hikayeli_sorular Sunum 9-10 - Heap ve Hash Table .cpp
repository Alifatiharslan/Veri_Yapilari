Soru 1 (20p) – “Acil Servis” Min-Heap (Insert + Print)

Bir hastanenin acil servisinde hastalar öncelik (priority) değerine göre çağrılıyor. Küçük priority = daha acil.
Aşağıdaki Min-Heap yapısında pushPatient(int pr) fonksiyonunu ve printLevelOrder() fonksiyonunu tamamlayınız.

struct ERHeap {
    int a[1024];
    int n = 0;

    void pushPatient(int pr) {
        // TODO: Min-Heap insert (percolate up)
    }

    void printLevelOrder() {
        // TODO: a[1..n] değerlerini sırayla yazdır
    }
};

Cevap
#include <iostream>
using namespace std;

void pushPatient(int pr) {
    n++;
    int hole = n;

    while (hole > 1 && pr < a[hole / 2]) {
        a[hole] = a[hole / 2];
        hole /= 2;
    }
    a[hole] = pr;
}

void printLevelOrder() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

Soru 2 (20p) – “Acil Servis” DeleteMin + Tek Adım İzah

Aynı sistemde en acil hasta çağrılınca heap’ten silinir. popPatient() fonksiyonunu yazınız.
Fonksiyon minimum priority’yi döndürsün. Boşsa -1 döndürsün.

int popPatient() {
    // TODO: DeleteMin
}

Cevap
int popPatient() {
    if (n == 0) return -1;

    int minItem = a[1];
    int last = a[n--];

    int hole = 1;
    while (hole * 2 <= n) {
        int child = hole * 2;
        if (child != n && a[child + 1] < a[child]) child++;

        if (a[child] < last) {
            a[hole] = a[child];
            hole = child;
        } else break;
    }
    a[hole] = last;
    return minItem;
}

Soru 3 (20p) – “Kütüphane” Hash Tablosu (Linear Probing + Silme)

Üniversite kütüphanesi kitapları id ile saklıyor. Hash tablosu Linear Probing kullanıyor.
Boş hücre -1, silinmiş hücre -2’dir.
Aşağıdaki insertBook, findBook, removeBook fonksiyonlarını tamamlayınız.

struct LibraryHash {
    static const int M = 11;
    int t[M];

    int h(int x) { return x % M; }

    void init() {
        for (int i = 0; i < M; i++) t[i] = -1;
    }

    void insertBook(int id) {
        // TODO
    }

    int findBook(int id) {
        // TODO: index döndür, yoksa -1
    }

    void removeBook(int id) {
        // TODO: varsa -2 yap
    }
};

Cevap
void insertBook(int id) {
    int idx = h(id);
    int firstDel = -1;

    for (int i = 0; i < M; i++) {
        int pos = (idx + i) % M;
        if (t[pos] == id) return;                 // zaten var
        if (t[pos] == -2 && firstDel == -1) firstDel = pos;
        if (t[pos] == -1) {
            if (firstDel != -1) t[firstDel] = id;
            else t[pos] = id;
            return;
        }
    }
}

int findBook(int id) {
    int idx = h(id);
    for (int i = 0; i < M; i++) {
        int pos = (idx + i) % M;
        if (t[pos] == -1) return -1;   // boş gördük => yok
        if (t[pos] == id) return pos;
    }
    return -1;
}

void removeBook(int id) {
    int idx = h(id);
    for (int i = 0; i < M; i++) {
        int pos = (idx + i) % M;
        if (t[pos] == -1) return;
        if (t[pos] == id) {
            t[pos] = -2;
            return;
        }
    }
}

Soru 4 (20p) – “Sistem İzleme” Top-K Alarm (Min-Heap mantığı)

Bir izleme sisteminde her alarmın bir “risk” skoru var. Ama ekranda sadece en riskli K alarm tutulacak.
Aşağıdaki fonksiyon scores dizisinden en büyük K skoru döndürsün. (Sıralı olmak zorunda değil.)
Zaman karmaşıklığı hedefi: O(N log K).

#include <vector>
using namespace std;

vector<int> topKAlerts(const vector<int>& scores, int K) {
    // TODO
}

Cevap
#include <queue>
#include <vector>
using namespace std;

vector<int> topKAlerts(const vector<int>& scores, int K) {
    vector<int> res;
    if (K <= 0) return res;

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    for (int x : scores) {
        if ((int)pq.size() < K) pq.push(x);
        else if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

Soru 5 (20p) – “Kod Okuma” Big-O (Hikâyeli)

Bir öğrenci yurdu sistemi her öğrencinin id’sini kontrol ediyor. Aşağıdaki kodun en kötü durum zaman karmaşıklığını bulunuz:

for (int i = 1; i <= n; i++) {
    int x = i;
    while (x > 1) {
        x = x / 2;
    }
}

Cevap

İç döngü: x her seferinde 2’ye bölünüyor → O(log i)

Dış döngü: n kez

Toplam: O(n log n)