#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
char A[1005][1005];
bool visited[1005][1005];
int dist[1005][1005];
pair<int, int> s, e;
list< pair<int, int> > L;
pair<int, int> parent[1005][1005];

ll inf = 10000000000;

bool valid(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m){
        if(A[i][j] != '#' && !visited[i][j])return true;
    }
    return false;
}

char direction(int x1, int y1, int x2, int y2){
    if(x1 == x2){
        if(y2 > y1)return 'R';
        return 'L';
    }
    if(x2 > x1)return 'D';

    return 'U';
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
            if(A[i][j] == 'A'){
                s = {i, j};
            }
            if(A[i][j] == 'B'){
                e = {i, j};
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            visited[i][j] = false;
            dist[i][j] = inf;
        }
    }

    L.push_back(s);
    dist[s.first][s.second] = 0;
    visited[s.first][s.second] = true;
    while(!L.empty()){

        pair<int, int> cell = L.front();
        L.pop_front();

        int i = cell.first;
        int j = cell.second;

        if(valid(i-1, j)){
            dist[i-1][j] = dist[i][j] + 1;
            L.push_back({i-1, j});
            visited[i-1][j] = true;
            parent[i-1][j] = cell;
        }
        if(valid(i, j-1)){
            dist[i][j-1] = dist[i][j] + 1;
            L.push_back({i, j-1});
            visited[i][j-1] = true;
            parent[i][j-1] = cell;
        }
        if(valid(i, j+1)){
            dist[i][j+1] = dist[i][j] + 1;
            L.push_back({i, j+1});
            visited[i][j+1] = true;
            parent[i][j+1] = cell;
        }
        if(valid(i+1, j)){
            dist[i+1][j] = dist[i][j] + 1;
            L.push_back({i+1, j});
            visited[i+1][j] = true;
            parent[i+1][j] = cell;
        }

    }

    if(!visited[e.first][e.second]){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dist[e.first][e.second] << endl;

        vector< pair<int, int> > path;
        path.push_back(e);
        pair<int, int> cr = e;
        bool possible = true;
        while(possible){
            pair<int, int> a = parent[cr.first][cr.second];
            if(a.first == s.first && a.second == s.second){
                path.push_back(a);
                possible = false;
                break;
            } else {
                path.push_back(a);
                cr = a;
            }
        }

        reverse(path.begin(), path.end());

        string answer = "";
        for(int i = 1; i < path.size(); i++){
            answer += direction(path[i-1].first, path[i-1].second, path[i].first, path[i].second);
        }
        cout << answer << endl;

    }
    return 0;
}
