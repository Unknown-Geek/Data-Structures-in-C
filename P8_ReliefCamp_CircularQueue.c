/* Ex No:8
 * Menu driven program for a circular queue at a relief camp to do the following : allow new person at the end, display number of persons, display all persons with token number and Supply food to person in the front
 * 70 Shravan Nander Pandala S3 B2
 * 22/08/2024
 */
#include <stdio.h>
#include <string.h>
#define SIZE 100

//Structure to store the person's details
struct Person{
    int token;
    int packets;
} P[SIZE];

int N;
int front = -1;
int rear = -1;
int current_token = 0;
int last_issued = 0;

//Enqueue function to add people at rear
void enqueue(struct Person temp)
{
    if ((front == 0 && rear == N-1) || (rear == (front-1) % (N-1)))
    {
        printf("Queue Full\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == N-1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    P[rear] = temp;
}

//Dequeue function to remove person from the front
void dequeue()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == N-1)
        front = 0;
    else
        front++;
}

//Function to display the queue
void display_queue()
{
    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("%8s\t%8s\n","Token No","Packets");
    printf("------------------------\n");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%8d\t%8d\n", P[i].token, P[i].packets);
    }
    else
    {
        for (int i = front; i < N; i++)
            printf("%8d\t%8d\n", P[i].token, P[i].packets);
        for (int i = 0; i <= rear; i++)
            printf("%8d\t%8d\n", P[i].token, P[i].packets);
    }
    printf("\n");
}

//Main function
int main()
{
    int ch, no_waiting;
    int running = 1;
    struct Person temp;
    printf("Enter max number of people in the queue : ");
    scanf("%d",&N);
    printf("\nMENU\n");
    printf("1. Allow new person at the end\n");
    printf("2. Display all persons in the queue\n");
    printf("3. Supply food to first person\n");
    printf("4. Exit\n");
    
    while(running)
    {   
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        if(front == -1)
            no_waiting = 0;
        else if (rear >= front)
            no_waiting = rear - front + 1;
        else
            no_waiting = N - front + rear + 1;
           
        switch(ch)
        {
        case 1:
            last_issued++;
            printf("Enter family size : ");
            scanf("%d", &temp.packets);
            if (temp.packets == 0)
            {
                printf("Family size cannot be 0\n");
                break;
            }
            temp.token = last_issued;
            enqueue(temp);
            printf("Person added.\n");
            break;
            
        case 2:
            if (no_waiting == 0)
                printf("Queue Empty\n");
            else
            {
                printf("Number of persons in the queue : %d\n",no_waiting);
                display_queue();
            }
            break;
            
        case 3:
            if (front != -1) {
                P[front].packets -= 3;
                if (P[front].packets <= 0)
                {
                    dequeue();
                    printf("Person served.\n");
                }
                else {
                    temp = P[front];
                    dequeue();
                    enqueue(temp);
                    printf("Token %d moved to the end\n", temp.token);
                }
            } else {
                printf("Queue Empty\n");
            }
            break;
            
        case 4:
            running = 0;
            break;
            
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
