#pragma once
#include <string>

class Pokemon {
private:
    std::string nombre;
    std::string tipo;
    int nivel;
    int hp;
    int ataque;
    int defensa;
    int velocidad;

public:
    Pokemon(std::string nombre, std::string tipo, int nivel);
    
    // Getters
    std::string getNombre() const;
    std::string getTipo() const;
    int getNivel() const;
    int getHp() const;
    int getAtaque() const;
    int getDefensa() const;
    int getVelocidad() const;
    
    // Métodos de combate
    void atacar(Pokemon& oponente);
    void recibirDano(int dano);
    bool estaDebilitado() const;
    void mostrarInfo() const;
};