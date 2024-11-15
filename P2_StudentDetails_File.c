/* Ex.No:2 Program to dislay the list of students in the order of register number and display the name and cgpa with reg.no
 * 70 Shravan Nander Pandala S3 B2
 * 25/07/2024
 */

#include <stdio.h>
#include <string.h>

//Structure for student details
struct Student
{
	char reg_no[11];
	float cgpa;
	char name[21];
}st[100];

void bubble_sort(int len);
void binary_search(char *reg_no,int len);

//Main function
int main()
{
	int len = 0;
	int running,ch;
	char key[11];
	FILE *fp;
	fp = fopen("student_details.txt","r");
	while(fscanf(fp," %10c%20c%5f",&st[len].reg_no,&st[len].name,&st[len].cgpa) != EOF)	
	{
		st[len].reg_no[11] = '\0';
		st[len].name[21] = '\0';
		len++;
	}
	bubble_sort(len);
	running = 1;
	
	while(running)
		{
			printf("\n");
			printf("1. Display list of students in order of register number\n");
			printf("2. Display Name and CGPA by searching register number\n");
			printf("3. Exit\n");
			printf("Enter your choice : ");
			scanf("%d",&ch);
			printf("\n");
			switch(ch)
			{
				case 1:
					bubble_sort(len);
					printf(" ---------------------------------------------------\n");
					printf(" |   REG_NO    |           Name         |    CGPA  |    \n");
					printf(" ---------------------------------------------------\n");
					for(int i = 0; i<len; i++)
					{
						printf(" | %s  |  %s  |  %3.2f    |\n",st[i].reg_no,st[i].name,st[i].cgpa);
					}
					printf(" ---------------------------------------------------\n");
					break;

				case 2:
					bubble_sort(len);
					printf("Enter register number to search : ");
					scanf("%s",&key);
					printf("\n");
					binary_search(key,len);
					break;

				case 3:
					running = 0;
					break;

				default:
					printf("Invalid Choice.\n");
			}
			if(ch == 3)
				break;

		}
}

//Bubble Sort
void bubble_sort(int len)
{
	struct Student temp;
	for(int i = 0; i<len ; i++)
	{
		for(int j = 0 ; j<len-i-1; j++)
		{
			if(strcasecmp(st[j].reg_no,st[j+1].reg_no)>0)
			{
				temp = st[j];
				st[j] = st[j+1];
				st[j+1] = temp;
			}
		}
	}
}

//Binary Search
void binary_search(char *reg_no,int len)

{
	int low = 0,high = len,mid;
	int flag = 0;
	mid = high/2;
	while(mid>0)
	{
		mid = (low + high)/2;
		if(strcasecmp(st[mid].reg_no,reg_no) == 0)
		{
			flag = 1;
			printf("Element found at %d.\n",mid);			
			break;
		}
		else if(strcasecmp(st[mid].reg_no, reg_no)<0)
			low = mid+1;
		else
			high = mid-1;
	}
	if(flag == 0)
		printf("Element not found.\n");
	else
		printf("Name:%s  CGPA:%f\n",st[mid].name,st[mid].cgpa);
}
