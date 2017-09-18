// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
using namespace std;

class quick_sort{
	public :
		// �Լ�
		void quick(int start, int last);
		int sort(int start, int last);
		void print();
		void start_quick();
		// ������
		quick_sort(int *_p,int start,int last);
		// ���� 
	private :
		int *p;
		int start,last;		
};
// ������ 
quick_sort::quick_sort(int *_p,int _start, int _last)
{
	p = _p;
	start = _start;
	last = _last;
}
// ����
void quick_sort::quick(int start, int last){
	cout << "------------------------------------\n";
	print();
	if(start >= last) return;
	int mid;
	mid = sort(start, last+1);
	cout << "start = " << start << "mid = " << mid << "last = " << last << "\n";
	cout << "------------------------------------\n";
	//cout << "mid = " << mid << "\n";
	if(mid < start || mid >= last) return;
	quick(start, mid);
	quick(mid+1, last);
	return;
}
int quick_sort::sort(int start, int last){
	int tmp = start, i;
	while(1){
		while(p[++start] <= p[tmp]) {};
		cout << "start = " << start << "last = " << last << "\n";
		// �ߺ����� ó���ϱ� ���ؼ� ���� 2���� �߿��ϴ� !! 
		while(p[--last] >= p[tmp]) {
			if(last == tmp) break;
		};
 		cout << "start = " << start << "last = " << last << "\n";
		if(start > last) break;
		i = p[start];
		p[start] = p[last];
		p[last] = i;
	}
	if(p[last] == p[tmp]) return last;
	i = p[last];
	p[last] = p[tmp];
	p[tmp] = i;
	return last;
}
void quick_sort::print(){
	int i;
	for(i=0;i<=last;i++){
		cout << p[i] << " ";
	}
	cout << "\n";
}
void quick_sort::start_quick(){
	cout << "before ! \n";
	print();
	cout << "------------------------------------\n";
	quick(start,last);
	cout << "after ! \n";
	print();
	cout << "------------------------------------\n";
}
//

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
	int n,k,res; 
    int i;
	scanf("%d", &TC);	// cin ��� ����
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
    	// ���� �� : n, ���ΰ����� �� : k
		n = k = res =0;
        cin >> n;
        cin >> k;
        int *p = new int [n]; 
        // ���� �Է¹ޱ�. 
		for(i=0;i<n;i++){
			cin >> p[i];			
		}
		// sort�� �ʿ��ϴ� !! 
        quick_sort test(p,0,n-1);
		test.start_quick();
        // sort �� k���� ���������� �޾ƿ��� !!
		for(i=n-1;i>=n-k;i--){
			res += p[i];
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
        cout << res << "\n";
        delete[] p;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
