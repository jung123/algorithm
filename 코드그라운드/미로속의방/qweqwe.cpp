// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <stdlib.h>
void get_num(int x, int y, int n);
void move(int *x, int *y,char ch);

int main() {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
	            // �����ӿ����� x,y�� ����
	            //move(&x,&y,ch);
	            // x,y�� ����ó�� ( x,y > 1)
	            if((x < 1) || (x > n)) return 0;
	            if((y < 1) || (y > n)) return 0;
	            // ����
				get_num(x, y, n);
				x++;
				}
				y++;
				printf("\n");
        }
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
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
