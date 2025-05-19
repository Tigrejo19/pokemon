#include "Entrenador.h"
#include <iostream>
#include <stdexcept>

// Constructor
Entrenador::Entrenador(std::string nombre) : nombre(nombre) {}

// Getters
std::string Entrenador::getNombre() const { return nombre; }

// Métodos
void Entrenador::agregarPokemon(Pokemon p) {
    if (equipo.size() < 6) {
        equipo.push_back(p);
    } else {
        std::cout << "El equipo está completo\n";
    }
}

Pokemon& Entrenador::getPokemonActual() {
    for (auto& p : equipo) {
        if (!p.estaDebilitado()) {
            return p;
        }
    }
    throw std::runtime_error("No hay Pokémon vivos");
}

bool Entrenador::tienePokemonVivos() const {
    for (const auto& p : equipo) {
        if (!p.estaDebilitado()) {
            return true;
        }
    }
    return false;
}

void Entrenador::mostrarEquipo() {
    std::cout << "Equipo de " << nombre << ":\n";
    for (auto& p : equipo) {
        std::cout << "- " << p.getNombre() << " (HP: " << p.getHp() << "/" 
                  << (50 + p.getNivel() * 10) << ")";
        if (p.estaDebilitado()) std::cout << " [DEBILITADO]";
        std::cout << "\n";
    }
}