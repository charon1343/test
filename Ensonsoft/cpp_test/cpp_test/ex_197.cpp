//#include<iostream>
//using namespace std;
//
//class SingleList;
//class Node{
//public:
//	Node(const int& _data,Node* _next=0)
//		:data(_data),next(_next){}
//private:
//	int data;
//	Node* next;
//	friend class SingleList;
//};
//class SingleList{
//private:
//	int sizes;
//public:
//	SingleList();
//	~SingleList();
//	void add(const int& n);
//	void print();
//	int pop();
//	void erase();
//	int size(){return sizes;}
//protected:
//	Node* head;
//	Node* end;
//};
//SingleList::SingleList(){
//	head =0;
//	end =0;
//	sizes =0;
//}
//SingleList:: ~SingleList(){
//	cout<<"--end signlelist--"<<endl;
//	while(head!=0){
//		Node* p=head;
//		head = head ->next;
//		delete p;
//	}
//	sizes = 0;
//}
//void SingleList::add(const int& newdata){
//	Node* newNode;
//	if(head==0){
//		newNode = new Node(newdata,0);
//		head = end = newNode;
//	}else{
//		newNode = new Node(newdata,head);
//		head = newNode;
//	}
//	sizes++;
//}
//int SingleList::pop(){
//	int tmp = 0;
//	if(head){
//		Node* temp = head;
//		tmp = head->data;
//		head = head->next;
//		delete temp;
//	}
//	sizes--;
//	return tmp;
//}
//void SingleList::erase(){
//	while(head!=0){
//		pop();
//	}
//}
//void SingleList::print(){
//	Node* p = head;
//	cout<<"[";
//	while(p!=0){
//		cout<<p->data<<",";
//		p=p->next;
//	}
//	cout<<"\b\b]"<<endl;
//}
//int main(){
//	SingleList intSingleList;
//
//	for(int i=0;i<50;++i){
//		intSingleList.add(i);
//		cout<<"<"<<intSingleList.size()<<">";
//	}
//	cout<<endl;
//
//	intSingleList.print();
//
//	cout<<intSingleList.pop()<<"<----"<<endl;
//	cout<<intSingleList.pop()<<"<<----"<<endl;
//	cout<<intSingleList.pop()<<"<<----"<<endl;
//
//	cout<<intSingleList.size()<<">"<<endl;
//	intSingleList.print();
//	intSingleList.erase();
//	cout<<"<"<<intSingleList.size()<<">"<<endl;
//	intSingleList.print();
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}