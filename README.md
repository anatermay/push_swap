# ![Push_Swap](https://github.com/anatermay/anatermay/raw/main/png/anatermay_header.png)

# Push_Swap
¡Bienvenidos a **Push_Swap**! Este proyecto está enfocado en aprender y dominar algoritmos eficientes de ordenación a través del lenguaje de programación C. 

> **Nota**: Este README está orientado a aquellos sin conocimientos previos en programación. Aquí aprenderás desde lo básico hasta el funcionamiento detallado del proyecto, incluyendo teoría de programación, algoritmos de costes y cómo utilizar `Push_Swap` en tus propios entornos.

<details>
	<summary style="background: #000000; color: #FFFFFF; padding: 9px; margin: 9px; font-size: 18px; width: 90%;">Tabla de Contenidos</summary>
	<ol style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;">
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#conceptos-básicos"><b>Conceptos Básicos</b></a></li>
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#descripción-del-proyecto-push_swap"><b>Descripción del Proyecto <i>Push_Swap</i></b></a></li>
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#estructura-del-proyecto"><b>Estructura del Proyecto</b></a></li>
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#makefile"><b>Makefile</b></a></li>
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#compilación-e-instalación"><b>Compilación e Instalación</b></a></li>
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#ejemplos-y-funcionamiento-del-programa"><b>Ejemplos y Funcionamiento del Programa</b></a></li>
		<li style="background: #C0C0C0; color: #000000; padding: 9px; margin: 9px; font-size: 12px; width: 90%;><a href="#limitaciones-y-posibles-mejoras"><b>Limitaciones y Posibles Mejoras</b></a></li>
	</ol>
</details>

<img src="https://cdn.leonardo.ai/users/af8ee1cf-2a87-473e-9ef3-d0caefff30d5/generations/423a773d-300d-4675-a8eb-1842e2937902/Leonardo_Kino_XL_A_digital_illustration_bitmoji_style_for_a_Gi_1.jpg" alt="push_swap header img">

---

## Conceptos Básicos
* La **programación** es el proceso de escribir instrucciones (código) que una computadora puede entender para ejecutar tareas específicas. En este proyecto, emplearemos el lenguaje **C**, uno de los lenguajes de programación más antiguos y populares, conocido por su eficiencia y control sobre el hardware.

* El **lenguaje C** es un lenguaje de bajo nivel que ofrece control sobre la memoria y eficiencia en el procesamiento. Es la base de muchos sistemas operativos y aplicaciones de alto rendimiento. En este proyecto, usamos C para manejar listas enlazadas y aplicar un algoritmo de ordenación eficiente usando estructuras de datos y operaciones matemáticas.

---

## Descripción del Proyecto Push_Swap
**Push_Swap** es un proyecto desarrollado en **42 Málaga Fundación Telefónica**. Su objetivo es ordenar una lista de números enteros utilizando una cantidad mínima de operaciones específicas.

> El proyecto se basa en implementar un algoritmo de ordenación que emplee dos pilas (stacks) y una serie de operaciones básicas (`pa`, `pb`, `ra`, `rb`, etc.) para organizar los números de menor a mayor en una de las pilas.

**Funcionalidades principales del programa:**
- **Ordenación de números** en una pila.
- Uso de dos pilas, `stack_a` y `stack_b`, donde `stack_a` almacena los números inicialmente desordenados y al final debe contenerlos en orden.
- Empleo de algoritmos de costes y optimización de operaciones para minimizar el número de movimientos.
---

## Estructura del Proyecto
El proyecto contiene varios archivos C y un `Makefile` que compila el código de forma eficiente.
```
	argv_checker.c \
	bso.c \
	costs_algorithm.c \
	costs_algorithm_1.c \
	costs_algorithm_2.c \
	if_nbr_args.c \
	libft.c \
	max_handling.c \
	memory_handling.c \
	min_handling.c \
	stack_handling.c \
	push_swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	swap.c \
```
># [START CODE](https://github.com/anatermay/push_swap/blob/main/push_swap.c)

## Makefile
El **Makefile** es un archivo que automatiza la compilación del proyecto. 

Este archivo contiene las instrucciones para:
- Compilar cada archivo `.c` en un archivo de objeto `.o`
- Enlazar todos los archivos de objeto en un ejecutable llamado `push_swap`

### Uso del Makefile
Para compilar el proyecto desde el terminal, simplemente usa el siguiente comando:
```bash
make
```
Este comando compilará todo el proyecto y generará el ejecutable ```push_swap```.
Compilación e Instalación
Clona el repositorio:
```
git clone https://github.com/anatermay/push_swap.git
```
Entra en el directorio del proyecto:
```
cd push_swap
```
Compila el proyecto usando make:
```
make
```
Al finalizar, obtendrás el ejecutable push_swap listo para ejecutarse.
## Ejemplos y Funcionamiento del Programa
El programa toma una lista de números enteros como argumentos y muestra los pasos para ordenarlos. Aquí un ejemplo de ejecución:
```
./push_swap 3 2 5 1 4
```
Resultado:
```
pb
pb
sa
ra
pb
pb
```
Cada línea indica una operación en las pilas para acercarse al objetivo de ordenación.
## Algoritmo y Optimización
### Algoritmo de Costes
El algoritmo implementado calcula los costes para cada operación de mover elementos entre stack_a y stack_b. Se elige la operación de menor coste en cada paso para minimizar la cantidad de movimientos.
#### Estrategia de Ordenación
1. Push-Swap básico: Se mueve el número más pequeño de una pila a la otra y se realiza una rotación si es necesario.
2. Optimización por coste: A través de la implementación de costes, el programa elige las operaciones más económicas para reducir la cantidad total de movimientos.
### Técnicas de Optimización
1. Control de costes: Cada operación tiene un coste calculado en base al número de movimientos necesarios. El algoritmo selecciona las operaciones con menor coste.
2. Optimización de espacio: Liberación de memoria en pilas ya procesadas para mejorar el uso de memoria.
## Limitaciones y Posibles Mejoras
### Limitaciones
* Rendimiento: Aunque está optimizado, el programa puede ser más lento con listas muy grandes.
* Gestión de memoria: Puede mejorar en términos de manejo de memoria, especialmente para listas muy extensas.
## Mejoras Futuras
* Optimización adicional del algoritmo de coste: Implementar técnicas avanzadas para reducir aún más los movimientos.
* Manejo dinámico de memoria: Mejorar el manejo de memoria para reducir el uso en listas grandes.
* Interfaz gráfica: Añadir una interfaz visual para visualizar el proceso de ordenación.
<hr>
Push_Swap es un excelente proyecto para aprender algoritmos de ordenación y optimización en C. Mediante el uso de estructuras de datos, operaciones matemáticas y control de memoria, podrás mejorar tus habilidades de programación en C y resolver problemas de ordenación de manera eficiente.

¡Gracias por leer!


<p align="right">
	<b>@anatermay | <i>login: aternero</i></b>
	<a href="https://www.linkedin.com/in/ana-ternero-mayorga/" target="_blank"><img alt="LinkedIn" width="22px" src="https://cdn.jsdelivr.net/npm/simple-icons@v3/icons/linkedin.svg" /></a>
	<a href="https://www.instagram.com/anatermay.git/" target="_blank"><img alt="Instagram" width="22px" src="https://cdn.jsdelivr.net/npm/simple-icons@v3/icons/instagram.svg" /></a>
</p>
