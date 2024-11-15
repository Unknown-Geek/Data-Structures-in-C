/* Ex No:9
 * Menu driven program for a double ended queue to - insert at front,rear and delete from front,rear.Also check whether deleted string is palindrome or not.
 * 70 Shravan Nander Pandala S3 B2
 * 29/08/2024
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    char deque[SIZE][SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue dq;
int N;

void isPalindrome(char *str);
void insert_at_front();
void insert_at_rear();
void delete_from_front();
void delete_from_rear();
void display();

int main()
{
    dq.front = -1;
    dq.rear = -1;
    dq.size = 0;

    printf("Enter the size of the deque: ");
    scanf("%d", &N);

    int ch;
    printf("\nMENU\n");
    printf("1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert_at_front();
            break;
        case 2:
            insert_at_rear();
            break;
        case 3:
            delete_from_front();
            break;
        case 4:
            delete_from_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}

void insert_at_front()
{
    if((dq.rear + 1) % N == dq.front)
        printf("Dequeue full\n");
    else if(dq.front == -1 && dq.rear == -1)
    {
        dq.front = 0;
        dq.rear = 0;
    }
    else if (dq.front == 0)
        dq.front = N-1;
    else
        dq.front -= 1;
    printf("Enter the string : ");
    scanf("%s", dq.deque[dq.front]);
    dq.size++;
}

void insert_at_rear()
{
    if((dq.rear + 1) % N == dq.front)
        printf("Deque full\n");
    else if(dq.front == -1 && dq.rear == -1)
    {
        dq.front = 0;
        dq.rear = 0;
    }
    else if (dq.rear == N-1)
        dq.rear = 0;
    else
        dq.rear += 1;
    printf("Enter the string : ");
    scanf("%s", dq.deque[dq.rear]);
    dq.size++;
}

void delete_from_front()
{
    char str[SIZE];
    if((dq.front == -1 && dq.rear == -1) || dq.size == 0)
    {
        printf("Deque empty\n");
        return;
    }
    else 
    {
        strcpy(str, dq.deque[dq.front]);
        if (dq.front == dq.rear)
        {
            dq.front = -1;
            dq.rear = -1;
        }
        else if (dq.front == N-1)
            dq.front = 0;
        else
            dq.front += 1;
    }   
    dq.size--;
    printf("%s was deleted from front\n", str);
    isPalindrome(str);
}

void delete_from_rear()
{
    char str[SIZE];
    if((dq.front == -1 && dq.rear == -1) || dq.size == 0)
    {
        printf("Deque empty\n");
        return;
    }
    else 
    {
        strcpy(str, dq.deque[dq.rear]);
        if (dq.front == dq.rear)
        {
            dq.front = -1;
            dq.rear = -1;
        }
        else if (dq.rear == 0)
            dq.rear = N-1;
        else
            dq.rear -= 1;
    }   
    dq.size--;
    printf("%s was deleted from rear\n", str);
    isPalindrome(str);
}

void display()
{
    if(dq.size == 0)
        printf("Deque empty\n");
    else if (dq.rear >= dq.front)
        for(int i = dq.front; i <= dq.rear; i++)
            printf("%s\t", dq.deque[i]);
    else
    {
        for(int i = dq.front; i < N; i++)
            printf("%s\t", dq.deque[i]);
        for(int i = 0; i <= dq.rear; i++) 
            printf("%s\t", dq.deque[i]);
    }
    printf("\n");
}

void isPalindrome(char *str)
{
    int flag = 0;
    int len = strlen(str);
    for(int i = 0; i < len/2; i++)
    {
        if(str[i] != str[len-1-i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
}
