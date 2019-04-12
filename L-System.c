#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

int main(void)
{
 int gd=VGA;
 int gm=VGAHI;
 int iter=0;
 initwindow(640,480,"bgi");
 printf("Enter the number of iteration: ");
 scanf("%d",&iter);
 int Arr[20][3][2];
 Arr[0][0][0]=300;
 Arr[0][0][1]=100;
 Arr[0][1][0]=200;
 Arr[0][1][1]=300;
 Arr[0][2][0]=400;
 Arr[0][2][1]=300;
 int nt=1;
 int a[3][2];
 int b[3][2];
 int c[3][2];
 int tempArr[20][3][2];
 int tempnt=-1;
 
 line(Arr[0][0][0], Arr[0][0][1], Arr[0][1][0], Arr[0][1][1]);
 line(Arr[0][1][0], Arr[0][1][1], Arr[0][2][0], Arr[0][2][1]);
 line(Arr[0][0][0], Arr[0][0][1], Arr[0][2][0], Arr[0][2][1]);
 
 for(int j=0;j<iter;j++)
 {
 
	for(int i=0;i<nt;i++)
	{
	 	printf("\n%d",i);
	 	a[0][0]=Arr[i][0][0];
	 	a[0][1]=Arr[i][0][1];
	 	a[1][0]=(Arr[i][0][0]+Arr[i][1][0])/2;
	 	a[1][1]=(Arr[i][0][1]+Arr[i][1][1])/2;
	 	a[2][0]=(Arr[i][0][0]+Arr[i][2][0])/2;
	 	a[2][1]=(Arr[i][0][1]+Arr[i][2][1])/2;

	 	
	 	line(a[0][0],a[0][1],a[1][0],a[1][1]);
	 	line(a[1][0],a[1][1],a[2][0],a[2][1]);
	 	line(a[0][0],a[0][1],a[2][0],a[2][1]);
	 	
		b[0][0]=Arr[i][1][0];
	 	b[0][1]=Arr[i][1][1];
	 	b[1][0]=(Arr[i][1][0]+Arr[i][0][0])/2;
	 	b[1][1]=(Arr[i][1][1]+Arr[i][0][1])/2;
	 	b[2][0]=(Arr[i][1][0]+Arr[i][2][0])/2;
	 	b[2][1]=(Arr[i][1][1]+Arr[i][2][1])/2;
	
	 	line(b[0][0],b[0][1],b[1][0],b[1][1]);
	 	line(b[1][0],b[1][1],b[2][0],b[2][1]);
	 	line(b[0][0],b[0][1],b[2][0],b[2][1]);
	 	
		c[0][0]=Arr[i][2][0];
	 	c[0][1]=Arr[i][2][1];
	 	c[1][0]=(Arr[i][2][0]+Arr[i][0][0])/2;
	 	c[1][1]=(Arr[i][2][1]+Arr[i][0][1])/2;
	 	c[2][0]=(Arr[i][2][0]+Arr[i][1][0])/2;
	 	c[2][1]=(Arr[i][2][1]+Arr[i][1][1])/2;
	 	
	 	line(c[0][0],c[0][1],c[1][0],c[1][1]);
	 	line(c[1][0],c[1][1],c[2][0],c[2][1]);
	 	line(c[0][0],c[0][1],c[2][0],c[2][1]);
	 	
	 	tempnt+=1;
	 	tempArr[tempnt][0][0]=a[0][0];
	 	tempArr[tempnt][0][1]=a[0][1];
	 	tempArr[tempnt][1][0]=a[1][0];
	 	tempArr[tempnt][1][1]=a[1][1];
	 	tempArr[tempnt][2][0]=a[2][0];
	 	tempArr[tempnt][2][1]=a[2][1];
	 	
		tempnt=tempnt+1;
	 	tempArr[tempnt][0][0]=b[0][0];
	 	tempArr[tempnt][0][1]=b[0][1];
	 	tempArr[tempnt][1][0]=b[1][0];
	 	tempArr[tempnt][1][1]=b[1][1];
	 	tempArr[tempnt][2][0]=b[2][0];
	 	tempArr[tempnt][2][1]=b[2][1];
	 	
		tempnt=tempnt+1;
	 	tempArr[tempnt][0][0]=c[0][0];
	 	tempArr[tempnt][0][1]=c[0][1];
	 	tempArr[tempnt][1][0]=c[1][0];
	 	tempArr[tempnt][1][1]=c[1][1];
	 	tempArr[tempnt][2][0]=c[2][0];
	 	tempArr[tempnt][2][1]=c[2][1];
	 	
		if(i>200)
	 	{
	 		i=7;
		}
	}
	nt*=3;
	for(int k=0;k<=tempnt;k++)
	{
		for(int l=0;l<3;l++)
		{
			Arr[k][l][0]=tempArr[k][l][0];
			Arr[k][l][1]=tempArr[k][l][1];
		}
	}
	tempnt=-1;
 }
 getch();
}
