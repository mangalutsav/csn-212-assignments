//Roads
// problem link : https://community.topcoder.com/stat?c=problem_statement&pm=1889
//http://ideone.com/NmyjEi
#include <bits/stdc++.h>

using namespace std;
int x,y,n,xcr,ycr,num;long long int ans[101][101] = {0};
string s,tmp;
bool b[101][101] = {0};
int main() {
	// your code goes here
	cin >> x >> y;
	//cin >> s;
	getline(cin,s,'|');
//	cout <<s;
	int ct = 0;
	for(int i=0;i<s.size();)
	{
//	cout <<s[i] << " ";
		if((int)s[i] > 47 && (int)s[i] < 58)
		{
			num = 0;
			while((int)s[i] > 47 && (int)s[i] < 58){
				num *= 10;
				num += (int)s[i]-48;
				i++;
			}
	//		cout <<"hi";
			ct++;
			if(ct == 1)
			{
				xcr = num;
			}
			else
			{
				ycr = num;
				ct = 0;
				b[xcr][ycr] = 1;
			}
		}
		else i++;
	}

	ans[0][0] = 1;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		{
			if(b[i][j])
			{
		//		cout <<"hi";
				if(!b[i+1][j])
				{
					ans[i+1][j] += ans[i][j];
				}
				if(!b[i][j+1])
				{
					ans[i][j+1] += ans[i][j];
				}
			}
			else
			{
				ans[i+1][j] += ans[i][j];
				ans[i][j+1] += ans[i][j];
			}
		}
	}
/*	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
*/	cout << ans[x][y] << endl;
	return 0;
}
/*
6
6
{"0 0 0 1","6 6 5 6"}
*/
