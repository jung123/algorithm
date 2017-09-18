#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand((unsigned int)time(NULL));
	ofstream file("input.txt");
	int i,tmp;
	
	file << 1 << "\n";
	file << 100 << "\n";
	for(i=0;i<100;i++){
		tmp = rand() % 100 +1;
		file<<tmp<<" ";
	}
	
	
	return 0;
}
