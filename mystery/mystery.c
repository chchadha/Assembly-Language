//
//  mystery.c
//  Assembly Language Programming
//
//  Created by Chirag Chadha on 11/6/16.
//  Copyright © 2016 ChiragChadha. All rights reserved.
//

#include "mystery.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
 There are three functions I see when dealing with the Mystery.s file. That is: 1. add 2. dothething 3. main
 */


/*
 add:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax   //adding second number to first
	popl	%ebp
	ret                     //returning value
	.size	add, .-add
 */

int add(int a, int b){
    return a + b;
}

int fibonacci(int input){  //Fibonacci
    
    int num;
    
    if(input == 0){
        return 0;
    }else if(input == 1){
        return 1;
    }else{
         num = add(fibonacci(input-1), fibonacci(input -2));
    }
    
    return num;
    
    /* 
     I realized that the code was conversion because I continuously saw a call statement. Specifically, 
     
     call	dothething
     
     in the function dothething. I immediately realized that the function was calling itself and I implemented it in my c function.
    */
}

int main(int argc, char ** argv) {
   //Error checking
    if(argv[1] == NULL){
        printf("Error: Input was not given. Please enter a positive number input\n");
        
    }else if(isdigit(*argv[1]) == 0){
       
        printf("Error: Input was not a positive number. User entered non digit character. Please enter a positive number input\n");
    
    }else if(*argv[1] < 0){
        printf("Error: Input was not a positive number. User entered negative digit. Please enter a positive number input\n");
        
    }else if(argc > 2){
        printf("Error: Multiple arguments were given. Please enter a positive integer.\n");
    }else{
        //Convert number and compute fib number. 
        int value;
        int userInput = atoi(argv[1]);
        value = fibonacci(userInput);
        printf("Value: %d \n", value);
        
    }

}
