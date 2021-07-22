/*
	NO recibe parámetros
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *hola(){ //tiene que ser tipo void
	printf("Hola desde thread\n");
	//exit(1); //Es a nivel proceso. Termina todo el proceso.
	//pthread_exit(1) termina a nivel thread
	sleep(5); //para que espere el main
}

int main(int argc, char *argv[]){
	printf("Estoy en funcion main\n");
	int res;
	
	pthread_t tid;
	
	res = pthread_create(&tid, NULL, hola, NULL);
	if (res != 0){ //validación
		perror("Error al crear el thread\n");
		printf("%d", res); //imprime el numero del error 
	}
	
	//sleep(1); //da paso a que termine el otro thread
	
	res = pthread_join(tid, NULL);
	if (res != 0){
		perror("Error al hacer un join\n");
	}
	
	//pthreate_create //se pierde la paralizacion, "Cuellos de botella"
	printf("Todos los threads han terminado\n");
	
	return 0;
}
