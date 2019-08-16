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
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n########Options########\n");
        printf("  Enter 1 to create list:\n Enter 2 to display list:\n Enter 3 to add node at beginning:\n Enter 4 to add at ending: \n Enter 5 to delete from beginning:\n Enter 6 to delete a particular node:\nEnter 7 for Deleting at end:\n Enter 8 for delete after a value: \n Enter 9 to delete the complete list :\n Enter 15 to close:");
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
            case 5:
                    start=delete_beg(start);
                    printf("Node deleted successfully from beginning");
                    break;
            case 6:
                    start=delete_node(start);
                    printf("Selected Node deleted successfully");
                    break;

            case 7:
                    start=delete_end(start);
                    printf("Node deleted successfully from ending");
                    break;
            case 8:
                    start=delete_after(start);
                    printf("Node deleted after the value successfully: ");
                    break;
            case 9:
                start=delete_list(start);
                printf("LIst has been deleted successfully:");
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




//function for deleting a node from beginning
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}

//function for deleting a node from ending
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    struct node *preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    } 
    preptr->next=NULL;
    free(ptr);
    return start;
}

//function for deleting any node containing a particular value
struct node *delete_node(struct node *start)
{
    int num;
    struct node *ptr=start;
    struct node *preptr;
    printf("Enter the value of the node you want to delete: ");
    scanf("%d",&num);
    if(ptr->data==num)
    {
        start=delete_beg(start);
        return start;
    }
    else
    {
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
    
}

//function to delete a node after certain value
struct node *delete_after(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    preptr=ptr;
    int num;
    printf("ENter the value after which you want to delete: ");
    scanf("%d",&num);
    while(preptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

//function to delete the complete list
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d is to be deleted next\n",ptr->data);
            start=delete_beg(ptr);
            ptr=start;
        }

    }
    return start;
}


