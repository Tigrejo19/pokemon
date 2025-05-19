#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"
#include "Entrenador.h"

using namespace std;
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