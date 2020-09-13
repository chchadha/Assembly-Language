//
//  formula.c
//  Assembly Language Programming
//
//  Created by Chirag Chadha on 11/6/16.
//  Copyright © 2016 ChiragChadha. All rights reserved.
//

//  Assembly Language Programming
//
//  Created by Chirag Chadha on 11/1/16.
//  Copyrigh/Users/chiragchadha/My Cloud/Assembly Language Programming/Assembly Language Programming/main.ct © 2016 ChiragChadha. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nCr.h"
#include <ctype.h>
#include "formula.h"
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char ** argv) {
   
    char *help = "-h"; //string for help flag
    
    if(argv[1] == NULL){ //check if arguments are empty
        printf("Error: Input was not given. Please enter a positive number input\n");
        
    }else if(strcmp(argv[1], help) == 0){ //check if the input is help flag
        printf("Usage: formula <positive integer>\n");
        printf("Enter a positive integer to calucluate the combination. Do not use any negative numbers or non-integer characters\n");
        
    }else if(isdigit(*argv[1]) == 0){ //Tell if input is integer.
        printf("Error: Input was not a positive number. User entered non digit character / negative number. Please enter a positive number input\n");
        
    }else if(argc > 2){ // check if user entered multiple arguments
        printf("Error: User has provided too many inputs. Please enter a postive number only.\n");
        
    }else{
   
        char stringVal[] = "*x^";   //constant string
        char finalResult[200] = ""; //allocated memory for an empty string
        int pos =0;
        
        int userInput = atoi(argv[1]); //convert input string to number
        
        int index;
        
        struct timeval start, end; // declare timeval type variables start and end
        gettimeofday(&start, NULL); //get start time

        //For loop concatinates string after doing computations on integer value.
        for(index = 0; index <= userInput ; index++){
            
            int leadingTerm = nCr(userInput, index);
            
            if(userInput == 0){
                pos += sprintf(&finalResult[pos], "%d", leadingTerm);
            }else if(index == 0){
                pos += sprintf(&finalResult[pos], "%d%s", leadingTerm," + ");
            }else if(index == userInput){
                pos += sprintf(&finalResult[pos], "%d%s%d", leadingTerm, stringVal, index);
            }else{
                pos += sprintf(&finalResult[pos], "%d%s%d%s", leadingTerm, stringVal, index," + ");
            }
        }
        gettimeofday(&end, NULL); //get end time
        /* subtract start time from end time and print them in microseconds. */
        printf("Time Required = %ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec)
                         - (start.tv_sec * 1000000 + start.tv_usec)));

        printf("The expanded form is: %s \n", finalResult);
    }
}




