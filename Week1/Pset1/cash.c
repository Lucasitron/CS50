/*Autor: Lucasitron
**Description: Algoritimo guloso que conta quantas moedas serão utilizadas para
**chegar a um determinado valor que será obtido via input de usuário.
**
____________________________________________________________________________________*/
#include <cs50.h>
#include <stdio.h>

int main(void){

/*cash enter*/
float cash = get_float("cash: ");

/*Valid entered validate*/
if (cash < 0)
{
    exit(0);
}


/*cashback calculator*/
short int count = 0;

/*25$ decrement*/
for ( cash; (cash - 25) > 0; cash - 25){
    count++;
}

/*10$ decrement*/
for (cash; (cash - 10) > 0; cash - 10)
{
    count++;
}

/*5$ decrement*/
for ( cash; (cash - 5) > 0; cash - 5){
    count++;
}

/*1$ decrement*/
for (cash; (cash - 1) > 0; cash - 1)
{
    count++;
}

/*cashback print*/
printf("back: %i", count);

}