#include <stdio.h>

void printTablero(int tablerodeljuego[11][11]);

int main()
{
     
     int retry = 1;   // variable que se utiliza al final por eljugador por si quiere volver a jugar se tiene que establecer afuera de ese loop
     int PRESCORE = 0; // guardamos el puntaje anterior del jugador
     int switcher = 0;
     int looper = 0;
     while(retry != 0)
     {
         while(looper == 0)
         {
             //Main Menu
             
             printf(" 1.Jugar \n 2.Score Total Anterior \n 3.Quit\n");
             
             printf(" Seleccione una opcion: \n");
             scanf("%d",&switcher);
            
             switch(switcher)
             {
                 case 1:  //solo sale del loop y empieza el juego
                 printf("START\n");
                 looper = 1;
                 break;
                 
                 case 2: // da el score del juego anterior y no cambia looper entonces no sale del loop del switch
                 printf("su puntaje anterior fue %d \n",PRESCORE); 
                 break;
                 
                 case 3: //acaba el juego y sale 
                 retry = 0;
                 looper = 1;
                 break;
             } 
         }
         if(retry== 0) //esto sigue despues que se elije CASE 3 en el switch porque este break debe ser hecho afuera del switch para que haga break al main loop
         {
             break;
         }
         srand(time(NULL)); //RNG
         int tablerodeljuego[11][11]; //11x11 por que el tablero esta adentro de un marco de numero 0 lo que hace que todas las casillas SIEMPRE tienen un completo cuadrado de numeros adyacentes para que no se cuasen errores
         
         int i;
         int j;
         int k;
           
         int cordx = 0; //para el usario 
         int cordy = 0;
         int cordx2 = 0;
         int cordy2 = 0;
           
         int match = 0; //variables ocupadas en while loops
         int repeat = 1;
         int counter =0;
         int GAMEEND = 0;
         int finisher = 0;
         int subir = 2; //variable que cuenta si una linea entera esta vacia, y se resetea cada vez que una linea es analizada por el codigo
         
            
         
         
          //----------------------------------------------------------------------------------------------------- pre programa
         for(int i=0 ; i<11 ; i++) //llena el tablero con numeros vacios 
         {
            for(int j=0 ; j<11 ; j++)
             {
                 tablerodeljuego[i][j]=0;
             }
         } 
          
         for(int i=1 ; i<10 ; i++) //llena el tablero con numeros aleatorios entre 1 y 9 
         {
            for(int j=1 ; j<10 ; j++)
             {
                 tablerodeljuego[i][j]=rand() % 9+1;
             }
         } 
            
         
            
            
          
         //MAIN LOOP---------------------------------------------------------------------------------------------
         while (GAMEEND==0) //cuando la variable counter sea igual a matchcounter(la cantidad total de matches en el tablero), el juego termina 
         {    
             printf("\n");
             match = 0; //variable que indica cuando se encuentra un par de cartas
             repeat=1;
                
             //resetea estas variables cada vez que se repite el loop del juego 
             cordx=0;
             cordy=0;
             cordx2=0;
             cordy2=0;
             finisher=0;
             switcher = 0;
             
             printf("\t*****Match10!!!*****\n"); //imprime el primer tablero
             printf("        0  1  2  3  4  5  6  7  8\n");
             
             printTablero(tablerodeljuego);   
             printf("\n");
                
             while (switcher < 1|| switcher > 2)
             {
                 printf("1. elegir casilla? \n");
                 printf("2. remplazar las 3 filas por otras mas? %d chances mas quedan \n",subir);
                 scanf("%d",&switcher);
                 if(subir == 0 && switcher == 2) //cuando se queda sin chances de subir filas, el programa detiene al jugador de volverlo hacer
                 {
                     switcher =3;
                 }
                 
             }
             
             
             switch(switcher)
             {
                 case 1: 
                 break; //solo continua el juego
                 
                 case 2:
                 if(subir == 2)
                 
                 {
                     for(k =1 ; k<10 ; k++)
                       
                     {
                         
                         
                          tablerodeljuego[1][k] = 0; //la primera vez que el jugador pide cambiar las tres filas hace esta funcion adonde toma las lineas escondidas 4 5 y 6 y remplaza  1 2 y 3 por ellas. lineas 4 5 y 6 se llenan de 0s
                          tablerodeljuego[1][k] = tablerodeljuego[1][k] + tablerodeljuego[4][k];
                          tablerodeljuego[4][k] = 0;
                          
                          tablerodeljuego[2][k] = 0;
                          tablerodeljuego[2][k] = tablerodeljuego[2][k] + tablerodeljuego[5][k];
                          tablerodeljuego[5][k] = 0;
                         
                          
                          tablerodeljuego[3][k] = 0;
                          tablerodeljuego[3][k] = tablerodeljuego[3][k] + tablerodeljuego[6][k];
                          tablerodeljuego[6][k] = 0;
                         
                     }
                 }
                 
                 if (subir == 1)
                 {
                      for(k =1 ; k<10 ; k++)
                       
                     {
                         
                         
                          tablerodeljuego[1][k] = 0; // la segunda vez que pregunte se le acaban los chances y sube las filas 7 8 y 9 y las remplaza por 1 2 y 3.  tambien las filas 7 8 y 9 se llenan de 0s
                          tablerodeljuego[1][k] = tablerodeljuego[1][k] + tablerodeljuego[7][k];
                          tablerodeljuego[7][k] = 0;
                          
                          tablerodeljuego[2][k] = 0;
                          tablerodeljuego[2][k] = tablerodeljuego[2][k] + tablerodeljuego[8][k];
                          tablerodeljuego[8][k] = 0;
                         
                          
                          tablerodeljuego[3][k] = 0;
                          tablerodeljuego[3][k] = tablerodeljuego[3][k] + tablerodeljuego[9][k];
                          tablerodeljuego[9][k] = 0;
                         
                     }
                 }
                 subir = subir - 1;
                 break;
             }
                
             for(i=0; i<11; i++) //checkea si aun quedan matches adyacentes en el tablero
             {
             
                 for(j=0; j<11; j++)
                 {
                    
                     if((i>0 && j>0) && (i<10 && j<10))
                     {
                         if(((tablerodeljuego[i][j] != tablerodeljuego[i][j-1]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i][j-1] == 0)) &&//primer check que determina si existen pares posibles que sean del mismo numeros
                         ((tablerodeljuego[i][j] != tablerodeljuego[i][j+1]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i][j+1] == 0)) &&// en las casillas adyacentes lo que se hace casilla por casilla
                         ((tablerodeljuego[i][j] != tablerodeljuego[i+1][j]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i+1][j] == 0)) &&
                         ((tablerodeljuego[i][j] != tablerodeljuego[i-1][j]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i-1][j] == 0)) &&
                         ((tablerodeljuego[i][j] != tablerodeljuego[i+1][j+1]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i+1][j+1] == 0)) &&
                         ((tablerodeljuego[i][j] != tablerodeljuego[i-1][j-1]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i-1][j-1] == 0)) &&
                         ((tablerodeljuego[i][j] != tablerodeljuego[i+1][j-1]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i+1][j-1] == 0)) &&
                         ((tablerodeljuego[i][j] != tablerodeljuego[i-1][j+1]) || (tablerodeljuego[i][j] == 0 && tablerodeljuego[i-1][j+1] == 0)))
                         {
                             finisher=finisher+1; //si finisher ==81 entonces todas las casillas no tienen adyacentes del mismo numero
                             
                             
                                
                         }
                    }
                }
             }
             
             for(i=0; i<11; i++) 
             {
             
                 for(j=0; j<11; j++)
                    {
                     
                     
                     
                     if((i>0 && j>0) && (i<10 && j<10))
                     {
                         if(((tablerodeljuego[i][j] + tablerodeljuego[i][j-1]) != 10) && //segundo check que determina si existen pares posibles que sean iguales a 10 en la matriz
                         ((tablerodeljuego[i][j] + tablerodeljuego[i][j+1]) != 10) && // analiza casilla por casilla 
                         ((tablerodeljuego[i][j] + tablerodeljuego[i+1][j]) != 10) &&
                         ((tablerodeljuego[i][j] + tablerodeljuego[i-1][j]) != 10) &&
                         ((tablerodeljuego[i][j] + tablerodeljuego[i+1][j+1]) != 10) &&
                         ((tablerodeljuego[i][j] + tablerodeljuego[i-1][j-1]) != 10) &&
                         ((tablerodeljuego[i][j] + tablerodeljuego[i+1][j-1]) != 10) &&
                         ((tablerodeljuego[i][j] + tablerodeljuego[i-1][j+1]) != 10))
                         {
                             finisher=finisher+1; // si finisher = 81 entonces todas las casillas no tienen pares adyacentes que hagan igual a 10 
                             
                             
                             
                         }
                     }
                 }
             }
              
             
             printf("\nla cantidad de puntos es %d \n", counter); 
               
             if(finisher > 161)
             {
                  break;
             }                                
                
             cordx=0;
             cordy=0;
             cordx2=0;
             cordy2=0;
             
              
             
             while (match != 1) //cuando un match es encontrado regresa aqui para otro turno
             {
             
                 printf("\t*****Match10!!!*****\n"); //imprime el primer tablero
                 printf("        0  1  2  3  4  5  6  7  8\n");
                 
                 printTablero(tablerodeljuego);   
                  
                 printf("\n");
                 
                 repeat=1; //variable para evitar que el jugador elija una casilla vacia
                 while (repeat == 1)
                 {
                     printf("\n"); //pregunta al usuario su primera casilla
                     printf("eliga su primera casilla\n");
                     printf("cuantas lineas abajo \n");
                     scanf("%d",&cordy);
                     printf("cuantas lineas a la derecha \n");
                     scanf("%d",&cordx);
                      
                     cordy = cordy + 1;
                     cordx = cordx + 1;
                     
                     if (tablerodeljuego[cordy][cordx]==0) //checkea si se elijio una casilla vacia
                     {
                         printf("esta casilla es incorrecta \n");
                     }
                     else 
                     {
                          repeat = 0;
                     }
                       
                 }
                 
                 repeat =  1; //variable para evitar que el jugador elija una casilla vacia
                 
                 printf("\t*****Match10!!!*****\n"); //imprime el primer tablero
                 printf("         0  1  2  3  4  5  6  7  8\n");
                 
                 printTablero(tablerodeljuego);   
                 
                 printf("\n");
                 
                  
                 while (repeat == 1)
                 {
                     printf("\n");  //pregunta la segunda casilla a elegir 
                     printf("eliga su segunda casilla\n");
                     printf("cuantas lineas abajo \n");
                     scanf("%d",&cordy2);
                     printf("cuantas lineas a la derecha \n");
                     scanf("%d",&cordx2);
                     cordx2 = cordx2 + 1;
                     cordy2 = cordy2 + 1;
                     if (tablerodeljuego[cordy2][cordx2]==0) //checkea si se elijio una casilla vacia
                     {
                         printf("esta casilla es incorrecta \n");
                     }
                     else 
                     {
                         repeat = 0;
                     }   
                 
                 }
                   
                  
                 while (cordx2 == cordx && cordy2 == cordy) //loop solo para evitar que causen un error por elejir la misma casilla dos veces
                 {
                    
                 printf("no puede elegir la misma casilla dos veces \n");
                 printf("\n");
                 printf("eliga su segunda casilla\n");
                 printf("cuantas lineas abajo \n");
                 scanf("%d",&cordy2);
                 printf("cuantas lineas a la derecha \n");
                 scanf("%d",&cordx2);
                 cordx2 = cordx2 +1;
                 cordy2 = cordy2 +1;
                 }
                  
                    
                    
                 if ((tablerodeljuego[cordy][cordx] == tablerodeljuego[cordy2][cordx2]) || (tablerodeljuego[cordy][cordx] + tablerodeljuego[cordy2][cordx2] ==10))  //largo check que busca saber si la segunda casilla es adyacente a la primera  y que el valor de la casilla 1 es = a casilla 2 
                 {
                        
                     if(cordx2 == cordx-1 || 
                     cordx2 ==  cordx+1 ||
                     cordy2 == cordy+1 || 
                     cordy2 ==  cordy-1||
                     (cordy2 == cordy+1 && cordx2 == cordx+1) ||
                     (cordy2  ==  cordy-1 && cordx2 == cordx-1) ||
                     (cordy2  == cordy+1  && cordx2 == cordx-1)|| 
                     (cordy2  ==  cordy-1  && cordx2 == cordx+1))
                     {       
                         printf("\nencontro un match \n");
                         match = 1; //un match encontrado entonces el loop termina aqui inmediatamente
                         counter = counter + 1; //cantidad de pares encontrados + 1
                         tablerodeljuego[cordy][cordx]=0;
                         tablerodeljuego[cordy2][cordx2]=0;
                        
                     }
                 }
                    
                 if(match == 0) //si no fue un match no cambia nada en el tablero
                 {
                     printf("\nNo Match \n"); 
                 }
                    
                   
             
             }
         
         }
     printf("\ntodas las parejas fueron encontradas");
     printf("\nsu puntaje total es %d \n", counter);
     printf("su puntaje de su juego anterior es igual a %d \n",PRESCORE);
     printf("Retry? 1 o 0\n");
     scanf("%d",&retry);
     PRESCORE = counter;
     
      
     }
     printf("Gracias por jugar");
     return 0;
}

    void printTablero(int tablerodeljuego[11][11])
    {
        for(int i=0; i<4; i++)
         {
             if(i<10)
             {
                if(i !=0)
                 {
                     printf("%d   ", i-1);
                 }
             } 
             for(int j=0; j<11; j++)
             {
                             
                 if(tablerodeljuego[i][j]==0)
                 {
                     printf("   ");
                 }
                             
                 if(tablerodeljuego[i][j]!=0)
                 {
                     printf("|%d|", tablerodeljuego[i][j]);
                 }
             }    
                printf("\n");
         }           
    }
