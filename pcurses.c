#include <curses.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *lista[] = {"El dato es", "Se genero", "El aleatorio es" };
pthread_mutex_t lock; /* cerrojo */
void* hilo1();
void* hilo2();
int dato,c=0;

int leeChar() {
  int chars[5];
  int ch,i=0;
  nodelay(stdscr, TRUE);
  while((ch = getch()) == ERR); /* Espera activa */
  ungetch(ch);
  while((ch = getch()) != ERR) {
    chars[i++]=ch;
  }
  /* convierte a numero con todo lo leido */
  int res=0;
  for(int j=0;j<i;j++) {
    res <<=8;
    res |= chars[j];
  }
  return res;
}

int main()
{
   pthread_t tid1,tid2; /* the thread identifier */
   pthread_attr_t attr; /* set of attributes for the thread */
   int i = 0;
   int c;

   // Inicialización de curses
   initscr();
   raw();
   noecho(); /* No muestres el caracter leido */
   cbreak(); /* Haz que los caracteres se le pasen al usuario */

   /* get the default attributes */
   pthread_attr_init(&attr);

   /* inicia cerrojo */
   pthread_mutex_init(&lock, NULL);

   /* create the thread 1*/
   pthread_create(&tid1, &attr, hilo1, NULL);

   /* create the thread 2*/
   pthread_create(&tid2, &attr, hilo2, NULL);

   /* espera a los hilos */
   pthread_join(tid2, NULL);
   pthread_join(tid1, NULL);

   getch();
   endwin();
   return 0;
}

void* hilo1() {

	for (int i = 0; i < 10; i++) {
		dato = rand() % 51;
		sleep(1);
	}

}

void* hilo2() {

	char str[70];

	for (int i = 0; i < 10; i++) {

		int t = rand() % 3;
		// Imprime el dato que se obtuvo
		snprintf(str, 70, "%s %d", lista[t], dato);
		mvprintw(10, 5, str);
		clrtoeol();
		refresh();

		sleep(1);
	}

	mvprintw(12, 5, "¡Ya termine!");

}


