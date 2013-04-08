/*******************/
/*Taxi Rank Program*/
/*By Joshua Jacobs**/
/******j010004b*****/
/*******************/

/*CHANGES
MAKE ADDITIONAL HEADER FILES SO YOU CAN INCLUDE THEM IN THE PROGRAM
*/

#include <conio.h>
#include "defs.h"

void init(struct queue *s)
{
    //initialise the queue
	s -> top = 0;
}

void push(struct queue *s , int num)
{
    //make sure the queue isn't full
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

int pop(struct queue *s)
{ // -1 returned if queue empty.
    int i;
	if (s -> top > 0)
	{
        for (i = 1; i < MAX_SIZE; i++)
        {
            //reorder the rank so that the taxis are in position
            s -> n[i - 1] = s -> n[i];
        }
            s -> top--;
            return(s -> a[s -> top]);
	}
	else return -1;
}

void print (struct queue *s)
{
	int i;

	printf("\n-------------------\n");
    //if there's taxis in the queue
	if( s -> top > 0 )
		{
        //print out the position and number of each taxi
		for(i = 0; i < s -> top ; i++)
			printf("Pos - %d -- Num - %d\n", s -> a[i] + 1, s -> n[i]);
		}
    //if it's empty
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

int findTaxi(int a[], int num_elements, int value)
{
   int i;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i] == value)
	 {
	    return(i); //it was found
	 }
   }
   return(-1); //it was not found
}

int showMenu(struct queue *s)
{
    int selection, num, search, found;
    
    //show the menu structure
    printf("\n#####################\n");
    printf("1 - Taxi Arrives\n");
    printf("2 - Taxi Departs\n");
    printf("3 - Print\n");
    printf("4 - Find a Taxi\n");
    printf("0 - Exit\n");
    printf("#####################\n");
    printf("Please Enter a Menu Option: ");
    //read the users choice
    scanf("%d", &selection);
    
    //process the users choice
    switch(selection)
    {
        case 1:
            //add a taxi to the rank
            printf("What is the taxi's number?\n");
            scanf("%d", &num);
            push(s, num);
            break;
        case 2:
            //pop a taxi
            if (pop(s) == -1) {
                printf("The array is empty!\n");
            } else {
                printf("Next Taxi: %d\n", s -> n[0]);
            }
            break;
        case 3:
            //print the rank
            print(s);
            break;
        case 4:
            //search in the numbers array
            printf("What is the taxi's number?");
            scanf("%d", &search);
            found = findTaxi(s -> n[], MAX_SIZE, search);
            if (found != -1)
            {
                printf("That Taxi is Number %d\n", found + 1);
            }
            else printf("That Taxi is Not in The Rank!\n");
            break;
        case 0:
            //exit the program
            printf("Exiting...\n");
            break;
        default:
            printf("\nNot An Acceptable Option,\nPlease Select Another!\n\n");
            break;
    }
    return selection;
}

int main()
{
	struct queue st1;
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
    
    //run the menu while the user doesn't want to exit
    while (selection != 0)
    {
        
        selection = showMenu(&st1);
        if (selection != 0) {
            
            printf("Press enter to continue...\n");
            char cp;
        do
            {
                cp = getche(); //captures the enter key
            } while (cp != '\r');
        }
    }
	return 0;
}
