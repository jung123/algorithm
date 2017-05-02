// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
typedef enum {LEFT, RIGHT, UP, DOWN} direction;
using namespace std;
int **room;
int res,n;

void func(int x,int y, direction vec);

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
    int i,j;
	char buf[1000];
	
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		res = 0;
        // 방갯수 받기
		cin >> n;
		room =(int **) new int [n];
		for(i=0;i<n;i++) *(room+i) = new int [n];
        //
        for(i=0;i<n;i++){
        	cin >> buf;
        	for(j=0;j<n;j++){
        		room[i][j] = buf[j] - 48;
			}
		}
        // 알고리즘
        
		func(0,0,RIGHT);
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
        cout << res << endl;
        for(i=0;i<n;i++) delete[] *(room+i);
        delete[] room;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
void func(int x,int y, direction vec){
	if(x >= n || x < 0) return;
	if(y >= n || y < 0) return;
	//
	int tmp = room[y][x];
	int _x=x,_y=y;
	switch((tmp > 100) ? tmp-100 : tmp){
		// 거울이 없는 경우 
		case 0:
			if(vec == RIGHT || vec == LEFT) _x = (vec == RIGHT) ? x+1 : x-1;
			else if(vec == UP || vec == DOWN) _y = (vec == UP) ? y-1 : y+1;
			func(_x,_y,vec);
			break;
		// 거울이 우측상단 -> 좌측하단  /
		case 1:
			if(vec == RIGHT || vec == LEFT) _y = (vec == RIGHT) ? y-1 : y+1;
			else if(vec == UP || vec == DOWN) _x = (vec == UP) ? x+1 : x-1; 
			if(vec == RIGHT || vec == LEFT) vec = (_y > y) ? DOWN : UP;
			else if(vec == UP || vec == DOWN) vec = (_x > x) ? RIGHT : LEFT;
			if(room[y][x] < 100){
				res++;
				room[y][x] += 100;
			}
			func(_x,_y,vec);
			break;
		// 거울이 좌측상단 -> 우측하단 
		case 2:
			if(vec == RIGHT || vec == LEFT) _y = (vec == RIGHT) ? y+1 : y-1;
			else if(vec == UP || vec == DOWN) _x = (vec == UP) ? x-1 : x+1;
			if(vec == RIGHT || vec == LEFT) vec = (_y > y) ? DOWN : UP;
			else if(vec == UP || vec == DOWN) vec = (_x > x) ? RIGHT : LEFT;
			if(room[y][x] < 100){
				res++;
				room[y][x] += 100;
			}
			func(_x,_y,vec);
			break;
	}

	return;
}
