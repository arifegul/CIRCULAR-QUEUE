#include<stdio.h>
#include<stdlib.h> // for exit() 
#include<conio.h>	// for getch();
#define MAX 7  // Size of array 

void enqueue(int);	// enqueue() operation is used to add an value to the queue
void dequeue();	// dequeue() operation is used to delete(remove) an value to the queue
void display();	// display() operation is used to display values in the queue.

int countqueue[MAX];	// It is defined to count the size of the array.
int front = -1, rear = -1;  // Global value of front and rear.

int main() {

	int value;
	
	do {
		printf("\n\t\t/-/ CIRCULAR QUEUE /-/ \n\n 1-INSERT \n\n 2-DELETE\n\n 3-DISPLAY\n\n 4-EXIT\n\n");
		switch (getch()){  // getch() -> This function is available in the conio.h library. It is used to get a character from the user. 
			
			case '1': 
			printf("\nEnter the value to be insert:  ");
			scanf("%d",&value);	// Takes value from the user
			enqueue(value);	// Goes to the enqueue(int value) operation defined.
			break;

			case '2': dequeue();	// Goes to the dequeue() operation defined.
			break;
			
			case '3': display();	// Goes to the display() operation defined.
			break;
			
			case '4': {	// for EXIT operation
			return 0;
			break;
			}
			
			default:
			printf("Error!");
			system("CLS");
		}
	}

	while(1);
	getch();
	return 0;
	
	}
	
void enqueue(int value)
{
   if((front == 0 && rear == MAX - 1) || (front == rear+1))	// Statuses indicating that the Circular Queue is full
      printf("\n Circular Queue is Full \n");
   else{  
	if(front == -1)	// If front = -1, this indicates that the array is empty and front will be equal to 0, the first place in the array. (front = 0)
	front = 0;
	
	// If rear = MAX-1 and front are not equal to 0, the array is declared empty. 
	//Each added value takes place in the array in order.
   	if(rear == MAX-1 && front != 0)
	rear = -1;
    countqueue[++rear] = value;
    printf("\nInserted Value -> %d \n");

   }
}

void dequeue()
{
	// In the case of front = -1 and rear = -1, the array is empty and cannot be deleted.
   if(front == -1 && rear == -1)
	printf("\nDeletion cannot be Performed, because the Circular Queue is Empty.\n");
      
      
   else{
   	printf("\nDeleted Value : %d\n",countqueue[front++]); // increase front index by 1 circularly
    if(front == MAX)
	front = 0;
	
    if(front-1 == rear)
	front = rear = -1; // Reset the FRONT and REAR values to -1 for the last element
	
   }
}
void display()
{
   if(front == -1)
      printf("\nCircular Queue is Empty\n");
   else{
   	
      int i = front;
      printf("\nCircular Queue Elements are : \n");
      
      if(front <= rear){
      	
      	 while(i <= rear)
	     printf("%d\t",countqueue[i++]);
	     
      }
      
      else{
      	
	   while(i <= MAX - 1)
		printf("%d\t", countqueue[i++]);
		
	 	i = 0;
	 	while(i <= rear)
	    printf("%d\t",countqueue[i++]);
	    
      }
   }
}
