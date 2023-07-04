//main.c - Main source file
//Exercise 1.8.1
//
//Goal: using struct(), arrays, and pointers to initialize data about an article.
//
//Modification date: 11/18/2022

#include <stdio.h>
#include <string.h>

#ifndef LENGTH
#define LENGTH 20				//Defining LENGTH as being equal to 20

#endif

struct Article
{
	int Article_number;			//Variable declaration storing the article number
	int Quantity;				//Variable declaration storing the quantity of articles
	char Description[LENGTH+1];	//Variable declaration storing a description about the said article; \0 at end of string justifies the +1
};

void Print(struct Article* random_p_article);	//Declaring function Print() which will printout the article's number, quantities available, and a description about it

int main(){

	struct Article first_article = {1, 325, "CPP MAGAZINE BY USER"};	//Initializing first article with some random data I came up with.
	Print(&first_article);

	return 0;
}

void Print(struct Article* random_p_article)
{
	printf("Article number is: %d. \n", random_p_article-> Article_number);
	printf("Quantity number is: %d.\n", random_p_article-> Quantity);
	printf("The description of the article is: %s.\n", random_p_article-> Description);
}
