//various functionalities of singly linked list using c

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
struct node *insert_beg(struct node*);
struct node *insert_end(struct node *);

int main()
{
    int option;
    do
    {
        printf("\nOptions\n");
        printf("  Enter 1 to create list\n Enter 2 to display list\n Enter 3 to add node at beginning\n Enter 4 to add at ending \n Enter 15 to close:");
        printf("\nEnter Your Option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start=create_li(start);
                    printf("Linked List Created\n");
                    break;
            case 2:
                    start=display(start);
                    break;
            case 3:
                    start=insert_beg(start);
                    printf("\nNew node at beginning created successfully ");
                    break;
            case 4:
                    start=insert_end(start);
                    printf("new node added at ending");
                    break;
        }
    }while(option!=15);
    return 0;
}

//function for creating the singly linked list 
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
//function to display the singly linked list
struct node *display(struct node* start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

//function for inserting node at beginning of a singly linked list

struct node *insert_beg(struct node* start)
{
    struct node *new_node= (struct node*)malloc(sizeof(struct node));
    int value;
    printf("\nEnter the data the to add: ");
    scanf("%d",&value);
    new_node->data=value;
    new_node->next=start;
    start=new_node;
    return start;
}

//function for adding data at the end of a singly linked list
struct node *insert_end(struct node *start)
{
    struct node *ptr;
    ptr=start;
    int value;
    printf("\nEnter The Value to add at the end: ");
    scanf("%d",&value);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->data=value;
    new_node->next=NULL;
    return start;
}
