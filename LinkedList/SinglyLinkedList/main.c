#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
int count=0;

void reverselist()
{
    struct node *current,*prevnode;

        if(head!=NULL)
        {
            prevnode=head;
            current=head->next;
            head=head->next;
            prevnode->next=NULL;

        while(head!=NULL)
        {
            head=head->next;
            current->next=prevnode;
            prevnode=current;
            current=head;
        }
        head=prevnode;
    }
}

void DfromEnd()
{
    struct node *temp,*secondLastNode;
    if(head==NULL)
    {
        printf("\nEmpty List");
    }
    else{
        temp=head;
        secondLastNode=head;
        while(temp->next!=NULL)
        {
            secondLastNode=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            head=NULL;
        }
        else{
            secondLastNode->next=NULL;
        }
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
        temp->next=0;
        free(temp);
    }
}

void DfrmSpecificpos()
{
    struct node *temp,*secondLastNode;
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
           secondLastNode=temp;
           temp=temp->next;
           i++;
        }
      secondLastNode->next=temp->next;
      free(temp);
    }
}

void endoflist()
{
    int data;
    struct node *newnode,*ptr;
    if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data to insert at end of list: ");
        scanf("%d",&data);
        newnode->data = data;
        newnode->next = NULL;
        ptr = head;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=newnode;
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
    while(i<position-1){
        temp = temp->next;
        i++;
      }
    newnode->next = temp->next;
    temp->next = newnode;
    }
}

void insertafterpos()
{
    int data,position,i=0;;
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
    newnode->next=NULL;
    while(i<position){
        temp = temp->next;
        i++;
      }
    newnode->next = temp->next;
    temp->next = newnode;
    }
}
void create()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next =0;
    if(head==NULL)
    {
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
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
    printf("The elements in SLL are :\n ");
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
    printf("\nIMPLEMENTATION OF SINGLY LINKEDLIST");
    printf("\n\nEnter your choice:\n");
    printf("1] To Create SLL\n2] Insert at Beginning\n3] Insert at End\n");
    printf("4] Insert at position\n5] Insert afterPosition\n");
    printf("6] Delete Beginning\n7] Delete at End\n8] Delete at specific position");
    printf("\n9] Reverse SLL\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:printf("\nHow many numbers you want to create : ");
           scanf("%d",&n);
           printf("\nEnter data : ");
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
