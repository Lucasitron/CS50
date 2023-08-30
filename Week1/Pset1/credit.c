/*Autor: Lucasitron
**Objetivo: Criar um validador de cartões de credito implementando o algoritimo do luhn
**fontes:https://ead.napratica.org.br/enrollments/8156038/courses/84414/course_contents/2140244
**Biblioteca CS50: https://github.com/cs50/libcs50.git
**github.com/lucasitron
______________________________________________________________________________________________________________*/

#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_Digits(long num){
    /*digits count*/
    int count = 0;
    while (num > 0)
    {
        num = num/10;
        count ++;
    }
    return(count);
}

int* par_Multiplicator(long num, int digits){
    /*vector stores a number*/
    int *store = (int *)malloc((digits) * sizeof(int));
    
    /*Stores a num in the vector*/
    for (int i = 0; i < digits; i++)
    {
        if (i == 0 || (i%2) == 0)
        {
            store[i] = num%10;
            num = num / 10;    
        }else {
            store[i] = ((num%10)*2);
            num = num / 10;
        }
                
    }


    return store;
}

/*sum for all digits*/
bool valid(int* dig, int qtd){
    
    /*store a validity of card*/
    bool val = 0;

    int sum = 0;

    for (int i = 0; i < qtd; i++)
    {
        if (i==0 || i%2 == 0)
        {
            sum = sum + dig[i];

        }else if(i%2 != 0 && dig[i] >=10){

            sum = sum + (dig[i]%10);
            dig[i] = dig[i]/10;
            sum = sum + dig[i];

        }else if(i%2 != 0 && dig[i]< 10){
            sum = sum + dig[i];
        }
                
    }

    /*If sum(Checksum) is divisible by teen, the card credit is valid and val is true.*/
    if(sum % 10 == 0){val = 1;}

    /*return of function*/
    return val;


}

/*Flag varification*/
string vFlag(int qDig,int *dig){
    /*Comparison the 4 first numbers whith the flag digtis*/
    /*number of digits per flag*/
    /*Visa 13 || 16
    **American 15
    **MasterCard 16*/

   /*Store flar variable*/
   string nFlag;

   /*if the number of digits is thirteen, the card credit is Visa
   **if is fifteen, American*/
   if (qDig == 13 || (qDig == 16 && dig[16] == 4))
   {
        nFlag = "Visa";
   }else if (qDig == 15)
   {
        nFlag = "AmericanExpress";
   }else{
        nFlag = "MasterCard";
   }
   
   return nFlag;
}

int main(void){
    
    /*exit key*/
    bool key = false;
    do{
        /*entered credit number*/
        long number = get_long("enter a card number: ");
        system("clear");

        /*Stores the number of digits of the card.*/
        int qDigits = count_Digits(number);

        /*par case multiplication*/
        int *digits = par_Multiplicator(number, qDigits);

        /*Output informing if the card is valid and its flag*/
        if(valid(digits, qDigits)){
            printf("Card number: %li\n", number);
            printf("Flag: %s \n", vFlag(qDigits,digits));
            printf("VALID \n");
        }else{
            printf ("Card number: %li", number);
            printf("INVALID\n");
        }

        /*Stop comand*/
        int enter;
        
        /*prompts for input until typed correctly*/
        do
        {
            enter = get_int("Press\n1: continue\t2: quit\n");
        } while (enter > 2 || enter < 1);
        

        /*comand verification*/
        if (enter == 2)
        {
            printf("Thanks");
            key = true;
        }else{
            system("clear");
        }
        
    }while(key == false);
    
}
