/*
* �������һ���������ȫ���У������
* �ļ���perm.cpp
*/
#include <iostream>
using namespace std;

template<class T>
inline void Swap(T& a,T& b)
{//exchange a and b
  T temp = a;a = b;b = temp;
}
/*
* ����ģ�壬�ݹ���ö�һ���������ȫ����
*/
template <class T>
void Perm(T list[],int k,int m)
{
  int i;
  if(k == m)//���һ��ȫ����
    {
      for(i=0;i <= m;i++)
        cout<<list[i];
      cout<<endl;
    }
  else //list[k:m]�ж�����з�ʽ
    //�ݹ�Ĳ�����Щ���з�ʽ
    for(i = k;i <= m;i++)
    {
      Swap(list[k],list[i]);//����λ�ã���ǰ��
      Perm(list,k+1,m);
      Swap(list[k],list[i]);//��λ�û���ȥ������һ�����и���
    }
}

//һ�����Գ���
int main()
{
  char list[]="abc";
  Perm(list,0,2);
  return 0;
}

