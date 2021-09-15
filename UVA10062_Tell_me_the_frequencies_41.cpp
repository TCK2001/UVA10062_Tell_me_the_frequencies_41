/*
Sample Input
AAABBC
122333
Sample Output
67 1
66 2
65 3
49 1
50 2
51 3
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	
	string in;
	while(getline(cin,in)) //���鵵 �־ getline����; 
	{
		int asc[97]={0},count[97]={0};
		for(int i=0;i<96;i++)
		{
			asc[i]=i+32; //�켱 �ƽ�Ű�ڵ� ����; 
		}
		for(int i=0;i<in.length();i++)
		{
			count[in[i]-32]++; //���� �Է��� �ƽ�Ű �ڵ� ����; 
		}
		for(int i=0;i<96;i++)
		{
			for(int j=i;j<96;j++)
			{
				if(count[i]>count[j]) //ũ�� ���� �迭; 
				{
					int temp=count[i];
					count[i]=count[j];
					count[j]=temp;
					
					int tmp=asc[i];
					asc[i]=asc[j];
					asc[j]=tmp;
				}
				else if(count[j]==count[j+1]&&asc[j]<asc[j+1]) //���� ����� ������ �ڿ��� �� ũ�� ��ġ �ٲ��ֱ� , ���� BBAA��AABB�� �ٲ����; 
				{
					int tmp=asc[j];
					asc[j]=asc[j+1];
					asc[j+1]=tmp;
				}
			}
		}
		for(int i=0;i<96;i++) //���; 
		{
			if(count[i]!=0)
			{
				cout<<asc[i]<<" "<<count[i]<<endl;
			}
		}
	}
return 0;
}

