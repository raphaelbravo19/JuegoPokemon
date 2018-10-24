#pragma once
#include "ArregloObjetoanimado.h"
#include "Mapa.h"
#include "Marco.h"
#include "Gimnasio.h"
#include "Pokemon.h"
#include "Zonas.h"
#include "PokemonEleccion.h"
#include "ArregloPokemon.h"
class Juego
{
private:
	Marco* Jugador;
	Mapa* Terreno;
	Mapa* Centropokemon;
	Mapa* Lorelei;
	Mapa* Bruno;
	Mapa* Agatha;
	Mapa* Lance;
	Mapa* Debora;
	Mapa* Giovanni;
	Gimnasio* Local;
	
	PokemonEleccion* PikachuE;
	PokemonEleccion* SquirtleE;
	PokemonEleccion* CharmanderE;
	PokemonEleccion* BulbasaurE;
	PokemonEleccion* Pokeball;
	PokemonEleccion* Pokeballcaptura;
	PokemonEleccion* Pokeballcambio;
	PokemonEleccion* PokeballCambioPCArriba;
	PokemonEleccion* PokeballCambioPCAbajo;
	PokemonEleccion* Flechaderechaarriba;
	PokemonEleccion* Flechaderechaabajo;
	PokemonEleccion* Flechaizquierdaarriba;
	PokemonEleccion* Flechaizquierdaabajo;
	PokemonEleccion* Interrogacionpokedex;
	PokemonEleccion* Flechamenu;
	PokemonEleccion* Marcopokedex;
	PokemonEleccion* Pokeballpokedex;
	PokemonEleccion* Medalla1;
	PokemonEleccion* Medalla2;
	PokemonEleccion* Medalla3;
	PokemonEleccion* Medalla4;
	PokemonEleccion* Medalla5;
	PokemonEleccion* Medalla6;
	PokemonEleccion* Animacionevo;

	ArregloObjetoanimado* ListaZonasNoPaso;
	ArregloObjetoanimado* ListaZonasNoPasoCentro;
	ArregloObjetoanimado* ListaZonasCaptura;
	ArregloObjetoanimado* ListaZonasNoPasoLorelei;
	ArregloObjetoanimado* ListaZonasNoPasoBruno;
	ArregloObjetoanimado* ListaZonasNoPasoAgatha;
	ArregloObjetoanimado* ListaZonasNoPasoLance;
	ArregloObjetoanimado* ListaZonasNoPasoDebora;
	ArregloObjetoanimado* ListaZonasNoPasoGiovanni;
	ArregloObjetoanimado* Etiquetatipos;

	ArregloPokemon* ListaMarco;
	ArregloPokemon* ListaMarcoPC;
	ArregloPokemon* ListaSalvajes;
	ArregloPokemon* ListaPokedex;
	ArregloPokemon* ListaIntercambio;
	ArregloPokemon* ListaLorelei;
	ArregloPokemon* ListaBruno;
	ArregloPokemon* ListaAgatha;
	ArregloPokemon* ListaLance;
	ArregloPokemon* ListaDebora;
	ArregloPokemon* ListaGiovanni;

	int pokeballe;//eleccion pokemon inicial
	int Estado;//estadodejuego | 1=mapapokemon 2=prebatalla 3=batalla 4=centropokemon 5=eleccionstarter 6=curapokemon 7=cambiopokemon
	//8=gimnasio1 9=centropokemoncerezo 10=curapokemon2 11=gimansio2 12=gimnasio3 13=gimnasio4 14=gimnasio5 15=gimnasio6 
	//16=batallalider 17=cambiopokemonlider 18=cambiopokemonPC 20=prebatallalider 
	int cuadros;//animacion prebatalla
	int letras;//paso de letras en batalla
	int AnchoDibujo;
	int AltoDibujo;
	int eleccion;//eleccion ataque en batalla
	int eneleccion;//eleccion enemigo ataque en batalla
	bool yaataco;//true=pokemonyaataco false=pokemonaunnoataca
	int ganador;//1=ganamos 2=perdimos
	int estadobatalla;//estado en batalla
	bool yapeleo;//ya peleo en batalla
	int tiempojuego;//ayuda animacion cuadro
	bool captura;//true=ordencaptura false=noordencaptura|aunnopuedecapturar
	int hierba;//0=squirtle 1=bulbasaur 2=charmander 3=Pikachu 4=pidgey;
	bool yasubio;//yasubioexperiencia
	int pokemonelegido;//pokemonactualbatalla
	bool todosdebi;//true=todosdebilitados false=aunnotodosdebilitados
	int pokemoncambio;
	bool cambio;
	bool debicam;
	bool sipu;
	int alea;
	int lider;
	int pokemonlider;
	int liderregreso;
	bool debilider;
	bool* medallas;
	bool* pokedex;
	bool* capturas;
	int pokemonarriba;
	int pokemonabajo;
	bool indicearriba;
	int indicepokemonarriba;
	int indicepokemonabajo;
	bool cerezo;
	bool flechas;
	int letrasint;
	int pokint;
	bool eleinte;
	bool siloti;
	int indice;
	bool hierba1;
	int indicepokedex;
	bool capt;
	bool evo;
	int indiceevo;
	bool animaevo;
	
public:
	Juego(int pAnchoDibujo, int pAltoDibujo);
	void ProcesarTick(int pTick);
	int BuscarPokemon(Pokemon* pPokemon, ArregloPokemon* pListaMarco);
	int BuscarPokemonpornombre(char* pnombre, ArregloPokemon* pListaMarco);
	void MostrarTodos(System::Drawing::Graphics ^gr);
	void MostrarLetras(System::Drawing::Graphics ^gr);
	void MostrarVida(System::Drawing::Graphics ^gr, int px, int py, Pokemon* pPokemon);
	void MostrarAtaques(System::Drawing::Graphics ^gr, Pokemon* pPokemon, int peleccion);
	void ProcesarKeyDown(System::Windows::Forms::Keys pTecla);
	void MostrarAtaqueUsado(System::Drawing::Graphics ^gr, Pokemon* pPokemon, Pokemon* pPokemon2, int pataque);
	void EnemigoAtaca(Pokemon* pPokemon1,Pokemon* pPokemon2);
	void Atacar(Pokemon* pPokemon1,Pokemon* pPokemon2);
	bool Debilitado(Pokemon* pPokemon);
	void Ganador(System::Drawing::Graphics ^gr);
	void AgregarZonasNoPaso();
	void AgregarZonasNoPasoCentro();
	void AgregarZonasNoPasoLorelei();
	void AgregarZonasNoPasoBruno();
	void AgregarZonasNoPasoAgatha();
	void AgregarZonasNoPasoLance();
	void AgregarZonasNoPasoDebora();
	void AgregarZonasNoPasoGiovanni();
	void AgregarZonasCaptura();
	void AgregarEtiquetas();
	void AgregarPokemonesSalvajes();
	bool HabraColision(Objetoanimado* pObjeto1, Objetoanimado* pObjeto2);
	bool HayColision(Objetoanimado* pObjeto1, Objetoanimado* pObjeto2);
	void BatallaPokemon(System::Drawing::Graphics ^gr, Pokemon* pPokemon, Pokemon* pPokemon2);
	void BatallaLider(System::Drawing::Graphics ^gr, Pokemon* pPokemon, Pokemon* pPokemon2, int pEstado);
	void AnimacionCuadros(System::Drawing::Graphics ^gr);
	void CambioPokemon(System::Drawing::Graphics ^gr);
	void CambioPokemonPC(System::Drawing::Graphics ^gr);
	void MostrarPokemonesactuales(System::Drawing::Graphics ^gr);
	void MostrarMedallas(System::Drawing::Graphics ^gr);
	void Capturapokemon(System::Drawing::Graphics ^gr,Pokemon* pPokemon);
	void AgregarListaLorelei();
	void AgregarListaBruno();
	void AgregarListaAgatha();
	void AgregarListaLance();
	void AgregarListaDebora();
	void AgregarListaGiovanni();
	void Intercambiopokemon(System::Drawing::Graphics ^gr);
	void AgregarListaIntercambio();
	void AgregarListaPokedex();
	void MostrarMenu(System::Drawing::Graphics ^gr, int pindice);
	void MostrarPokedex(System::Drawing::Graphics ^gr, int pindicepokedex);
	void EvolucionPokemon(int pindiceevo, System::Drawing::Graphics ^gr);
	Marco* DameJugador();
	ArregloObjetoanimado* DameListaNoPaso();
	~Juego();
};
