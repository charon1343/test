//#include<cmath>
//#include<iostream>
//#include<cstring>
//#include<cstdlib>
//using std::endl;
//using std::cout;
//using std::ostream;
//using std::istream;
//using std::cin;
//struct strMat{
//	double** mat;
//	int row;
//	int col;
//	strMat(int _row,int _col,double **_mat){
//		row=_row;
//		col=_col;
//		mat = new double*[_row];
//		int colsize = _col*sizeof(double);
//		for(int i=0;i<row;i++){
//			mat[i] = new double[_col];
//				memset(mat[i],0,colsize);
//			if(_mat)memcpy(mat[i],_mat[i],colsize);
//		}
//	}
//	~strMat(){
//		for(int i=0;i<row;i++){
//			delete[] mat[i];
//		}
//		delete[] mat;
//	}
//};
//class Matrixs{
//private:
//	strMat* _matrix;
//	Matrixs reverse();
//public:
//	int getRow() const{return _matrix->row;}
//	int getCol() const{return _matrix->col;}
//	double getVal(int low,int col) const{
//		return _matrix->mat[low][col];
//	}
//	Matrixs(const Matrixs& m);
//	Matrixs(int row=5,int col=5){
//		_matrix = new strMat(row,col,0);
//	}
//	~Matrixs(){
//		if(_matrix) delete _matrix;
//	}
//	friend ostream& operator<<(ostream& os,const Matrixs& m);
//	friend istream& operator>>(istream& ios,Matrixs& m);
//	double Matrixs::operator()(int i,int j) const;
//	void setMatrix(double* readM,int row,int col);
//	Matrixs& operator= (const Matrixs& m);
//	Matrixs& operator+= (const Matrixs& m);
//	Matrixs& operator-= (const Matrixs& m);
//	Matrixs& operator*= (double C);
//	Matrixs& operator*= (const Matrixs& m);
//	friend Matrixs operator+(const Matrixs& mal, const Matrixs& ma2);
//	friend Matrixs operator-(const Matrixs& mal, const Matrixs& ma2);
//	friend Matrixs operator*(const Matrixs& mal, const Matrixs& ma2);
//	friend Matrixs operator!(const Matrixs& mal);
//};
//void Matrixs::setMatrix(double* readM,int row,int col){
//	for(int i=0;i<row;i++){
//		for(int j=0;j<col;i++){
//			_matrix->mat[i][j]=*(readM+i*col+j);
//		}
//	}
//}
//Matrixs::Matrixs(const Matrixs& m){
//	int row=m.getRow();
//	int col=m.getCol();
//	_matrix=new strMat(row,col,m._matrix->mat);
//}
//ostream& operator<<(ostream& os,const Matrixs& m){
//	int row=m.getRow();
//	int col=m.getCol();
//	for(int i=0;i<row;i++){
//		for(int j=0;j<col;j++){
//			os<<m(i,j)<<"\t";
//		}
//		os<<endl;
//	}
//	return os;
//}
//istream& operator>>(istream& ist,Matrixs& m){
//	int row=m.getRow();
//	int col=m.getCol();
//	double temp=0.0;
//	for(int i=0;i<row;i++){
//		for(int j=0;j<col;j++){
//			ist>>temp;
//			m._matrix->mat[i][j]=temp;
//		}
//	}
//	return ist;
//}
//Matrixs& Matrixs::operator=(const Matrixs& m){
//	if(this==&m)return *this;
//	int row=m.getRow();
//	int col=m.getCol();
//	if(_matrix){
//		delete _matrix;
//		_matrix = new strMat(row,col,m._matrix->mat);
//	}else{
//		_matrix=m._matrix;
//	}
//	return *this;
//}
//
//double Matrixs::operator()(int i,int j)const{
//	return _matrix->mat[i][j];
//}
//Matrixs& Matrixs::operator+=(const Matrixs& m){
//	for(int i=0;i<_matrix->row;i++)
//		for(int j=0;j<_matrix->col;j++)
//			_matrix->mat[i][j] += m(i,j);
//	return *this;
//}
//Matrixs& Matrixs::operator-=(const Matrixs& m){
//	for(int i=0;i<_matrix->row;i++)
//		for(int j=0;j<_matrix->col;j++)
//			_matrix->mat[i][j] -= m(i,j);
//	return *this;
//}
//Matrixs& Matrixs::operator*=(double C){
//	for(int i=0;i<_matrix->row;i++)
//		for(int j=0;j<_matrix->col;j++)
//			_matrix->mat[i][j] *= C;
//	return *this;
//}
//Matrixs& Matrixs::operator*=(const Matrixs& m){
//	int row = _matrix->row;
//	int col = m.getCol();
//	int klen= _matrix->col;
//	Matrixs tmx(row,col);
//	for(int i=0;i<row;i++)
//		for(int j=0;j<col;j++){
//			tmx._matrix->mat[i][j]=0;
//			for(int k=0;k<klen;k++){
//				tmx._matrix->mat[i][j]+=(_matrix->mat[i][k]*m(k,j));
//			}
//		}
//		*this = tmx;
//		return *this;
//}
//Matrixs operator+(const Matrixs& mal,const Matrixs& ma2){
//	Matrixs tmx = mal;
//	tmx += ma2;
//	return tmx;
//}
//Matrixs operator-(const Matrixs& mal,const Matrixs& ma2){
//	Matrixs tmx = mal;
//	tmx -= ma2;
//	return tmx;
//}
//Matrixs operator*(const Matrixs& mal,const Matrixs& ma2){
//	Matrixs tmx = mal;
//	tmx *= ma2;
//	return tmx;
//}
//Matrixs operator!(const Matrixs& m){
//	Matrixs tmx = m;
//	return tmx.reverse();
//}
//Matrixs Matrixs::reverse(){
//	int row=getRow();
//	int col=getCol();
//	int i=0,j=0,k=0,temp=0;
//	double pivot=0.0;
//	double max=0.0,piv=1.0;
//	double piv2=1.0;
//	Matrixs self(row,col);
//	strMat *r = new strMat(row,2*col,0);
//	int sizes=(col*2)*sizeof(double);
//	for(i=0;i<row;i++){
//		memcpy(r->mat[i],_matrix->mat[i],sizes/2);
//		r->mat[i][i+col]=1.0;
//	}
//	double *tempmtrix = new double[2*col];
//	for(k=0;k<row;k++){
//		max=0.0;
//		temp=k;
//		for(j=k;j<row;j++){
//			if(fabs(r->mat[j][k])>max){
//				max=fabs(r->mat[j][k]);
//				temp=j;
//			}
//		}
//		memset(tempmtrix,0,sizes);
//		memcpy(tempmtrix,r->mat[temp],sizes);
//		memcpy(r->mat[temp],r->mat[k],sizes);
//		memcpy(r->mat[k],tempmtrix,sizes);
//
//		pivot=r->mat[k][k];
//		for(j=k;j<2*2;j++){
//			r->mat[k][j]=r->mat[k][j]/pivot;
//		}
//		for(i=0;i<row;i++){
//			if(i!=k){
//				piv=r->mat[i][k];
//				for(j=0;j<row;j++){
//					r->mat[i][j]-=piv*r->mat[k][j];
//					r->mat[i][j+col]-=piv*r->mat[k][j+col];
//				}
//			}
//		}
//	}
//	for(i=0;i<row;i++){
//		for(j=0;j<col;j++){
//			self._matrix->mat[i][j]=r->mat[i][j+col];
//		}
//	}
//	delete [] tempmtrix;
//	delete r;
//	return self;
//}
//int main(){
//	Matrixs mat(3,3);
//	Matrixs mat2(3,1);
//
//	cout<<"---- 3x3-----"<<endl;
//	cin>>mat;
//	cout<<"---- 3x3-----"<<endl;
//	cout<<mat;
//	cout<<"---- 3x1-----"<<endl;
//	cin>>mat2;
//	cout<<"---- 3x1-----"<<endl;
//	cout<<mat2;
//	cout<<"---- 역행렬을 이용한 연립방정식 해-----"<<endl;
//	Matrixs mat3 = mat*(!mat2);
//	cout<<mat3;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}