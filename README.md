# Proyecto-de-seguridad-en-C
Proyecto inyegrador realizado en C para la asignatura de Desarrollo lógico y algoritmos

# Proyecto Integrador: Sistema de Control de Acceso y Seguridad en C

Proyecto académico desarrollado en lenguaje C enfocado en la implementación de lógica de autenticación, gestión de roles, mitigación básica de ataques de fuerza bruta y persistencia de datos mediante manejo de archivos.

## Objetivos y conceptos aplicados

* **Estructuras de datos estáticas y cadenas:** Manejo de arreglos bidimensionales de caracteres (`char[][]`) y vectores paralelos para relacionar usuarios, credenciales, estados de bloqueo y métricas de acceso.
* **Programación modular:** División de la lógica del sistema en funciones independientes para menús, validación de credenciales, auditoría y persistencia.
* **Control de flujo y validaciones:** Uso de ciclos `do-while`, estructuras `switch-case` y validación de longitud y coincidencia de cadenas con `string.h` (`strcmp`, `strlen`, `strcpy`).
* **Persistencia en archivos (`stdio.h`):** Lectura y escritura secuencial (`fopen`, `fscanf`, `fprintf`) para conservar cambios de contraseñas y bloqueos entre ejecuciones en `contrasenas.txt` y `bloqueados.txt`.
* **Lógica de seguridad básica:**
  * Control de acceso basado en roles (Administrador vs. Usuario estándar).
  * Bloqueo automático de cuentas tras 3 intentos fallidos consecutivos.
  * Políticas de longitud mínima de contraseñas (8 caracteres para administrador, 6 para usuarios).
  * Flujo de recuperación de administrador mediante clave maestra predefinida.

## Compilación y ejecución

### Con GCC (terminal)
```bash
gcc sistema_seguridad.c -o sistema_seguridad

