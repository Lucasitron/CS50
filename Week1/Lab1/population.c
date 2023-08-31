/*Autor: Lucasitron
**Objetivo: Criar um validador de cartões de credito implementando o algoritimo do luhn
**Fontes: https://ead.napratica.org.br/enrollments/8156038/courses/84414/course_contents/2140244
**Biblioteca CS50: https://github.com/cs50/libcs50.git
**github.com/lucasitron
______________________________________________________________________________________________*/

#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*function to death calculate*/
int death(int qtd, int year){
    int dea = (qtd/3) * year;
    return dea; 
}

/*function to calculate a bith rate*/
int bith(int qtd, int year){
    int bit = ((qtd/4) * year) * -1;
    return bit;
}


int main(void) {
    
    /*input of population data and a quantity years*/
    int pop;
    int year;
    do{
        pop = get_int("Enter a current quantity: ");
    }while(pop < 1);
    do
    {
        year = get_int("year: ");
    } while (year < 1);
    
    /*stores the quantity of animals in the final of period*/
    int population = pop + (death(pop, year) + bith(pop, year));

    printf("Population: %i", population);

    return 0;
}