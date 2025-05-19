#include "Pokemon.h"
#include <iostream>

// Constructor
Pokemon::Pokemon(std::string nombre, std::string tipo, int nivel)
    : nombre(nombre), tipo(tipo), nivel(nivel),
      hp(50 + nivel * 10),
      ataque(10 + nivel * 2),
      defensa(8 + nivel * 2),
      velocidad(5 + nivel) {}

// Getters
std::string Pokemon::getNombre() const { return nombre; }
std::string Pokemon::getTipo() const { return tipo; }
int Pokemon::getNivel() const { return nivel; }
int Pokemon::getHp() const { return hp; }
int Pokemon::getAtaque() const { return ataque; }
int Pokemon::getDefensa() const { return defensa; }
int Pokemon::getVelocidad() const { return velocidad; }

// Métodos
void Pokemon::atacar(Pokemon& oponente) {
    int dano = ataque - (oponente.getDefensa() / 2);
    if (dano < 0) dano = 0;
    oponente.recibirDano(dano);
}

void Pokemon::recibirDano(int dano) {
    hp -= dano;
    if (hp < 0) hp = 0;
}

bool Pokemon::estaDebilitado() const { return hp <= 0; }

void Pokemon::mostrarInfo() const {
    std::cout << nombre << "(Nivel " << nivel << ")\n";
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "HP: " << hp << "\n";
    std::cout << "Ataque: " << ataque << "\n";
    std::cout << "Defensa: " << defensa << "\n";
    std::cout << "Velocidad: " << velocidad << "\n";
}