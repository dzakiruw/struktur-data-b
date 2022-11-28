#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjLists;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex, int endVertex);
    void showList();
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
  adjLists[src].push_back(dest);
  // adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    if (currVertex == endVertex)
    {
      break;
    }
    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
    {
      int adjVertex = *i;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::showList()
{
  for (int i = 0; i < numVertices; i++)
  {
    cout << i << ": ";
    list<int>::iterator it;
      for(it = adjLists[i].begin(); it != adjLists[i].end(); ++it){
        cout << *it << " ";
      }
    cout << endl;
  }
}

int main()
{
  Graph tryList(20);

  tryList.addEdge(0, 4);
  tryList.addEdge(0, 5);
  tryList.addEdge(1, 0);
  tryList.addEdge(1, 3);
  tryList.addEdge(2, 1);
  tryList.addEdge(5, 6);
  tryList.addEdge(5, 8);
  tryList.addEdge(6, 7);
  tryList.addEdge(6, 8);
  tryList.addEdge(8, 9);
  tryList.addEdge(8, 16);
  tryList.addEdge(9, 10);
  tryList.addEdge(10, 11);
  tryList.addEdge(10, 14);
  tryList.addEdge(11, 12);
  tryList.addEdge(12, 13);
  tryList.addEdge(13, 14);
  tryList.addEdge(14, 15);
  tryList.addEdge(16, 17);
  tryList.addEdge(17, 18);
  tryList.addEdge(18, 19);

  tryList.BFS(0, 19);
  cout << endl;
  tryList.showList();

  return 0;
}
