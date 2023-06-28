//Exercise 1.4.3

/* Goal: Same intention as last exercises but exclusively using SWITCH-case.*/

/* Note: I paid particular attention to all potential subcases, as to whether current input and previous input justified adding to word,line, and character counters.
         Only using switch()-case was extremely tedious, but am quite satisfied with the final result (rules for punctuation, alphanumeric inputs, double spaces, etc.)*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int letter = 0, prev_letter = 0, num_char = 0, num_words = 0, num_lines = 1;


    printf("User, please provide any text you wish using letters, spaces, tabs, and enter. \n When done, enter Ctrl+D or Ctrl+Z on your keyboard.");
    
    while ((letter = getchar()) != 4 && letter!= 26 && letter != EOF)                    //In ASCII, Ctrl+D is 4, and Ctrl+Z is 26
    {       switch(isspace(letter))
            {
                case 0:         //False = is not a whitespace.                                    
                {      
                    switch(isalnum(letter))
                       {
                            case 0: num_char++; break;   //All other cases are just another character added in this case 0 (Not whitespace)
                            {       
                                    switch(isalnum(prev_letter))
                                    {
                                        case 0: num_char++;

                                        default: num_words++; num_char++; break;
                                    }
                            }break;

                            default: 
                                    switch(isalnum(prev_letter))
                                    {
                                            case 0: num_char++; num_words++; break;

                                            default: num_char++; break;
                                    }
                            break;
                       }
                }break;
                default: break;
            }

                
            switch(letter)
            {       
                case 9:            // 9 = Horizontal tab
                {    switch(isspace(prev_letter))
                        {
                        case 0: 
                        {switch(isalnum(prev_letter))
                            {   case 0: break;
                                default: num_words++; break;
                            }
                        }break;        
                        default: break;
                        }
                    
                }break;
                    
                case 32:            //32 = Space
                {   switch(isspace(prev_letter))
                    {
                        case 0: 
                        {    switch(isalnum(prev_letter))
                            {   case 0: break;
                                default: num_words++; break;
                            }
                        }break;

                        default: break;
                    }
                    
                }break;
                 
                            
                case 10 :   //10 = Line Feed
                {    switch(isspace(prev_letter))
                    {
                        case 0: 
                        {       switch(isalnum(prev_letter))
                            {       case 0: num_char++; break;

                                    default: num_words; num_lines++; break;

                            }
                        }break; 
                            
                        default: num_lines++; break; 
                    }
                    
                }break;

                default: break;
            }

    prev_letter = letter;       
          
    }       
    
    printf("Number of characters is: %d. \n", num_char);
    printf("Number of words is: %d. \n", num_words);
    printf("Number of lines is: %d. \n", num_lines);
    return 0;
}
