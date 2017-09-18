#include <iostream>
#include <iomanip>
#include <exception>
#include <chrono>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

const int MAXWEIGHT = 10;
/*
	edge 객체 생성
*/
typedef struct doubleEdge {
	uint32_t weight;
	uint32_t a;
	uint32_t b;
	doubleEdge() {
		a = b = 0;
		weight = 0;
	}
	doubleEdge(uint32_t a_, uint32_t b_, uint32_t weight_) : a(a_), b(b_), weight(weight_)
	{
	}
} Edge;
/*
	union-find 알고리즘을 위한 클래스 생성
*/
class ForUnion {
private : 
	uint32_t n;
public :

};
// 함수
void printGraph(uint32_t **graph, uint32_t n);
void getMST(list<doubleEdge>& inputGraph, uint32_t n, uint32_t m);

int main() {
	srand(time(NULL));
	uint32_t n, tmp = 0, i ,j, m = 0; // m = edge의 갯수
	uint32_t **graph = NULL;			// 입력용 그래프 생성하기 위한 행렬이다 !!
	list<doubleEdge> inputGraph;

	// graph 할당 및 생성 // mst 할당 및 초기화
	try
	{
		n = 5;
		graph = new uint32_t*[n];
		for (i = 0; i < n; i++) {
			graph[i] = new uint32_t[n];
		}
	}
	catch (const std::exception& e)
	{
		cout << "create Graph throw error : " << e.what() << endl;
	}
	//
	for ( i = 0; i < n; i++) {
		// 이미 생성된 곳이다 !!
		for ( j = 0; j < i; j++) {
			graph[i][j] = graph[j][i];
		}
		// i == j 
		graph[i][j] = 0; // 자기 자신에대한 거리이니 0이다. ! 
		// 새로 생성해야하는 부분 !!
		for ( j = i+1; j < n; j++) {
	//		if ((rand() % 2) == 1) { // test
			if (true) { // test
				graph[i][j] = rand() % MAXWEIGHT + 1;
				m++;
				inputGraph.push_back(doubleEdge(i, j, graph[i][j]));
			}
			else {
				graph[i][j] = 0;
			}

		}
	}
	printGraph(graph, n);			// 입력된 기존의 그래프
	// mst 생성
	getMST(inputGraph, n, m);

	// 입력용 graph 삭제
	for ( i = 0; i < n; i++) {
		delete[] graph[i];
	}
	delete[] graph;
	return 0;
}

void getMST(list<doubleEdge>& inputGraph, uint32_t n, uint32_t m) {
	vector<list<uint32_t>> forUnion;
	uint32_t **tableT = NULL;
	uint32_t i, j, vertex;
	list<doubleEdge> mst;
	// union-find 알고리즘에서 사용할 자료구조
	forUnion.resize(n);
	for (i = 0; i < n; i++) {
		forUnion[i].push_back(i);
	}
	// mst 결과를 보여주기 용 행렬 할당 및 초기화
	tableT = new uint32_t*[n];
	for (i = 0; i < n; i++) {
		tableT[i] = new uint32_t[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			tableT[i][j] = 0;
		}
	}
	// union-find  이거 마저 해야한다. !!
	auto unionFindFunc = [&forUnion](doubleEdge& arg) {
		for (auto& t : forUnion) {
			if ((t.front() == arg.a) || (t.front() == arg.b)) {

			}
		}
		forUnion[arg.a].push_back();
		forUnion[arg.b].push_back();
		return true;
	};
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	// edge sort !!
	inputGraph.sort([](doubleEdge& first, doubleEdge& second) {
		if (first.weight > second.weight) return false;
		else if (first.weight == second.weight) return false;
		else if (first.weight < second.weight) return true;
	});
	// mst start
	for (auto&t : inputGraph) { // edge의 수만큼 반복된다 !
		if (unionFindFunc(t)) {		// union-find test !!
			mst.push_back(t);		// 추가한다.
			tableT[t.a][t.b] = t.weight;
			tableT[t.b][t.a] = t.weight;
		}
	}
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
	// mst 결과 출력
	cout << "result !!\n";
	printGraph(tableT, n);
	cout << "걸린시간 : " << sec.count() << endl;
	for (auto&t : mst) {

	}
	// 정리
	for (i = 0; i < n; i++) {
		delete[] tableT[i];
	}
	delete[] tableT;
}

void printGraph(uint32_t **graph, uint32_t n) {
	uint32_t i, j;
	//
	cout << "-------------------------------------------------" << endl;
	cout << setw(n) << "  i" << " ";
	for (i = 0; i < n; i++) {
		cout << setw(2) << i << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		cout << setw(n) << i << " ";
		for (j = 0; j < n; j++) {
			cout << setw(2) << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------" << endl;
}