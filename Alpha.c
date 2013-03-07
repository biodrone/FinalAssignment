//////////////////////
//Taxi Rank Program//
//By Joshua Jacobs//
///////////////////

#include <stdio.h>
#define MAX_SIZE 6

//function definitions
void init(struct stack *s);
void push(struct stack *s , int num);
int pop(struct stack *s);
void print (struct stack *s);
int getTaxis();
int showMenu(struct stack *s);
    
struct stack
{
	int a[MAX_SIZE]; //for position
    int n[MAX_SIZE]; //for number
	int top;
};

void init(struct stack *s)
{
	s -> top = 0;
}

void push(struct stack *s , int num)
{
    //make sure the stack isn't full
	if(s -> top < MAX_SIZE) 
	{
		s -> a[s->top] = s -> top; //add taxi position
        s -> n[s->top] = num; //add taxi number
		s -> top++; //increment top
	}
    else
    {
        printf("The Rank is Full!");
    }
}

int pop(struct stack *s)
{ // -1 returned if stack empty.
	if (s -> top > 0)
	{
		s -> top--;
		return(s -> a[s -> top]);
	}
	else return -1;
}

void print (struct stack *s)
{
	int i;

	printf("\n-------------------\n");
	if( s -> top > 0 )
		{
		for(i = 0; i < s -> top ; i++)
			printf("Pos - %d -- Num - %d\n", s -> a[i] + 1, s -> n[i]);
		}
	else printf("EMPTY\n");
    printf("-------------------\n");
}

int getTaxis()
{
    int taxis = 0;
    //get number of taxis
    printf("How Many Taxis Do You Need?\n");
    scanf("%d", &taxis);
    
    //check that there aren't more than 6 taxis
    if (taxis > 6)
    {
        printf("Cannot Have More Than 6 Taxis\nPlease Enter A Different Number\n");
        //if there are, do it again
        getTaxis();
    }
    return taxis;
}

int showMenu(struct stack *s)
{
    int selection, num, search;
    
    printf("\n#####################\n");
    printf("1 - Taxi Arrives\n");
    printf("2 - Taxi Departs\n");
    printf("3 - Print\n");
    printf("4 - Find a Taxi\n");
    printf("0 - Exit\n");
    printf("#####################\n");
    scanf("%d", &selection);
    
    switch(selection)
    {
        case 1:
            //do taxi arrive stuffs
            printf("What is the taxi's number?\n");
            scanf("%d", &num);
            push(s, num);
            break;
        case 2:
            //do taxi depart stuffs
            printf("Next Taxi: %d", pop(s));
            break;
        case 3:
            print(s); //somethings not working, push and pop dont show up when i print the stack
            break;
        case 4:
            //find the taxi stuffs
            printf("What is the taxi's number?");
            scanf("%d", &search);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("\nNot An Acceptable Option\nPlease Select Another!\n\n");
            break;
    }
    return selection;
}

int main()
{
	struct stack st1;
	int taxis = 0, i, selection = 1, num;
	
	init(&st1);
    
    //get the number of taxis
    taxis = getTaxis();
    
    //adds taxis to the queue
    for(i = 1; i <= taxis; i++)
    {
        printf("Number for taxi %d: ", i);
        scanf("%d", &num);
        push(&st1, num);
    }

    while (selection != 0)
    {
        selection = showMenu(&st1);
        printf("Press enter to continue...");
        char c = getchar();
        while (c != '\n')
        {
            c = getchar();
        }
    }
    
	return 0;
}