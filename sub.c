# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int LCS(char a[],int p,int m,char b[],int q,int n,int s[][n]);
int main()
{
	int m,n;
	char a[]="thisisatest";
	char b[]="testingtesting";
	m=strlen(a);
	n=strlen(b);
	int s[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			s[i][j]=0;
		}
	}
	printf("%d\n",LCS(a,0,m,b,0,n,s) );
}

int LCS(char a[],int p,int m,char b[],int q,int n,int s[][m])
{
	if(s[p][q]!=0){return s[p][q];}
	for(int i=p;i<m;i++){
		for(int j=q;j<n;j++){
			if(a[i]==b[j]){ 
	    		s[i+1][j+1]=LCS(a,i+1,m,b,j+1,n,s);
	    		if(s[p][q]<(1+s[i+1][j+1])){s[p][q]=(1+s[i+1][j+1]);};
			}
		}
	}
return s[p][q];
}
