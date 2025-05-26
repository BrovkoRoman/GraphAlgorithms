#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5; // константа, котора€ должна быть не меньше числа вершин

int p[N], siz[N]; // массивы дл€ системы непересекающихс€ множеств: родитель вершины и размер дерева (размер осмыслен только дл€ корней деревьев)

int get(int x) { // по вершине x получить корень еЄ дерева
    if(x == p[x]) {
        return x;
    }

    p[x] = get(p[x]); // сжатие путей: x подвешиваетс€ напр€мую к корню

    return p[x];
}

void unite(int x, int y) { // объединить множества, содержащие x и y
    x = get(x);
    y = get(y);

    if(x == y) { // x и y уже в одном множестве
        return;
    }

    if(siz[x] > siz[y]) { // теперь вершине x будет соответствовать меньшее дерево (нужно дл€ small-to-large)
        swap(x, y);
    }

    p[x] = y; // переподвешиваем дерево x к корню дерева y
    siz[y] += siz[x]; // обновл€ем размер дл€ корн€ полученного дерева
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > edges; // чтобы отортировать рЄбра по весам, будем хранить их тройками (вес, начало, конец)

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < n; i++) { // инициализаци€ —Ќћ
        p[i] = i;
        siz[i] = 1;
    }

    for(auto x:edges) {
        int u = x[1], v = x[2], w = x[0];

        if(get(u) == get(v)) { // добавление ребра создаст цикл
            continue;
        }

        // добавл€ем ребро в дерево
        unite(u, v);
        cout << "add edge: " << u + 1 << ' ' << v + 1 << ' ' << w << endl;
    }
}

/*
ѕример входных данных (разобран в прикреплЄнной лекции):
5 7
1 4 5
1 2 3
2 4 7
2 3 2
3 4 6
4 5 1
3 5 4

*/
