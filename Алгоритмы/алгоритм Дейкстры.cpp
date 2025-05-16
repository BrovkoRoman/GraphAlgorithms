#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int N = 1e5 + 5; // константа должна быть не меньше количества вершин в графе
// если количество вершин неизвестно, можно использовать vector вместо глобальных массивов

vector <pair <int, int> > g[N]; // граф будем хранить в виде списка смежности:
// для каждой вершины хранится список пар (вершина, в которую можно прийти из данной по ребру,  вес ребра)

int main() {
    int n, m; // число вершин и рёбер
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w; // вводим концы ребра (они должны быть от 1 до n) и вес
        cin >> u >> v >> w;

        u--; // но в программе будем нумеровать вершины от 0 до n-1
        v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w}); // эта строка нужна только для неориентированных графов
    }

    int start = 0; // стартовая вершина

    vector <bool> used(n, false); // отмечаем рассмотренные вершины (хотя в версии алгоритма с set это необязательно)
    vector <long long> d(n, 1e18); // расстояния от стартовой вершины до всех остальных; в качестве бесконечности используем 10^18

    d[start] = 0;

    set <pair <long long, int> > st; // в set хранятся пары (d[v], v) для нерассмотренных вершин

    for(int i = 0; i < n; i++) {
        st.insert({d[i], i});
    }

    while(!st.empty()) {
        int v = st.begin()->second; // находим вершину с минимальным значением d из нерассмотренных

        used[v] = 1;
        st.erase(st.begin());

        for(auto to:g[v]) { // перебираем ребро из v; to - это пара (конец ребра, вес ребра)
            if(!used[to.first] && d[to.first] > d[v] + to.second) { // если можем сделать обновление по ребру
                st.erase({d[to.first], to.first});
                d[to.first] = d[v] + to.second;
                st.insert({d[to.first], to.first});
            }
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
1 2 3
2 3 6
1 3 8
1 4 5
4 3 2

*/
