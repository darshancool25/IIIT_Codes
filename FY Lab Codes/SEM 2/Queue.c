#include<stdio.h>
#define size 10


int queue[size],front=-1,rear=-1;

void enqueue(int item)
{
	if(rear>=size)
	{
		printf("\nqueue is full");

	}
	else
	{
		if(front==-1)
		{
			front=0;
			rear=0;

		}	

		queue[rear]=item;
		rear++;

	}

}

void dequeue()
{
	int i;
	if(front==rear)
	{
		printf("\nqueue is empty");
	}
	else
	{
		printf("\nitem deleted is : %d ",queue[front]);
		for(i=0;i<rear;i++)
		{
			queue[i]=queue[i+1];
		}
		rear--;
	}
}

void display()
{
	if(front==rear)
	{
		printf("\nqueue is empty");
	}
	else
	{
		int i;
		printf("\n");
		for(i=0;i<rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}




int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		enqueue(100+i);
	}
	enqueue(6969);
	display();
	dequeue();
	display();
	return 0;

}