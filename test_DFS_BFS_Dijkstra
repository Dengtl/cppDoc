#include <iostream>
#include <fstream>
#include <string>
#include <limits.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include "Graphm.h"
using namespace std;
#define INFINITY INT_MAX	//定义无穷大的宏

void graphTraverseDFS(Graphm* G);
void graphTraverseBFS(Graphm* G);
void DFS(Graphm* G, int v);
void BFS(Graphm* G, int start);
void Dijkstra(Graphm* G, int* D, int s);
int minVertex(Graphm* G, int* D);
void topsort(Graphm* G);
void tophelp(Graphm* G, int v);
void topsortQueue(Graphm* G);

void string_replace(string & strBig, const string & strsrc, const string &strdst)
{
    string::size_type pos=0;
    string::size_type srclen=strsrc.size();
    string::size_type dstlen=strdst.size();
    while( (pos=strBig.find(strsrc, pos)) != string::npos)
    {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
}


int main(){
	Graphm graph(6);
	graph.setEdge(0, 1, 1);
	graph.setEdge(0, 2, 6);
	graph.setEdge(0, 4, 5);
	graph.setEdge(1, 4, 3);
	graph.setEdge(2, 3, 7);
	graph.setEdge(3, 4, 4);
	graph.setEdge(4, 5, 2);
	
	cout<<"Depth-first search:"<<'\n';
	graphTraverseDFS(&graph);
	cout<<'\n';


	cout<<"Breadth-first search:"<<'\n';
	graphTraverseBFS(&graph);
	cout<<'\n';

	cout<<"Topsort result <use recurr>:"<<'\n';
	topsort(&graph);
	cout<<'\n';
	cout<<"Topsort result <use queue>:"<<'\n';
	topsortQueue(&graph);

	//利用文件dis.txt初始化一个图
	ifstream is;
	int weight = 0;
	int dim = 0, row = 0, col = 0;
	is.open("dis.txt");
	string str;
	getline(is, str, '\n');
	dim = str[0] - '0';
	Graphm g(dim);

	cout<<'\n'<<"src"<<'\t'<<"dst"<<'\t'<<"weight"<<endl;
	while(is){
		int i = 0;
		string str;
		getline(is, str, '\n');		//扫描文件中的行
		if(!is) break;
		string_replace(str, "-1", "0");
		string_replace(str, "\t", " ");
		str += '\0';

		while(str[i] != '\0'){
			if(str[i] == ' ') { col++; i++; }
			else
				if(str[i] != '0'){
					while(str[i] != ' '){
						if(str[i] == '\0') break;
						weight = weight*10 + (str[i] - '0');
						i++;
					}
					cout<<row<<'\t'<<col<<'\t'<<weight<<'\n';
					g.setEdge(row, col, weight);
					weight = 0;
				}
				else i++;
		}
		col = 0;
		row++;
	}
	
	//求最短距离
	int src, dst;
	int* arr = new int(dim);
	cout<<"输入起点和终点:";
	cin>>src>>dst;

	for(int i = 0; i < dim; i++)
		if(i == src)
			arr[i] = 0;
		else arr[i] = INFINITY;

	Dijkstra(&g, arr, src);
	cout<<'\n';

	cout<<arr[dst]<<endl;
	for(int i = 0; i<dim; i++){
		if(arr[i] != INFINITY)
			cout<<"Shortest road from "<<src<<" to "<<i<<" equals "<<arr[i]<<'\n';
		else
			cout<<"It is unreachable from "<<src<<" to "<<i<<'\n'; 
	}

	/*
	//What is map.
	std::map<char, std::string> mymap;
	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];
	std::cout<<"Test of map:"<<std::endl;
	cout<<"mymap['a'] is "<<mymap['a']<<'\n';
	cout<<"mymap['b'] is "<<mymap['b']<<'\n';
	cout<<"mymap['c'] is "<<mymap['c']<<'\n';
	
	//Constructor of map.
	std::map<char, int> first;
	first['a'] = 0;
	first['b'] = 1;
	first['c'] = 2;
	std::map<char, int> second(first.begin(), first.end());
	std::map<char, int> third(second);

	//Vector
	std::cout<<"Use of vector:"<<std::endl;
	std::vector<int> myvector;
	myvector.push_back(0);
	myvector.push_back(1);
	myvector.push_back(2);
	std::vector<int> secondVec(myvector.begin(), myvector.end());
	std::vector<int> thirdVec(secondVec);
	int a[] = {0, 1, 2};
	std::vector<int> useArray(a, a+sizeof(a)/sizeof(int));
	myvector.pop_back();
	//Use iterator to catch its value.
	std::vector<int>::iterator it = myvector.begin();	//Make a iterator.
	while(it != myvector.end()){
		std::cout<<*it<<' ';	//output its value.
		it++;	//find next value.
	}
	std::cout<<std::endl;
	it = useArray.begin();
	while(it != useArray.end()){
		std::cout<<*it<<' ';
		it++;
	}
	//Sort it use algorithm header.
	useArray.push_back(-1);
	sort(useArray.begin(), useArray.end());
	it = useArray.begin();
	std::cout<<std::endl;
	while(it != useArray.end()){
		std::cout<<*it<<' ';
		it++;
	}*/


	system("pause");
	return 0;
}


void graphTraverseDFS(Graphm* G){
	int v;
	for(v = 0; v<G->n(); v++){
		G->setMark(v, UNVISITED);
	}
	for(v = 0; v<G->n(); v++){
		if(G->getMark(v) == UNVISITED)
			DFS(G, 0);
	}
}

void graphTraverseBFS(Graphm* G){
	int v;
	for(v = 0; v<G->n(); v++){
		G->setMark(v, UNVISITED);
	}
	for(v = 0; v<G->n(); v++){
		if(G->getMark(v) == UNVISITED)
			BFS(G, 0);
	}
}

void DFS(Graphm* G, int v){
	cout<<v<<' ';
	G->setMark(v, VISITED);
	for(int w=G->first(v); w<G->n(); w = G->next(v, w)){
		if(G->getMark(w) == UNVISITED)
			DFS(G, w);
	}
}

void BFS(Graphm* G, int start){
	int v, w;
	queue<int>* Q = new queue<int>;
	Q->push(start);
	G->setMark(start, VISITED);
	while(Q->size() != 0){
		v = Q->front();		//queue头文件中的队列pop()返回void,只能先调用front,再将其pop()出来
		Q->pop();
		cout<<v<<' ';
		for(w = G->first(v); w < G->n(); w = G->next(v, w)){
			if(G->getMark(w) == UNVISITED){
				G->setMark(w, VISITED);
				Q->push(w);
			}
		}
	}
}

void Dijkstra(Graphm* G, int* D, int s){
	int i, v, w;
	for(i=0; i<G->n(); i++){
		v = minVertex(G, D);
		if(D[v] == INFINITY) return;
		G->setMark(v, VISITED);
		for(w=G->first(v); w<G->n(); w=G->next(v, w)){
			if(D[w] > (D[v] + G->weight(v, w)))
				D[w] = D[v] + G->weight(v, w);
		}
	}
}

int minVertex(Graphm* G, int* D){
	int i, v = -1;
	for(i = 0; i < G->n(); i++){
		if(G->getMark(i) == UNVISITED){
			v = i; break;
		}
	}
	for(i++; i < G->n(); i++){
		if((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
			v = i;
	}
	return v;
}

void topsort(Graphm* G){
	int i;
	for(i = 0; i<G->n(); i++){
		G->setMark(i, UNVISITED);
	}
	for(i = 0; i<G->n(); i++){
		if(G->getMark(i) == UNVISITED)
			tophelp(G, i);
	}
}

void tophelp(Graphm* G, int v){
	G->setMark(v, VISITED);
	for(int w = G->first(v); w<G->n(); w = G->next(v, w)){
		if(G->getMark(w) == UNVISITED)
			tophelp(G, w);
	}
	cout<<v<<' ';
}

void topsortQueue(Graphm* G){
	vector<int> Count(G->n(), 0);
	queue<int> Q;
	int v, w;
	for(v = 0; v<G->n(); v++)
		for(w = G->first(v); w<G->n(); w = G->next(v, w))
			Count[w]++;
	for(v = 0; v<G->n(); v++)
		if(Count[v] == 0)
			Q.push(v);
	while(Q.size() != 0){
		v = Q.front();
		Q.pop();
		cout<<v<<' ';
		for(w = G->first(v); w<G->n(); w = G->next(v, w)){
			Count[w]--;
			if(Count[w] == 0)
				Q.push(w);
		}
	}
}


/*
Depth-first search:
0 1 4 5 2 3
Breadth-first search:
0 1 2 4 3 5
Topsort result <use recurr>:
5 4 1 3 2 0
Topsort result <use queue>:
0 1 2 3 4 5
src     dst     weight
0       1       10
0       2       3
0       3       20
1       3       5
2       1       2
2       4       15
3       4       11
输入起点和终点:0 2

3
Shortest road from 0 to 0 equals 0
Shortest road from 0 to 1 equals 5
Shortest road from 0 to 2 equals 3
Shortest road from 0 to 3 equals 10
Shortest road from 0 to 4 equals 18
请按任意键继续. . .
*/
