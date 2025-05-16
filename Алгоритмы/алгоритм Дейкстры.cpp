#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int N = 1e5 + 5; // ��������� ������ ���� �� ������ ���������� ������ � �����
// ���� ���������� ������ ����������, ����� ������������ vector ������ ���������� ��������

vector <pair <int, int> > g[N]; // ���� ����� ������� � ���� ������ ���������:
// ��� ������ ������� �������� ������ ��� (�������, � ������� ����� ������ �� ������ �� �����,  ��� �����)

int main() {
    int n, m; // ����� ������ � ����
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w; // ������ ����� ����� (��� ������ ���� �� 1 �� n) � ���
        cin >> u >> v >> w;

        u--; // �� � ��������� ����� ���������� ������� �� 0 �� n-1
        v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w}); // ��� ������ ����� ������ ��� ����������������� ������
    }

    int start = 0; // ��������� �������

    vector <bool> used(n, false); // �������� ������������� ������� (���� � ������ ��������� � set ��� �������������)
    vector <long long> d(n, 1e18); // ���������� �� ��������� ������� �� ���� ���������; � �������� ������������� ���������� 10^18

    d[start] = 0;

    set <pair <long long, int> > st; // � set �������� ���� (d[v], v) ��� ��������������� ������

    for(int i = 0; i < n; i++) {
        st.insert({d[i], i});
    }

    while(!st.empty()) {
        int v = st.begin()->second; // ������� ������� � ����������� ��������� d �� ���������������

        used[v] = 1;
        st.erase(st.begin());

        for(auto to:g[v]) { // ���������� ����� �� v; to - ��� ���� (����� �����, ��� �����)
            if(!used[to.first] && d[to.first] > d[v] + to.second) { // ���� ����� ������� ���������� �� �����
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
������ ������� ������ (�������� � ������������ ������):
4 5
1 2 3
2 3 6
1 3 8
1 4 5
4 3 2

*/
