// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int score[101];
int func(int k){
	int i=100;
	long long res = 0;
	while(1){
		if(score[i] == 0){
			i--;
			continue;
		}
		if(k - score[i] >= 0){
			res += (i * score[i]);
			k = k - score[i];
			if(k == 0) return res;
		}else{
			while(k != 0 ){
				res += i;
				k--;
			}
			return res;
		}
		i--;
	}
}
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
	//
	int n,k,i,tmp;
	long long res;
	//
	scanf("%d", &TC);	// cin ��� ����
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		n = k = res = 0;
		memset(score,0,sizeof(int) * 101);
		cin >> n;
		cin >> k;
    	for(i=0;i<n;i++){
    		cin >> tmp;
    		score[tmp]++;
		}
		res = func(k);
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		cout << res << "\n";
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
