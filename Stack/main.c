#include <stdio.h>
#include<stdlib.h>
int MAXSIZE = 10;
int stack[10];
int top = -1;

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

void peek() {
   printf("The top of the element in stack is %d",stack[top]);
}

void pop() {
   int data;

   if(!isempty()) {

      data = stack[top];
      top = top - 1;
      printf("The number %d is poped out",data);
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
      main();
   }
}

void push() {
   int data;
   if(!isfull()) {
      printf("Enter data: ");
      scanf("%d",&data);
      top = top + 1;
      stack[++top] = data;
      printf("Success!!! you pushed %d into stack",stack[top]);
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
int main()
{
    int choice,data;
    while(1){
    printf("\n**************WELCOME**************");
    printf("\nIMPLEMENTATION OF STACK");
    printf("\n\nEnter your choice:\n");
    printf("1] Push\n2] Pop\n");
    printf("3] Top of stack\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:push();
           break;

    case 2:if(isempty())
           {
               printf("Stack Underflow!!!Please insert");
           }
           else{
           pop();}
           break;


    case 3:if(isempty())
           {
               printf("Stack Underflow!!!Please insert");
           }
           else{
           peek();}
           break;

    default:exit(0);
      }
    }
    return 0;
}


/*
#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
   // push items on to the stack
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   // print stack data
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");

   return 0;
}

*/
