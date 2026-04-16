# practica_pinza

# Práctica 2 de Sistemas Operativos — Procesamiento de Datos de Sensores en Pinza Robótica

## 1. Descripción
Este repositorio contiene una **práctica de Sistemas Operativos** desarrollada en **Bash y C++**, cuyo objetivo es aplicar y demostrar conceptos fundamentales de la asignatura.

Este proyecto consiste en el desarrollo de un programa capaz  de procesar datos provenientes de **sensores** instalados en una pinza robótica
El sistema analiza:
  La deformacion estructural (galga extensiométrica)
  La fuerza aplicada en el dedo izquierdo.
  La fuerza aplicada en el dedo derecho.
A partir de estos datos, el programa:
  Lee información desde un archivo de texto.
  Organiza los datos en arrays y matrices
  Calcula medias de los sensores 
  Evalua la estabilidad del agarre.
  Genera un archivo de resultados.

---

## 2. Estructura del repositorio

```
practica_pinza/
|
├── main.cpp                    #Código fuente en C++
├── datos_pinza.txt             #Archivo de entrada con datos de sensores
├── resultados_pinza.txt        #Archivo generado con resultados        
├── script.sh                   #Script Bash para ejecución automática
└── README.md                   #Documentación del proyecto
```


---

## 3. Requisitos del sistema
- Sistema operativo: **Linux** (probado en Ubuntu 22.04)
- Compilador: **sh** con soporte **Bash** y **c++** con soporte **g++**
- Terminal Bash
- Git
- 

### Instalación de herramientas básicas
```terminal
sudo apt update
sudo apt install g++
Instalar Git:
sudo apt install git
```

---

## 4. Dependencias externas

### 4.1 No requiere librerías externas. Se utilizan librerías de C++:

<iostream>
<fstream>
<cmath>


## 5. Compilación

### 5.1 Compilación del programa

Desde la raíz del repositorio:

```bash
cd Documentos
cd practica_pinza
g++ main.cpp -o pinza
```

Esto generará un ejecutable llamado: pinza


## 6. Ejecución

### 6.1 Ejecución básica

```bash
./pinza
Ejecutar mediante script Bash:
sh script.sh
```


## 7. Ejemplo mínimo con capture_mqtt.sh

Caso mas simple:
1   0.200   1.50   1.50
Interpretacion:
Fuerzas iguales o menor que 0,15 -> agarre estable


## 8. Salida esperada

Al ejecutar correctamente el programa:

ID: 5 Galga: 0,245 Izq: 1.82 Der: 1.76
Media galga: ...
Media fuerza izquierda: ...
Media fuerza derecha: ...
Estado muestra 5: ESTABLE

Se generará un archivo llamado: resultado_pinza.txt):

RESULTADOS DEL SISTEMA DE PINZA ROBÓTICA

Medias:
Galga = ...
Fuerza izquierda = ...
Fuerza derecha = ...
Clasificacion:
5 ESTABLE

---

## 9. Depuración

Si el programa falla: **error violacion de segmento** se están leyendo más datos que el tamaño del array
Solución: limitar la lectura de datos con while (i < 100 && archivo >> ...)

---

## 10. Problemas comunes

### Error: todos los resultados son ESTABLE

los datos tienen poca diferencia o error de sintaxis en codigo.

### Error: no se ejecuta el script

dar permisos con: chmod +x script.sh

---

## 11. Autoría

Claudia Gonzalez Rodriguez

---

## 12. Licencia
