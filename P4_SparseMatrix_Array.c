	/* Ex No:4
	* Menu driven program to input two sparse matrices, convert hem to tuple representation and display tuple representation, transpose and sum.
	* 70 Shravan Nander Pandala S3 B2
	* 08/08/2024
	*/

	#include <stdio.h>
	#define SIZE 50

	struct Tuple
	{
		int row,col,val;
	}tup1[SIZE],tup2[SIZE],trans1[SIZE], trans2[SIZE],sum[SIZE];

	int mat1[SIZE][SIZE];
	int mat2[SIZE][SIZE];
	int r1,c1,n1,r2,c2,n2;
	int t1,t2;
	int sum_count = 0;

	void input();
	void convert_to_tuple();
	void display (struct Tuple disp[SIZE],int n);
	void transpose(struct Tuple trans[SIZE], struct Tuple tup[SIZE],int t_size);
	int matrix_sum(struct Tuple tup1[SIZE],struct Tuple tup2[SIZE],int t1, int t2);

	int main()
	{
		int running = 1;
		int ch;
		int stop = 0;
		input();
		printf("MENU \n");
		printf("\t1.Convert to tuple form\n\t2.Display tuple form\n\t3.Display transpose in tuple form\n\t4.Display sum in tuple form\n\t5.Exit\n");		
		while(running)
		{
			printf("Enter your choice : ");
			scanf("%d",&ch);
			printf("\n");
			switch(ch)
			{
			case 1:
				convert_to_tuple();
				break;

			case 2:
				convert_to_tuple();
				printf("Matrix 1  in tuple form :\n");
				display(tup1,t1);
				printf("\n");
				printf("Matrix 2  in tuple form :\n");
				display(tup2,t2);
				printf("\n");
				break;

			case 3:
				convert_to_tuple();
				transpose(trans1,tup1,t1);
				printf("Transpose of matrix 1  in tuple form :\n");
				display(trans1,t1);
				printf("\n");
				transpose(trans2,tup2,t2);
				printf("Transpose of matrix 2  in tuple form :\n");
				display(trans2,t2);
				printf("\n");
				break;

			case 4:
				convert_to_tuple();
				stop = matrix_sum(tup1,tup2,t1,t2);
				if (stop == 1)
					break;
				printf("Sum of matrices in tuple form :\n");
				display(sum,sum_count);
				printf("\n");
				break;

			case 5:
				running = 0;
				break;
			}
			if (ch == 5)
				break;
		}

	}

	void input()
	{
		printf("Enter the order of Matrix 1 : ");
		scanf("%d",&r1);
		scanf("%d",&c1);
		printf("\n");

		printf("Enter a %dx%d matrix : \n",r1,c1);
		for(int i = 0; i<r1; i++)
		{
			for(int j = 0; j<c1; j++)
			{
				scanf("%d", &mat1[i][j]);
			}
		}
		printf("\n");

		printf("Enter the order of Matrix 2 : ");
		scanf("%d",&r2);
		scanf("%d",&c2);
		printf("\n");

		printf("Enter a %dx%d matrix : \n",r2,c2);
		for(int i = 0; i<r2; i++)
		{
			for(int j = 0; j<c2; j++)
			{
				scanf("%d", &mat2[i][j]);
			}
		}
		printf("\n");

	}

	//Convert sparse matrix to tuple form
	void convert_to_tuple()
	{
		//Matrix 1
		t1 = 1;
		tup1[0].row = r1;
		tup1[0].col = c1;
		for (int i = 0; i<r1; i++)
		{
			for(int j = 0; j<c1;j++)
			{
				if(mat1[i][j] != 0)
				{
					tup1[t1].row = i;
					tup1[t1].col = j;
					tup1[t1].val = mat1[i][j];
					t1++; 
				}

			}
		}
		tup1[0].val =t1-1;

		//Matrix 2
		t2 = 1;
		tup2[0].row = r2;
		tup2[0].col = c2;
		for (int i = 0; i<r2; i++)
		{
			for(int j = 0; j<c2;j++)
			{
				if(mat2[i][j] != 0)
				{
					tup2[t2].row = i;
					tup2[t2].col = j;
					tup2[t2].val = mat2[i][j];
					t2++; 
				}
			}
		}
		tup2[0].val = t2-1;
	}

	//Display function to display tuple form
	void display(struct Tuple disp[SIZE],int n)
	{
		for(int i = 0; i<n; i++)
		{
			printf("< %d , %d , %d >\n",disp[i].row,disp[i].col,disp[i].val);
		}

	}

	//To generate transpose of tuple form
	void transpose(struct Tuple trans[SIZE], struct Tuple tup[SIZE],int t_size)
	{
		int ch;
		struct Tuple temp;
		for(int i = 0; i<t_size ; i++)
		{
			trans[i].row = tup[i].col;
			trans[i].col = tup[i].row;
			trans[i].val = tup[i].val;
		}

		//Sorting
		for(int i = 1; i < t_size ; i++)
		{
			for(int j = 1; j < t_size-i ; j++)
			{
				if((trans[j].row > trans[j+1].row) || ((trans[j].row == trans[j+1].row) && (trans[j].col>trans[j+1].col)))
				{
					temp = trans[j];
					trans[j] = trans[j+1];
					trans[j+1] = temp;
				}
			}
		}
	}

	// TO find the matrix sum
	int matrix_sum(struct Tuple tup1[SIZE],struct Tuple tup2[SIZE],int t1, int t2)
	{
		int r1,c1,r2,c2;
		int i = 1, j = 1, k= 1;
		struct Tuple temp;

		r1 = tup1[0].row;
		c1 = tup1[0].col;
		r2 = tup2[0].row;
		c2 = tup2[0].col;

		sum[0].row = r1;
		sum[0].col = c1;

		if(r1!=r2 || c1!=c2)
		{
			printf("The matrices cannot be added.");
			return 1;
		}

		while((i < t1) && (j < t2))
		{
			if(tup1[i].row < tup2[j].row || ((tup1[i].row == tup2[j].row) && (tup1[i].col < tup2[j].col)))
			{
				sum[k].row = tup1[i].row;
				sum[k].col = tup1[i].col;
				sum[k].val = tup1[i].val;
				i++;
			}
			else if(tup1[i].row > tup2[j].row || ((tup1[i].row == tup2[j].row) && (tup1[i].col > tup2[j].col)))
			{
				sum[k].row = tup2[j].row;
				sum[k].col = tup2[j].col;
				sum[k].val = tup2[j].val;
				j++;
			}
			else
			{
				sum[k].row = tup1[i].row;
				sum[k].col = tup1[i].col;
				sum[k].val = tup1[i].val + tup2[j].val;
				i++;
				j++;
			}
			k++;
		}

		while (i < t1)
		{
			sum[k] = tup1[i];
			i++;
			k++;
		}

		while (j <= t2)
		{
			sum[k] = tup2[j];
			j++;
			k++;
		}

		sum_count = k-1;
		sum[0].val = sum_count - 1;

		return 0;
	}
