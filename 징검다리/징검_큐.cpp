#include <cstdio>
#include <iostream>

using namespace std;

// �������� 
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
// ť ����
class my_queue {
	public :
		~my_queue();	// �Ҹ���
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
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	   C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   ���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
    int n, k, l, i, tmp, res;
    myPos *tmp_pos = NULL;
    my_queue queue;
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		// �ʱ�ȭ 
		tmp_pos = NULL;
		n = k = l = i = tmp = res = 0;
        // �Է¹ޱ� 
		cin >> n;
        cin >> k;
        cin >> l;
        printf("%d %d %d\n",n,k,l);
        // ���ڱ�� 
        for(i=0;i<l;i++){
        	cin >> tmp;
        	ston[tmp] = 1;
		}
        // �ʱ� k��ŭ enqueue�ϱ� 
        for(i=1;i<=k;i++){
        	if(ston[i] != 1){
        		// �ʱ⿡ queue�� ���� �ֱ� ! 
        		queue.enqueue(i,i);
			}
		}
        // ����� �� ���ϱ�
        res = queue.algorithm(n,k);
        queue.delete_queue();
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
        printf("%d\n",res);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
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
	// queue ����
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
	if(tmp == NULL) cout << "newObject() myPos ������ �����߽��ϴ�." << endl;
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
		//cout << "queue�� ������ϴ�. !!" << endl;
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
	// n == ���� ����
	// k == �ִ� �����Ÿ� 
	myPos *tmp = NULL;
	int position = 0;
	int ink = 0;
	int i;
	unsigned int res = 0;
	//
	while((tmp = this->dequeue()) != NULL){
		position = tmp->getPosition();
		// �������� ������� 
		ink = tmp->getInk();
		for(i=1;i<=k;i++){
		// ���ڰ� ���� ��� �� ���� �Ÿ��� �������� ���� �� 
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
	// queue ����
	while(tmp != NULL){
		tmp_delete = tmp;
		tmp = tmp->next();
		delete tmp_delete;
	}
	//
	len =0;
	pmyPosHead = pmyPosTail = NULL;
}
