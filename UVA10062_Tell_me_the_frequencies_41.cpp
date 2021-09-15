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
	while(getline(cin,in)) //공백도 있어서 getline으로; 
	{
		int asc[97]={0},count[97]={0};
		for(int i=0;i<96;i++)
		{
			asc[i]=i+32; //우선 아스키코드 저장; 
		}
		for(int i=0;i<in.length();i++)
		{
			count[in[i]-32]++; //내가 입력한 아스키 코드 저장; 
		}
		for(int i=0;i<96;i++)
		{
			for(int j=i;j<96;j++)
			{
				if(count[i]>count[j]) //크기 비교후 배열; 
				{
					int temp=count[i];
					count[i]=count[j];
					count[j]=temp;
					
					int tmp=asc[i];
					asc[i]=asc[j];
					asc[j]=tmp;
				}
				else if(count[j]==count[j+1]&&asc[j]<asc[j+1]) //만약 곗수는 같은데 뒤에게 더 크면 위치 바꿔주기 , 예시 BBAA는AABB로 바꿔야함; 
				{
					int tmp=asc[j];
					asc[j]=asc[j+1];
					asc[j+1]=tmp;
				}
			}
		}
		for(int i=0;i<96;i++) //출력; 
		{
			if(count[i]!=0)
			{
				cout<<asc[i]<<" "<<count[i]<<endl;
			}
		}
	}
return 0;
}

