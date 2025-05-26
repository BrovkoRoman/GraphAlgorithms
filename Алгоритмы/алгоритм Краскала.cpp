#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5; // ���������, ������� ������ ���� �� ������ ����� ������

int p[N], siz[N]; // ������� ��� ������� ���������������� ��������: �������� ������� � ������ ������ (������ �������� ������ ��� ������ ��������)

int get(int x) { // �� ������� x �������� ������ � ������
    if(x == p[x]) {
        return x;
    }

    p[x] = get(p[x]); // ������ �����: x ������������� �������� � �����

    return p[x];
}

void unite(int x, int y) { // ���������� ���������, ���������� x � y
    x = get(x);
    y = get(y);

    if(x == y) { // x � y ��� � ����� ���������
        return;
    }

    if(siz[x] > siz[y]) { // ������ ������� x ����� ��������������� ������� ������ (����� ��� small-to-large)
        swap(x, y);
    }

    p[x] = y; // ��������������� ������ x � ����� ������ y
    siz[y] += siz[x]; // ��������� ������ ��� ����� ����������� ������
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > edges; // ����� ������������ ���� �� �����, ����� ������� �� �������� (���, ������, �����)

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < n; i++) { // ������������� ���
        p[i] = i;
        siz[i] = 1;
    }

    for(auto x:edges) {
        int u = x[1], v = x[2], w = x[0];

        if(get(u) == get(v)) { // ���������� ����� ������� ����
            continue;
        }

        // ��������� ����� � ������
        unite(u, v);
        cout << "add edge: " << u + 1 << ' ' << v + 1 << ' ' << w << endl;
    }
}

/*
������ ������� ������ (�������� � ������������ ������):
5 7
1 4 5
1 2 3
2 4 7
2 3 2
3 4 6
4 5 1
3 5 4

*/
