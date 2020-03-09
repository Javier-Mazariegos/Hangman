    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>


    #define MAX_WORDS 23



    // # FUNCTION PROTOTYPES
    const char* get_random_word(void);




    // Global variables
    const char *word_collection[MAX_WORDS]= {
                        "caracter","internet","algoritmo","variable","google",
                        "aplicacion","programa","facebook","bitcoin",
                        "parasitos","agregar","flexible","iphone","pantalla",
                        "palabras","gamaer","","instagram","snapchat",
                        "whatsapp","telegram","impresora","blockchain"
                        };

    const char* get_random_word(void){
        srand ( time (0) );
        int random_position = rand() % MAX_WORDS;
        return word_collection[random_position];
    }



    /*
    Insert your code here
    */

    int main(){
        // note como se invoca la funcion, la funcion se invoca de esta manera y se guarda en una variable
        const char* palabra_elegida = get_random_word();
        printf("%s\n",palabra_elegida);
        int menu = 0;
        char nombre_jugador[] = "";
        int intentos = 0;
        int aciertos = 0;

        while(1)
        {

        //Menu-----------------------------------------------
        printf("\n--------------HANGMAN MENU--------------\n");
        printf("1. Empezar juego\n");
        printf("2. Ver Instrucciones\n");
        printf("3. About\n");
        printf("4. Salir\n");
        printf("----------------------------------------\n");
        //Fin menu-------------------------------------------

        //Elegir---------------------
        printf("Ingrese Opcion: ");
        scanf("%d",&menu);
        printf("\n");
        //---------------------------

        //Opcion 1--------------------------------------------
        if(menu == 1)
        {
           
        }
        //----------------------------------------------------
        }

        //char str1[] = "abcd", str2[] = "abcd", str3[]="abCd";
        //printf("strcmp(str1, str2) = %d\n", strcmp(str1,str2));
        //printf("strcmp(str1, str2) = %d\n", strcmp(str1,str3));

        /*
            Insert your code here
        */
        return 0;
    }