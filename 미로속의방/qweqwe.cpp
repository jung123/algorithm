// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <stdlib.h>
void get_num(int x, int y, int n);
void move(int *x, int *y,char ch);

int main() {
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int TC;
	int test_case;
    int x,y;
	int sum_xy = 0;
    int n, k, i, sum;
    char ch;
	scanf("%d", &TC);
	if(TC >50 || TC <1) return 0;
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        x = y = 1;
        sum = 1;
        scanf("%d",&n);
		if(n <2 || n >100000) return 0;
        //if(k <1 || k>300000) return 0;
        getchar();
        int j;
        for(i=0;i<n;i++){
        	x=1;
        	for(j=0;j<n;j++){
	            // 움직임에따른 x,y값 수정
	            //move(&x,&y,ch);
	            // x,y값 예외처리 ( x,y > 1)
	            if((x < 1) || (x > n)) return 0;
	            if((y < 1) || (y > n)) return 0;
	            // 로직
				get_num(x, y, n);
				x++;
				}
				y++;
				printf("\n");
        }
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
void move(int *x, int *y, char ch){
	switch(ch){
		case 'U' : *y = *y - 1;	break;
		case 'D' : *y = *y + 1; break;
		case 'L' : *x = *x - 1; break;
		case 'R' : *x = *x + 1; break;
	}
}
void get_num(int x, int y, int n){
    int sum = x+y;
    int val = 0;
    int j;
    //
    if(x== 1 && y == 1)	{
    	printf("%5d ",x);
    	return;	
	}
    if(x == n && y ==n){
    	printf("%5d ",n*n);
    	return;	
	}
    if(sum <= n+1){
        for(j=1;j<=sum-2;j++){
        	val = val + j;
		}
		if(sum % 2 != 0) val = val + y;
		else val = val + sum - y;		
    }else if(sum > n+1){
    	for(j=1;j<n+1;j++){
        	val = val + j;
		}
		int tmp = n-1;
		for(j=n+2;j<sum;j++){
			val = val + tmp--;
		}
	//	printf("sum %d %d\n",sum, y);
		y = y - (sum - (n+1));
		if(sum % 2 != 0) val = val+y;
		else val = val +(tmp + 1 -y);
	}
    //printf("x : %d y : %d val : %d\n",x,y,val);
    printf("%5d ",val);
}
