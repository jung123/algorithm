// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
using namespace std;

class quick_sort{
	public :
		// 함수
		void quick(int start, int last);
		int sort(int start, int last);
		void print();
		void start_quick();
		// 생성자
		quick_sort(int *_p,int start,int last);
		// 변수 
	private :
		int *p;
		int start,last;		
};
// 생성자 
quick_sort::quick_sort(int *_p,int _start, int _last)
{
	p = _p;
	start = _start;
	last = _last;
}
// 정의
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
		// 중복숫자 처리하기 위해서 다음 2줄이 중요하다 !! 
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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	//
	int n,k,res; 
    int i;
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
    	// 과목 수 : n, 공부가능한 수 : k
		n = k = res =0;
        cin >> n;
        cin >> k;
        int *p = new int [n]; 
        // 점수 입력받기. 
		for(i=0;i<n;i++){
			cin >> p[i];			
		}
		// sort가 필요하다 !! 
        quick_sort test(p,0,n-1);
		test.start_quick();
        // sort 후 k개의 과목점수를 받아오기 !!
		for(i=n-1;i>=n-k;i--){
			res += p[i];
		}
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
        cout << res << "\n";
        delete[] p;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
