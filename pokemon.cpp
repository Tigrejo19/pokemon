#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class Pokemon
{
private:
    string nombre;
    string tipo;
    int nivel;
    int hp;
    int ataque;
    int defensa;
    int velocidad;

public:
    Pokemon(string nombre, string tipo, int nivel)
        : nombre(nombre), tipo(tipo), nivel(nivel)
    {
        hp = 50 + nivel * 10;
        ataque = 10 + nivel * 2;
        defensa = 8 + nivel * 2;
        velocidad = 5 + nivel;
    }

    string getNombre() const { return nombre; }
    string getTipo() const { return tipo; }
    int getNivel() const { return nivel; }
    int getHp() const { return hp; }
    int getAtaque() const { return ataque; }
    int getDefensa() const { return defensa; }
    int getVelocidad() const { return velocidad; }

    void atacar(Pokemon &oponente)
    {
        int dano = ataque - oponente.defensa / 2;
        if (dano < 0) dano = 0;
        oponente.recibirDano(dano);
    }

    void recibirDano(int dano)
    {
        hp -= dano;
        if (hp < 0) hp = 0;
    }

    bool estaDebilitado() const { return hp <= 0; }

    void mostrarInfo() const
    {
        cout << nombre << "(Nivel " << nivel << ")\n";
        cout << "Tipo: " << tipo << "\n";
        cout << "HP: " << hp << "\n";
        cout << "Ataque: " << ataque << "\n";
        cout << "Defensa: " << defensa << "\n";
        cout << "Velocidad: " << velocidad << "\n";
    }
};

class Entrenador
{
private:
    string nombre;
    vector<Pokemon> equipo;

public:
    Entrenador(string nombre) : nombre(nombre) {}

    string getNombre() const { return nombre; }

    void agregarPokemon(Pokemon p)
    {
        if (equipo.size() < 6)
        {
            equipo.push_back(p);
        }
        else
        {
            cout << "El equipo esta completo\n";
        }
    }

    Pokemon& getPokemonActual()
    {
        for (auto &p : equipo)
        {
            if (!p.estaDebilitado())
            {
                return p;
            }
        }
        throw runtime_error("No hay Pokemon vivos");
    }

    bool tienePokemonVivos()
    {
        for (auto &p : equipo)
        {
            if (!p.estaDebilitado())
            {
                return true;
            }
        }
        return false;
    }

    void mostrarEquipo()
    {
        cout << "Equipo de " << nombre << ":\n";
        for (auto& p : equipo)
        {
            cout << "- " << p.getNombre() << " (HP: " << p.getHp() << "/" 
                 << (50 + p.getNivel() * 10) << ")";
            if (p.estaDebilitado()) cout << " [DEBILITADO]";
            cout << "\n";
        }
    }
};

void batalla(Entrenador &entrenador1, Entrenador &entrenador2)
{
    cout << "¡Comienza la batalla entre " << entrenador1.getNombre() 
         << " y " << entrenador2.getNombre() << "!\n";

    while (entrenador1.tienePokemonVivos() && entrenador2.tienePokemonVivos())
    {
        try
        {
            Pokemon &pokemon1 = entrenador1.getPokemonActual();
            Pokemon &pokemon2 = entrenador2.getPokemonActual();

            cout << "\n--- Estado actual ---\n";
            entrenador1.mostrarEquipo();
            entrenador2.mostrarEquipo();
            cout << "---------------------\n";

            if (pokemon1.getVelocidad() >= pokemon2.getVelocidad())
            {
                // Turno del pokemon1 (más rápido)
                cout << pokemon1.getNombre() << " de " << entrenador1.getNombre() 
                     << " ataca a " << pokemon2.getNombre() << "!\n";
                int hp_antes = pokemon2.getHp();
                pokemon1.atacar(pokemon2);
                cout << "Inflige " << (hp_antes - pokemon2.getHp()) << " de daño!\n";

                if (pokemon2.estaDebilitado())
                {
                    cout << pokemon2.getNombre() << " ha sido debilitado!\n";
                    continue;
                }

                // Turno del pokemon2
                cout << pokemon2.getNombre() << " de " << entrenador2.getNombre() 
                     << " contraataca!\n";
                hp_antes = pokemon1.getHp();
                pokemon2.atacar(pokemon1);
                cout << "Inflige " << (hp_antes - pokemon1.getHp()) << " de daño!\n";

                if (pokemon1.estaDebilitado())
                {
                    cout << pokemon1.getNombre() << " ha sido debilitado!\n";
                }
            }
            else
            {
                // Turno del pokemon2 (más rápido)
                cout << pokemon2.getNombre() << " de " << entrenador2.getNombre() 
                     << " ataca a " << pokemon1.getNombre() << "!\n";
                int hp_antes = pokemon1.getHp();
                pokemon2.atacar(pokemon1);
                cout << "Inflige " << (hp_antes - pokemon1.getHp()) << " de daño!\n";

                if (pokemon1.estaDebilitado())
                {
                    cout << pokemon1.getNombre() << " ha sido debilitado!\n";
                    continue;
                }

                // Turno del pokemon1
                cout << pokemon1.getNombre() << " de " << entrenador1.getNombre() 
                     << " contraataca!\n";
                hp_antes = pokemon2.getHp();
                pokemon1.atacar(pokemon2);
                cout << "Inflige " << (hp_antes - pokemon2.getHp()) << " de daño!\n";

                if (pokemon2.estaDebilitado())
                {
                    cout << pokemon2.getNombre() << " ha sido debilitado!\n";
                }
            }
        }
        catch (const runtime_error& e)
        {
            break;
        }
    }

    cout << "\n--- Resultado final ---\n";
    if (entrenador1.tienePokemonVivos())
    {
        cout << "¡" << entrenador1.getNombre() << " ha ganado la batalla!\n";
    }
    else
    {
        cout << "¡" << entrenador2.getNombre() << " ha ganado la batalla!\n";
    }
}

int main()
{
    srand(time(0));
    
    // Crear entrenadores
    Entrenador ash("Ash");
    ash.agregarPokemon(Pokemon("Pikachu", "Electrico", 5));
    ash.agregarPokemon(Pokemon("Bulbasaur", "Planta", 4));

    Entrenador misty("Misty");
    misty.agregarPokemon(Pokemon("Staryu", "Agua", 5));
    misty.agregarPokemon(Pokemon("Psyduck", "Agua", 4));

    // Iniciar batalla
    batalla(ash, misty);

    return 0;
}