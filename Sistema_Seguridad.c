#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char USUARIOS[4][20] = {
	"Admin",
	"Usuario1",
	"Usuario2",
	"Usuario3"
};

char CONTRASENAS[4][20] = {
    "admin1234",
    "user098",
    "user765",
    "user432"
};

 int BLOQUEADOS[4] = {0, 0, 0, 0};
 
 int IntentosFallidos[4] = {0, 0, 0, 0};
 int IntentosConcedidos[4] = {0, 0, 0, 0};
 
 void MenuAdministrador();
 void VerEstadoDeUsuarios();
 void DesbloquearUsuarios();
 void CambiarContrasenas();
 void HistorialDeAccesos();
 
 void InicioDeSesion();
 void InicioAdministrador();
 
 void MenuDeUsuarios();
 void VerMiEstado();
 void CambiarMiContrasena();
 void MiHistorialDeAccesos();
 
 void DesbloqueoDeAdministrador();
 
 void GuardarDatos();
 void CargarDatos();
 
 #define CLAVE_DE_RECUPERACION "K9#vR2_Lp7!Xm4$Qz8"
 
 int UsuarioActual;
 int opcion;
 
 FILE *archivo;
 
int main() {
	
	CargarDatos();
	
	do {
    printf("============SISTEMA DE PROTECCION============\n");
    printf("0. Admin\n");
    printf("1. Usuario1\n");
    printf("2. Usuario2\n");
    printf("3. Usuario3\n");
    printf("4. Cerrar el sistema\n");
    printf("Elija el usuario al que desea acceder: ");
    scanf("%d", &opcion);
    
    switch (opcion) {
    	case 0:
    		InicioAdministrador();
    		break;
    	case 1:
    		 InicioDeSesion();
    		 break;
    	case 2:
    	     InicioDeSesion();
    	     break;
    	case 3:
    		 InicioDeSesion();
    		 break;
    	case 4:
    		printf("\n======================================\n\n");
    		printf("      Se ha cerrado el sistema\n");
    		printf("\n======================================\n\n");
    		break;
    	default:
    		printf("Opcion no valida, por favor intente de nuevo\n");
    		break;
	}
} while (opcion != 4);

    return 0;
}

void GuardarDatos() {
	int i;
	archivo = fopen("contrasenas.txt", "w");
	 if (archivo != NULL) {
	for (i = 0; i < 4; i++) {
		fprintf(archivo, "%s\n", CONTRASENAS[i]);
	}
	fclose(archivo);
}
    archivo = fopen("bloqueados.txt", "w");
	if (archivo != NULL) {
	for (i = 0; i < 4; i++) {
		fprintf(archivo, "%d\n", BLOQUEADOS[i]);
	}
	fclose(archivo);
}
}

void CargarDatos() {
	int i;
	archivo = fopen("contrasenas.txt", "r");
	 if (archivo != NULL) {
	for (i = 0; i < 4; i++) {
		fscanf(archivo, "%s\n", CONTRASENAS[i]);
	}
	fclose(archivo);
}
	archivo = fopen("bloqueados.txt", "r");
	if (archivo != NULL) {
	for (i = 0; i < 4; i++) {
		fscanf(archivo, "%d\n", &BLOQUEADOS[i]);
	}
	fclose(archivo);
}
}


void InicioDeSesion() {
	char password[25];
	int intentos;
		system("cls");
    		if (BLOQUEADOS[opcion] == 1) {
    			printf("==========%s==========\n", USUARIOS[opcion]);
    	        printf("Este usuario ha sido bloqueado\n\n");
    	} else {
    		intentos = 3;
    		do {
    		printf("=============ACCESO A %s================\n", USUARIOS[opcion]);
    		printf("Intentos restantes: %d\n", intentos);
    		printf("Usuario: %s\n", USUARIOS[opcion]);
    		printf("Ingrese la contrasena: ");
    		scanf("%24s", password);
    		if (strcmp(CONTRASENAS[opcion], password) == 0) {
    			UsuarioActual = opcion;
                system("cls");
                IntentosConcedidos[opcion]++;
                MenuDeUsuarios();
                break;
             } else {
                intentos--;
                IntentosFallidos[opcion]++;
                printf("Acceso denegado\n\n");
            } 
    	} while (intentos >= 1);
    	    if (intentos == 0) {
    	    	BLOQUEADOS[opcion] = 1;
    	    	GuardarDatos();
    	    	system("cls");
    	        printf("Limite de intentos alcanzado\n");
    	        printf("Este usuario ha sido bloqueado\n\n");
    	}
    	}
}

void InicioAdministrador() {
	char password[25];
	int intentos;
	system("cls");
    		if (BLOQUEADOS[0] == 1) {
    			printf("==========ADMINISTRADOR==========\n");
    	        printf("Este usuario ha sido bloqueado\n\n");
    	        DesbloqueoDeAdministrador();
    	    } else {
    		intentos = 3;
    		do {
    		printf("=============ACCESO A ADMINISTRADOR============\n");
    		printf("Intentos restantes: %d\n", intentos);
    		printf("Usuario: Admin\n");
    		printf("Ingrese la contrasena: ");
    		scanf("%24s", password);
    		if (strcmp(CONTRASENAS[0], password) == 0) {
    			UsuarioActual = 0;
    			system("cls");
                IntentosConcedidos[0]++;
                MenuAdministrador();
                break;
             } else {
             	intentos--;
             	IntentosFallidos[0]++;
                printf("Acceso denegado\n\n");
           	}
		} while (intentos >= 1);
		   if (intentos == 0) {
		   	    BLOQUEADOS[0] = 1;
		   	    GuardarDatos();
		   	    system("cls");
    	        printf("Limite de intentos alcanzado\n");
    	        printf("Este usuario ha sido bloqueado\n\n");
    	}
			}
}


void MenuAdministrador() {
	int opciones;
	
	do {
	printf("==========MENU DE ADMINISTRADOR==========\n");
	printf("1. Ver estado de los usuarios\n");
	printf("2. Desbloquear usuarios\n");
	printf("3. Cambiar contrasena de usuarios\n");
	printf("4. Historial de accesos\n");
	printf("5. Cerrar sesion\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opciones);
	
	switch (opciones) {
		case 1:
			system("cls");
			VerEstadoDeUsuarios();
			break;
		case 2:
			system("cls");
			DesbloquearUsuarios();
			break;
		case 3:
			system("cls");
			CambiarContrasenas();
			break;
		case 4:
			system("cls");
			HistorialDeAccesos();
			break;
		case 5:
			system("cls");
			break;
		default:
			printf("Opcion no valida\n");
		    break;
	}
	} while (opciones != 5);
}

void VerEstadoDeUsuarios() {
	int i;
	printf("===========ESTADO DE USUARIOS=============\n");
	for (i = 0; i < 4; i++) {
		printf("\nUsuario: %s\n", USUARIOS[i]); 
		if (BLOQUEADOS[i] == 1) {
			printf("Estado: Bloqueado\n");
		} else {
			printf("Estado: Activo\n");
		}
	}
		printf("\nPresione Enter para continuar...");
        getchar();
        getchar();
        system("cls");
}


void DesbloquearUsuarios() {
	int usuarios;
	char NuevaContrasena[25];
	char ConfirmaContrasena[25];
	printf("===========DESBLOQUEAR USUARIOS============\n");
	printf("1. Usuario1\n");
	printf("2. Usuario2\n");
	printf("3. Usuario3\n");
	printf("Seleccione el usuario a desbloquear: ");
	scanf("%d", &usuarios);
	system("cls");
	
	if (usuarios <= 3 && usuarios >= 1) {
		printf("===========DESBLOQUEAR USUARIOS============\n");

        if (BLOQUEADOS[usuarios] == 1) {
        printf("Para desbloquear debe cambiar la contrasena\n");
        printf("Ingrese la nueva contrasena: ");
        scanf("%24s", NuevaContrasena);

        if (strlen(NuevaContrasena) < 6 || strlen(NuevaContrasena) > 19) {
        printf("La contrasena debe tener entre 6 y 19 caracteres\n\n");
    } else {
        printf("Confirme la contrasena ingresada: ");
        scanf("%24s", ConfirmaContrasena);

        if (strcmp(NuevaContrasena, ConfirmaContrasena) == 0) {
            BLOQUEADOS[usuarios] = 0;
            strcpy(CONTRASENAS[usuarios], ConfirmaContrasena);
            GuardarDatos();
            system("cls");
            printf("Contrasena cambiada exitosamente\n");
            printf("El usuario ha sido desbloqueado\n\n");
        } else {
            printf("Las contrasenas ingresadas no coinciden\n\n");
        }
    }
} else {
    printf("Este usuario no esta bloqueado\n\n");
}
	} else {
		printf("opcion invalida\n\n");
	}
}
	
void CambiarContrasenas() {
	int usuario;
	char NuevaContrasena[25];
	char ConfirmarContrasena[25];
	
	printf("=====CAMBIAR CONTRASENA=====\n");
    printf("0. Admin\n");
    printf("1. Usuario1\n");
    printf("2. Usuario2\n");
    printf("3. Usuario3\n");
    printf("Seleccione un usuario: ");
    scanf("%d", &usuario);
    
    if (usuario <= 3 && usuario >= 0) {
    	printf("Ingrese la nueva contrasena: ");
    	scanf("%24s", NuevaContrasena);
    	printf("Confirme la contrasena: ");
    	scanf("%24s", ConfirmarContrasena);
        
         if (strcmp(NuevaContrasena, ConfirmarContrasena) != 0) {
        	printf("Las contrasenas no coinciden\n");
        	return;
		}
        
        if (usuario == 0) {
		if (strlen(NuevaContrasena) < 8 || strlen(NuevaContrasena) > 19){
			printf("La contrasena del administrador debe tener entre 8 y 19 caracteres\n");
			return;
		}
		strcpy(CONTRASENAS[usuario], NuevaContrasena);
		GuardarDatos();
		system("cls");
		printf("Contrasena cambiada exitosamente\n");
		return;
		
	} else {
		if (strlen(NuevaContrasena) < 6 || strlen(NuevaContrasena) > 19){
			printf("La contrasena de los usuarios debe tener entre 6 y 19 caracteres\n");
			return;
		}
		strcpy(CONTRASENAS[usuario], NuevaContrasena);
		GuardarDatos();
		system("cls");
		printf("Contrasena cambiada exitosamente\n");
		return;
	}
} else {
	system("cls");
	printf("Opcion no valida\n");
	return;
}
}
	

void HistorialDeAccesos() {
	int i;
	system("cls");
	printf("===========HISTORIAL DE ACCESOS ===========\n");
	for (i = 0; i < 4; i++) {
		printf("\nUsuario: %s\n", USUARIOS[i]);
		printf("Intentos fallidos: %d\n", IntentosFallidos[i]);
	    printf("Intentos concedidos: %d\n", IntentosConcedidos[i]);
		}
		printf("\nPresione Enter para continuar...");
        getchar();
        getchar();
        system("cls");
	}

void DesbloqueoDeAdministrador() {
	char Clave[25];
	char NuevaContrasena[25];
	char ConfirmacionContrasena[25];
	
	printf("=========DESBLOQUEO DE ADMINISTRADOR=========\n");
	printf("Para desbloquear al administrador debe ingresar la clave de recuperacion\n");
	printf("Clave de Recuperacion: ");
	scanf("%24s", Clave);
	
	if (strcmp(Clave, CLAVE_DE_RECUPERACION) != 0) {
		printf("Clave incorrecta\n");
		return;
	} else {
		printf("Clave correcta. Ahora debe cambiar la contrasena\n");
		printf("Ingrese la nueva contrasena: ");
		scanf("%24s", NuevaContrasena);
		printf("Confirme la contrasena: ");
		scanf("%24s", ConfirmacionContrasena);
	}
	 if (strcmp(NuevaContrasena, ConfirmacionContrasena) != 0) {
        printf("Las contrasenas no coinciden. Operacion cancelada\n\n");
        return;
    }
	if (strlen(NuevaContrasena) < 8 || strlen(NuevaContrasena) > 19) {
		printf("La contrasena del administrador debe tener entre 8 y 19 caracteres\n");
		return;
	} 
        strcpy(CONTRASENAS[0], NuevaContrasena);
		BLOQUEADOS[0] = 0;
		GuardarDatos();
		system("cls");
		printf("Usuario administrador desbloqueado exitosamente\n");
	}

void MenuDeUsuarios() {
	int seleccion;
	
	do {
	printf("===========MENU DE USUARIOS============\n");
	printf("1. Ver mi estado\n");
	printf("2. Cambiar mi contrasena\n");
	printf("3. Ver mi historial de accesos\n");
	printf("4. Cerrar Sesion\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &seleccion);
	
	switch(seleccion) {
		case 1:
			VerMiEstado();
			break;
		case 2:
			CambiarMiContrasena();
			break;
		case 3:
			MiHistorialDeAccesos();
			break;
		case 4:
			system("cls");
			break;
		default:
			printf("\nOpcion no valida\n");
			break;
	}
} while (seleccion != 4);
}

void VerMiEstado() {
	system("cls");
	printf("===========VER MI ESTADO===========\n");
	printf("Usuario: %s\n", USUARIOS[UsuarioActual]);
		if (BLOQUEADOS[UsuarioActual] == 1) {
			printf("Estado: Bloqueado\n\n");
		} else {
			printf("Estado: Activo\n\n");
		}
		printf("\nPresione Enter para continuar...");
        getchar();
        getchar();
        system("cls");
}


void CambiarMiContrasena() {
	char NuevaContrasena[25];
	char ContrasenaActual[25];
	char ConfirmarContrasena[25];
	system("cls");
	printf("=========CAMBIO DE CONTRASENA=========\n");
	printf("Ingrese la contrasena actual: ");
	scanf("%24s", ContrasenaActual);
	if (strcmp(CONTRASENAS[UsuarioActual], ContrasenaActual) != 0) {
		printf("Contrasena Incorrecta. Operacion Cancelada\n\n");
		return;
	}
	
    	printf("Ingrese la nueva contrasena: ");
    	scanf("%24s", NuevaContrasena);
    	printf("Ingrese la contrasena nuevamente: ");
    	scanf("%24s", ConfirmarContrasena);
    	if (strcmp(NuevaContrasena, ConfirmarContrasena) != 0) {
    		printf("Las contrasenas no coinciden. Operacion Cancelada\n\n");
    		return;
    	}
			if (strlen(NuevaContrasena) < 6 || strlen(NuevaContrasena) > 19) {
				printf("La contrasena de los usuarios de tener entre 6 y 19 caracteres\n\n");
				return;
			} else {
		        strcpy (CONTRASENAS[UsuarioActual], NuevaContrasena);
		        GuardarDatos();
		         printf("Contrasena actualizada correctamente.\n\n");
		         system("cls");
		   }     
		}

void MiHistorialDeAccesos() {
	system("cls");
	printf("===========MI HISTORIAL===========\n");
	printf("Usuario: %s\n", USUARIOS[UsuarioActual]);
	printf("Intentos fallidos de sesion: %d\n", IntentosFallidos[UsuarioActual]);
	printf("Intentos concedidos de sesion: %d\n\n", IntentosConcedidos[UsuarioActual]);
	printf("\nPresione Enter para continuar...");
    getchar();
    getchar();
    system("cls");
}
