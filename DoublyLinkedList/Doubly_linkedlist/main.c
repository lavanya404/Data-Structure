#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*tail=NULL;
int count=0;

void reverselist()
{
    struct node *current,*nextnode;
    if(head==NULL)
        printf("\nEmpty");
    else{
        current = head;
        while(current!=NULL)
        {
            nextnode = current->next;
            current->next = current->prev;
            current->prev = nextnode;
            current = nextnode;
        }
        current = head;
        head = tail;
        tail = current;
    }
}

void DfromEnd()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("\nEmpty List");
    }
    else{
        temp=tail;
        tail->prev->next=0;
        free(temp);
    }

}

void Dbegin()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        printf("\nList already Empty");
    else{
        temp=head;
        head=head->next;
        head->prev=0;
        temp->next=0;
        free(temp);
    }
}

void DfrmSpecificpos()
{
    struct node *temp;
    int pos,i=1;
    temp=head;
    printf("\nEnter the position you want to delete: ");
    scanf("%d",&pos);
    if(pos==1)
        Dbegin();
    else if(pos==count)
        DfromEnd();
    else if(head==NULL)
        printf("\nEMPTY LIST");
    else{
        while(i<pos)
        {
           temp=temp->next;
           i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void endoflist()
{
    int data;
    struct node *newnode;
    if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data to insert at end of list: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = newnode->prev=0;
        tail->next = newnode;
        newnode->prev = tail;
        tail=newnode;
    }
}

void beginning()
{
    int data;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert: ");
    scanf("%d",&data);
    newnode->data = data;
    newnode->next = newnode->prev=0;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertatpos()
{
    int data,position,i=1;;
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter position to insert :");
    scanf("%d",&position);
    if(position==1)
    {
        beginning();
    }
    else if(position>count){
        printf("\nThis is Beyond the limit\n");

    }
    else{
    printf("\nEnter the data u want to insert at position %d : ",position);
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=newnode->prev=0;
    while(i<position-1){
        temp = temp->next;
        i++;
      }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    }
}

void insertafterpos()
{
    int data,position,i=1;;
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter position to insert :");
    scanf("%d",&position);
    if(position==1)
    {
        beginning();

    }
    else if(position==count){
            endoflist();

    }
    else if(position>count)
    {
        printf("\nTHIS IS BEYOND LIMIT\n");
    }
    else{
    printf("\nEnter the data you want to insert at position after %d : ",position);
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=newnode->prev=0;
    while(i<position){
        temp = temp->next;
        i++;
      }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    }
}
void create()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&newnode->data);
    newnode->next = newnode->prev =0;
    if(head==NULL)
    {
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    count++;
}

void display()
{
    struct node *temp;
    temp = head;
    if(head==NULL)
    {
        printf("\nEmpty List");
    }
    else{
    printf("The elements in DLL are :\n ");
    while(temp!=0)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
  }
}


int main()
{
    int choice,n;
    while(1){
    //system("CLS");
    printf("\n**************WELCOME**************");
    printf("\nIMPLEMENTATION OF DOUBLY LINKEDLIST");
    printf("\n\nEnter your choice:\n");
    printf("1] To Create DLL\n2] Insert at Beginning\n3] Insert at End\n");
    printf("4] Insert at position\n5] Insert afterPosition\n");
    printf("6] Delete Beginning\n7] Delete at End\n8] Delete at specific position");
    printf("\n9] Reverse DLL\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("\nHow many numbers you want to create : ");
           scanf("%d",&n);
           for(int i=0;i<n;i++){
            create();}
           display();
           break;

    case 2:if(head==NULL)
           {
               printf("\nYou must create a list first then you can insert\nPlease enter 1 to create first ");
           }
           else{
           beginning();}
           display();
           break;

    case 3:if(head==NULL)
           {
               printf("\nYou must create a list first then you can delete\nPlease enter 1 to create first ");
           }
           else{
           endoflist();}
           display();
           break;


    case 4:if(head==NULL)
           {
               printf("\nYou must create a list first then you can delete\nPlease enter 1 to create first ");
           }
           else{
            insertatpos();}
            display();
            break;
    case 5:if(head==NULL)
           {
               printf("\nYou must create a list first then you can delete\nPlease enter 1 to create first ");
           }
           else{
           insertafterpos();}
           display();
           break;

    case 6:Dbegin();
           display();
           break;

    case 7:DfromEnd();
           display();
           break;

    case 8:DfrmSpecificpos();
           display();
           break;

    case 9:reverselist();
           display();
           break;
      }
    }
    return 0;
}
