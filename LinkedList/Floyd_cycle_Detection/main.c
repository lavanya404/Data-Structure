#include <stdio.h>
#include <stdlib.h>

/* A structure of linked list node */
struct node {
  int data;
  struct node *next;
};
struct node *head=NULL,*tail=NULL;

void findloop(struct node *head) {
    struct node *slow, *fast;
    slow = fast = head;

    while(slow && fast && fast->next) {
        /* Slow pointer will move one node per iteration whereas
        fast node will move two nodes per iteration */
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return;
        }
    }
    printf("No Loop in Linked List\n");
}
void create()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next =0;
    if(head==NULL)
    {
        head = tail= newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
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

int main() {
    int choice,n;
    while(1){
    //system("CLS");
    printf("\n**************WELCOME**************");
    printf("\nFLOYD\'s CYCLIC LOOP DETECTION IN SINGLY LINKEDLIST");
    printf("\n\nEnter your choice:\n");
    printf("1] To Create SLL\n2] Detect loop\n");
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

    case 2://creating loop
           head->next->next->next->next = head;
           findloop(head);
           //display();
           break;
    }


}
return 0;
}

