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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        scanf("%d",&n);
        scanf("%d",&m);
        //
        if((n%2 == 0)&&(m%2 == 0)){ // ���μ��� ��� ¦�� 
        	res = ((n*m)/2)-2; 
		}else {						// ��� ¦���� �ƴ� ��� 
			res = ((n*m)/2)-1;
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n",res);
        
	}

	return 0;
}
