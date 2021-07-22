#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int a;
	char b;
	double c;
} arg;

int suma(){
	//procesamiento
	return 4;
}

//FUncion que sea apuntador o referencíe a un apuntador '&'
void *funcion1(void *arg2){
	/* 
		'arg *' tipo casting
		*(arg *) apuntador al casting que está haciendo
	*/
	arg param = *(arg *)arg2;
	printf("Recibimos %d, %c, %.2lf\n", param.a, param.b, param.c);
	sleep(5);
	printf("Ya desperte\n");
}

int main(int argc, char *argv[]){
	printf("Estoy en el main\n");
	
	pthread_t tid, tid2;
	int res;
	arg args;
	args.a = 10;
	args.b = 'c';
	args.c = 1.3;
	arg args2;
	args2.a = 50;
	args2.b = 'a';
	args2.c = 9.8;
	int a=5;
	
	//COmportamiento del thread
	res = pthread_create(&tid, NULL, funcion1, (void *)&args);
	if (res != 0){
		perror("Fallo creacion del thread\n");
	}
	
	res = pthread_create(&tid2, NULL, funcion1, (void *)&args2);
	if (res != 0){
		perror("Fallo creacion del thread 2\n");
	}
	
	res = pthread_join(tid, NULL);
	if (res != 0){
		perror("Fallo join del thread\n");
	}
	
	//SImpre indicar cuál thread está esperando
	res = pthread_join(tid2, NULL);
	if (res != 0){
		perror("Fallo join del thread 2\n");
	}
	
	printf("Listooo\n");
	return 0;
}
