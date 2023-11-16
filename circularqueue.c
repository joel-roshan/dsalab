#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear =-1;

int isFull() {
   if((front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
   return 0;
}

int isEmpty() {
   if(front == -1) return 1;
   return 0;
}

void enqueue(int element) {
   if(isFull()) printf("\n Queue is full!! \n");
   else {
       if(front == -1) front = 0;
       rear = (rear + 1) % SIZE;
       items[rear] = element;
       printf("\n Inserted -> %d", element);
   }
}

int dequeue() {
   int element;
   if(isEmpty()) {
       printf("\n Queue is empty !! \n");
       return(-1);
   } else {
       element = items[front];
       if (front == rear){
           front = -1;
           rear = -1;
       } /* Q has only one element, so we reset the queue after dequeing it. ? */
       else {
           front = (front + 1) % SIZE;
           
       }
       printf("\n Deleted element -> %d \n", element);
       return(element);
   }
}

void display() {
   int i;
   if(isEmpty()) printf(" \n Empty Queue\n");
   else {
       printf("\n Front -> %d ",front);
       printf("\n Items -> ");
       for( i = front; i!=rear; i=(i+1)%SIZE) {
           printf("%d ",items[i]);
       }
       printf("%d ",items[i]);
       printf("\n Rear -> %d \n",rear);
   }
}

int main() {
   // Fails because it doesn't check whether queue is full or empty.
   int choice, item;
   while(1) {
       printf("\n\n *****MAIN MENU***** \n");
       printf("\n 1.Insert Element ");
       printf("\n 2.Delete Element ");
       printf("\n 3.Display ");
       printf("\n 4.Quit ");
       printf("\n\n Enter your choice : ");
       scanf("%d", &choice);
       switch(choice) {
           case 1:
               if(!isFull()) {
                  printf("\n Enter a value : ");
                  scanf("%d", &item);
                  enqueue(item);
               }
               break;
           case 2:
               if(!isEmpty()) {
                  dequeue();
               }
               break;
           case 3:
               display();
               break;
           case 4:
               exit(0);
           default:
               printf("\n\n Invalid! Choose a choice 1, 2, 3 or 4. \n\n");
               break;
       }
   }
   return 0;
}
