	     /* * C Program to Solve Josephus Problem using Linked List */
#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
struct node { int num;
int angle;
struct node *next; };
void create(struct node **);
void display(struct node *);
void draw(struct node *);
int survivor(struct node **,int);
int main()
{
	int gdriver = DETECT, gmode, errorcode;
  /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

	struct node *head = NULL;
	int survive, skip;
	cleardevice();
	create(&head);
	printf("The persons in circular list are:\n");
	display(head);
	printf("Enter the number of persons to be skipped: ");
	scanf("%d", &skip); survive = survivor(&head,skip);
	printf("The person to survive is : %d\n", survive);
	free(head);
	getch();
	return 0;
}
void draw(struct node *head)
{
	cleardevice();
	struct node *p, *q,*r;
	int i,j=0,angle,number,n;
	char people[50];
	q = p = head;
	while (p->next !=q )
	{

		p = p->next;
		j++;

	}
	p = p->next;
	j=j+1;
	circle(getmaxx()/2,getmaxy()/2,140);
	circle(getmaxx()/2,getmaxy()/2,200);

	angle=360/j;
	j=0;
	while (p->next !=q)
	{
		j++;
		number=p->num;
		sprintf(people,"%d",number);
		setcolor(6);
		outtextxy((getmaxx()/2)+(120*cos(j*angle*3.14/180)-120*sin(j*angle*3.14/180)),(getmaxy()/2)+(120*sin(angle*j*3.14/180)+120*cos(angle*j*3.14/180)),people);
		p = p->next;

	}
	j++;

	number=p->num;
	sprintf(people,"%d",number);
	setcolor(6);
	outtextxy((getmaxx()/2)+(120*cos(j*angle*3.14/180)-120*sin(j*angle*3.14/180)),(getmaxy()/2)+(120*sin(angle*j*3.14/180)+120*cos(angle*j*3.14/180)),people);


	for(int n=0;n<j;n++)
	{
	circle((getmaxx()/2)+(120*cos(n*angle*3.14/180)-120*sin(n*angle*3.14/180)),(getmaxy()/2)+(120*sin(angle*n*3.14/180)+120*cos(angle*n*3.14/180)),15);
	}
	settextstyle(7,HORIZ_DIR,4);
	outtextxy(getmaxx()/2-120,getmaxy()/2-20,"Josephus \nfirst");
	p=p->next;
	getch();

}
int survivor(struct node **head, int k)
{
	struct node *p, *q;
	int i,j=0,number,ang=0;
	q = p = *head;
	draw(p);
	ang=ang+p->angle;
	while (p->next != p)
	{
		for (i = 0; i < k - 1; i++)
		{
			q = p;
			setcolor(10);
			ang=ang+q->angle;
			p = p->next;
		}

		setfillstyle(1,BLACK);
		setcolor(0);
		sleep(1);
		fillellipse((getmaxx()/2)+(120*cos(ang*3.14/180)-120*sin(ang*3.14/180)),(getmaxy()/2)+(120*sin(ang*3.14/180)+120*cos(ang*3.14/180)),20,20);
		q->angle=q->angle+p->angle;
		ang=ang+p->angle ;
		q->next = p->next;
		printf("%d has been killed.\n", p->num);
		free(p);
		p = q->next;
	}
	*head = p; return (p->num);
}
void create (struct node **head)
{
	struct node *temp,*rear;
	int a, ch=0,i=0,angle;
	printf("Enter how many number in que: ");
	scanf("%d", &a);
	angle=360/a;
	do {
	printf("enter %d no:-  ",i+1);
	scanf("%d", &ch);
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = ch;
	temp->angle=angle;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		rear->next = temp;
	}
	rear=temp;
	i++;
	}
	while (i !=a); rear->next = *head;
}
void display(struct node *head)
{
	struct node *temp;
	temp = head; printf("%d ", temp->num);
	temp = temp->next;
	while (head != temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");
}
