#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <time.h>


using namespace::std;

class ZeroDivideException
 
{
 
public:
 
 int idx;
 
 ZeroDivideException(int i)
 
 {
 
 idx = i;
 
 }
 
};
 
//����� ���������� "������ �� �������������� �����"
 
class SqrtException
 
{
 
public:
 
 int idx;
 
 SqrtException(int i)
 
 {
 
 idx = i;
 
 }
 
};
 
//����� ���������� "����� �� ������� �������� �������"
 
class IndexException
 
{
 
public:
 
 int idx;
 
 IndexException(int i)
 
 {
 
 idx = i;
 
 }
 
};
 
//������� ��������� ���������� �������� �������
 
void SetValue(double val,int i,int n,double* ar)
 
{
 
 if (val==0.0) //�������� ������ �� ����
 
 {
 
 ar[i] = 0.0;
 
 throw ZeroDivideException(i); 
 
 }
 
 
 
 if (i>=n) //������������ ������ �������
 
 throw IndexException(i);
 
 ar[i] = logf((val-1)/(val+1)); //���������� ��������
 
}
 
//������� ������ �������
 
void Set2(int i,int n,double* c)
 
{
 
if (c[i]<0) //�������� ������� ������ �� �����. �����
 
 {
 
 c[i] = 0.0;
 
 throw SqrtException(i);
 
 }
 
 
 if (i>=n) //������������ ������ �������
 
 throw IndexException(i);
 
//c[i]=sqrt(a[i]+b[i]) ; //���������� ��������
 
}
void Print(int i,int n,double* ar)
 
{
 
 if (i>=n) //������������ ������ �������
 
 throw IndexException(i);
 
 cout<<ar[i]<<' ';
 
}
 
 
 
int main(){
 setlocale(LC_ALL,"rus");
 int n;
 
 cout<<"Input n: "; //������ ������� �������
 
 cin>>n;
 
 double* a = new double[n];
 


 double x = -3.0;
 
 for (int i=0;x<=7.0;i++,x+=0.5)
 
 {
 
 try
 
 {
 
 SetValue(x,i,n,a); //�������� ������������ ������
 
 }
 
 catch (ZeroDivideException ex) //�������� ����������
 
 {
 
 cout<<"Zero divide error in index "<<ex.idx<<endl;
 
 }
 

 
 catch (IndexException ex)
 
 {
 
	 cout<<"Index out of range in index "<<ex.idx<<endl;
 
 }
 //for
 }
 
 for (int i=0;i<2*n;i++) //��������� ������������� �������
 
 {
 
 try
 
 {
 
 Print(i,n,a); //�������� ����������� ������
 
 }
 
 catch (IndexException ex) //�������� ����������
 
 {
 
 cout<<"Index out of range in index"
 
"<<ex.idx<<endl";
 
 }
 
 }
 
 cout<<endl;
 cout<<"������ ������"<<endl;

 int n1,i;
 
 cout<<"Input n: "; //������ ������� �������
 
 cin>>n1;
 srand(time(NULL));

 double* b = new double[n1];
 for(i=0;i<n1;i++){
	 b[i]=-10+rand()%20;
	 printf("%f ",b[i]) ;
 }
 //
  cout<<"������ ������"<<endl;

 int n2;
 
 cout<<"Input n: "; //������ ������� �������
 
 cin>>n2;


 double*c = new double[n2];

 for(i=0;i<n2;i++){
	try
 
 {
 c[i]=sqrt(a[i]+b[i]);
 Set2(i,n2,c); //�������� ������������ ������
 
 }
 
 catch (SqrtException ex)
 
 {
 
 cout<<"Sqrt error in index "<<ex.idx<<endl;
 
 }
 

 
 catch (IndexException ex)
 
 {
 
	 cout<<"Index out of range in index "<<ex.idx<<endl;
 
 }
 }
 for(i =0;i<n2;i++){

 Print(i,n2,c);
 }
 

 delete []a;
 delete []b;
  delete []c;
system("pause");
	return 0;
}