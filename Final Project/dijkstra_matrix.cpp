#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

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

	void addVertex(string str, int u, int v, int w){
	    adjM[u][v] = w;
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

	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 1000;
		}
		dist[src] = 1;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i <= V; i++){
				int v = i;
				int w = adjM[u][i];
				if(dist[v] > dist[u] + w && w != 0){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    	for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
	}
};

int main(){
	Graph graph(20);
	graph.addVertex("Rumah", 1, 1, 1);
	graph.addVertex("Toko Olahraga", 1, 2, 2);
	graph.addVertex("Rumah Makan", 1, 6, 6);
	graph.addVertex("Toko Olahraga", 2, 2, 2);
	graph.addVertex("Cafe", 2, 3, 3);
	graph.addVertex("Gudang", 2, 5, 5);
	graph.addVertex("Cafe", 3, 3, 3);
	graph.addVertex("Bakso", 3, 4, 4);
	graph.addVertex("Bakso", 4, 4, 4);
	graph.addVertex("Gudang", 5, 5, 5);
	graph.addVertex("Rumah Makan", 6, 6, 6);
    graph.addVertex("JNE", 6, 7, 7);
    graph.addVertex("Toko Pancing", 6, 9, 9);
	graph.addVertex("JNE", 7, 7, 7);
    graph.addVertex("Bakso Sapi", 7, 8, 8);
    graph.addVertex("Toko Pancing", 7, 9, 9);
	graph.addVertex("Bakso Sapi", 8, 8, 8);
	graph.addVertex("Toko Pancing", 9, 9, 9);
    graph.addVertex("Bank BNI", 9, 10, 10);
    graph.addVertex("SMK YPKK 2 Sleman", 9, 17, 17);
	graph.addVertex("Bank BNI", 10, 10, 10);
    graph.addVertex("Samsat Sleman", 10, 11, 11);
	graph.addVertex("Samsat Sleman", 11, 11, 11);
    graph.addVertex("SD Muhammadiyah Sleman", 11, 12, 12);
	graph.addVertex("Tempura", 11, 15, 15);
	graph.addVertex("SD Muhammadiyah Sleman", 12, 12, 12);
    graph.addVertex("Pasar Sleman", 12, 13, 13);
	graph.addVertex("Pasar Sleman", 13, 13, 13);
    graph.addVertex("Agen Lava Tour", 13, 14, 14);
	graph.addVertex("Agen Lava Tour", 14, 14, 14);
	graph.addVertex("Tempura", 15, 15, 15);
    graph.addVertex("Hotel", 15, 16, 16);
	graph.addVertex("Hotel", 16, 16, 16);
	graph.addVertex("SMK YPKK 2 Sleman", 17, 17, 17);
    graph.addVertex("Puskesmas Sleman", 17, 18, 18);
	graph.addVertex("Puskesmas Sleman", 18, 18, 18);
    graph.addVertex("Optik", 18, 19, 19);
	graph.addVertex("Optik", 19, 19, 19);
    graph.addVertex("Klinik", 19, 20, 20);
	graph.addVertex("Klinik", 20, 20, 20);
	graph.showAllVertex();
	int src;
    // source = 1;
	// dest = 20;
	cin >> src;
    graph.djikstra(src);
}