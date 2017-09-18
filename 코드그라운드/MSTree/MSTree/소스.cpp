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
	edge ��ü ����
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
	union-find �˰����� ���� Ŭ���� ����
*/
class ForUnion {
private : 
	uint32_t n;
public :

};
// �Լ�
void printGraph(uint32_t **graph, uint32_t n);
void getMST(list<doubleEdge>& inputGraph, uint32_t n, uint32_t m);

int main() {
	srand(time(NULL));
	uint32_t n, tmp = 0, i ,j, m = 0; // m = edge�� ����
	uint32_t **graph = NULL;			// �Է¿� �׷��� �����ϱ� ���� ����̴� !!
	list<doubleEdge> inputGraph;

	// graph �Ҵ� �� ���� // mst �Ҵ� �� �ʱ�ȭ
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
		// �̹� ������ ���̴� !!
		for ( j = 0; j < i; j++) {
			graph[i][j] = graph[j][i];
		}
		// i == j 
		graph[i][j] = 0; // �ڱ� �ڽſ����� �Ÿ��̴� 0�̴�. ! 
		// ���� �����ؾ��ϴ� �κ� !!
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
	printGraph(graph, n);			// �Էµ� ������ �׷���
	// mst ����
	getMST(inputGraph, n, m);

	// �Է¿� graph ����
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
	// union-find �˰��򿡼� ����� �ڷᱸ��
	forUnion.resize(n);
	for (i = 0; i < n; i++) {
		forUnion[i].push_back(i);
	}
	// mst ����� �����ֱ� �� ��� �Ҵ� �� �ʱ�ȭ
	tableT = new uint32_t*[n];
	for (i = 0; i < n; i++) {
		tableT[i] = new uint32_t[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			tableT[i][j] = 0;
		}
	}
	// union-find  �̰� ���� �ؾ��Ѵ�. !!
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
	for (auto&t : inputGraph) { // edge�� ����ŭ �ݺ��ȴ� !
		if (unionFindFunc(t)) {		// union-find test !!
			mst.push_back(t);		// �߰��Ѵ�.
			tableT[t.a][t.b] = t.weight;
			tableT[t.b][t.a] = t.weight;
		}
	}
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
	// mst ��� ���
	cout << "result !!\n";
	printGraph(tableT, n);
	cout << "�ɸ��ð� : " << sec.count() << endl;
	for (auto&t : mst) {

	}
	// ����
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