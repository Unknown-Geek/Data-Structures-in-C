/* Ex No:3
 * Program to input two polynomials and display their sum
 * 70 Shravan Nander Pandala S3 B2
 * 01/08/2024
 */

#include <stdio.h>

struct Terms{
	int c,d;
} 	A[50],B[50],R[50];

//Main Function
int main()
{	
	int n = 0;
	int n1, n2,i,j,k,count = 0;
	int flag = 0;
	printf("Enter the no. of terms in polynomial 1 : ");
	scanf("%d", &n1);
	printf("\n");
	printf("Enter the no. of terms in polynomial 2 : ");
	scanf("%d",&n2);
	printf("\n");
	printf("Enter the coeff. and degrees term wise of polynomial 1 : \n");
	for(int i = 0; i<n1; i++)
	{
		scanf("%d %d",&A[i].c,&A[i].d);		
	}
	printf("Enter the coeff. and degrees term wise of polynomial 2 : \n");
	for(int j = 0; j<n2 ; j++)
	{
		scanf("%d %d",&B[j].c,&B[j].d);
	}
	
	//Printing entered polynomials
	printf("Entered polynomials : \n");
	for(int i =0; i<n1; i++)
	{	
		if(A[i].d == 0)
			printf("%d",A[i].c);
		else if (i == n1 -1)
			printf("%dx^%d ",A[i].c,A[i].d);
		else
			printf("%dx^%d + ",A[i].c,A[i].d);
	}
	printf("\n");

	for(int j =0;j<n2; j++)
	{	
		if(B[j].d == 0)
			printf("%d",B[j].c);
		else if (j == n2 -1)
			printf("%dx^%d ",B[j].c,B[j].d);
		else
			printf("%dx^%d +  ",B[j].c,B[j].d);
	}
	printf("\n");
	
	//Adding the polynomials
	i = 0, j= 0, k = 0;
	while((i < n1) || (j < n2))
	{
		if (A[i].d > B[j].d)
		{
			R[k].d = A[i].d;
			R[k].c = A[i].c;
			i++;
		}
		else if (A[i].d < B[j].d)
		{
			R[k].d = B[j].d;
			R[k].c = B[j].c;
			j++;
		}
		else
		{
			R[k].d = A[i].d;
			R[k].c = A[i].c + B[j].c;
			i++;
			j++;
		}
		k++;
	}



	// Display result
	printf("Added Polynomial: \n");
	for(i = 0; i < k; i++)
	{
		if(R[i].d == 0)
			printf("%d",R[i].c);
		else if (R[i].c == 1)
			printf("x^%d + ",R[i].d);
		else
			printf("%dx^%d + ",R[i].c,R[i].d);
	}
	printf("\n");
}
