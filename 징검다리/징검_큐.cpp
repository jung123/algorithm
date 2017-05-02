#include <cstdio>
#include <iostream>

using namespace std;

// 전역변수 
int ston[50000];

// object
class myPos {
	public :
		myPos();
		myPos(int p, int k);
		~myPos();
		
		myPos *next();
		void setLink(myPos* tmp);
		int getPosition();
		int getInk();

	private :
		int position;
		int ink;
		myPos *link;
}; 
// 큐 구현
class my_queue {
	public :
		~my_queue();	// 소멸자
		my_queue();
		
		myPos* newObject(int pos, int k);
		void enqueue(int pos, int k);
		myPos* dequeue();
		int algorithm(int n, int k);
		void delete_queue();
	private :
		int len;
		myPos *pmyPosHead;
		myPos *pmyPosTail;
};

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	   C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
    int n, k, l, i, tmp, res;
    myPos *tmp_pos = NULL;
    my_queue queue;
    
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		// 초기화 
		tmp_pos = NULL;
		n = k = l = i = tmp = res = 0;
        // 입력받기 
		cin >> n;
        cin >> k;
        cin >> l;
        printf("%d %d %d\n",n,k,l);
        // 지뢰깔기 
        for(i=0;i<l;i++){
        	cin >> tmp;
        	ston[tmp] = 1;
		}
        // 초기 k만큼 enqueue하기 
        for(i=1;i<=k;i++){
        	if(ston[i] != 1){
        		// 초기에 queue에 값을 넣기 ! 
        		queue.enqueue(i,i);
			}
		}
        // 경우의 수 구하기
        res = queue.algorithm(n,k);
        queue.delete_queue();
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        printf("%d\n",res);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

myPos::myPos()
:position(0),ink(0),link(NULL) {};
myPos::myPos(int p, int k)
:position(p),ink(k),link(NULL) {};
myPos::~myPos()
{
	position = ink = 0;
}
myPos *myPos::next(){
	return link;
}
void myPos::setLink(myPos* tmp)
{
	link = tmp;
}
int myPos::getPosition(){
	return position;
}
int myPos::getInk(){
	return ink;
}
///////
///////
my_queue::~my_queue()
{
	myPos *tmp = pmyPosHead;
	myPos *tmp_delete = NULL;
	// queue 비우기
	while(tmp != NULL){
		tmp_delete = tmp;
		tmp = tmp->next();
		delete tmp_delete;
	}
	//
	len =0;
	pmyPosHead = pmyPosTail = NULL;
}
my_queue::my_queue()
:len(0), pmyPosHead(NULL), pmyPosTail(NULL) {};

myPos* my_queue::newObject(int pos, int k){
	myPos *tmp = new myPos(pos,k);
	if(tmp == NULL) cout << "newObject() myPos 생성에 실패했습니다." << endl;
	return tmp;
}
void my_queue::enqueue(int pos, int k){
	myPos *tmp = this->newObject(pos, k);
	printf("enqueue() position : %d k : %d\n",pos,k);
	if(pmyPosTail == NULL){
		pmyPosHead = pmyPosTail = tmp;
	}
	else {
		pmyPosTail->setLink(tmp);
		pmyPosTail = tmp;
	}
	this->len++;
	
}
myPos* my_queue::dequeue()
{
	if(pmyPosHead == NULL){
		//cout << "queue가 비었습니다. !!" << endl;
		return pmyPosHead;
	}else if(pmyPosHead == pmyPosTail){
		myPos *tmp = pmyPosHead;
		this->pmyPosHead = this->pmyPosTail = NULL;
		this->len--;
		return tmp;
	}else{
		myPos *tmp = pmyPosHead;
		pmyPosHead = tmp->next();
		this->len--;
		printf("dequeue() position : %d ink : %d\n",tmp->getPosition(),tmp->getInk());
		return tmp;
	}
}
int my_queue::algorithm(int n, int k)
{
	// n == 돌의 갯수
	// k == 최대 점프거리 
	myPos *tmp = NULL;
	int position = 0;
	int ink = 0;
	int i;
	unsigned int res = 0;
	//
	while((tmp = this->dequeue()) != NULL){
		position = tmp->getPosition();
		// 도착하지 않은경우 
		ink = tmp->getInk();
		for(i=1;i<=k;i++){
		// 지뢰가 없는 경우 와 같은 거리를 점프하지 않을 때 
			if((ston[position + i] != 1) && (i != ink)){
				if(position + i >= n) res++;
				else{
					this->enqueue(position+i,i);	
				} 
			}
		}	
		delete tmp;
	}
	return (res % 1000000009);
}
void my_queue::delete_queue(){
	myPos *tmp = pmyPosHead;
	myPos *tmp_delete = NULL;
	// queue 비우기
	while(tmp != NULL){
		tmp_delete = tmp;
		tmp = tmp->next();
		delete tmp_delete;
	}
	//
	len =0;
	pmyPosHead = pmyPosTail = NULL;
}
