    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>


    #define MAX_WORDS 23



    // # FUNCTION PROTOTYPES
    const char* get_random_word(void);




    // Global variables
    int tamaño = 0;
    int intentos = 10;
    int aciertos = 0;
    char palabra_oculta[] = "";
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



    void ocultar_palabra(const char* palabra)
    {
        tamaño = strlen(palabra);
        for(int i=0; i<tamaño; i++)
        {
            palabra_oculta[i] = '_';
        }
    }

    void verificar_palabra(char letras[], const char* palabra)
    {
        intentos--;
        if(intentos>=0)
        {
         if(strcmp(letras,palabra) == 0)
         {
          aciertos++;
         }
         else 
         {
           printf("No Adivino la palabra\n");
         }
        } 
    }

    int main(){
        int menu = 0;
        intentos = 10;
        aciertos = 0;
        char letras[20] = "";
        char nombre_jugador[20] = "";
        int ejemplo;

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
            const char* palabra_elegida = get_random_word();
            printf("%s\n",palabra_elegida);
            ocultar_palabra(palabra_elegida);
            printf("\nIngrese su nombre: ");
            scanf("%s", nombre_jugador);
            
            while(1)
            {
             printf("Jugador: %s\n", nombre_jugador);
             printf("Intentos: %d\n", intentos);
             printf("Aciertos: %d\n", aciertos);
             printf("        ");
             for(int i=0; i<tamaño; i++)
             {
              printf("%c ", palabra_oculta[i]);
             }
             printf("\n\n Ingrese Letra/Palabra: ");
             scanf("%s",letras);
             verificar_palabra(letras, palabra_elegida);
            // scanf("%d",&ejemplo);
            }
            
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