#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node *start;
struct node *create_li(struct node*);
struct node *display(struct node*);

int main()
{
    int option;
    do
    {
        printf("\nOptions\n");
        printf("  Enter 1 to create list\n Enter 2 to display list\n Enter 3 to add node at beginning\n\n Enter 15 to close:");
        printf("Enter Your Option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start=create_li(start);
                    printf("Linked List Created\n");
                    break;
            case 2:
                    start=display(start);
                    break;
        }
    }while(option!=15);
    return 0;
}
struct node *create_li(struct node* start)
{
    struct node *ptr,*new_node;
    int num;
    printf("\nEnter -1 to end:");
    printf("\nEnter the value");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("Enter the data:");
        scanf("%d",&num);
        
    }
    return start;
}

struct node *display(struct node* start)
{
    struct node *ptr=start;
    while(ptr->next!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}