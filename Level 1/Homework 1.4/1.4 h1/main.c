//Exercise 1.4.1

/* Goal: Write a C-program that asks for text input from the keyboard. The output of this program
         should be the amount of characters, the amount of words and the amount of lines that have 
         been typed. Multiple consecutive spaces should not be counted as multiple words. */

#include <stdio.h>
#include <ctype.h>

int main()
{
    int letter= 0, prev_letter=0, num_char = 0, num_words = 0, num_lines = 1;

    printf("User, please provide any text you wish using letters, spaces, tabs, and enter. \n When done, enter Ctrl+D or Ctrl+Z on your keyboard.");
    
    while ((letter = getchar()) != 4 && letter!= 26 && letter != EOF){   //In ASCII, Ctrl+D is 4, and Ctrl+Z is 26
        if (isalnum(letter)) //Characters considered are letters, numbers or digits, not spaces.
        num_char++;
        
        else if (letter == 10)   // 10 = Line feed, 13
        {
            num_lines++;
            if (isalpha(prev_letter))
            num_words++;
        }
        else if (letter == 32 || letter == 9)   // 9 = Horizontal tab, 32 = space
        {
            if (isalpha(prev_letter))
            num_words++;
        }
        else if(ispunct(letter))  //Punctuation marks to end sentence
        {
            if(isalnum(prev_letter))
            num_words++;
            else{num_char++;}
        }
        
        prev_letter = letter;
    }

    printf("Number of characters is: %d. \n", num_char);
    printf("Number of words is: %d. \n", num_words);
    printf("Number of lines is: %d. \n", num_lines);
    return 0;
}