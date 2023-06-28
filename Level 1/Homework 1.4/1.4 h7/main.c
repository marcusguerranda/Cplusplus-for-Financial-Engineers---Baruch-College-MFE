// Exercise 1.4.6

// Goal: Count number of times user inputs numbers from 0 to 4, whilst also keeping track of any other characters. 

/* Structure: the assignment question asks to count how many times " the numbers 0-4" have been typed. Hence, if one types 24, the program will count 2 and 4
              as additional instances of 2 and 4, as well as being two different additional characters.

*/

#include <stdio.h>

int main()
{
    
    int cnum_0 = 0, cnum_1=0, cnum_2=0, cnum_3=0, cnum_4=0, cnum_others=0, users_input=0; 
   
    printf("User, please provide any number that comes to your mind:");
    
    while ((users_input=getchar()) != 4 && users_input != 26 && users_input != EOF)  // As long as program not terminated by an input of Ctrl+D, Ctrl+Z, EOF
    {  
       switch (users_input)
        {
            case 48: //0 in ASCII
                    cnum_0++;
                    break;
        
            case 49: //1 in ASCII
                    cnum_1++;
                    break;
        
            case 50: //2 in ASCII
                    cnum_2++;
                    break;
        
            case 51: //3 in ASCII
            
                    cnum_3++;
                    break;

            case 52: //4 in ASCII
                    cnum_4++;
                    break;
        
            default:
                    cnum_others++; //All other characters other than 0-4 --> base case/default.
                    break;  
        }
    }
    printf("User has inputted %d times 0. \n", cnum_0);
    printf("User has inputted %d times 1. \n", cnum_1);
    printf("User has inputted %d times 2. \n", cnum_2);
    
    switch(cnum_3)
    {
        case 0: printf("User has given zero times the number 3. \n"); 
                break;
        
        case 1: printf("User has given one time the number 3. \n");
                break;

        case 2: printf("User has given two times the number 3. \n");
                break;
        default: printf("The number 3 appears more than two times. \n");
    }

    printf("User has inputted %d times 4. \n", cnum_4);
    printf("User has inputted %d other characters. \n", cnum_others);
    
    return 0;
}