/* Ex No:7
 * Menu driven program for a Token Management System to display the following : the current student being served, Students waiting, last token number issued and issue a new token
 * 70 Shravan Nander Pandala S3 B2
 * 22/08/2024
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

int current_token = 0;
int last_issued = 0;
int front = -1;
int rear = -1;
int waiting_queue[SIZE];

void enqueue(int token)
{
	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else
		rear += 1;

	waiting_queue[rear] = token;
}

int dequeue()
{
	int token;
	if(front > rear)
		printf("Queue Empty\n");
	else
	{
		token = waiting_queue[front];
		front +=1;
		return token;
	}
	return -1;
}

void display_queue()
{
	printf("Students waiting are :\n");
	for(int i = front; i<rear+1 ; i++)
	{
		printf("%d\t",waiting_queue[i]);
	}
	printf("\n");
}

void main()
{
	int ch, token, no_waiting;
	int running = 1;
	printf("MENU\n");
	printf("1. Current Student being served\n");
	printf("2. Waiting students\n");
	printf("3. Last token number issued\n");
	printf("4. Issue new token\n");
	printf("5. Finish serving current student\n");
	printf("6. Exit");
	while(running)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			if (front > rear)
				printf("No student is being served\n");
			else
			{
				current_token = waiting_queue[front];
				printf("Current student being served : Token No %d\n",current_token);
			}
			break;

		case 2:
			no_waiting = rear - front+1;
			if (front > rear)
				printf("Empty queue\n");
			else
			{
				printf("Number of students waiting : %d\n",no_waiting);
				display_queue();
			}
			break;

		case 3:
			if (last_issued == 0)
				printf("No tokens issued yet.\n");
			else
				printf("Last token number issued : %d\n",last_issued);
			break;

		case 4:
			last_issued ++;
			enqueue(last_issued);
			printf("New token issued!\n");
			break;

		case 5:
			if (front > rear)
				printf("No student to serve\n");
			else
			{
				token = dequeue();
				printf("Finished serving Token No : %d\n",token);
			}
			break;

		case 6:
			running = 0;
			break;

		default:
			printf("Invalid Choice\n");
			break;
		}
		if (ch == 6)
			break;
	}
}

