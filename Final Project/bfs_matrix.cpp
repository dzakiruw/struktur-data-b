#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v){
	    adjM[u][v] = v;
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}

	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i<=V; i++){
			if(visited[i] == false && adjM[u][i] != 0){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }

    void shortestDistance(int src, int dest){
		int pred[V], dist[V];
		shortest_path(src, dest, pred, dist);
		vector<int> path;
		int c = dest;
		path.push_back(c);
		while(pred[c] != 0){
			path.push_back(pred[c]);
			c = pred[c];
		}
		for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph graph(20);
	graph.addVertex("Rumah", 1, 1);
	graph.addVertex("Toko Olahraga", 1, 2);
	graph.addVertex("Rumah Makan", 1, 6);
	graph.addVertex("Toko Olahraga", 2, 2);
	graph.addVertex("Cafe", 2, 3);
	graph.addVertex("Gudang", 2, 5);
	graph.addVertex("Cafe", 3, 3);
	graph.addVertex("Bakso", 3, 4);
	graph.addVertex("Bakso", 4, 4);
	graph.addVertex("Gudang", 5, 5);
	graph.addVertex("Rumah Makan", 6, 6);
    graph.addVertex("JNE", 6, 7);
    graph.addVertex("Toko Pancing", 6, 9);
	graph.addVertex("JNE", 7, 7);
    graph.addVertex("Bakso Sapi", 7, 8);
    graph.addVertex("Toko Pancing", 7, 9);
	graph.addVertex("Bakso Sapi", 8, 8);
	graph.addVertex("Toko Pancing", 9, 9);
    graph.addVertex("Bank BNI", 9, 10);
    graph.addVertex("SMK YPKK 2 Sleman", 9, 17);
	graph.addVertex("Bank BNI", 10, 10);
    graph.addVertex("Samsat Sleman", 10, 11);
	graph.addVertex("Samsat Sleman", 11, 11);
    graph.addVertex("SD Muhammadiyah Sleman", 11, 12);
	graph.addVertex("Tempura", 11, 15);
	graph.addVertex("SD Muhammadiyah Sleman", 12, 12);
    graph.addVertex("Pasar Sleman", 12, 13);
	graph.addVertex("Pasar Sleman", 13, 13);
    graph.addVertex("Agen Lava Tour", 13, 14);
	graph.addVertex("Agen Lava Tour", 14, 14);
	graph.addVertex("Tempura", 15, 15);
    graph.addVertex("Hotel", 15, 16);
	graph.addVertex("Hotel", 16, 16);
	graph.addVertex("SMK YPKK 2 Sleman", 17, 17);
    graph.addVertex("Puskesmas Sleman", 17, 18);
	graph.addVertex("Puskesmas Sleman", 18, 18);
    graph.addVertex("Optik", 18, 19);
	graph.addVertex("Optik", 19, 19);
    graph.addVertex("Klinik", 19, 20);
	graph.addVertex("Klinik", 20, 20);

	graph.showAllVertex();
	int source, dest;
	// source = 1;
	// dest = 20;
	cin >> source >> dest;
    graph.shortestDistance(source,dest);
}