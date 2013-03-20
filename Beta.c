/*******************/
/*Taxi Rank Program*/
/*By Joshua Jacobs**/
/*******************/

//CHANGES
//CALL SOMETHING HERE TO REMOVE NULL VALS FROM THE QUEUE
//MAKE ADDITIONAL HEADER FILES SO YOU CAN INCLUDE THEM IN THE PROGRAM

#include <stdio.h>
#define MAX_SIZE 6

//function definitions
void init(struct queue *s);
void push(struct queue *s , int num);
int pop(struct queue *s);
void print (struct queue *s);
int getTaxis();
int showMenu(struct queue *s);
int findTaxi();

struct queue
{
	int a[MAX_SIZE]; //for position
    int n[MAX_SIZE]; //for number
	int top;
};

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

int pop(struct queue *s) //CHANGE THIS SO THAT IS POPS FROM THE FRONT NOT THE BACK
{ // -1 returned if queue empty.
    int i;
	if (s -> top < MAX_SIZE)
	{
        for (i = 1; i < MAX_SIZE; i++)
        {
            s -> a[i - 1] = s -> a[i];
            s -> n[i - 1] = s -> n[i];
        }
            s -> top++;
        //CALL SOMETHING HERE TO REMOVE NULL VALS FROM THE QUEUE
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
    //read the users choice
    scanf("%d", &selection);
    
    //process the users choice
    switch(selection)
    {
        case 1:
            //do taxi arrive stuffs
            printf("What is the taxi's number?\n");
            scanf("%d", &num);
            push(s, num);
            break;
        case 2:
            //pop a taxi
            pop(s);
            printf("Next Taxi: %d\n", s -> n[0]);
            break;
        case 3:
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
        //make the press enter thing work in the beta
        printf("Press enter to continue...");
        char *cp, buff[80]; 
    do //capture the enter key
        {
        cp = fgets(buff, sizeof(buff), stdin); 
        } while (cp && *cp != '\n'); //check buffer and pointer
    }
	return 0;
}
