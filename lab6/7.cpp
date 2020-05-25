#include<bits/stdc++.h>
using namespace std;
 
void print(vector<vector<double>> dist, vector<vector<int>> next) {
  cout << "(pair, dist, path)" << endl;
  const auto size = next.size();
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      if (i != j) {
        auto u = i + 1;
        auto v = j + 1;
        cout << "(" << u << " -> " << v << ", " << dist[i][j]
          << ", ";
        stringstream path;
        path << u;
        do {
          u = next[u - 1][v - 1];
          path << " -> " << u;
        } while (u != v);
        cout << path.str() << ")" << endl;
      }
    }
  }
}
 
void solve(vector<vector<int>> w_s, const int num_vertices) {
  vector<vector<double>> dist(num_vertices);
  for (auto& dim : dist) {
    for (auto i = 0; i < num_vertices; ++i) {
      dim.push_back(INT_MAX);
    }
  }
  for (auto& w : w_s) {
    dist[w[0] - 1][w[1] - 1] = w[2];
  }
  vector<vector<int>> next(num_vertices);
  for (auto i = 0; i < num_vertices; ++i) {
    for (auto j = 0; j < num_vertices; ++j) {
      next[i].push_back(0);
    }
    for (auto j = 0; j < num_vertices; ++j) {
      if (i != j) {
        next[i][j] = j + 1;
      }
    }
  }
  for (auto k = 0; k < num_vertices; ++k) {
    for (auto i = 0; i < num_vertices; ++i) {
      for (auto j = 0; j < num_vertices; ++j) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
  print(dist, next);
}
 
int main() {
  vector<vector<int>> w = {
    { 1, 3, -2 },
    { 2, 1, 4 },
    { 2, 3, 3 },
    { 3, 4, 2 },
    { 4, 2, -1 },
  };
  int num_vertices = 4;
  solve(w, num_vertices);
  return 0;
}
