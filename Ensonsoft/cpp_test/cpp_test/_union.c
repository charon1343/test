//#include <stdio.h>
//
//union u_data{
//	int d1;
//	double d2;
//	char d3;
//};
//
//int main(void)
//{
//	union u_data data;
//
//	data.d2=3.3;
//	printf("%d, %f, %c \n",data.d1, data.d2, data.d3);
//
//	data.d1=2;
//	printf("%d, %f, %c \n",data.d1, data.d2, data.d3);
//
//	data.d3='a';
//	printf("%d, %f, %c \n",data.d1, data.d2, data.d3);
//	
//	return 0;
//}