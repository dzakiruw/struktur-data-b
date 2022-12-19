#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );

            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
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
    graph.showGraph();

    int start, end;
    // source = 1;
	// dest = 20;
    cin >> start >> end;
    graph.DFS(start, end);


}