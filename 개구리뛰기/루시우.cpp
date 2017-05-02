// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
using namespace std;
int *ston;

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
	int n, k;
	int i, status, jump;
    
	scanf("%d", &TC);	// cin ��� ����
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		//
		status = jump = 0;
		// ������ ���� �Է¹ޱ�. 
        cin >> n;
        ston = new int [n+1];
        if(ston == NULL){
        	cout << "�����Ҵ� ����!\n";
        	return 0;
		}
		// ������ ��ǥ �Է¹ޱ� 
		for(i=1;i<n+1;i++){
			cin >> ston[i];
		}
		// �ִ� �����Ÿ� �Է¹ޱ�
		cin >> k;
		// �˰��� 
		int tmp;
		i=1;
        while(status != ston[n]){
        	if(k + status > ston[i] ){
        		if(i == n){
    				jump++;
    				break;
				}
				i++;					
			}
    		else if(k + status == ston[i]){
    			status = ston[i++];
				jump++;	
			}
    		else{
    			if(ston[i] - ston[i-1] > k){
    				jump = -1;
    				break;
				}
    			status = ston[--i];
				jump++;	
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
        cout << jump << endl;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
