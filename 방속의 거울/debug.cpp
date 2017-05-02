// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
typedef enum {LEFT, RIGHT, UP, DOWN} direction;
using namespace std;
int **room;
int res,n;

void func(int x,int y, direction vec);

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
    int i,j;
	char buf[1000];
	
	scanf("%d", &TC);	// cin ��� ����
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		res = 0;
        // �氹�� �ޱ�
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
        // �˰���
        
		func(0,0,RIGHT);
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
        cout << res << endl;
        for(i=0;i<n;i++) delete[] *(room+i);
        delete[] room;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
void func(int x,int y, direction vec){
	if(x >= n || x < 0) return;
	if(y >= n || y < 0) return;
	//
	int tmp = room[y][x];
	int _x=x,_y=y;
	switch((tmp > 100) ? tmp-100 : tmp){
		// �ſ��� ���� ��� 
		case 0:
			if(vec == RIGHT || vec == LEFT) _x = (vec == RIGHT) ? x+1 : x-1;
			else if(vec == UP || vec == DOWN) _y = (vec == UP) ? y-1 : y+1;
			func(_x,_y,vec);
			break;
		// �ſ��� ������� -> �����ϴ�  /
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
		// �ſ��� ������� -> �����ϴ� 
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
