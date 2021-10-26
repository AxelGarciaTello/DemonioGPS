#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include "estructura.h"

extern LOCALIZACION loc;

void atiendeCliente(int cliente_sockfd){
   syslog(LOG_INFO, "Se aceptó un cliente, atendiendolo \n");
   if( write (cliente_sockfd, &loc, sizeof(LOCALIZACION)) < 0 ){
     syslog(LOG_INFO, "Ocurrio un problema en el envio de un mensaje al cliente");
     exit(1);
   }

   close(cliente_sockfd);
   exit(0);
}
