#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	int test_case;
    int n,m;
	int res;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d",&n);
        scanf("%d",&m);
        //
        if((n%2 == 0)&&(m%2 == 0)){ // 가로세로 모두 짝수 
        	res = ((n*m)/2)-2; 
		}else {						// 모두 짝수가 아닌 경우 
			res = ((n*m)/2)-1;
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n",res);
        
	}

	return 0;
}
