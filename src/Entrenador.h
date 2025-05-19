#pragma once
#include <vector>
#include "Pokemon.h"

class Entrenador {
private:
    std::string nombre;
    std::vector<Pokemon> equipo;

public:
    Entrenador(std::string nombre);
    
    // Getters
    std::string getNombre() const;
    
    // Gestión del equipo
    void agregarPokemon(Pokemon p);
    Pokemon& getPokemonActual();
    bool tienePokemonVivos() const;
    void mostrarEquipo();
};