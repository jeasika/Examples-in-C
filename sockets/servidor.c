#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1025

int main () {    
	int fd;    
	// 1. Crear socket TCP    
	fd = socket(AF_INET, SOCK_STREAM, 0);    
	// 2. Asignar puerto a socket    
	struct sockaddr_in addr;    
	addr.sin_family = AF_INET;    
	addr.sin_port = htons(PORT);    
	addr.sin_addr.s_addr = INADDR_ANY;    
	// 3. Poner al socket en modo escucha (bind)    
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1){        
	perror("Unable to bind\n");        
	close(fd);        
	exit(1);    
	}    
	if (listen(fd, 1) == -1) {        
	perror("Unable to listen\n");    
	}    
	// 4. Repetir    
	int connfd, connfd2;    
	struct sockaddr_in cli_addr;    
	char *buffer = (char *)malloc(1*sizeof(char));
	char *hola = (char *)malloc(6*sizeof(char));
	
	//while(1) {         
		printf("Entro\n");        
		// 4.1 Aceptar nueva conexion        
		socklen_t cli_addr_len = sizeof(cli_addr);        
		/*connfd = accept(fd, (struct sockaddr *)&cli_addr, &cli_addr_len);*/        
		connfd = accept(fd, NULL, NULL);
		printf("Una conexion inicializada\n");
		connfd2 = aacept(fd, NULL, NULL);
		printf("Dos conexiones inicializadas\n");    
		if (connfd == -1 || connfd2 == -1 ) {            
			perror("Unable to connect\n");       
		}        
		printf("Acepto\n");        
		// 4.2 Comunicacion
		
		read(connf, hola, 6);
		printf("%s\n", hola);
		read(conff2, hola, 6);
		printf("%s\n", hola);
		        
		read(connfd, buffer, 1);
		printf("%s Recibido.\n", buffer);
		char *str = "OK";
		write(connf, str, strlen(str));
		        
		if(tolower(*buffer) - 'a' >=25 ) {            
			*buffer = 'a';       
		}        
		else
			*buffer += 1;
			       
		write(connfd2, buffer, strlen(buffer));
		printf("%s Enviado.\n", buffer);
		read(connf2, str, 2);
		printf("%s Recibido.\n", buffer);
		    
	//}    
	free(buffer);    
	// 4.3 Cerrar conexion    
	close(connfd);
	close(fd);
	close(connfd2); 
	printf("Fin\n");    
	return 0;
}
