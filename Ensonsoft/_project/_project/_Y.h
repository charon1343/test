#include<iostream>

using namespace std;

int Ystrlen(char* a)
{
	char* _a = a;
	int len = 0;

		while(*_a!='\0')
		{
			_a++;
			len++;
		}
		return len;
}

int Ystrcmp(char* a,char* b)
{
	char* _a = a;
	char* _b = b;

	while(*_a!='\0'||*_b!='\0')
	{
		if(*_a>*_b)
			{
				return 1;
			}
		else if(*_a<*_b)
			{
				return -1;
			}
		_a++;
		_b++;
	}
	return 0;
}
int Ystrncmp(char* a,char* b,int n)
{
	char* _a = a;
	char* _b = b;
	int i = 0;
	int _n = n;

	while((*_a!='\0'||*_b!='\0')&&i!=n)
	{
		if(*_a>*_b)
			{
				return 1;
			}
		else if(*_a<*_b)
			{
				return -1;
			}
		_a++;
		_b++;
		i++;
	}
	return 0;
}

int Ystrchr(char* a,char b)
{
	char* _a = a;
	int len = 0;

	while(*_a!='\0')
	{
		len++;
		if(*_a==b)
		{
			return len;
		}
		_a++;
	}
	return 0;
}
char* Ystrcpy_s(char* a,int aSize,char* b)
{
	char* _a = a;
	char* _b = b;
	int _aSize = aSize;

	if(_aSize<Ystrlen(b))
	{
		cout<<"size error"<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<_aSize;i++)
		{
			while(*_b!='\0')
			{
				*_a=*_b;
				_a++;
				_b++;
				i++;
			}
			*_a='\0';
		}
		
	}
	return a;

}

char* Ystrcat_s(char* a,int aSize,char* b)
{
	
	char* _a = a;
	char* _b = b;
	int _aSize = aSize;
	if(_aSize<(Ystrlen(a)+Ystrlen(b)))
	{
		printf("size error\n");
		return 0;
	}
	else
	{
		for(int i=0;i<aSize;i++)
		{
			while(*_a!='\0')
			{
				_a++;
				i++;
			}
			while(*_b!='\0')
			{
				*_a=*_b;
				_a++;
				_b++;
				i++;
			}
			*_a='\0';
		}
		return a;
	}
	
}
char* Ystrncat_s(char* a,int aSize,char* b,int bSize)
{
	char* _a = a;
	char* _b = b;
	int _aSize = aSize;
	int _bSize = bSize;

	if(_aSize<(Ystrlen(a)+bSize))
	{
		printf("size error\n");
		return 0;
	}
	else
	{
		for(int i=0;i<Ystrlen(a)+bSize-1;i++)
		{
			while(*_a!='\0')
			{
				_a++;
				i++;
			}
			for(int j=0;j<bSize&&*_b!='\0';j++,i++)
			{
				*_a=*_b;
				_a++;
				_b++;
			}
			*_a='\0';	
		}
		return a;
	}
}
char* Ystrstr(char* a,char* b)
{
	char* _a = a;
	char* _b = b;

	if(Ystrlen(a)<Ystrlen(b))
	{
		printf("size error\n");
		return 0;
	}
	else
	{
		while(*_a!='\0')
		{
			while(*_a==*_b)
			{
				_a++;
				_b++;
				if(*_b=='\0')
				{
					_a-=Ystrlen(b);
					return _a;
				}
			}
			_b=b;
		}
		return 0;
	}
}
