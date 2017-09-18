#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;
char ptr[1000][3];

int mysearch(int n,int pos, int dep, int length);

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int T;
	int test_case;
    int n,i,j,a,b;
    int num1,num2,num3,pos,res;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d %d",&(ptr[i][0]),&(ptr[i][1]),&(ptr[i][2]));
		}
        //
        num1 = mysearch(0,0,2,n);
        num2 = mysearch(0,1,2,n);
        num3 = mysearch(0,2,2,n);
        if((num1 > num2)&&(num1 > num3)){
        	pos = 0;
        	res = ptr[0][0];
		}else if((num2 > num1)&&(num2 > num3)){
			pos = 1;
			res = ptr[0][1];
		}else if((num3 > num1)&&(num3 > num2)){
			pos = 2;
			res = ptr[0][2];
		}
        //
        for(i=1;i<n;i++){
        	//
        	if(pos == 0){
				a = 1;
				b = 2;
			}else if(pos == 1){
				a = 0;
				b = 2;
			}else {
				a = 0;
				b = 1;
			}
        	//
        	if(mysearch(i,a,2,n) > mysearch(i,b,2,n)){
        		pos = a;
        		res += ptr[i][a];
			}else{
				pos = b;
				res += ptr[i][b];
			}
		}
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        printf("%d\n",res);
	}

	return 0;
}

int mysearch(int n,int pos, int dep, int length){
	if((length-1 == n)||(dep == 1)) return ptr[n][pos];
	int t1,t2;
	if(pos == 0){
		t1 = 1;
		t2 = 2;
	}else if(pos == 1){
		t1 = 0;
		t2 = 2;
	}else {
		t1 = 0;
		t2 = 1;
	}
	int a = mysearch(n+1,t1,length-1,length) + ptr[n][pos];
	int b = mysearch(n+1,t2,length-1,length) + ptr[n][pos];
	return (a > b ? a : b);
}
