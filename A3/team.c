//
// EECS2031 team.c
//
// Program for maintaining a personal team.
//
//
// Uses a linked list to hold the team players.
//
// Author: Vladimir Stefanovich
// Student Info: 214962740

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

//**********************************************************************
// Linked List Definitions 
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//
//   ADD STATEMENT(S) HERE

struct Node {
  char *familyName;
  char *firstName;
  char position;
  int value;
  struct Node *next;
};


//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE

void push(struct Node** head, char *family, char *first, char pos, int val) {
  //allocate memory for a node
  struct Node* new = (struct Node*) malloc(sizeof(struct Node));
  //set data
  new->familyName = family;
  new->firstName = first;
  new->position = pos;
  new->value = val;
  //assign next
  new->next = (*head);
  //make new node head
  (*head) = new;
}

void insertAfter(struct Node* node, char *family, char *first, char pos, int val) {
  //alocate memory
  struct Node* new = (struct Node*) malloc(sizeof(struct Node));
  //set data
  new->familyName = family;
  new->firstName = first;
  new->position = pos;
  new->value = val;
  //assign next
  new->next = node->next;
  //next of node to new 
  node->next = new;
}

void append(struct Node** head, char *family, char *first, char pos, int val) {
  //alocate memory
  struct Node* new = (struct Node*) malloc(sizeof(struct Node));
  //
  struct Node *last = *head;
  //set data
  new->familyName = family;
  new->firstName = first;
  new->position = pos;
  new->value = val;
  //making new be the last node
  new->next = NULL;
  //
  if (*head == NULL) {
    *head = new;
    return;
  }
  //finding the original last element
  while(last != NULL)
    last = last->next;
  //making the last element be the second last
  last->next = new;
  return;
}

void printList(struct Node *node) {
  while (node != NULL) {
    printf("%s", node->familyName);
    printf("%s", node->firstName);
    printf("%c\n", node->position);
    printf("%d", node->value);
    node = node->next;
  }
  printf("\n");
}

//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void familyNameDuplicate (char familyName[]);   // marker/tester friendly 
void familyNameFound (char familyName[]);       //   functions to print
void familyNameNotFound (char familyName[]);    //     messages to user
void familyNameDeleted (char familyName[]);
void printTeamEmpty (void);
void printTeamTitle(void);
void printNoPlayersWithLowerValue(int value);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char GOALKEEPER = 'G';
const char DEFENDER = 'D';
const char MIDFIELDER = 'M';
const char STRIKER = 'S';


//**********************************************************************
// Main Program
//

int main (void)
{ 
    const char bannerString[]
        = "Personal Team Maintenance Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  V (search by value), P (print), Q (quit).\n";

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.
    struct Node *start = NULL;
    int size = 0;

    // announce start of program
    printf("%s",bannerString);
    printf("%s",commandList);
    
    char response;
    char input[MAX_LENGTH+1];
    do
    {
        printf("\nCommand?: ");
        safegets(input,MAX_LENGTH+1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
	  {
	    // Insert a player entry into the linked list.
            // Maintain the list in correct order (G, D, M, S).
            //   ADD STATEMENT(S) HERE
	    char family[20], first[20];
	    char pos;
	    int val;

            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
	    printf("  family name: ");
	    fgets(family, 20, stdin);

	    printf("  first name: ");
	    fgets(first, 20, stdin);

	    printf("  position: ");
	    scanf("%c", &pos);

	    printf("  value: ");
	    scanf("%d", &val);
	    
	    if(start == NULL) {
	      push(&start, family, first, pos, val);
	    } else {
	      struct Node* current = start;
	      
	      while(current->next != NULL) {
		if (current->position == pos) {
		  while (current->next != NULL && current->position == pos)
		    current = current->next;
		  break;
		} else {
		  current = current->next;
		}
	      }
	      if (current->next == NULL)
		append(&current, family, first, pos, val);
	      else
		insertAfter(current,family, first, pos, val);
	    }
	    
	  }
	else if (response == 'D')
	  {
	    // Delete a player from the list.
	    
	    printf("\nEnter family name for entry to delete: ");
	    
            //   ADD STATEMENT(S) HERE
	    
	  }
        else if (response == 'S')
	  {
            // Search for a player by family name.
	    
            printf("\nEnter family name to search for: ");
	    
            //   ADD STATEMENT(S) HERE
	    
	  }
        else if (response == 'V')
	  {
            // Search for players that are worth less than or equal a value.
	    
            printf("\nEnter value: ");

            //   ADD STATEMENT(S) HERE

        }
        else if (response == 'P')
        {
            // Print the team.

            //   ADD STATEMENT(S) HERE
	  
	  if(start == NULL)
	    printTeamEmpty();
	  else{
	    printTeamTitle();
	    printList(start);
	  }
	  
        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        else 
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n",commandList);
        }
    } while (response != 'Q');
  
    // Delete the whole linked list that hold the team.
    //   ADD STATEMENT(S) HERE
    

    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
    printList(start);

    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize-1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name 
// that is already in the book.
void familyNameDuplicate (char familyName[])
{
    printf("\nAn entry for <%s> is already in the team!\n"
           "New entry not entered.\n",familyName);
}

// Function to call when a player with this family name was found in the team.
void familyNameFound (char familyName[])
{
    printf("\nThe player with family name <%s> was found in the team.\n",
             familyName);
}

// Function to call when a player with this family name was not found in the team.
void familyNameNotFound (char familyName[])
{
    printf("\nThe player with family name <%s> is not in the team.\n",
             familyName);
	
}

// Function to call when a family name that is to be deleted
// was found in the team.
void familyNameDeleted (char familyName[])
{
    printf("\nDeleting player with family name <%s> from the team.\n",
             familyName);
}

// Function to call when printing an empty team.
void printTeamEmpty (void)
{
    printf("\nThe team is empty.\n");
}

// Function to call to print title when whole team being printed.
void printTeamTitle (void)
{
    printf("\nMy Team: \n");
}

// Function to call when no player in the team has lower or equal value to the given value
void printNoPlayersWithLowerValue(int value)
{
	printf("\nNo player(s) in the team is worth less than or equal to <%d>.\n", value);
}

//**********************************************************************
// Add your functions below this line.
