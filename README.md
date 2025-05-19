# Pokémon Battle Simulator


**Pokémon C++**

## Descripción
Este es un simulador de batallas Pokémon ¡EN DESARROLLO! en C++ que permite a dos entrenadores enfrentarse con sus equipos de Pokémon.  
El proyecto incluye mecánicas básicas de combate como turnos basados en velocidad, cálculo de daño y estados de debilitamiento.

## Características principales

- Sistema de combate por turnos basado en velocidad.
- Creación de Pokémon con estadísticas variables según nivel.
- Gestión de equipos de hasta 6 Pokémon por entrenador.
- Visualización del estado del combate en tiempo real.
- Detección automática del Pokémon actual en batalla.

## Requisitos

- Compilador de C++ (g++, clang, etc.)
- Sistema operativo Windows, Linux o macOS

## Instalación

1. Clona el repositorio:  
   `git clone https://github.com/Tigrejo19/pokemon.git`
2. Navega al directorio del proyecto:  
   `cd pokemon`
3. Compila el proyecto:  
   `g++ src/*.cpp -o pokemon`
4. Ejecuta el programa:  
   `./pokemon`

## Uso por el momento

El programa simula automáticamente una batalla entre dos entrenadores predefinidos (Ash y Misty) con sus respectivos Pokémon.  
Para personalizar los equipos, modifica el archivo main.cpp.

## Estructura del proyecto

📦 pokemon  
├── 📂 src/  
│   ├── 📜 main.cpp          *// Programa principal*  
│   ├── 📜 Pokemon.h         *// Definición clase Pokémon*  
│   ├── 📜 Pokemon.cpp       *// Implementación clase Pokémon*  
│   ├── 📜 Entrenador.h      *// Definición clase Entrenador*  
│   └── 📜 Entrenador.cpp    *// Implementación clase Entrenador*  
├── 📜 README.md             *// Documentación del proyecto*  
└── 📜 .gitignore            *// Archivos excluidos de Git*  


## Contribución

Si deseas contribuir a este proyecto, sigue estos pasos:

1. Haz un fork del repositorio
2. Crea una rama para tu contribución:  
   `git checkout -b feature/nueva-funcionalidad`
3. Realiza tus cambios y haz commit:  
   `git commit -m 'Añade nueva funcionalidad'`
4. Haz push a la rama:  
   `git push origin feature/nueva-funcionalidad`
5. Abre un Pull Request

## Autor
👤 **Tigrejo19**  
📧 [leonardovalverde19@gmail.com]

## Licencia
Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más información.

¡Disfruta del simulador de batallas Pokémon! 🚀
