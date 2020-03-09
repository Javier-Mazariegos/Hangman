    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    #define MAX_WORDS 23



    // # FUNCTION PROTOTYPES
    const char* get_random_word(void);




    // Global variables
    int tamaño = 0;
    int tamaño_letras_repetidas =0;
    int intentos = 10;
    int aciertos = 0;
    char palabra_oculta[20] = "";
    char letras_repetidas[11] = "";
    const char *word_collection[MAX_WORDS]= {
                        "caracter","internet","algoritmo","variable","google",
                        "aplicacion","programa","facebook","bitcoin",
                        "parasitos","agregar","flexible","iphone","pantalla",
                        "palabras","gamaer","nintendo","instagram","snapchat",
                        "whatsapp","sony","impresora","blockchain"
                        };

    const char* get_random_word(void){
        srand ( time (0) );
        int random_position = rand() % MAX_WORDS;
        return word_collection[random_position];
    }

    void enter()
    {
      char c = ' ';
      printf("\nPresione Enter para volver a Menu\n");
      getchar();
      if(c == ' ')
      {
        getchar();
      }
          system("@cls||clear");
    }

    void ocultar_palabra(const char* palabra)
    {
        tamaño = strlen(palabra);
        for(int i=0; i<tamaño; i++)
        {
            palabra_oculta[i] = '_';
        }
    }

    int verificar_palabra(char letras[], const char* palabra)
    {
        if(letras[0] != '0')
        {
        intentos--;
        if(intentos>=0)
        {
         if(strcmp(letras,palabra) == 0)
         {
           aciertos++;
          return 1;
         }
         else 
         {
           tamaño_letras_repetidas = strlen(letras_repetidas);
           
           for(int i =0; i<tamaño_letras_repetidas; i++)
           {
             if(letras[0] == letras_repetidas[i])
             {
               return 0;
             }
           }
           
           char aumento = 'f';
           for(int i =0; i< tamaño; i++)
           { 
             if(letras[0] == palabra[i])
             {
               if(aumento == 'f')
               {
                 aciertos++;
                 aumento = 'v';
               }
              palabra_oculta[i] = letras[0];
              letras_repetidas[tamaño_letras_repetidas] = letras[0];
             }
           }

           if(strcmp(palabra_oculta,palabra) == 0)
           {
             return 1;
           }
           
         }
        }
        else if(intentos == -1)
        {
          return 2;
        }
        }
        else if(letras[0] == '0')
        {
          return 2;
        }
        return 0;
    }

    int main(){
        int menu = 0;

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
            intentos = 10;
            aciertos = 0;
            char letras[20] = "";
            char nombre_jugador[20] = "";
            srand ( time (0) );
            const char* palabra_elegida = get_random_word();
           // printf("%s\n",palabra_elegida);
            ocultar_palabra(palabra_elegida);
            printf("\nIngrese su nombre: ");
            scanf("%s", nombre_jugador);
            
            while(1)
            {
             printf("Jugador: %s\n", nombre_jugador);
             printf("Intentos: %d\n", (intentos-10)*-1);
             printf("Aciertos: %d\n", aciertos);
             printf("        ");
             for(int i=0; i<tamaño; i++)
             {
              printf("%c ", palabra_oculta[i]);
             }
             printf("\n\n Ingrese Letra/Palabra: ");
             scanf("%s",letras);

             int gano = verificar_palabra(letras, palabra_elegida);        
             if(gano == 1)
             {
          
        
              printf("######### GANO!!! #########\n");
              printf("Palabra adivinada: '%s'\n",palabra_elegida);
              printf("Jugador: %s\n", nombre_jugador);
              printf("Intentos: %d/10\n", (intentos-10)*-1);
          
              enter();
              break;
             } else if(gano == 2)
             {
           
              printf("\033[0;31m"); 
              printf("######### GAME OVER #########\n");
              printf("Palabra a adivinar: '%s'\n",palabra_elegida);
              printf("Jugador: %s\n", nombre_jugador);
              printf("Intentos: %d/10\n", 10);
         
              enter();
              break;
             }
            
            }
         }
         //-----------------------------------------------------------

        //opcion 2----------------------------------------------------
        if(menu==2)
        {
    +
          printf("----------------------Instrucciones----------------------\n");
          printf("1. Tienes 10 intentos en los que tienes que ir descubriendo la palabra\n");
          printf("2. Puedes ingresar la palabra directamente\n");
          printf("3. Solo puedes ingresar una palabra a la vez\n");
          printf("4. Todas las letras ingresadas tienen que ser en minuscula\n");
          printf("5. El juego termina al adivinar la palbra o al presionar la letra 0\n");
           printf("---------------------------------------------------------\n");
         
           enter();
          
        }
        //------------------------------------------------------------

        //Opcion 3-----------------------------------------------
        if(menu == 3)
        {
     
        printf("----------------------ABOUT----------------------\n");
        printf("Desarrollador: Javier Alejandro Mazariegos Godoy\n");
        printf("Correo electronico: javiermazariegos@ufm.edu\n");
        printf("Numero de telefono: +50255571419\n");
        printf("Programa hecho en C\n");
        printf("--------------------------------------------------\n");
   
        enter();
        
        }
        //----------------------------------------------------

        //Opcion 4--------------------------------------------
        if(menu == 4)
        {
          break;
        }
        //----------------------------------------------------

        }
        return 0;
    }