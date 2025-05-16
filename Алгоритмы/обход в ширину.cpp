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
        g[v].push_back(u); // ��� ����������������� ������
    }

    int start = 0; // ��������� �������
    queue <int> q; // ������� ������

    used[start] = true; // ��������� ������� ����� ��������
    q.push(start); // � ��������� � �������

    while(!q.empty()) {
        int v = q.front(); // ������ ������ ������� �������
        q.pop(); // � ������� � �� �������

        cout << "bfs " << v + 1 << endl;

        for(auto to:g[v]) { // ���������� �������, � ������� ����� ������� �� ����� �� ������
            if(!used[to]) { // ���� ����� ����� � ������������ �������
                used[to] = 1; // �� �������� � ��� ���������� � ��������� � ����� �������
                q.push(to);
            }
        }
    }
}

/*
������ ������� ������ (�������� � ������������ ������):
7 7
1 3
1 4
3 5
4 5
4 7
5 7
2 6

*/
