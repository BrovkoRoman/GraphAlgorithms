#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector <int> u(m), v(m), w(m); // для этого алгоритма можно просто хранить список рёбер, без списка смежности
                                    // граф ориентированный, так что каждое ребро будет входить в список 1 раз (в одном направлении)

    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }

    vector <long long> d(n, 1e18);

    int start = 0;
    d[start] = 0;

    for(int i = 0; i < n - 1; i++) { // n-1 итерация перебора всех рёбер
        for(int j = 0; j < m; j++) {
            d[v[j]] = min(d[v[j]], d[u[j]] + w[j]);
        }
    }

    cout << "Shortest paths from vertex " << start + 1 << ": ";

    for(int i = 0; i < n; i++) {
        if(d[i] < 1e17) {
            cout << d[i] << ' ';
        } else {
            cout << "INF ";
        }
    }
}

/*
Пример входных данных (разобран в прикреплённой лекции):
4 5
2 3 -3
1 2 3
1 3 8
1 4 5
4 3 -8

*/
