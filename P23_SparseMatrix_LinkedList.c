#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int val;
    struct Node *next;
} *tup1, *tup2, *trans1, *trans2, *sum;

void display(struct Node *head, int t_size)
{
    struct Node *cursor;
    cursor = head;
    while (cursor != NULL)
    {
        printf("<%d , %d , %d>", cursor->row, cursor->col, cursor->val);
        printf("\n");
        cursor = cursor->next;
    }
}

struct Node *Sort(struct Node *head)
{
    struct Node *cursor1, *cursor2, *min;
    int temp_row, temp_col, temp_val;
    cursor1 = head->next;
    while (cursor1 != NULL)
    {
        min = cursor1;
        cursor2 = cursor1->next;
        while (cursor2 != NULL)
        {
            if ((cursor2->row < min->row) || (cursor2->row == min->row && cursor2->col < min->col))
            {
                min = cursor2;
            }
            cursor2 = cursor2->next;
        }
        if (min != cursor1) {
            // Swap row
            int temp_row = cursor1->row;
            cursor1->row = min->row;
            min->row = temp_row;
            
            // Swap col
            int temp_col = cursor1->col;
            cursor1->col = min->col;
            min->col = temp_col;
            
            // Swap val
            int temp_val = cursor1->val;
            cursor1->val = min->val;
            min->val = temp_val;
        }
        cursor1 = cursor1->next;
    }
    return head;
}

struct Node *Convert_to_tuple(int mat[50][50], int r, int c)
{
    struct Node *head, *temp, *prev;
    head = malloc(sizeof(struct Node));
    head->row = r;
    head->col = c;
    head->val = 0;
    prev = head;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                head->val += 1;
                temp = malloc(sizeof(struct Node));
                temp->row = i;
                temp->col = j;
                temp->val = mat[i][j];
                temp->next = NULL;
                prev->next = temp;
                prev = temp;
            }
        }
    }
    return head;
}

struct Node *transpose(struct Node *head)
{
    struct Node *cursor, *temp, *transpose, *prev;
    transpose = malloc(sizeof(struct Node));
    transpose->row = head->col;
    transpose->col = head->row;
    transpose->val = head->val;
    prev = transpose;
    cursor = head->next;
    while (cursor != NULL)
    {
        temp = malloc(sizeof(struct Node));
        temp->col = cursor->row;
        temp->row = cursor->col;
        temp->val = cursor->val;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
        cursor = cursor->next;
    }
    transpose = Sort(transpose);
    return transpose;
}

struct Node* Tuple_Sum(struct Node *tup1,struct Node *tup2,struct Node *sum) {
    struct Node *cursor1, *cursor2, *temp, *prev;
    cursor1 = tup1->next;
    cursor2 = tup2->next;
    sum = malloc(sizeof(struct Node));
    sum->row = tup1->row;
    sum->col = tup1->col;
    sum->val = 0;
    prev = sum;
    while (cursor1 != NULL && cursor2 != NULL)
    {
        temp = malloc(sizeof(struct Node));
        if (cursor1->row < cursor2->row || (cursor1->row == cursor2->row && cursor1->col < cursor2->col))
        {
            temp->row = cursor1->row;
            temp->col = cursor1->col;
            temp->val = cursor1->val;
            cursor1 = cursor1->next;
        }
        else if (cursor1->row > cursor2->row || (cursor1->row == cursor2->row && cursor1->col > cursor2->col))
        {
            temp->row = cursor2->row;
            temp->col = cursor2->col;
            temp->val = cursor2->val;
            cursor2 = cursor2->next;
        }
        else
        {
            temp->row = cursor1->row;
            temp->col = cursor1->col;
            temp->val = cursor1->val + cursor2->val;
            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
        }   
    }
}

void main()
{
    int r1, c1, r2, c2;
    int t1_size, t2_size;
    int mat1[50][50], mat2[50][50];
    printf("Enter size of first matrix : ");
    scanf("%d%d", &r1, &c1);
    printf("\n");
    printf("Enter size of second matrix : ");
    scanf("%d%d", &r2, &c2);
    printf("\n");

    printf("Enter matrix 1 : \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n");
    printf("Enter matrix 2 : \n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\n");

    tup1 = Convert_to_tuple(mat1, r1, c1);
    tup2 = Convert_to_tuple(mat2, r2, c2);
    t1_size = tup1->val;
    t2_size = tup2->val;
    printf("Tuple 1 : \n");
    display(tup1, t1_size);
    printf("\nTuple 2 : \n");
    display(tup2, t2_size);

    trans1 = transpose(tup1);
    trans2 = transpose(tup2);
    printf("Transpose 1 : \n");
    display(trans1, t1_size);
    printf("\nTranspose 2 : \n");
    display(trans2, t2_size);
}
