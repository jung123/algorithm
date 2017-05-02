// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
//#include <time.h>

int rank_block[300000];	// ���� ��� 
unsigned long long score[300000];		// ���� �迭 
 
void sort(int low,int high);
int quick_sort(int low, int high);

int main(void) {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        // �������� �� �ޱ�  
        scanf("%d",&n);
        if(n <0 || n>300000) return 0;
		if(n==1){
			printf("Case #%d\n", test_case);
			printf("1\n");
			continue;
		} 
        // ���� �� �����ޱ� 
        for(i=0;i<n;i++){
        	//	�����ޱ�
			scanf("%d",&k);
			score[i] = k; 
		}
		// ����
		sort(0,n-1);
		// �����Ѱ� ����ϱ� 
		/*
		for(i=0;i<n;i++){
        	//	�����ޱ�
			printf("%d ",score[i]); 
		}
		printf("\n");
		*/
        // ranking_block �����
        k=0;
        rank_block[k] =1;
        for(i=0;i<n-1;i++){
        	if(score[i] == score[i+1]) rank_block[k] += 1;
        	else rank_block[++k] =1;
		}
		/*
		for(i=0;i<k;i++){
        	//	�����ޱ�
			printf("%d ",rank_block[i]); 
		}
		printf("\n");
		*/
        // �˰��� �κ�
        tmp = n-1;
		for(i=0;i<n;i++){
			for(j=k;j>=0;j--){
				// ���⼭ ������ �߻��ߴ� !!!!
				// �̰� �ٽ� Ȯ������ !! 
				if(score[tmp] == score[i]){
					j = -1;
					break;
				}
				// �̶��� ����� ���ɼ��� ���� ����̴�. 
				if(score[tmp] + rank_block[j] > score[i] + n) break;
				tmp = tmp - rank_block[j];
			}
			if(j < 0) number++;
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n",number);
	}
	//end = clock();
//	printf("\n�ɸ��ð� : %f\n",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
void sort(int low,int high){
	int mid;
	//for(i=0;i<5;i++) printf("%d ",score[i]);
	//printf("\n");
	if(high <= low) return;
	mid = quick_sort(low, high+1);
	//
	if(mid <= low) return;
	// ���ٵ� ���⼭ ���� �����̴�.
	// �����Ľ� �ߺ����� �����ΰͰ���. 
	if(score[low] != score[mid]) sort(low,mid);
	if(score[mid+1] != score[high]) sort(mid+1,high);
	return;
}
int quick_sort(int low, int high){
	int k=low;
	int tmp;
	while(1){
		// ������ score[k]���� ���� ���� ���ö����� 
		while(score[++low] <= score[k]) {};
		// ������ score[k]���� ���ų� ū���� ���� ���� 
		while(score[--high] > score[k]) {};
		//
		if(high < low) break;
		// swap 
		tmp = score[high];
		score[high] = score[low];
		score[low] = tmp;
	}
	// ������ swap 
	if(k == high) return high;
	tmp = score[high];
	score[high] = score[k];
	score[k] = tmp;
	return high;
}


