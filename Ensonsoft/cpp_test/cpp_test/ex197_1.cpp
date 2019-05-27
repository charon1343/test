//#include<iostream>
//using namespace std;
//
//template<class T> class SingleList;
//template<class T>
//class Node{
//public:
//	Node(const T& _data,Node* _next=0)
//		:data(_data),next(_next){}
//private:
//	T data;
//	Node<T>* next;
//	friend class SingleList<T>;
//};
//template<class T>
//class SingleList{
//private:
//	int sizes;
//public:
//	SingleList();
//	~SingleList();
//	void add(const T&);
//	void Print();
//	T pop();
//	void erase();
//	int size(){return sizes;}
//
//protected:
//	Node<T>* head;
//	Node<T> *end;
//};
//
//template<class T>
//SingleList<T>::SingleList(){
//	head=0;
//	end =0;
//	sizes=0;
//}
//template<class T>
//SingleList<T>::~SingleList(){
//	cout<<"--end singlelist--"<<endl;
//	while(head!=0){
//		Node<T>*p = head;
//		head = head ->next;
//		delete p;
//	}
//	sizes=0;
//}
//
//template<class T>
//void SingleList<T>::add(const T& newdata){
//	Node<T>*newNode;
//	if(head==0){
//		newNode = new Node<T>(newdata,0);
//		head = end = newNode;
//	}else{
//		newNode = new Node<T>(newdata,head);
//		head=newNode;
//	}
//	sizes++;
//}
//template<class T>
//T SingleList<T>::pop(){
//	T tmp=0;
//	if(head){
//		Node<T>* temp=head;
//		tmp=head->data;
//		head=head->next;
//		delete temp;
//	}
//	sizes--;
//	return tmp;
//}
//template<class T>
//void SingleList<T>::erase(){
//	while(head!=0){
//		pop();
//	}
//}
//template<class T>
//void SingleList<T>::Print(){
//	Node<T>* p=head;
//	cout<<"[";
//	while(p!=0){
//		cout<<p->data<<",";
//		p=p->next;
//	}
//	cout<<"\b\b\b]"<<endl;
//}
//int main(){
//	SingleList<char> intSingleList;
//	for(int i=50;i<80;++i){
//		intSingleList.add(i);
//		cout<<"<"<<intSingleList.size()<<">";
//	}
//	cout<<endl;
//
//	intSingleList.Print();
//	cout<<intSingleList.pop()<<"<---"<<endl;
//	cout<<intSingleList.pop()<<"<---"<<endl;
//	cout<<intSingleList.pop()<<"<---"<<endl;
//
//	cout<<intSingleList.size()<<">"<<endl;
//	intSingleList.Print();
//	intSingleList.erase();
//	cout<<"<"<<intSingleList.size()<<">"<<endl;
//	intSingleList.Print();
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}