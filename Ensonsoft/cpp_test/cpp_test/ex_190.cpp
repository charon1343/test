//#include<cstdlib>
//#include<string>
//#include<vector>
//#include<iostream>
//using namespace std;
//int main(){
//	vector<int> v;
//
//	v.push_back(5);
//	v.push_back(6);
//	v.push_back(3);
//	v.push_back(7);
//	v.push_back(4);
//	v.push_back(8);
//	v.push_back(2);
//	v.push_back(9);
//
//	cout<<"엘리먼트 개수"<<v.capacity()<<endl;
//	cout<<"엘리먼트 개수"<<v.size()<<endl;
//
//	cout<<"3번째 수"<<v[3]<<endl;
//	cout<<"3번째 수"<<v.at(3)<<endl;
//	v.insert(v.begin()+3,-6);
//	cout<<"3번째 수"<<v[3]<<endl;
//	cout<<"4번째 수"<<v.at(4)<<endl;
//
//	cout<<"첫번째 수"<<v.front()<<endl;
//	cout<<"마지막 수"<<v.back()<<endl;
//
//	v.erase(v.end()-1);
//	cout<<"엘리먼트 개수"<<v.size()<<endl;
//
//	vector<int>::iterator iter = v.begin();
//
//	cout<<iter[3]<<endl;
//	iter[4]=-9;
//	cout<<*iter<<endl;
//	cout<<"----------------"<<endl;
//	for(iter=v.begin();iter!=v.end();iter++){
//		cout<<*iter<<" ";
//	}
//	cout<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
