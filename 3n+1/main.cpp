#include <cstdio>
#include <iostream>
using namespace std;

void func(unsigned long long int x, int i);
int res;
int small;
unsigned long long int large;

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int x,j;
	unsigned long long int i;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        x = 0;
        large = 1;
        cin >> x;
        large = (x == 0) ? 1 : large << x;
        
        for(i=1;i<=large;i++){
        	res = 0;
	        func(i,0);
	        if(res == x){
	        	//cout << "-------------------------" << endl;
	        	//cout << "res = " << res << " x = " << x << "\n";
	        	small = i;
				break;
			}
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        printf("%d %llu\n",small,large);
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
void func(unsigned long long int x, int i){
	if(x <= 1) return;
	// res는 몇번 함수가 호출됬는지 마지막 1은 제외한다.
	res++;
	return (x % 2 == 0) ? func(x/2, i+1) : func(3*x + 1, i+1);
}
