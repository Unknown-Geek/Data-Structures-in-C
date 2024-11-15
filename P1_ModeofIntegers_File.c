/*
 * Ex.No:1 Prg to find the mode of integer numbers stored in a text file.
 * 70 Shravan Nander Pandala S3 B2
 * 25/07/2024
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numbers[100];
	int num, len = 0 , st_len = 0;
	int max_count = 0,cnt,mode;
	int flag = 0;
	FILE *fp;
	fp = fopen("numbers.txt","r");
	if(fp == NULL)
		{
			printf("File cannot be opened.\n");
			return 1;
		}

	//Read the numbers to array
	while(fscanf(fp,"%d",&num) != EOF)
	{
		numbers[len] =  num;
		len++;
	}
	
	//Linear Search
	for(int i = 0; i < len; i++)
	{	
		cnt = 0;
		for(int j = i; j< len; j++)
		{
			if(numbers[i] == numbers[j])
			{
				cnt++;
			}
		}
		//check if count is more
		if(cnt > max_count)
		{
			max_count = cnt;
			mode = numbers[i];
		}
	}
	
	printf("The mode of the integers stored in the file is %d, occuring %d times.\n",mode,max_count);
	return 0;
}
