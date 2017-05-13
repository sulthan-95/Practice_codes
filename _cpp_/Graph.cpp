#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(int v,bool visited[]);
	void topsortUtil(int v,bool visited[],stack<int> &S);
	void fillStack(int V,bool visited,stack<int> &S);
	Graph reverseDAG();
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void addEdgeDG(int v,int w);
		void BFS(int start);
		void DFS(int start);
		void topsort();
		void topologicalSort();
		void SCC();
};
Graph::Graph(int V)
{
	this->V=V;
	this->adj=new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::addEdgeDG(int v,int w)
{
	adj[v].push_back(w);
}
void Graph::BFS(int start)
{
	list<int> queue;
	list<int>::iterator i;
	bool *visited=new bool[V];
	for(int j=0;j<V;j++)
		visited[j]=false;
	visited[start]=true;
	queue.push_back(start);
	while(!queue.empty())
	{
		int v=queue.front();
		cout<<v<<" ";
		queue.pop_front();
		for(i=adj[v].begin();i!=adj[v].end();++i)
		{
			if(visited[*i]!=true)
			{
				queue.push_back(*i);
				visited[*i]=true;
			}
		}
	}
}
void Graph::DFSUtil(int v,bool visited[])
{
	list<int>::iterator it;
	visited[v]=true;
	cout<<v<<" ";
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
			DFSUtil(*it,visited);
	}
}
void Graph::DFS(int start)
{
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	DFSUtil(start,visited);
}
void Graph::topsortUtil(int v,bool visited[],stack<int> &S)
{
	list<int>::iterator it;
	visited[v]=true;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(visited[*it]!=true)
			topsortUtil(*it,visited,S);
	}
	S.push(v);
}
void Graph::topsort()
{
	stack<int> S;
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			topsortUtil(i,visited,S);
	}
	
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();	
	}
}
//Kahn's Algorithm
void Graph::topologicalSort()
{
    vector<int> in_degree(V, 0);
    for (int u=0; u<V; u++)
    {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
             in_degree[*itr]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int cnt = 0;
    vector <int> top_order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            if (--in_degree[*itr] == 0)
                q.push(*itr);
 
        cnt++;
    }
    if (cnt != V)
    {
        cout << "There exists a cycle in the graph\n";
        return;
    }
	for (int i=0; i<top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}
void Graph::fillStack(int v,bool visited[],stack<int> &S)
{
	visited[v]=true;
	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(visited[*it]!=true)
			fillStack(*it,visited,S);
	}
	S.push(v);
}
Graph Graph::reverseDAG()
{
	Graph gr(V);
	list<int>::iterator it;
	for(int i=0;i<V;i++)
	{
		for(it=adj[i].begin();it!=adj[i].end();it++)
			gr.addEdgeDG(*it,i);
	}
	return gr;
}
void Graph::SCC()
{
	stack<int> S;
	bool *visited=new bool[V];
	fill_n(visited,V,false);
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			fillStack(i,visited,S);
	}
	Graph gr=this->reverseDAG();
	fill_n(visited,V,false);
	while(!S.empty())
	{
		int k=S.top();
		S.pop();
		if(visited[k]!=true){
			gr.DFSUtil(k,visited);	
			cout<<endl;
		}
	}	
}
int main()
{
	Graph g(6);
	//g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,4);
	g.addEdge(4,5);
	cout<<"BFS\n";
	g.BFS(0);	
	Graph g1(7);
	g1.addEdge(0,1);
	g1.addEdge(1,2);
	g1.addEdge(2,3);
	g1.addEdge(3,4);
	g1.addEdge(4,1);
	g1.addEdge(2,5);
	g1.addEdge(5,6);
	cout<<"\nDFS\n";
	g1.DFS(0);
	Graph g2(6);
	g2.addEdgeDG(5,0);
	g2.addEdgeDG(4,0);
	g2.addEdgeDG(5,2);
	g2.addEdgeDG(4,1);
	g2.addEdgeDG(3,1);
	g2.addEdgeDG(2,3);
	//g1.addEdge();
	cout<<"\nTop Sort\n";
	g2.topsort();
	cout<<"\nKahn's Topological Sort\n";
	g2.topologicalSort();

}
