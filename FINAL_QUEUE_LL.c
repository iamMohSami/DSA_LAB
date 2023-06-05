

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
} ;

struct node * front ;
struct node * rear ;
struct node * temp ;
struct node * front1 ;
 
int frontelem();
void enque(int data);
void deque();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 
int main()
{
    int data, choice, x;
 
    printf("\n 1] Enque");
    printf("\n 2] Deque");
    printf("\n 3] Front/First element");
    printf("\n 4] Is Empty ??");
    printf("\n 5] Queue size");
    printf("\n 6] Display");
    printf("\n 7] EXIT");
    create();
    while (1)
    {
        printf("\n \n Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to Add in Queue : ");
            scanf("%d", &data);
            enque(data);
            break;
        case 2:
            deque();
            break;
        case 3:
            x = frontelem();
            if (x != 0)
                printf("Front (or) First element of Queue is : %d \n", x);
            else
                printf("\n Sorry, your queue is empty \n");
            break;
        case 4:
            empty();
            break;
        case 7:
            exit(0);
        case 6:
            display();
            break;
        case 5:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  \n");
            break;
        }
    }
return 0 ;
}
 

void create()
{
    front = rear = NULL;
}
 

void queuesize()
{
    printf("\n The Size of your Queue is : %d", count);
}
 

void enque(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        rear = temp;
    }
    count++;
}


void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Your Queue is empty \n");
        return;
    }
    while (front1 != rear)
    {
        printf("%d \t", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d \n", front1->info);
}
 

void deque()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Sorry,Your Queue is Empty.. \n");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed/Removed Value is : %d \n", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed/Remove value  is : %d \n", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 

int frontelem()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 

void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n your Queue is Empty....");
    else
       printf("Your Queue is not Empty....");
}