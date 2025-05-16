#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 5;

bool used[N];
vector <int> g[N];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u); // для неориентированных графов
    }

    int start = 0; // стартовая вершина
    queue <int> q; // очередь вершин

    used[start] = true; // стартовая вершина сразу посещена
    q.push(start); // и добавлена в очередь

    while(!q.empty()) {
        int v = q.front(); // достаём первую вершину очереди
        q.pop(); // и удаляем её из очереди

        cout << "bfs " << v + 1 << endl;

        for(auto to:g[v]) { // перебираем вершину, в которую можно попасть по ребру из данной
            if(!used[to]) { // если нашли ребро в непосещённую вершину
                used[to] = 1; // то отмечаем её как посещённую и добавляем в конец очереди
                q.push(to);
            }
        }
    }
}

/*
Пример входных данных (разобран в прикреплённой лекции):
7 7
1 3
1 4
3 5
4 5
4 7
5 7
2 6

*/
