Soru 1 (20p) – Min-Heap Insert (C++)

Dizi tabanlı bir Min-Heap için insert(int x) fonksiyonunu yazınız.
Heap 1’den indekslenmektedir.

struct MinHeap {
    int arr[1000];
    int size = 0;

    void insert(int x) {
        // TODO
    }
};

Cevap
void insert(int x) {
    size++;
    int hole = size;

    while (hole > 1 && x < arr[hole / 2]) {
        arr[hole] = arr[hole / 2];
        hole /= 2;
    }
    arr[hole] = x;
}

Soru 2 (20p) – DeleteMin (C++)

Min-Heap’te minimum elemanı silip döndüren deleteMin() fonksiyonunu yazınız.

int deleteMin() {
    // TODO
}

Cevap
int deleteMin() {
    if (size == 0) return -1;

    int minItem = arr[1];
    int last = arr[size--];

    int hole = 1, child;

    while (hole * 2 <= size) {
        child = hole * 2;
        if (child != size && arr[child + 1] < arr[child])
            child++;

        if (arr[child] < last) {
            arr[hole] = arr[child];
            hole = child;
        } else {
            break;
        }
    }
    arr[hole] = last;
    return minItem;
}

Soru 3 (20p) – Linear Probing ile Hash Insert & Search

Tablo boyutu M = 11, hash fonksiyonu h(x) = x % 11.

const int M = 11;
int table[M];

int h(int x) {
    return x % M;
}

void insertLinear(int key) {
    // TODO
}

int searchLinear(int key) {
    // TODO
}

Cevap
void insertLinear(int key) {
    int idx = h(key);

    for (int i = 0; i < M; i++) {
        int pos = (idx + i) % M;
        if (table[pos] == -1) {
            table[pos] = key;
            return;
        }
    }
}

int searchLinear(int key) {
    int idx = h(key);

    for (int i = 0; i < M; i++) {
        int pos = (idx + i) % M;
        if (table[pos] == -1) return -1;
        if (table[pos] == key) return pos;
    }
    return -1;
}

Soru 4 (20p) – Quadratic Probing Insert (C++)

Quadratic probing kullanılan hash tablosu için insertQuadratic fonksiyonunu yazınız.

void insertQuadratic(int key) {
    // TODO
}

Cevap
void insertQuadratic(int key) {
    int idx = h(key);

    for (int i = 0; i < M; i++) {
        int pos = (idx + i * i) % M;
        if (table[pos] == -1) {
            table[pos] = key;
            return;
        }
    }
}

Soru 5 (20p) – Build Max-Heap (Bottom-Up)

Verilen diziden Max-Heap oluşturan buildHeap fonksiyonunu yazınız.

void percolateDown(int a[], int n, int i) {
    // TODO
}

void buildMaxHeap(int a[], int n) {
    // TODO
}

Cevap
void percolateDown(int a[], int n, int i) {
    int tmp = a[i];
    int child;

    while (i * 2 <= n) {
        child = i * 2;
        if (child != n && a[child + 1] > a[child])
            child++;

        if (a[child] > tmp) {
            a[i] = a[child];
            i = child;
        } else {
            break;
        }
    }
    a[i] = tmp;
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        percolateDown(a, n, i);
    }
}