#include <stdio.h>
#define MAX_SIZE 6

struct queue
{
	int a[MAX_SIZE]; //for position
    int n[MAX_SIZE]; //for number
	int top;
};

//function definitions
void init(struct queue *s);
void push(struct queue *s , int num);
int pop(struct queue *s);
void print (struct queue *s);
int getTaxis();
int showMenu(struct queue *s);
int findTaxi();