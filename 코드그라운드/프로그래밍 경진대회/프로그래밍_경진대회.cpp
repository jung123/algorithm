// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
//#include <time.h>

int rank_block[300000];	// 순위 블록 
unsigned long long score[300000];		// 점수 배열 
 
void sort(int low,int high);
int quick_sort(int low, int high);

int main(void) {
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
//	freopen("test.txt", "r", stdin);
//	time_t start,end;
//	start = clock();
	
	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int n,i,k,j,tmp;
	int number =0;
	
	scanf("%d", &TC);
	if(TC > 5 || TC < 0) return 0;
	
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        // 응시자의 수 받기  
        scanf("%d",&n);
        if(n <0 || n>300000) return 0;
		if(n==1){
			printf("Case #%d\n", test_case);
			printf("1\n");
			continue;
		} 
        // 정렬 및 점수받기 
        for(i=0;i<n;i++){
        	//	점수받기
			scanf("%d",&k);
			score[i] = k; 
		}
		// 정렬
		sort(0,n-1);
		// 정렬한거 출력하기 
		/*
		for(i=0;i<n;i++){
        	//	점수받기
			printf("%d ",score[i]); 
		}
		printf("\n");
		*/
        // ranking_block 만들기
        k=0;
        rank_block[k] =1;
        for(i=0;i<n-1;i++){
        	if(score[i] == score[i+1]) rank_block[k] += 1;
        	else rank_block[++k] =1;
		}
		/*
		for(i=0;i<k;i++){
        	//	점수받기
			printf("%d ",rank_block[i]); 
		}
		printf("\n");
		*/
        // 알고리즘 부분
        tmp = n-1;
		for(i=0;i<n;i++){
			for(j=k;j>=0;j--){
				// 여기서 문제가 발생했다 !!!!
				// 이거 다시 확인하자 !! 
				if(score[tmp] == score[i]){
					j = -1;
					break;
				}
				// 이때는 우승할 가능성이 업는 경우이다. 
				if(score[tmp] + rank_block[j] > score[i] + n) break;
				tmp = tmp - rank_block[j];
			}
			if(j < 0) number++;
		}
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n",number);
	}
	//end = clock();
//	printf("\n걸린시간 : %f\n",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
void sort(int low,int high){
	int mid;
	//for(i=0;i<5;i++) printf("%d ",score[i]);
	//printf("\n");
	if(high <= low) return;
	mid = quick_sort(low, high+1);
	//
	if(mid <= low) return;
	// 딱바도 여기서 나온 예외이다.
	// 퀵정렬시 중복숫자 문제인것같다. 
	if(score[low] != score[mid]) sort(low,mid);
	if(score[mid+1] != score[high]) sort(mid+1,high);
	return;
}
int quick_sort(int low, int high){
	int k=low;
	int tmp;
	while(1){
		// 기준인 score[k]보다 작은 수가 나올때까지 
		while(score[++low] <= score[k]) {};
		// 기준인 score[k]보다 같거나 큰수가 나올 때까 
		while(score[--high] > score[k]) {};
		//
		if(high < low) break;
		// swap 
		tmp = score[high];
		score[high] = score[low];
		score[low] = tmp;
	}
	// 기준점 swap 
	if(k == high) return high;
	tmp = score[high];
	score[high] = score[k];
	score[k] = tmp;
	return high;
}


