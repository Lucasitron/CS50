/*
**Autor: Lucasitron
**Objetivo: Imprimir uma "montanha" de # de altura e orientação definida por input do usuário
__________________________________________________________________*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    /*Variables*/
    short int height = 0;
    string guid;

    /*Height input*/
    height = get_int("enter the height: ");
    
    /*Close case height <=0 or > 8*/
    if(height <=0 || height > 8 ){
        exit(0);
    }

    /*orientation input*/
    guid = get_string("Enter guidance: ");

    /*Close case orientation != up or dow*/
    if(((strcmp(guid,"up")==1) || (strcmp(guid,"dow")==1)) || (strcmp(guid, "GOD")==1)){
        exit(0);
    }
    
    /*Print whith the orientation entered*/
    if(strcmp(guid, "up")==0){
        /*loop for print*/
        for (short int line = 1; line <= height; line++)
        {
            /*count the #*/
            short int count = line;
            /*print the line*/
            while(count > 0){
                printf("#");
                count --;
            }
            printf("\n");
        }
        
    }else if(strcmp(guid,"dow")==0){

        /*variable auxiliar for heigth*/
        short int aux = height;

        /*loop for print*/
        for (short int line = 1; line <= height; line++)
        {
            /* Count for # for line */
            short int count = aux;

            while (count > 0)
            {
                printf("#");
                count --;
            }
            
            aux--;

            /*insert one line*/
            printf("\n");
            
        }
        
    /*2 column version*/
    }else if(strcmp(guid,"GOD")==0){
        /*heigth auxiliar*/
        short int aux = height - 1;

        /*Count whith 2.heith +2*/
        //short int count = (height*2) + 2;

        /*height loop*/
        for (short int i = 1; i < height; i++)
        {
            /*Line loop*/
            /*spaces print*/
            for (short int j = 0; j < aux; j++)
            {
                printf(" ");
            }

            /*Print of #*/
            for (short int k = 0; k < height - aux; k++)
            {
                printf("#");
            }

            /*2 spaces*/
            printf("  ");
            
            /*print right side*/
            for (short int k = 0; k < height - aux; k++)
            {
                printf("#");
            }

            printf("\n");
            aux --;
        }
              
    }
}