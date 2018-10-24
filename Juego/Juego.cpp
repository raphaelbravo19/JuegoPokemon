#include "Juego.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
Juego::Juego(int pAnchoDibujo, int pAltoDibujo)
{
	//Marco
	Jugador = new Marco(233, 233, 0, 0, 28, 32, 1, true, "marco.png", 0, 0, 0, 0);
	//Mapa principal
	Terreno = new Mapa(0,0,906,200,1678, 93, 0, 0, 2064, 384, 1, true, "mapa1.png", 0, 0, 0, 0);
	//Centro Pokemon
	Centropokemon = new Mapa(0,0,-195, -130, -176, -21, 0, 0, 599, 346, 1, true, "centropokemon.png", 0, 0, 0, 0);
	//Fondo Batalla
 	Local = new Gimnasio(0, 0, 0, 0, 483, 465, 1, true, "mapabatalla.png", 0, 0, 0, 0);
	//Lideres de gimnasio
	Lorelei = new Mapa(400,406,-100, -100,-34, 68, 0, 0, 162, 194, 1, true, "Lorelei.png", 0, 0, 0, 0);
	Bruno = new Mapa(400, 406, -100, -100, -34, 68, 0, 0, 162, 194, 1, true, "Bruno.png", 0, 0, 0, 0);
	Agatha = new Mapa(400, 406, -100, -100, -34, 68, 0, 0, 162, 194, 1, true, "Agatha.png", 0, 0, 0, 0);
	Lance = new Mapa(400, 406, -100, -100, -34, 68, 0, 0, 162, 194, 1, true, "Lance.png", 0, 0, 0, 0);
	Debora = new Mapa(400, 406, -100, -100, -34, 68, 0, 0, 162, 194, 1, true, "Debora.png", 0, 0, 0, 0);
	Giovanni = new Mapa(400, 406, -100, -100, -34, 68, 0, 0, 162, 194, 1, true, "Giovanni.png", 0, 0, 0, 0);
	//Pokemones Iniciales
	PikachuE = new PokemonEleccion(-440,-450,25, 50, 0, 0, 563, 579, 1, true, "Pikachu eleccion.png", 0, 0, 0, 0);
	SquirtleE = new PokemonEleccion(-490, -490, 150, 65, 0, 0, 585, 600, 1, true, "Squirtle Eleccion.png", 0, 0, 0, 0);
	CharmanderE = new PokemonEleccion(-110, -120, 250, 55, 0, 0, 210, 238, 1, true, "Charmander Eleccion.png", 0, 0, 0, 0);
	BulbasaurE = new PokemonEleccion(-120, -120, 350, 55, 0, 0, 260, 240, 1, true, "Bulbasaur Eleccion.png", 0, 0, 0, 0);
	//Pokeball eleccion inicial
	Pokeball = new PokemonEleccion(-260, -260, 0, 200, 0, 0, 300, 301, 1, true, "Pokeball.png", 0, 0, 0, 0);
	//Pokeball cambio pokemon
	Pokeballcambio = new PokemonEleccion(-275, -275, 125, 340, 0, 0, 300, 301, 1, true, "Pokeball.png", 0, 0, 0, 0);
	//Pokeball captura
	Pokeballcaptura = new PokemonEleccion(-730, -730, 0, 200, 10, -3, 767, 767, 1, true, "pokeballcaptura.png", 0, 0, 0, 0);
	//Flechas menu
	Flechamenu = new PokemonEleccion(-625, -618, 312, 20, 0, 0, 640, 640, 1, true, "derecha1.png", 0, 0, 0, 0);
	//Interrogacion pokedex
	Interrogacionpokedex = new PokemonEleccion(-500, -500, 40, 40, 0, 0, 640, 640, 1, true, "interrogacion.png", 0, 0, 0, 0);
	//Marco pokedex
	Marcopokedex = new PokemonEleccion(1030, 1000, 224, 180, 0, 0, 640, 640, 1, true, "Marcopokedex.png", 0, 0, 0, 0);
	//Pokedex capturado
	Pokeballpokedex = new PokemonEleccion(-450, -450, 60, 230, 0, 0, 640, 640, 1, true, "Pokeball2.png", 0, 0, 0, 0);
	//Pokeball intercambio PC: Arriba / Abajo
	PokeballCambioPCArriba = new PokemonEleccion(-260, -260, 80, 60, 0, 0, 300, 301, 1, true, "Pokeball.png", 0, 0, 0, 0);
	PokeballCambioPCAbajo = new PokemonEleccion(-260, -260, 80, 280, 0, 0, 300, 301, 1, true, "Pokeball.png", 0, 0, 0, 0);
	//Flechas: Arriba(derecha/izquierda) / Abajo(derecha/izquierda)
	Flechaderechaarriba = new PokemonEleccion(-610, -610, 270, 70, 0, 0, 640, 640, 1, true, "derecha.png", 0, 0, 0, 0);
	Flechaizquierdaarriba = new PokemonEleccion(-610, -610, 20, 70, 0, 0, 640, 640, 1, true, "izquierda.png", 0, 0, 0, 0);
	Flechaderechaabajo = new PokemonEleccion(-610, -610, 270, 280, 0, 0, 640, 640, 1, true, "derecha.png", 0, 0, 0, 0);
	Flechaizquierdaabajo = new PokemonEleccion(-610, -610, 20, 280, 0, 0, 640, 640, 1, true, "izquierda.png", 0, 0, 0, 0);
	//Lista pokemon de Marco / Lista pokemon de Marco en PC
	ListaMarco = new ArregloPokemon(); ListaMarcoPC = new ArregloPokemon(); 
	//Lista zonas no paso:   Mapa principal / Centro Pokemon / Lorelei / Bruno / Agatha / Lance / Debora / Giovanni
	ListaZonasNoPaso = new ArregloObjetoanimado();AgregarZonasNoPaso(); 
	ListaZonasNoPasoCentro = new ArregloObjetoanimado(); AgregarZonasNoPasoCentro();
	ListaZonasNoPasoLorelei = new ArregloObjetoanimado(); AgregarZonasNoPasoLorelei();
	ListaZonasNoPasoBruno = new ArregloObjetoanimado(); AgregarZonasNoPasoBruno();
	ListaZonasNoPasoAgatha = new ArregloObjetoanimado(); AgregarZonasNoPasoAgatha();
	ListaZonasNoPasoLance = new ArregloObjetoanimado(); AgregarZonasNoPasoLance();
	ListaZonasNoPasoDebora = new ArregloObjetoanimado(); AgregarZonasNoPasoDebora();
	ListaZonasNoPasoGiovanni = new ArregloObjetoanimado(); AgregarZonasNoPasoGiovanni();
	Etiquetatipos = new ArregloObjetoanimado(); AgregarEtiquetas();
	//Lista zonas captura
	ListaZonasCaptura = new ArregloObjetoanimado(); AgregarZonasCaptura();
	//Lista pokemones salvajes
	ListaSalvajes = new ArregloPokemon(); AgregarPokemonesSalvajes(); 
	//Lista pokedex
	ListaPokedex = new ArregloPokemon(); AgregarListaPokedex();
	//Lista lideres de gimnasio
	ListaLorelei = new ArregloPokemon(); AgregarListaLorelei();
	ListaBruno = new ArregloPokemon(); AgregarListaBruno();
	ListaAgatha = new ArregloPokemon(); AgregarListaAgatha();
	ListaLance = new ArregloPokemon(); AgregarListaLance();
	ListaDebora = new ArregloPokemon(); AgregarListaDebora();
	ListaGiovanni = new ArregloPokemon(); AgregarListaGiovanni();
	//Lista Intercambio
	ListaIntercambio = new ArregloPokemon(); AgregarListaIntercambio();
	//Sprite de evolucion
	Animacionevo = new PokemonEleccion();
	//Medallas
	Medalla1 = new PokemonEleccion(-28, -28, 25, 15, 0, 0, 78, 78, 1, true, "medallaroca.png", 0, 0, 0, 0);
	Medalla2 = new PokemonEleccion(-35, -35, 100, 15, 0, 0, 83, 83, 1, true, "medallaagua.png", 0, 0, 0, 0);
	Medalla3 = new PokemonEleccion(-35, -35, 175, 15, 0, 0, 84, 84, 1, true, "medallatrueno.png", 0, 0, 0, 0);
	Medalla4 = new PokemonEleccion(-35, -35, 250, 15, 0, 0, 84, 84, 1, true, "medallaplanta.png", 0, 0, 0, 0);
	Medalla5 = new PokemonEleccion(-35, -35, 325, 15, 0, 0, 84, 84, 1, true, "medallaalma.png", 0, 0, 0, 0);
	Medalla6 = new PokemonEleccion(-35, -35, 400, 15, 0, 0, 84, 84, 1, true, "medallavolcan.png", 0, 0, 0, 0);
	//Otras variables
	Estado = 5; cuadros = 0; yapeleo = false; yaataco = false; tiempojuego = 0; ganador = 0;estadobatalla = 0; eneleccion = 0;
	pokeballe = 1; captura = false; yasubio = false; pokemonelegido = 0; todosdebi = false;
	hierba = 0; pokemoncambio = 0; cambio = false; debicam = false; sipu = true; lider = 0; pokemonlider = 0;
	medallas = new bool[6]; for (int i = 0; i < 6; i++) medallas[i] = false; indicearriba = false; indicepokemonarriba=0;
	indicepokemonabajo = 0; cerezo = true; flechas = true; letrasint = 0; pokint = 0; eleinte = true; siloti = false; indice = 0;
	hierba1 = false;
	pokedex = new bool[ListaPokedex->GetCantidad()-1]; for (int i = 0; i < ListaPokedex->GetCantidad(); i++) pokedex[i] = false; 
	indicepokedex = 0; capt = false; evo = false;indiceevo = 0; animaevo = false; capturas = new bool[ListaPokedex->GetCantidad() - 1];
	for (int i = 0; i < ListaPokedex->GetCantidad(); i++) capturas[i] = false;
	/* Tipo:
	1=Planta
	2=Agua
	3=Fuego
	4=Electrico
	5=Volador
	6=Roca
	7=Lucha
	8=Psiquico
	9=Fantasma
	10=Siniestro
	11=Hielo
	*/
}
Marco* Juego::DameJugador()
{
	return Jugador;
}
void Juego::ProcesarTick(int pTick)
{
	if (Estado == 20) {
		tiempojuego = tiempojuego + pTick;
		if (tiempojuego % 10 == 0)
		{
			cuadros++;
		}
	}
	if (Estado == 2) {
		tiempojuego = tiempojuego + pTick;
		if (tiempojuego%10 == 0)
		{
			cuadros++;
		}
	}
	if (captura==true) {
		tiempojuego = tiempojuego + pTick;
		if (tiempojuego % 10 == 0)
		{
			Pokeballcaptura->Mover();
		}
	}
	if (Estado == 18)
	{
		tiempojuego = tiempojuego + pTick;
		if (tiempojuego % 50 == 0)
		{
			flechas = !flechas;
		}
	}
	if (Estado == 18)
	{
		tiempojuego = tiempojuego + pTick;
		if (tiempojuego % 50 == 0)
		{
			flechas = !flechas;
		}
	}
	if (Estado == 23)
	{
		tiempojuego = tiempojuego + pTick;
		if (tiempojuego % 120 == 0)
		{
			if (animaevo == true && Animacionevo->GetIndiceSpriteX()<13)
			{
				Animacionevo->SetDeltaSpriteX(1);
				Animacionevo->CambiarSprite();
			}
		}
	}
}
void Juego::EvolucionPokemon(int pindiceevo,System::Drawing::Graphics ^gr)
{
	if (!animaevo)
	{
		
		Pokemon* Evolucion = new Pokemon();

		if (!strcmp(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), "Bulbasaur"))
		{
			Evolucion = new Pokemon(120, 120, "Ivysaur", ListaMarco->DameObjetoAnimado(pindiceevo)->Getnivel(),
				100, ListaMarco->DameObjetoAnimado(pindiceevo)->Getvidaactual(), 0, ListaMarco->DameObjetoAnimado(pindiceevo)->Gettipo(), "Hierba lazo", "Placaje",
				"Hoja magica", "Arañazo", ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque1(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque2(),
				ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque3(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque4(), 25, 120, 0, 0, 120, 120, 0,
				true, "ivysaurE.png", 0, 0, 0, 0, 17);
			Animacionevo = new PokemonEleccion(200, 200, 100, 80, 0, 0, 120, 120, 0, true, "evobulba.png", 0, 1, 0, 0);
		}
		else if (!strcmp(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), "Charmander"))
		{
			Evolucion = new Pokemon(120, 120, "Charmeleon", ListaMarco->DameObjetoAnimado(pindiceevo)->Getnivel(),
				100, ListaMarco->DameObjetoAnimado(pindiceevo)->Getvidaactual(), 0, ListaMarco->DameObjetoAnimado(pindiceevo)->Gettipo(), "Sofoco", "Placaje",
				"Humareda", "Arañazo", ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque1(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque2(),
				ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque3(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque4(), 25, 120, 0, 0, 120, 120, 0,
				true, "CharmeleonE.png", 0, 0, 0, 0, 17);
			Animacionevo = new PokemonEleccion(200, 200, 100, 80, 0, 0, 120, 120, 0, true, "evochar.png", 0, 1, 0, 0);
		}
		else if (!strcmp(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), "Squirtle"))
		{
			Evolucion = new Pokemon(120, 120, "Wartortle", ListaMarco->DameObjetoAnimado(pindiceevo)->Getnivel(),
				100, ListaMarco->DameObjetoAnimado(pindiceevo)->Getvidaactual(), 0, ListaMarco->DameObjetoAnimado(pindiceevo)->Gettipo(), "Salpicar", "Placaje",
				"Cascada", "Arañazo", ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque1(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque2(),
				ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque3(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque4(), 25, 120, 0, 0, 120, 120, 0,
				true, "WartortleE.png", 0, 0, 0, 0, 17);
			Animacionevo = new PokemonEleccion(200, 200, 100, 80, 0, 0, 120, 120, 0, true, "evosquir.png", 0, 1, 0, 0);
		}
		else if (!strcmp(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), "Charmeleon"))
		{
			Evolucion = new Pokemon(80, 80, "Charizard", ListaMarco->DameObjetoAnimado(pindiceevo)->Getnivel(),
				100, ListaMarco->DameObjetoAnimado(pindiceevo)->Getvidaactual(), 0, ListaMarco->DameObjetoAnimado(pindiceevo)->Gettipo(), "Lanzallamas", "Placaje",
				"Fuego Fatuo", "Arañazo", ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque1(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque2(),
				ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque3(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque4(), 15, 120, 0, 0, 164, 120, 0,
				true, "CharizardE.png", 0, 0, 0, 0, 0);
			Animacionevo = new PokemonEleccion(200, 200, 100, 70, 0, 0, 137, 120, 0, true, "evocharme.png", 0, 1, 0, 0);
		}
		else if (!strcmp(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), "Wartortle"))
		{
			Evolucion = new Pokemon(80, 80, "Blastoise", ListaMarco->DameObjetoAnimado(pindiceevo)->Getnivel(),
				100, ListaMarco->DameObjetoAnimado(pindiceevo)->Getvidaactual(), 0, ListaMarco->DameObjetoAnimado(pindiceevo)->Gettipo(), "Hidrobomba", "Placaje",
				"Hidropulso", "Arañazo", ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque1(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque2(),
				ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque3(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque4(), 15, 120, 0, 0, 164, 120, 0,
				true, "BlastoiseE.png", 0, 0, 0, 0, 0);
			Animacionevo = new PokemonEleccion(200, 200, 100, 70, 0, 0, 120, 120, 0, true, "evowar.png", 0, 1, 0, 0);
		}
		else if (!strcmp(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), "Ivysaur"))
		{
			Evolucion = new Pokemon(80, 80, "Venusaur", ListaMarco->DameObjetoAnimado(pindiceevo)->Getnivel(),
				100, ListaMarco->DameObjetoAnimado(pindiceevo)->Getvidaactual(), 0, ListaMarco->DameObjetoAnimado(pindiceevo)->Gettipo(), "Hoja aguda", "Placaje",
				"Latigazo", "Arañazo", ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque1(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque2(),
				ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque3(), ListaMarco->DameObjetoAnimado(pindiceevo)->Getataque4(), 15, 120, 0, 0, 164, 120, 0,
				true, "VenusaurE.png", 0, 0, 0, 0, 0);
			Animacionevo = new PokemonEleccion(200, 200, 100, 70, 0, 0, 120, 120, 0, true, "evoivy.png", 0, 1, 0, 0);
		}
		ListaMarco->AgregarPokemonEnPosicion(Evolucion, pindiceevo);
		pokedex[BuscarPokemonpornombre(Evolucion->GetNombre(), ListaPokedex)] = true;
		capturas[BuscarPokemonpornombre(Evolucion->GetNombre(), ListaPokedex)] = true;
		animaevo = true;
	}
	
	Animacionevo->Mostrar(gr);
	
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 14);
	System::String ^pre;
	System::String ^evo;
	if (Animacionevo->GetIndiceSpriteX() ==13)
	{
		
		gr->DrawRectangle(System::Drawing::Pens::Black, 3, 400, 477, 56);
		gr->DrawRectangle(System::Drawing::Pens::Black, 4, 401, 475, 54);

		System::String ^evo = gcnew System::String(ListaPokedex->DameObjetoAnimado(BuscarPokemonpornombre(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(),ListaPokedex))->GetNombre());
		System::String ^pre = gcnew System::String(ListaPokedex->DameObjetoAnimado(BuscarPokemonpornombre(ListaMarco->DameObjetoAnimado(pindiceevo)->GetNombre(), ListaPokedex)-1)->GetNombre());
			
		gr->DrawString(System::Convert::ToString("Tu "+pre+ " evoluciono en un "+evo), font, System::Drawing::Brushes::Black, 10,420);
		

	}
}
int Juego::BuscarPokemon(Pokemon* pPokemon, ArregloPokemon* pListaMarco)
{
	int indiceevo2;
	for (int i = 0; i < pListaMarco->GetCantidad(); i++)
	{
		if (!strcmp(pPokemon->GetNombre(), pListaMarco->DameObjetoAnimado(i)->GetNombre())&& pPokemon->Getnivel()== pListaMarco->DameObjetoAnimado(i)->Getnivel())
		{
			indiceevo2 = i;
			break;
		}
	}
	return indiceevo2;
}
void Juego::MostrarTodos(System::Drawing::Graphics ^gr)
{
	if (Estado == 1)
	{
		if (hierba1 == false)
		{
			Jugador->SetNombreArchivo("marco.png");
		}
		else
		{
			Jugador->SetNombreArchivo("marco1.png");
		}
		Terreno->Mostrar(gr); Jugador->Mostrar(gr);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
		for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++)
		{
			ListaZonasNoPaso->DameObjetoAnimado(i)->Mostrar(gr);
		}
		for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++)
		{
			ListaZonasCaptura->DameObjetoAnimado(i)->Mostrar(gr);
		}
		MostrarMedallas(gr);
		/*gr->DrawString(Terreno->GetPosX() + ", " + Terreno->GetPosY(),
			font, System::Drawing::Brushes::Blue, 0, 0);*/
		MostrarPokemonesactuales(gr);
		
	}
	if (Estado == 2)
	{
		Terreno->Mostrar(gr); Jugador->Mostrar(gr); AnimacionCuadros(gr);
		for (int i = 0; i < ListaMarco->GetCantidad(); i++)
		{
			if (ListaMarco->DameObjetoAnimado(i)->Getvidaactual() > 0)
			{
				pokemonelegido = i;
				break;
			}
		}
	}
	if (Estado == 3)
	{
		BatallaPokemon(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaSalvajes->DameObjetoAnimado(hierba));
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 16);
		gr->DrawString(System::Convert::ToString("P: Capturar"), font, System::Drawing::Brushes::Black, 350, 5);
		gr->DrawString(System::Convert::ToString("E: Escapar"), font, System::Drawing::Brushes::Black, 350, 30);
	}
	if (Estado == 4)
	{
		Centropokemon->Mostrar(gr); Jugador->Mostrar(gr);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
		/*gr->DrawString(Centropokemon->GetPosX() + ", " + Centropokemon->GetPosY(),
			font, System::Drawing::Brushes::Blue, 0, 0);*/
		for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++)
		{
			ListaZonasNoPasoCentro->DameObjetoAnimado(i)->Mostrar(gr);
		}
		MostrarPokemonesactuales(gr);
		MostrarMedallas(gr);
	}
	if (Estado == 5)
	{
		PikachuE->Mostrar(gr); SquirtleE->Mostrar(gr); CharmanderE->Mostrar(gr); BulbasaurE->Mostrar(gr);
		if (pokeballe == 1){ Pokeball->SetPosX(50); }
		if (pokeballe == 2){ Pokeball->SetPosX(170); }
		if (pokeballe == 3){ Pokeball->SetPosX(270); }
		if (pokeballe == 4){ Pokeball->SetPosX(390); }
		if (pokeballe != 0){ Pokeball->Mostrar(gr); }
		gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
		gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 28);
		System::Drawing::Font ^font2 = gcnew System::Drawing::Font("Lucida Sans", 15);
		gr->DrawString(System::Convert::ToString("Bienvenido, escoge tu"), font, System::Drawing::Brushes::Black, 20, 340);
		gr->DrawString(System::Convert::ToString("pokemon inicial . . ."), font, System::Drawing::Brushes::Black, 20, 385);
		gr->DrawString(System::Convert::ToString("1"), font, System::Drawing::Brushes::Black, 50, 5);
		gr->DrawString(System::Convert::ToString("2"), font, System::Drawing::Brushes::Black, 175, 5);
		gr->DrawString(System::Convert::ToString("3"), font, System::Drawing::Brushes::Black, 270, 5);
		gr->DrawString(System::Convert::ToString("4"), font, System::Drawing::Brushes::Black, 390, 5);
		if (pokeballe == 1){ gr->DrawString(System::Convert::ToString("Pikachu"), font2, System::Drawing::Brushes::Black, 30, 250); }
		if (pokeballe == 2){ gr->DrawString(System::Convert::ToString("Squirtle"), font2, System::Drawing::Brushes::Black, 150, 250); }
		if (pokeballe == 3){ gr->DrawString(System::Convert::ToString("Charmander"), font2, System::Drawing::Brushes::Black, 230, 250); }
		if (pokeballe == 4){ gr->DrawString(System::Convert::ToString("Bulbasaur"), font2, System::Drawing::Brushes::Black, 360, 250); }
	}
	if (Estado == 6)
	{
		Centropokemon->Mostrar(gr); Jugador->Mostrar(gr);
		for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++)
		{
			ListaZonasNoPasoCentro->DameObjetoAnimado(i)->Mostrar(gr);
		}
		MostrarLetras(gr);
	}
	if (Estado == 7)
	{
		BatallaPokemon(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaSalvajes->DameObjetoAnimado(hierba));
		CambioPokemon(gr);
	}
	if (Estado == 8)
	{
		Lorelei->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
		{
			ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->Mostrar(gr);
		}
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
		/*gr->DrawString(Lorelei->GetPosX() + ", " + Lorelei->GetPosY(),
			font, System::Drawing::Brushes::Blue, 0, 0);*/
	}
	if (Estado == 9)
	{
		Centropokemon->Mostrar(gr); Jugador->Mostrar(gr);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
		/*gr->DrawString(Centropokemon->GetPosX() + ", " + Centropokemon->GetPosY(),
			font, System::Drawing::Brushes::Blue, 0, 0);*/
		for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++)
		{
			ListaZonasNoPasoCentro->DameObjetoAnimado(i)->Mostrar(gr);
		}
		MostrarPokemonesactuales(gr);
		MostrarMedallas(gr);
	}
	if (Estado == 10)
	{
		Centropokemon->Mostrar(gr); Jugador->Mostrar(gr);
		for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++)
		{
			ListaZonasNoPasoCentro->DameObjetoAnimado(i)->Mostrar(gr);
		}
		MostrarLetras(gr);
	}
	if (Estado == 11)
	{
		Bruno->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++)
		{
			ListaZonasNoPasoBruno->DameObjetoAnimado(i)->Mostrar(gr);
		}
	}
	if (Estado == 12)
	{
		Agatha->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++)
		{
			ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->Mostrar(gr);
		}
	}
	if (Estado == 13)
	{
		Lance->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++)
		{
			ListaZonasNoPasoLance->DameObjetoAnimado(i)->Mostrar(gr);
		}
	}
	if (Estado == 14)
	{
		Debora->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++)
		{
			ListaZonasNoPasoDebora->DameObjetoAnimado(i)->Mostrar(gr);
		}
	}
	if (Estado == 15)
	{
		Giovanni->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++)
		{
			ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->Mostrar(gr);
		}
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
		/*gr->DrawString(Giovanni->GetPosX() + ", " + Giovanni->GetPosY(),
			font, System::Drawing::Brushes::Blue, 0, 0);*/
	}
	if (Estado == 16)
	{
		
		if (lider == 1)
		{
			liderregreso = 8;
			BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaLorelei->DameObjetoAnimado(pokemonlider), liderregreso);
		}
		if (lider == 2)
		{
			liderregreso = 11;
			BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaBruno->DameObjetoAnimado(pokemonlider), liderregreso);
		}
		if (lider == 3)
		{
			liderregreso = 12;
			BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaAgatha->DameObjetoAnimado(pokemonlider), liderregreso);
		}
		if (lider == 4)
		{
			liderregreso = 13;
			BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaLance->DameObjetoAnimado(pokemonlider), liderregreso);
		}
		if (lider == 5)
		{
			liderregreso = 14;
			BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaDebora->DameObjetoAnimado(pokemonlider), liderregreso);
		}
		if (lider == 6)
		{
			liderregreso = 15;
			BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaGiovanni->DameObjetoAnimado(pokemonlider), liderregreso);
		}
		
		
	}
	if (Estado == 17)
	{
		if (lider == 1) BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaLorelei->DameObjetoAnimado(pokemonlider),liderregreso);
		if (lider == 2) BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaBruno->DameObjetoAnimado(pokemonlider), liderregreso);
		if (lider == 3) BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaAgatha->DameObjetoAnimado(pokemonlider), liderregreso);
		if (lider == 4) BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaLance->DameObjetoAnimado(pokemonlider), liderregreso);
		if (lider == 5) BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaDebora->DameObjetoAnimado(pokemonlider), liderregreso);
		if (lider == 6) BatallaLider(gr, ListaMarco->DameObjetoAnimado(pokemonelegido), ListaGiovanni->DameObjetoAnimado(pokemonlider), liderregreso);

		CambioPokemon(gr);
	}
	if (Estado == 18)
	{
		Centropokemon->Mostrar(gr); Jugador->Mostrar(gr);
		CambioPokemonPC(gr);
	}
	if (Estado == 19)
	{
		Terreno->Mostrar(gr);
		Jugador->Mostrar(gr);
		Intercambiopokemon(gr);

	}
	if (Estado == 20)
	{
		if (lider == 1) Lorelei->Mostrar(gr);
		if (lider == 2) Bruno->Mostrar(gr);
		if (lider == 3) Agatha->Mostrar(gr);
		if (lider == 4) Lance->Mostrar(gr);
		if (lider == 5) Debora->Mostrar(gr);
		if (lider == 6) Giovanni->Mostrar(gr);
		Jugador->Mostrar(gr);
		AnimacionCuadros(gr);
		for (int i = 0; i < ListaMarco->GetCantidad(); i++)
		{
			if (ListaMarco->DameObjetoAnimado(i)->Getvidaactual() > 0)
			{
				pokemonelegido = i;
				break;
			}
		}
		
	}
	if (Estado == 21)
	{
		Terreno->Mostrar(gr); Jugador->Mostrar(gr); MostrarPokemonesactuales(gr); MostrarMedallas(gr);
		MostrarMenu(gr, indice);

	}
	if (Estado == 22)
	{
		MostrarPokedex(gr, indicepokedex);

	}
	if (Estado == 23)
	{
		EvolucionPokemon(indiceevo,gr);
	}
}
int Juego::BuscarPokemonpornombre(char* pnombre, ArregloPokemon* pListaMarco)
{
	int indiceevo2;
	for (int i = 0; i < pListaMarco->GetCantidad(); i++)
	{
		if (!strcmp(pnombre, pListaMarco->DameObjetoAnimado(i)->GetNombre()))
		{
			indiceevo2 = i;
			break;
		}
	}
	return indiceevo2;
}
void Juego::MostrarPokedex(System::Drawing::Graphics ^gr, int pindicepokedex)
{
	gr->FillRectangle(System::Drawing::Brushes::IndianRed, 0, 0, 500, 500);
	gr->FillRectangle(System::Drawing::Brushes::White, 8, 10, 200, 200);
	gr->DrawRectangle(System::Drawing::Pens::Black, 10, 12, 195, 195);
	gr->DrawRectangle(System::Drawing::Pens::Black, 11, 13, 193, 193);

	gr->FillRectangle(System::Drawing::Brushes::White, 220, 10, 255, 405);
	gr->FillRectangle(System::Drawing::Brushes::Black, 222, 12, 251, 401);

	gr->FillRectangle(System::Drawing::Brushes::White, 8, 216, 200, 200);
	gr->FillRectangle(System::Drawing::Brushes::Black, 10, 218, 196, 196);


	if (capturas[pindicepokedex] == true) Pokeballpokedex->Mostrar(gr);
	if (capturas[pindicepokedex]||pokedex[pindicepokedex]==true)ListaPokedex->DameObjetoAnimado(pindicepokedex)->Mostrar(gr);
	else Interrogacionpokedex->Mostrar(gr);
	//bool vist = false;
	Marcopokedex->Mostrar(gr);
	for (int i = 0; i < ListaPokedex->GetCantidad(); i++)
	{
		
		if (capturas[i] == true || pokedex[i]==true)
		{
			System::String ^s1 = gcnew System::String(ListaPokedex->DameObjetoAnimado(i)->GetNombre());
			System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 18);
			if(i<9)gr->DrawString(System::Convert::ToString("00"+(i+1)+ " ")+s1, font, System::Drawing::Brushes::White, 235, 192 + (i + (pindicepokedex*-1)) * 50);
			else gr->DrawString(System::Convert::ToString("0" + (i + 1) + " ") + s1, font, System::Drawing::Brushes::White, 235, 192 + (i + (pindicepokedex*-1)) * 50);
		}
		else
		{
			System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 18);
			if (i<9) gr->DrawString(System::Convert::ToString("00"+(i+1)+" - - - - - - - - - - -"), font, System::Drawing::Brushes::White, 235, 192 + (i + (pindicepokedex*-1)) * 50);
			else gr->DrawString(System::Convert::ToString("0" + (i + 1) + " - - - - - - - - - - -"), font, System::Drawing::Brushes::White, 235, 192 + (i + (pindicepokedex*-1)) * 50);
		}
	}
	gr->FillRectangle(System::Drawing::Brushes::IndianRed, 220, 415, 255, 50);
	gr->FillRectangle(System::Drawing::Brushes::IndianRed, 220, 0, 255, 10);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 20);
	gr->DrawString(System::Convert::ToString("X: Salir"), font, System::Drawing::Brushes::White, 280,420 );
	
	
}
void Juego::MostrarMenu(System::Drawing::Graphics ^gr, int pindice)
{
	gr->FillRectangle(System::Drawing::Brushes::Brown, 300, 4, 180, 250);
	gr->DrawRectangle(System::Drawing::Pens::Black, 300, 4, 180, 250);
	gr->DrawRectangle(System::Drawing::Pens::Black, 301, 5, 178, 248);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Arial", 17);
	gr->DrawString(System::Convert::ToString("Pokedex"), font, System::Drawing::Brushes::White,330 , 18);
	gr->DrawString(System::Convert::ToString("Pokemones"), font, System::Drawing::Brushes::White, 330, 68);
	gr->DrawString(System::Convert::ToString("Bolsa"), font, System::Drawing::Brushes::White, 330, 118);
	gr->DrawString(System::Convert::ToString("Datos"), font, System::Drawing::Brushes::White, 330, 168);
	gr->DrawString(System::Convert::ToString("Salir"), font, System::Drawing::Brushes::White, 330, 218);
	Flechamenu->SetPosY((pindice * 50)+20);
	Flechamenu->Mostrar(gr);


}
void Juego::AnimacionCuadros(System::Drawing::Graphics ^gr)
{
	int anchoo = 70;
	int alto = 67;
	for (int i = 0; i <= cuadros; i++){
		gr->FillRectangle(System::Drawing::Brushes::Black, anchoo*i, 0, anchoo, alto);
		if (cuadros>6) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 6, alto*(i - 5), anchoo, alto);
		if (cuadros>11) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 6 - (anchoo *(i - 10)), alto * 6, anchoo, alto);
		if (cuadros>16) gr->FillRectangle(System::Drawing::Brushes::Black, 0, alto * 6 - (alto *(i - 15)), anchoo, alto);
		if (cuadros>20) gr->FillRectangle(System::Drawing::Brushes::Black, 0 + anchoo*(i - 19), alto, anchoo, alto);
		if (cuadros>24) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 5, alto*(i - 23), anchoo, alto);
		if (cuadros>28) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 5 - (anchoo*(i - 27)), alto * 5, anchoo, alto);
		if (cuadros>31) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo, alto * 5 - (alto *(i - 30)), anchoo, alto);
		if (cuadros>33) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 2 + (anchoo*(i - 32)), alto * 2, anchoo, alto);
		if (cuadros>35) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 4, alto * (3 + (i - 34)), anchoo, alto);
		if (cuadros>37) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * 4 - (anchoo*(i - 36)), alto * 4, anchoo, alto);
		if (cuadros>39) gr->FillRectangle(System::Drawing::Brushes::Black, anchoo * (4 + (i - 38)), alto * 3, anchoo, alto);
		if (cuadros > 41)
		{
			if (lider != 0)
			{
				Estado = 16;
			}
			else
			Estado = 3;
			letras = 0;
			cuadros = 0;
		}
	}
}
void Juego::MostrarVida(System::Drawing::Graphics ^gr, int px, int py, Pokemon* pPokemon)
{
	gr->FillRectangle(System::Drawing::Brushes::White, px, py, 240, 9);
	gr->FillRectangle(System::Drawing::Brushes::ForestGreen, px+70, py+2, (pPokemon->Getvidaactual()*3)/2, 5);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 12);
	System::Drawing::Font ^font1 = gcnew System::Drawing::Font("Humnst777 Blk BT", 10);
	System::String ^s = gcnew System::String(pPokemon->GetNombre());
	gr->DrawString(System::Convert::ToString("HP"), font1, System::Drawing::Brushes::Blue, px+40, py-4);
	gr->DrawString(s, font, System::Drawing::Brushes::Black, px, py-20);
	gr->DrawString(System::Convert::ToString("   Lv. "+pPokemon->Getnivel()+ "   "+ pPokemon->Getexperiencia()+"/200"), font, System::Drawing::Brushes::Black, px+90, py-20);
	gr->DrawString(System::Convert::ToString(pPokemon->Getvidaactual()+"/"+pPokemon->Getvidamaxima()), font, System::Drawing::Brushes::Blue, px + 62, py +8);

	Etiquetatipos->DameObjetoAnimado(pPokemon->Gettipo() - 1)->SetPosX(px + 150); Etiquetatipos->DameObjetoAnimado(pPokemon->Gettipo() - 1)->SetPosY(py + 10);
	Etiquetatipos->DameObjetoAnimado(pPokemon->Gettipo() - 1)->Mostrar(gr);
}
void Juego::MostrarAtaques(System::Drawing::Graphics ^gr, Pokemon* pPokemon, int peleccion)
{
	gr->FillRectangle(System::Drawing::Brushes::White, 0, 308, 480, 155);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
	gr->DrawLine(System::Drawing::Pens::Black, 243, 310, 243, 460);
	gr->DrawLine(System::Drawing::Pens::Black, 3, 385, 480, 385);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 15);
	System::String ^s1 = gcnew System::String(pPokemon->Getnataque1());
	System::String ^s2 = gcnew System::String(pPokemon->Getnataque2());
	System::String ^s3 = gcnew System::String(pPokemon->Getnataque3());
	System::String ^s4 = gcnew System::String(pPokemon->Getnataque4());
	gr->DrawString(s1+System::Convert::ToString(" (1)"), font, System::Drawing::Brushes::Black, 15, 322);
	gr->DrawString(System::Convert::ToString("("+ pPokemon->Getataque1()+"/15)"), 
		font, System::Drawing::Brushes::Black, 150, 350);
	gr->DrawString(s2 + System::Convert::ToString(" (2)"), font, System::Drawing::Brushes::Black, 255, 322);
	gr->DrawString(System::Convert::ToString("(" + pPokemon->Getataque2() + "/15)"),
		font, System::Drawing::Brushes::Black, 390, 350);
	gr->DrawString(s3 + System::Convert::ToString(" (3)"), font, System::Drawing::Brushes::Black, 15, 397);
	gr->DrawString(System::Convert::ToString("(" + pPokemon->Getataque3() + "/15)"), 
		font, System::Drawing::Brushes::Black, 150, 425);
	gr->DrawString(s4 + System::Convert::ToString(" (4)"), font, System::Drawing::Brushes::Black, 255, 397);
	gr->DrawString(System::Convert::ToString("(" + pPokemon->Getataque4() + "/15)"), 
		font, System::Drawing::Brushes::Black, 390, 425);
	if (peleccion == 1)
	{
		gr->DrawRectangle(System::Drawing::Pens::Red, 5, 312, 237, 72);
		gr->DrawRectangle(System::Drawing::Pens::Red, 6, 313, 235, 70);
	}
	if (peleccion == 2)
	{
		gr->DrawRectangle(System::Drawing::Pens::Red, 244, 312, 237, 72);
		gr->DrawRectangle(System::Drawing::Pens::Red, 245, 313, 235, 70);
	}
	if (peleccion == 3)
	{
		gr->DrawRectangle(System::Drawing::Pens::Red, 5, 386, 237, 72);
		gr->DrawRectangle(System::Drawing::Pens::Red, 6, 387, 235, 70);
	}
	if (peleccion == 4)
	{
		gr->DrawRectangle(System::Drawing::Pens::Red, 244, 386, 237, 72);
		gr->DrawRectangle(System::Drawing::Pens::Red, 245, 387, 235, 70);
	}
}
void Juego::MostrarLetras(System::Drawing::Graphics ^gr)
{
		gr->FillRectangle(System::Drawing::Brushes::White, 3, 350, 477, 110);
		gr->DrawRectangle(System::Drawing::Pens::Black, 3, 350, 477, 110);
		gr->DrawRectangle(System::Drawing::Pens::Black, 4, 351, 475, 108);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 22);
		gr->DrawString(System::Convert::ToString("Deseas curar a tus pokemones"), font, System::Drawing::Brushes::Black, 10, 365);
		gr->DrawString(System::Convert::ToString("(A) Si     (B) No"), font, System::Drawing::Brushes::Black, 50, 405);
		
}
void Juego::ProcesarKeyDown(System::Windows::Forms::Keys pTecla)
{
		if (Estado == 1) {
			hierba1 = false;
			
			if ((Terreno->GetPosX() == 1646) && (Terreno->GetPosY() == 213) && (Jugador->GetIndiceSpriteY() == 3)) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 4;
			}
			if ((Terreno->GetPosX() == 334) && (Terreno->GetPosY() == 53) && (Jugador->GetIndiceSpriteY() == 3)) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 9;
			}
			if ((Terreno->GetPosX() == 926) && (Terreno->GetPosY() == 21) && (Jugador->GetIndiceSpriteY() == 3)) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 8;
			}
			if ((Terreno->GetPosX() == 134) && (Terreno->GetPosY() == 13) && (Jugador->GetIndiceSpriteY() == 3) && (pTecla == System::Windows::Forms::Keys::Enter)) {
				letrasint = 0;
				Estado = 19;
			}
			else if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				indice = 0;
				Estado = 21;
			}
				
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Terreno->SetDeltaX(8);
				Terreno->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++){
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaX(-14);
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++){
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaX(-14);
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Terreno->SetDeltaX(-8);
				Terreno->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++){
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaX(14);
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++){
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaX(14);
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Terreno->SetDeltaX(0);
				Terreno->SetDeltaY(-8);
				for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++){
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaY(17);
				}
				for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++){
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaY(17);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Terreno->SetDeltaX(0);
				Terreno->SetDeltaY(8);
				for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++){
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPaso->DameObjetoAnimado(i)->SetDeltaY(-17);
				}
				for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++){
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasCaptura->DameObjetoAnimado(i)->SetDeltaY(-17);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			Jugador->SetDeltaSpriteX(1);
			bool ok = true;
			for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPaso->DameObjetoAnimado(i))) {
					ok = false;
					break;
				}
			}
			bool ok2 = false;
			for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++){
				if (HayColision(Jugador, ListaZonasCaptura->DameObjetoAnimado(i))) {
					ok2 = true;
					hierba1 = true;
					break;
				}
				else hierba1 = false;
			}
			if (ok)
			{

				Terreno->Mover();
				for (int i = 0; i < ListaZonasNoPaso->GetCantidad(); i++){
					ListaZonasNoPaso->DameObjetoAnimado(i)->Mover();
				}
				for (int i = 0; i < ListaZonasCaptura->GetCantidad(); i++){
					ListaZonasCaptura->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
			{
				Jugador->SetIndiceSpriteX(0);
			}
			else Jugador->CambiarSprite();
			
			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			letrasint = 0;
			eleinte = true;
			yapeleo = false;
			yasubio = false;
			yaataco = false;
			

			for (int i = 0; i < ListaSalvajes->GetCantidad(); i++)
			{
				if (ListaSalvajes->DameObjetoAnimado(i)->Getvidaactual() <= ListaSalvajes->DameObjetoAnimado(i)->Getvidamaxima())
					ListaSalvajes->DameObjetoAnimado(i)->Setvidaactual(ListaSalvajes->DameObjetoAnimado(i)->Getvidamaxima());
			}
			if (ok2 && !todosdebi)
			{
				
				 if (rand() % 20 == 7)
				{
					hierba = rand()%13;
					pokedex[BuscarPokemonpornombre(ListaSalvajes->DameObjetoAnimado(hierba)->GetNombre(),ListaPokedex)] = true;
					Estado = 2;
					
				}
			}
			pTecla = System::Windows::Forms::Keys::Space;
		}
		if (Estado == 3)
		{
			if (pTecla == System::Windows::Forms::Keys::C) {
				Estado = 7;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad1) {
				eleccion = 1;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad2) {
				eleccion = 2;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad3) {
				eleccion = 3;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad4) {
				eleccion = 4;
			}
			if (pTecla == System::Windows::Forms::Keys::P) {
				captura = true;
			}
			if (pTecla == System::Windows::Forms::Keys::E) {
				estadobatalla = 4;
			}
			if (pTecla == System::Windows::Forms::Keys::Enter) {
				if (estadobatalla == 5)
				{
					debicam = true; estadobatalla = 0; letras = 0;
				}
				if (estadobatalla == 4) Estado = 1;
				letras++;
				if (estadobatalla == 0) estadobatalla = 1;
				if (ganador == 1)
				{
					estadobatalla = 3;
				}
				if (letras == 2 && estadobatalla == 1)
				{
					estadobatalla = 2;
				}
				if (ganador == 2)
				{
					estadobatalla = 3;
				}
				if (letras == 3 && ganador == 1 && estadobatalla == 3)
				{
					if(!evo)Estado = 1;
					else
					{
						
						Estado = 23;
					}
					yapeleo = true;
				}
				if (letras == 4 && ganador == 2 && estadobatalla == 3)
				{
					if (!evo)Estado = 1;
					else
					{
						Estado = 23;
					}
					yapeleo = true;
				}
				if (letras == 3 && estadobatalla != 3)
				{
					estadobatalla = 0;
					letras = 0;
					eneleccion = 0;
					yaataco = false;
					eleccion = 0;
				}
			}
		}
		if (Estado == 4)
		{
			cerezo = false;
			if ((((Centropokemon->GetPosX() == -176) && (Centropokemon->GetPosY() == -21)) ||
				((Centropokemon->GetPosX() == -156) && (Centropokemon->GetPosY() == -21)) ||
				((Centropokemon->GetPosX() == -136) && (Centropokemon->GetPosY() == -21))) && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 1;
			}
			if ((Centropokemon->GetPosX() == -176) && (Centropokemon->GetPosY() == -201) && (Jugador->GetIndiceSpriteY() == 3)
				&& (pTecla == System::Windows::Forms::Keys::Enter)) {
				Estado = 6;
			}
			if ((Centropokemon->GetPosX() == 244) && (Centropokemon->GetPosY() == -141) && (Jugador->GetIndiceSpriteY() == 3)
				&& (pTecla == System::Windows::Forms::Keys::Enter)) {
				Estado = 18;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Centropokemon->SetDeltaX(20);
				Centropokemon->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(-15);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Centropokemon->SetDeltaX(-20);
				Centropokemon->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(15);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Centropokemon->SetDeltaX(0);
				Centropokemon->SetDeltaY(-20);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(14);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Centropokemon->SetDeltaX(0);
				Centropokemon->SetDeltaY(20);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(-14);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			bool ok2 = true;
			for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoCentro->DameObjetoAnimado(i))) {
					ok2 = false;
					break;
				}
			}
			Jugador->SetDeltaSpriteX(1);
			if (ok2)
			{
				Centropokemon->Mover();
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();
		}
		if (Estado == 5)
		{
			if (pTecla == System::Windows::Forms::Keys::Left) {
				pokeballe--;
				if (pokeballe == 0) pokeballe = 4;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				pokeballe++;
				if (pokeballe == 5) pokeballe = 1;
			}
			
			if (pTecla == System::Windows::Forms::Keys::Enter && pokeballe!=0) {
				if (pokeballe == 1){ 
					Pokemon* Pikachu = new Pokemon(20, 20, "Pikachu", 10, 100, 100, 0, 4,
						"Impactrueno", "Placaje", "Rayo", "Arañazo", 15, 15, 15, 15, 
						45, 180, 0, 0, 120, 120, 23, true, "pikachuE.png", 0, 0, 0, 0, 0);
					ListaMarco->AgregaObjetoAnimado(Pikachu); capturas[BuscarPokemonpornombre("Pikachu",ListaPokedex)] = true;
				}
				if (pokeballe == 2){
					Pokemon* Squirtle = new Pokemon(100, 100, "Squirtle", 15
						, 100, 100, 0, 2,
						"Rayo Burbuja", "Placaje", "Pistola de agua", "Arañazo", 15, 15, 15,15,
						40, 140, 0, 0, 120, 120, 21, true, "squirtleE.png", 0, 0, 0, 0,16);
					ListaMarco->AgregaObjetoAnimado(Squirtle); capturas[BuscarPokemonpornombre("Squirtle", ListaPokedex)] = true;
				}
				if (pokeballe == 3){
					Pokemon* Charmander = new Pokemon(100, 100, "Charmander", 15, 100, 100, 0, 3,
						"Giro fuego", "Placaje", "Ascuas", "Arañazo", 15, 15, 15, 15,
						40, 140, 0, 0, 120, 120, 22, true, "charmanderE.png", 0, 0, 0, 0,16);
					ListaMarco->AgregaObjetoAnimado(Charmander); capturas[BuscarPokemonpornombre("Charmander", ListaPokedex)] = true;
				}
				if (pokeballe == 4){ 
					Pokemon* Bulbasaur = new Pokemon(100, 100, "Bulbasaur", 15, 100, 100, 0, 1,
						"Latigo cepa", "Placaje", "Hoja afilada", "Arañazo", 15, 15, 15, 15,
						40, 140, 0, 0, 120, 120, 20, true, "bulbasaurE.png", 0, 0, 0, 0,16);
					ListaMarco->AgregaObjetoAnimado(Bulbasaur); capturas[BuscarPokemonpornombre("Bulbasaur", ListaPokedex)] = true;
				}
				Estado = 1;
			}
		}
		if (Estado == 6)
		{
			if (pTecla == System::Windows::Forms::Keys::A) {
				for (int i = 0; i < ListaMarco->GetCantidad(); i++){
					ListaMarco->DameObjetoAnimado(i)->Setvidaactual(ListaMarco->DameObjetoAnimado(i)->Getvidamaxima());
					ListaMarco->DameObjetoAnimado(i)->Setataque1(15);
					ListaMarco->DameObjetoAnimado(i)->Setataque2(15);
					ListaMarco->DameObjetoAnimado(i)->Setataque3(15);
					ListaMarco->DameObjetoAnimado(i)->Setataque4(15);
				}
				Estado = 4;
				todosdebi = false;
			}
			if (pTecla == System::Windows::Forms::Keys::B) {
				Estado = 4;
			}
		}
		if (Estado == 7)
		{
			if (pTecla == System::Windows::Forms::Keys::Left) {
				pokemoncambio--;
				if (pokemoncambio < 0) pokemoncambio = ListaMarco->GetCantidad()-1;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				pokemoncambio++;
				if (pokemoncambio > ListaMarco->GetCantidad()-1) pokemoncambio = 0;
			}
			if (pTecla == System::Windows::Forms::Keys::Enter) {
				pokemonelegido = pokemoncambio;
				if (ListaMarco->DameObjetoAnimado(pokemonelegido)->Getvidaactual() > 0)
				{
					Estado = 3;
				}
			}
		}
		if (Estado == 8)
		{
			bool si = true;
			Jugador->SetDeltaSpriteX(1);
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if ((Lorelei->GetPosX() == -26) && (Lorelei->GetPosY() == -76) && (Jugador->GetIndiceSpriteY() == 3) && (medallas[0] == false) && !todosdebi)
				{
					lider = 1;
					Estado = 20;
				}
			}
			if ((((Lorelei->GetPosX() == -34) && (Lorelei->GetPosY() == 68)) || ((Lorelei->GetPosX() == -42) && (Lorelei->GetPosY() == 68))
				|| ((Lorelei->GetPosX() == -26) && (Lorelei->GetPosY() == 68))) && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 1;
				
			}
			if (Lorelei->GetPosY() == -112 && Jugador->GetIndiceSpriteY() == 3) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 11;
				si = false;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Lorelei->SetDeltaX(8);
				Lorelei->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
				{
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaX(-17);
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
				si = false;
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Lorelei->SetDeltaX(-8);
				Lorelei->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
				{
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaX(17);
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
				si = false;
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Lorelei->SetDeltaX(0);
				Lorelei->SetDeltaY(-9);
				for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
				{
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaY(18);
				}
				Jugador->SetIndiceSpriteY(3);
				si = false;
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Lorelei->SetDeltaX(0);
				Lorelei->SetDeltaY(9);
				for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
				{
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaY(-18);
				}
				Jugador->SetIndiceSpriteY(0);
				si = false;
			}
			if (si)
			{
				Lorelei->SetDeltaX(0);
				Lorelei->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
				{
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetDeltaSpriteX(0);
			}
			
			bool ok3 = true;
			for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoLorelei->DameObjetoAnimado(i))) {
					ok3 = false;
					break;
				}
			}
			if (ok3)
			{
				Lorelei->Mover();
				for (int i = 0; i < ListaZonasNoPasoLorelei->GetCantidad(); i++)
				{
					ListaZonasNoPasoLorelei->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();

			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			pokemonlider = 0;
			yapeleo = false;
			yasubio = false;
			yaataco = false;
			
			for (int i = 0; i < ListaLorelei->GetCantidad(); i++)
			{
				if (ListaLorelei->DameObjetoAnimado(i)->Getvidaactual() <= ListaLorelei->DameObjetoAnimado(i)->Getvidamaxima())
					ListaLorelei->DameObjetoAnimado(i)->Setvidaactual(ListaLorelei->DameObjetoAnimado(i)->Getvidamaxima());
			}

			
		}
		if (Estado == 9)
		{
			cerezo = true;
			if ((((Centropokemon->GetPosX() == -176) && (Centropokemon->GetPosY() == -21)) ||
				((Centropokemon->GetPosX() == -156) && (Centropokemon->GetPosY() == -21)) ||
				((Centropokemon->GetPosX() == -136) && (Centropokemon->GetPosY() == -21))) && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 1;
			}
			if ((Centropokemon->GetPosX() == -176) && (Centropokemon->GetPosY() == -201) && (Jugador->GetIndiceSpriteY() == 3)
				&& (pTecla == System::Windows::Forms::Keys::Enter)) {
				Estado = 10;
			}
			if ((Centropokemon->GetPosX() == 244) && (Centropokemon->GetPosY() == -141) && (Jugador->GetIndiceSpriteY() == 3)
				&& (pTecla == System::Windows::Forms::Keys::Enter)) {
				Estado = 18;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Centropokemon->SetDeltaX(20);
				Centropokemon->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(-15);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Centropokemon->SetDeltaX(-20);
				Centropokemon->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(15);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Centropokemon->SetDeltaX(0);
				Centropokemon->SetDeltaY(-20);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(14);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Centropokemon->SetDeltaX(0);
				Centropokemon->SetDeltaY(20);
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->SetDeltaY(-14);
				}
				Jugador->SetIndiceSpriteY(0);
			}

			bool ok2 = true;
			for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoCentro->DameObjetoAnimado(i))) {
					ok2 = false;
					break;
				}
			}
			Jugador->SetDeltaSpriteX(1);
			if (ok2)
			{
				Centropokemon->Mover();
				for (int i = 0; i < ListaZonasNoPasoCentro->GetCantidad(); i++){
					ListaZonasNoPasoCentro->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();
		}
		if (Estado == 10)
		{
			if (pTecla == System::Windows::Forms::Keys::A) {
				for (int i = 0; i < ListaMarco->GetCantidad(); i++){
					ListaMarco->DameObjetoAnimado(i)->Setvidaactual(ListaMarco->DameObjetoAnimado(i)->Getvidamaxima());
					ListaMarco->DameObjetoAnimado(i)->Setataque1(15);
					ListaMarco->DameObjetoAnimado(i)->Setataque2(15);
					ListaMarco->DameObjetoAnimado(i)->Setataque3(15);
					ListaMarco->DameObjetoAnimado(i)->Setataque4(15);
				}
				Estado = 9;
				todosdebi = false;
			}
			if (pTecla == System::Windows::Forms::Keys::B) {
				Estado = 9;
			}
		}
		if (Estado == 11)
		{
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if ((Bruno->GetPosX() == -26) && (Bruno->GetPosY() == -76) && (Jugador->GetIndiceSpriteY() == 3) && (medallas[1] == false) && !todosdebi)
				{
					lider = 2;
					Estado = 20;
				}
			}
			if (Bruno->GetPosY() == 68 && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 8;
			}
			if (Bruno->GetPosY() == -112 && Jugador->GetIndiceSpriteY() == 3) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 12;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Bruno->SetDeltaX(8);
				Bruno->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++)
				{
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaX(-17);
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Bruno->SetDeltaX(-8);
				Bruno->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++)
				{
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaX(17);
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Bruno->SetDeltaX(0);
				Bruno->SetDeltaY(-9);
				for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++)
				{
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaY(18);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Bruno->SetDeltaX(0);
				Bruno->SetDeltaY(9);
				for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++)
				{
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->SetDeltaY(-18);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			Jugador->SetDeltaSpriteX(1);
			bool ok3 = true;
			for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoBruno->DameObjetoAnimado(i))) {
					ok3 = false;
					break;
				}
			}
			if (ok3)
			{
				Bruno->Mover();
				for (int i = 0; i < ListaZonasNoPasoBruno->GetCantidad(); i++)
				{
					ListaZonasNoPasoBruno->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();

			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			pokemonlider = 0;
			yapeleo = false;
			yasubio = false;
			yaataco = false;

			for (int i = 0; i < ListaBruno->GetCantidad(); i++)
			{
				if (ListaBruno->DameObjetoAnimado(i)->Getvidaactual() <= ListaBruno->DameObjetoAnimado(i)->Getvidamaxima())
					ListaBruno->DameObjetoAnimado(i)->Setvidaactual(ListaBruno->DameObjetoAnimado(i)->Getvidamaxima());
			}
		}
		if (Estado == 12)
		{
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if ((Agatha->GetPosX() == -26) && (Agatha->GetPosY() == -76) && (Jugador->GetIndiceSpriteY() == 3) && (medallas[2] == false) && !todosdebi)
				{
					lider = 3;
					Estado = 20;
				}
			}
			if (Agatha->GetPosY() == 68 && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 11;
			}
			if (Agatha->GetPosY() == -112 && Jugador->GetIndiceSpriteY() == 3) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 13;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Agatha->SetDeltaX(8);
				Agatha->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++)
				{
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaX(-17);
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Agatha->SetDeltaX(-8);
				Agatha->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++)
				{
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaX(17);
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Agatha->SetDeltaX(0);
				Agatha->SetDeltaY(-9);
				for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++)
				{
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaY(18);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Agatha->SetDeltaX(0);
				Agatha->SetDeltaY(9);
				for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++)
				{
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->SetDeltaY(-18);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			Jugador->SetDeltaSpriteX(1);
			bool ok3 = true;
			for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoAgatha->DameObjetoAnimado(i))) {
					ok3 = false;
					break;
				}
			}
			if (ok3)
			{
				Agatha->Mover();
				for (int i = 0; i < ListaZonasNoPasoAgatha->GetCantidad(); i++)
				{
					ListaZonasNoPasoAgatha->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();

			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			pokemonlider = 0;
			yapeleo = false;
			yasubio = false;
			yaataco = false;

			for (int i = 0; i < ListaLance->GetCantidad(); i++)
			{
				if (ListaAgatha->DameObjetoAnimado(i)->Getvidaactual() <= ListaAgatha->DameObjetoAnimado(i)->Getvidamaxima())
					ListaAgatha->DameObjetoAnimado(i)->Setvidaactual(ListaAgatha->DameObjetoAnimado(i)->Getvidamaxima());
			}
		}
		if (Estado == 13)
		{
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if ((Lance->GetPosX() == -26) && (Lance->GetPosY() == -76) && (Jugador->GetIndiceSpriteY() == 3) && (medallas[3] == false) && !todosdebi)
				{
					lider = 4;
					Estado = 20;
				}
			}
			if (Lance->GetPosY() == 68 && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 12;
			}
			if (Lance->GetPosY() == -112 && Jugador->GetIndiceSpriteY() == 3) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 14;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Lance->SetDeltaX(8);
				Lance->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++)
				{
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaX(-17);
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Lance->SetDeltaX(-8);
				Lance->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++)
				{
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaX(17);
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Lance->SetDeltaX(0);
				Lance->SetDeltaY(-9);
				for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++)
				{
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaY(18);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Lance->SetDeltaX(0);
				Lance->SetDeltaY(9);
				for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++)
				{
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->SetDeltaY(-18);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			Jugador->SetDeltaSpriteX(1);
			bool ok3 = true;
			for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoLance->DameObjetoAnimado(i))) {
					ok3 = false;
					break;
				}
			}
			if (ok3)
			{
				Lance->Mover();
				for (int i = 0; i < ListaZonasNoPasoLance->GetCantidad(); i++)
				{
					ListaZonasNoPasoLance->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();

			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			pokemonlider = 0;
			yapeleo = false;
			yasubio = false;
			yaataco = false;

			for (int i = 0; i < ListaAgatha->GetCantidad(); i++)
			{
				if (ListaLance->DameObjetoAnimado(i)->Getvidaactual() <= ListaLance->DameObjetoAnimado(i)->Getvidamaxima())
					ListaLance->DameObjetoAnimado(i)->Setvidaactual(ListaLance->DameObjetoAnimado(i)->Getvidamaxima());
			}
		}
		if (Estado == 14)
		{
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if ((Debora->GetPosX() == -26) && (Debora->GetPosY() == -76) && (Jugador->GetIndiceSpriteY() == 3) && (medallas[4] == false) && !todosdebi)
				{
					lider = 5;
					Estado = 20;
				}
			}
			if (Debora->GetPosY() == 68 && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 13;
			}
			if (Debora->GetPosY() == -112 && Jugador->GetIndiceSpriteY() == 3) {
				Jugador->SetIndiceSpriteY(3);
				Estado = 15;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Debora->SetDeltaX(8);
				Debora->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++)
				{
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaX(-17);
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Debora->SetDeltaX(-8);
				Debora->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++)
				{
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaX(17);
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Debora->SetDeltaX(0);
				Debora->SetDeltaY(-9);
				for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++)
				{
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaY(18);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Debora->SetDeltaX(0);
				Debora->SetDeltaY(9);
				for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++)
				{
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->SetDeltaY(-18);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			Jugador->SetDeltaSpriteX(1);
			bool ok3 = true;
			for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoDebora->DameObjetoAnimado(i))) {
					ok3 = false;
					break;
				}
			}
			if (ok3)
			{
				Debora->Mover();
				for (int i = 0; i < ListaZonasNoPasoDebora->GetCantidad(); i++)
				{
					ListaZonasNoPasoDebora->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();

			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			pokemonlider = 0;
			yapeleo = false;
			yasubio = false;
			yaataco = false;

			for (int i = 0; i < ListaDebora->GetCantidad(); i++)
			{
				if (ListaDebora->DameObjetoAnimado(i)->Getvidaactual() <= ListaDebora->DameObjetoAnimado(i)->Getvidamaxima())
					ListaDebora->DameObjetoAnimado(i)->Setvidaactual(ListaDebora->DameObjetoAnimado(i)->Getvidamaxima());
			}
		}
		if (Estado == 15)
		{
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if ((Giovanni->GetPosX() == -26) && (Giovanni->GetPosY() == -76) && (Jugador->GetIndiceSpriteY() == 3) && (medallas[5] == false) && !todosdebi)
				{
					lider = 6;
					Estado = 20;
				}
			}
			if (Giovanni->GetPosY() == 68 && (Jugador->GetIndiceSpriteY() == 0)) {
				Jugador->SetIndiceSpriteY(0);
				Estado = 14;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				Giovanni->SetDeltaX(8);
				Giovanni->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++)
				{
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaX(-17);
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(2);
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				Giovanni->SetDeltaX(-8);
				Giovanni->SetDeltaY(0);
				for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++)
				{
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaX(17);
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaY(0);
				}
				Jugador->SetIndiceSpriteY(1);
			}
			if (pTecla == System::Windows::Forms::Keys::Up) {
				Giovanni->SetDeltaX(0);
				Giovanni->SetDeltaY(-9);
				for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++)
				{
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaY(18);
				}
				Jugador->SetIndiceSpriteY(3);
			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				Giovanni->SetDeltaX(0);
				Giovanni->SetDeltaY(9);
				for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++)
				{
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaX(0);
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->SetDeltaY(-18);
				}
				Jugador->SetIndiceSpriteY(0);
			}
			Jugador->SetDeltaSpriteX(1);
			bool ok3 = true;
			for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++){
				if (HabraColision(Jugador, ListaZonasNoPasoGiovanni->DameObjetoAnimado(i))) {
					ok3 = false;
					break;
				}
			}
			if (ok3)
			{
				Giovanni->Mover();
				for (int i = 0; i < ListaZonasNoPasoGiovanni->GetCantidad(); i++)
				{
					ListaZonasNoPasoGiovanni->DameObjetoAnimado(i)->Mover();
				}
			}
			if (Jugador->GetIndiceSpriteX() == 1)
				Jugador->SetIndiceSpriteX(0);
			else
				Jugador->CambiarSprite();

			estadobatalla = 0;
			letras = 0;
			ganador = 0;
			eleccion = 0;
			pokemonlider = 0;
			yapeleo = false;
			yasubio = false;
			yaataco = false;

			for (int i = 0; i < ListaGiovanni->GetCantidad(); i++)
			{
				if (ListaGiovanni->DameObjetoAnimado(i)->Getvidaactual() <= ListaGiovanni->DameObjetoAnimado(i)->Getvidamaxima())
					ListaGiovanni->DameObjetoAnimado(i)->Setvidaactual(ListaGiovanni->DameObjetoAnimado(i)->Getvidamaxima());
			}
		}
		if (Estado == 16)
		{
			if (pTecla == System::Windows::Forms::Keys::C) {
				Estado = 17;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad1) {
				eleccion = 1;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad2) {
				eleccion = 2;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad3) {
				eleccion = 3;
			}
			if (pTecla == System::Windows::Forms::Keys::NumPad4) {
				eleccion = 4;
			}
			if (pTecla == System::Windows::Forms::Keys::Enter) {
				if (estadobatalla == 5)
				{
					debicam = true; estadobatalla = 0; letras = 0;
				}
				if (estadobatalla == 4) Estado = 1;
				letras++;
				if (estadobatalla == 0) estadobatalla = 1;
				if (ganador == 1)
				{
					estadobatalla = 3;
				}
				if (letras == 2 && estadobatalla == 1)
				{
					estadobatalla = 2;
				}
				if (ganador == 2)
				{
					estadobatalla = 3;
				}
				if (letras == 3 && ganador == 1 && estadobatalla == 3)
				{
					if (lider == 1)
					{
						for (int i = 0; i < ListaLorelei->GetCantidad(); i++)
						{
							if (ListaLorelei->DameObjetoAnimado(i)->Getvidaactual() > 0)
							{
								pokemonlider = i;
								debilider = false;
								estadobatalla = 0;
								letras = 0;
								eneleccion = 0;
								yaataco = false;
								eleccion = 0;
								ganador = 0;
								break;
							}
							else debilider = true;
						}
						if (debilider)
						{
							medallas[0] = true;
							lider = 0;
							Estado = 8;
						}
					}
					if (lider == 2)
					{
						for (int i = 0; i < ListaBruno->GetCantidad(); i++)
						{
							if (ListaBruno->DameObjetoAnimado(i)->Getvidaactual() > 0)
							{
								pokemonlider = i;
								debilider = false;
								estadobatalla = 0;
								letras = 0;
								eneleccion = 0;
								yaataco = false;
								eleccion = 0;
								ganador = 0;
								break;
							}
							else debilider = true;
						}
						if (debilider)
						{
							medallas[1] = true;
							lider = 0;
							Estado = 11;
						}
					}
					if (lider == 3)
					{
						for (int i = 0; i < ListaAgatha->GetCantidad(); i++)
						{
							if (ListaAgatha->DameObjetoAnimado(i)->Getvidaactual() > 0)
							{
								pokemonlider = i;
								debilider = false;
								estadobatalla = 0;
								letras = 0;
								eneleccion = 0;
								yaataco = false;
								eleccion = 0;
								ganador = 0;
								break;
							}
							else debilider = true;
						}
						if (debilider)
						{
							medallas[2] = true;
							lider = 0;
							Estado = 12;
						}
					}
					if (lider == 4)
					{
						for (int i = 0; i < ListaLance->GetCantidad(); i++)
						{
							if (ListaLance->DameObjetoAnimado(i)->Getvidaactual() > 0)
							{
								pokemonlider = i;
								debilider = false;
								estadobatalla = 0;
								letras = 0;
								eneleccion = 0;
								yaataco = false;
								eleccion = 0;
								ganador = 0;
								break;
							}
							else debilider = true;
						}
						if (debilider)
						{
							medallas[3] = true;
							lider = 0;
							Estado = 13;
						}
					}
					if (lider == 5)
					{
						for (int i = 0; i < ListaDebora->GetCantidad(); i++)
						{
							if (ListaDebora->DameObjetoAnimado(i)->Getvidaactual() > 0)
							{
								pokemonlider = i;
								debilider = false;
								estadobatalla = 0;
								letras = 0;
								eneleccion = 0;
								yaataco = false;
								eleccion = 0;
								ganador = 0;
								break;
							}
							else debilider = true;
						}
						if (debilider)
						{
							medallas[4] = true;
							lider = 0;
							Estado = 14;
						}
					}
					if (lider == 6)
					{
						for (int i = 0; i < ListaGiovanni->GetCantidad(); i++)
						{
							if (ListaGiovanni->DameObjetoAnimado(i)->Getvidaactual() > 0)
							{
								pokemonlider = i;
								debilider = false;
								estadobatalla = 0;
								letras = 0;
								eneleccion = 0;
								yaataco = false;
								eleccion = 0;
								ganador = 0;
								break;
							}
							else debilider = true;
						}
						if (debilider)
						{
							medallas[5] = true;
							lider = 0;
							Estado = 15;
						}
					}
					yapeleo = true;
				}
				if (letras == 4 && ganador == 2 && estadobatalla == 3)
				{
					if (lider == 1)
					{
						lider = 0;
						Estado = 8;
					}
					if (lider == 2) 
					{
						lider = 0;
						Estado = 11;
					}
					if (lider == 3) 
					{
						lider = 0;
						Estado = 12;
					}
					if (lider == 4)
					{
						lider = 0;
						Estado = 13;
					}
					if (lider == 5)
					{
						lider = 0;
						Estado = 14;
					}
					if (lider == 6)
					{
						lider = 0;
						Estado = 15;
					}
					yapeleo = true;
				}
				if (letras == 3 && estadobatalla != 3)
				{
					estadobatalla = 0;
					letras = 0;
					eneleccion = 0;
					yaataco = false;
					eleccion = 0;
				}
			}
		}
		if (Estado == 17)
		{
			if (pTecla == System::Windows::Forms::Keys::Left) {
				pokemoncambio--;
				if (pokemoncambio < 0) pokemoncambio = ListaMarco->GetCantidad() - 1;
			}
			if (pTecla == System::Windows::Forms::Keys::Right) {
				pokemoncambio++;
				if (pokemoncambio > ListaMarco->GetCantidad() - 1) pokemoncambio = 0;
			}
			if (pTecla == System::Windows::Forms::Keys::Enter) {
				pokemonelegido = pokemoncambio;
				if (ListaMarco->DameObjetoAnimado(pokemonelegido)->Getvidaactual() > 0)
				{
					Estado = 16;
				}
			}
		}
		if (Estado == 18)
		{
			if (pTecla == System::Windows::Forms::Keys::Right) {
				if (indicearriba)
				{
					if (indicepokemonarriba == ListaMarcoPC->GetCantidad() - 1)
					{
						indicepokemonarriba = 0;
					}
					else
						indicepokemonarriba++;
				}
				else
				{
					if (indicepokemonabajo == ListaMarco->GetCantidad() - 1)
					{
						indicepokemonabajo = 0;
					}
					else
						indicepokemonabajo++;
				}
			}
			if (pTecla == System::Windows::Forms::Keys::Left) {
				if (indicearriba)
				{
					if (indicepokemonarriba == 0)
					{
						indicepokemonarriba = ListaMarcoPC->GetCantidad() - 1;
					}
					else
						indicepokemonarriba--;
				}
				else
				{
					if (indicepokemonabajo == 0)
					{
						indicepokemonabajo = ListaMarco->GetCantidad() - 1;
					}
					else
						indicepokemonabajo--;
				}
			}
			if (pTecla == System::Windows::Forms::Keys::Up && ListaMarcoPC->GetCantidad()>0) {
				indicearriba = !indicearriba;
			}
			if (pTecla == System::Windows::Forms::Keys::Down && ListaMarcoPC->GetCantidad()>0) {
				indicearriba = !indicearriba;
			}
			if (pTecla == System::Windows::Forms::Keys::Z && ListaMarcoPC->GetCantidad()>0) {
				Pokemon* Temp = ListaMarco->DameObjetoAnimado(indicepokemonabajo);
				ListaMarco->AgregarPokemonEnPosicion(ListaMarcoPC->DameObjetoAnimado(indicepokemonarriba),indicepokemonabajo);
				ListaMarcoPC->AgregarPokemonEnPosicion(Temp, indicepokemonarriba);
			}
			if (pTecla == System::Windows::Forms::Keys::X) {
				if(cerezo)Estado = 9;
				else Estado = 4;
			}
		}
		if (Estado == 19)
		{
			if (letrasint == 2)
			{
				if (pTecla == System::Windows::Forms::Keys::Up)
				{
					eleinte = !eleinte;
				}
				if (pTecla == System::Windows::Forms::Keys::Down)
				{
					eleinte = !eleinte;
				}
				if (pTecla == System::Windows::Forms::Keys::Enter)
				{
					letrasint++;
				}
			}
			else if (letrasint == 3)
			{
				if (siloti)
				{
					if (pokint == 3)
					{
						for (int i = 0; i < ListaMarco->GetCantidad(); i++)
						{
							if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 23 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 50)
							{
								ListaMarco->AgregarPokemonEnPosicion(ListaIntercambio->DameObjetoAnimado(pokint), i);
								pokint++;
							}
						}
					}
					if (pokint == 2)
					{
						for (int i = 0; i < ListaMarco->GetCantidad(); i++)
						{
							if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 22 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 40)
							{
								ListaMarco->AgregarPokemonEnPosicion(ListaIntercambio->DameObjetoAnimado(pokint), i);
								pokint++;
							}
						}
					}
					if (pokint == 1)
					{
						for (int i = 0; i < ListaMarco->GetCantidad(); i++)
						{
							if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 21 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 30)
							{
								ListaMarco->AgregarPokemonEnPosicion(ListaIntercambio->DameObjetoAnimado(pokint), i);
								pokint++;
							}
						}
					}
					if (pokint == 0)
					{
						for (int i = 0; i < ListaMarco->GetCantidad(); i++)
						{
							if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 20 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 20)
							{
								ListaMarco->AgregarPokemonEnPosicion(ListaIntercambio->DameObjetoAnimado(pokint), i);
								pokint++;
							}
						}
					}
				}

				Estado = 1;
				
			}
			else if (letrasint == 5)
			{
				Estado = 1;
			}
			else if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				letrasint++;
			}
		}
		if (Estado == 21)
		{
			if (pTecla == System::Windows::Forms::Keys::Up) {
				
				if(indice>0)indice--;
				else indice=4;

			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				if (indice<4)indice++;
				else indice=0;
			}
			if (pTecla == System::Windows::Forms::Keys::Enter)
			{
				if (indice == 0)
				{
					Estado = 22;
					indicepokedex = 0;
				}
				if (indice == 4)
				{
					Estado = 1;
				}
			}
		}
		if (Estado == 22)
		{
			if (pTecla == System::Windows::Forms::Keys::Up) {

				if (indicepokedex>0)indicepokedex--;
				else indicepokedex = ListaPokedex->GetCantidad()-1;

			}
			if (pTecla == System::Windows::Forms::Keys::Down) {
				if (indicepokedex<ListaPokedex->GetCantidad() - 1)indicepokedex++;
				else indicepokedex = 0;
			}
			if (pTecla == System::Windows::Forms::Keys::X) {
				Estado = 21;
				indice = 0;
			}
		}
		if (Estado == 23)
		{
			if (pTecla == System::Windows::Forms::Keys::Enter) {

				if (Animacionevo->GetIndiceSpriteX() == 13&& animaevo==true)
				{
					animaevo = false;
					evo = false;
					Estado = 1;
					
				}

			}
		}
}
void Juego::Capturapokemon(System::Drawing::Graphics ^gr, Pokemon* pPokemon)
{
	if (captura == true && pPokemon->Getvidaactual()<=10)
	{
		Pokeballcaptura->Mostrar(gr);
		if (Pokeballcaptura->GetPosX() > 270 && Pokeballcaptura->GetPosY() < 150)
		{
			if (hierba == 0)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Squirtle", /*pPokemon->Getnivel()*/15, pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 2,"Rayo Burbuja", "Placaje", "Pistola de agua", "Arañazo", 15, 15, 15, 15,
					40, 140, 0, 0, 120, 120, 21, true, "squirtleE.png", 0, 0, 0, 0,16);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 1)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Bulbasaur", /*pPokemon->Getnivel()*/15, pPokemon->Getvidamaxima(), 
					pPokemon->Getvidaactual(), 0, 1, "Latigo cepa", "Placaje", "Hoja afilada", "Arañazo", 15, 15, 15, 15,
					40, 140, 0, 0, 120, 120, 20, true, "bulbasaurE.png", 0, 0, 0, 0,16);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 2)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Charmander", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 3,"Giro fuego", "Placaje", "Ascuas", "Arañazo", 15, 15, 15, 15,
					40, 140, 0, 0, 120, 120, 22, true, "charmanderE.png", 0, 0, 0, 0,16);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 3)
			{
				Pokemon* Temp = new Pokemon(20, 20, "Pikachu", pPokemon->Getnivel(), pPokemon->Getvidamaxima(), 
					pPokemon->Getvidaactual(), 0, 4,"Impactrueno", "Placaje", "Rayo", "Arañazo", 15, 15, 15, 15,
					45, 180, 0, 0, 120, 120, 23, true, "pikachuE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 4)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Pidgey", pPokemon->Getnivel(), pPokemon->Getvidamaxima(), 
					pPokemon->Getvidaactual(), 0, 5,"Ataque Ala", "Placaje", "Picotazo", "Arañazo", 15, 15, 15, 15,
					45, 140, 0, 0, 120, 120, 0, true, "pidgeyE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 5)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Riolu", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 7, "Esfera Aural", "Placaje","Patada baja", "Arañazo", 15, 15, 15, 15,
					45, 135, 0, 0, 120, 120, 0, true, "rioluE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 6)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Haunter", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 9, "Tinieblas", "Placaje","Bola sombra", "Arañazo", 15, 15, 15, 15,
					45, 120, 0, 0, 120, 120, 0, true, "haunterE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 7)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Espeon", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 8, "Confusion", "Placaje","Psicorayo", "Arañazo", 15, 15, 15, 15, 
					45, 120, 0, 0, 120, 120, 0, true, "espeonE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 8)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Umbreon", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 10, "Mordisco", "Placaje","Persecucion", "Arañazo", 15, 15, 15, 15, 
					45, 120, 0, 0, 120, 120, 0, true, "umbreonE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 9)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Tyrogue", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 7, "Golpe roca", "Placaje","Ultrapuño", "Arañazo", 15, 15, 15, 15, 
					45, 125, 0, 0, 120, 120, 0, true, "tyrogueE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 10)
			{
				Pokemon* Temp = new Pokemon(100, 100, "Larvitar", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 6, "Terremoto", "Placaje","Magnitud", "Arañazo", 15, 15, 15, 15, 
					40, 130, 0, 0, 120, 120, 0, true, "larvitarE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 11)
			{
				Pokemon* Temp = new Pokemon(80, 80, "Growlithe", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 3, "Lanzallamas", "Placaje","Sofoco", "Arañazo", 15, 15, 15, 15, 
					40, 145, 0, 0, 120, 120, 0, true, "growlitheE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			if (hierba == 12)
			{
				Pokemon* Temp = new Pokemon(70, 70, "Absol", pPokemon->Getnivel(), pPokemon->Getvidamaxima(),
					pPokemon->Getvidaactual(), 0, 11, "Rayo Hielo", "Placaje","Ventisca", "Arañazo", 15, 15, 15, 15,
					40, 135, 0, 0, 120, 120, 0, true, "absolE.png", 0, 0, 0, 0, 0);
				if (ListaMarco->GetCantidad()<5) ListaMarco->AgregaObjetoAnimado(Temp);
				else ListaMarcoPC->AgregaObjetoAnimado(Temp);
			}
			capturas[BuscarPokemonpornombre(ListaSalvajes->DameObjetoAnimado(hierba)->GetNombre(), ListaPokedex)] = true;
			Estado = 1;
			captura = false;
			yapeleo = true;
			hierba = 0;
			Pokeballcaptura->SetPosX(0);
			Pokeballcaptura->SetPosY(200);
		}
	}
	else captura = false;
}
void Juego::BatallaPokemon(System::Drawing::Graphics ^gr, Pokemon* pPokemon, Pokemon* pPokemon2)
{
		Local->Mostrar(gr);
		
		pPokemon->Mostrar(gr);
		pPokemon2->Mostrar(gr);
		gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
		gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Arial", 25);
		Capturapokemon(gr,pPokemon2);
		
		
		if (estadobatalla == 4)
		{
			System::String ^s1 = gcnew System::String(pPokemon2->GetNombre());
			gr->DrawString(System::Convert::ToString("Escapaste del combate"), font, System::Drawing::Brushes::Black, 20, 340);
			gr->DrawString(System::Convert::ToString("con ")+s1, font, System::Drawing::Brushes::Black, 20, 380);
		}
	
		if (estadobatalla == 0)
		{
			MostrarAtaques(gr, pPokemon, eleccion);
		}
		if (estadobatalla == 1)
		{
			Atacar(pPokemon,pPokemon2);
			MostrarAtaqueUsado(gr, pPokemon, pPokemon2, eleccion);
			
			if (Debilitado(pPokemon2) == true)
			{
				ganador = 1;
				if (yasubio == false)
				{
					pPokemon->Setexperiencia(pPokemon->Getexperiencia() + 50);
					if (pPokemon->Getexperiencia() == 50)
					{
						pPokemon->Setnivel(pPokemon->Getnivel() + 1);
						pPokemon->Setexperiencia(0);
						if (pPokemon->Getnivel() == pPokemon->Getevo())
						{

							evo = true;
							indiceevo = BuscarPokemon(pPokemon,ListaMarco);
						}
		
						//EvolucionPokemon(pPokemon);
					}
					yasubio = true;
				}
			}
		}
		if (estadobatalla == 2)
		{
			EnemigoAtaca(pPokemon2, pPokemon);
			MostrarAtaqueUsado(gr, pPokemon2, pPokemon, eneleccion);
			if (pPokemon->Getvidaactual() <= 0)
			{
				debicam = true;
				if (debicam)
				{
					for (int i = 0; i < ListaMarco->GetCantidad(); i++)
					{
						if (Debilitado(ListaMarco->DameObjetoAnimado(i)) == true)
						{
							todosdebi = true;
						}
						else
						{
							todosdebi = false;
							pokemonelegido = i;
							break;
						}
					}
					if (todosdebi)
					{
						ganador = 2;
					}
				}
			}
			
		}
		if (estadobatalla == 3 )
		{
			Ganador(gr);
		}
		
		MostrarVida(gr, 240, 260, pPokemon);
		MostrarVida(gr, 10, 30, pPokemon2);
}
void Juego::BatallaLider(System::Drawing::Graphics ^gr, Pokemon* pPokemon, Pokemon* pPokemon2, int pEstado)
{
	Local->Mostrar(gr);
	pPokemon->Mostrar(gr);
	pPokemon2->Mostrar(gr);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
	
	if (estadobatalla == 0)
	{
		MostrarAtaques(gr, pPokemon, eleccion);
	}
	if (estadobatalla == 1)
	{
		Atacar(pPokemon, pPokemon2);
		MostrarAtaqueUsado(gr, pPokemon, pPokemon2, eleccion);
		if (Debilitado(pPokemon2) == true)
		{
			ganador = 1;
			if (yasubio == false)
			{
				pPokemon->Setexperiencia(pPokemon->Getexperiencia() + 50);
				if (pPokemon->Getexperiencia() == 50)
				{
					pPokemon->Setnivel(pPokemon->Getnivel() + 1);
					pPokemon->Setexperiencia(0);
				}
				yasubio = true;
			}
			
		}
	}
	if (estadobatalla == 2 && Estado==16)
	{
		EnemigoAtaca(pPokemon2, pPokemon);
		MostrarAtaqueUsado(gr, pPokemon2, pPokemon, eneleccion);
		if (pPokemon->Getvidaactual() <= 0)
		{
			debicam = true;
			if (debicam)
			{
				for (int i = 0; i < ListaMarco->GetCantidad(); i++)
				{
					if (Debilitado(ListaMarco->DameObjetoAnimado(i)) == true)
					{
						todosdebi = true;
					}
					else
					{
						todosdebi = false;
						pokemonelegido = i;
						break;
					}
				}
				if (todosdebi)
				{
					ganador = 2;
				}
			}
		}
	}
	if (estadobatalla == 3)
	{
		Ganador(gr);
	}

	MostrarVida(gr, 240, 260, pPokemon);
	MostrarVida(gr, 10, 30, pPokemon2);
}
void Juego::Ganador(System::Drawing::Graphics ^gr)
{
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Arial", 25);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
	if (ganador==1)gr->DrawString(System::Convert::ToString("Ganaste el combate!"), font, System::Drawing::Brushes::Black, 20, 360);
	if (ganador==2)gr->DrawString(System::Convert::ToString("Perdiste el combate!"), font, System::Drawing::Brushes::Black, 20, 360);
}
bool Juego::Debilitado(Pokemon* pPokemon)
{
	if (pPokemon->Getvidaactual() <= 0)
	{	
		pPokemon->Setvidaactual(0);
		return true;
		
	}
}
void Juego::EnemigoAtaca(Pokemon* pPokemon1, Pokemon* pPokemon2)
{
	int temnor = pPokemon1->Getnivel();
	int temefec = pPokemon1->Getnivel() * 2;
	int temnoe;
	if (pPokemon1->Getnivel() % 2 == 0)  temnoe = pPokemon1->Getnivel() / 2;
	if (pPokemon1->Getnivel() % 2 == 1)  temnoe = (pPokemon1->Getnivel() + 1) / 2;
	if (pPokemon1->Gettipo() == 1)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnoe);
	}
	if (pPokemon1->Gettipo() == 2)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnoe);
	}
	if (pPokemon1->Gettipo() == 3)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temefec);
	}
	if (pPokemon1->Gettipo() == 4)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temefec);
	}
	if (pPokemon1->Gettipo() == 5)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 6)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temefec);
	}
	if (pPokemon1->Gettipo() == 7)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 8)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 9)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 10)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 11)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	System::Random ^at = gcnew System::Random(System::DateTime::Now.Ticks);
	if (eneleccion == 0)
	{
		eneleccion = at->Next(0, 5);
		if ((eneleccion == 1) || (eneleccion == 2) || (eneleccion == 3) || (eneleccion == 4))
		{
			pPokemon2->Setvidaactual(pPokemon2->Getvidaactual() - pPokemon1->Getataque());
		}
	}
}
void Juego::Atacar(Pokemon* pPokemon1, Pokemon* pPokemon2)
{
	int temnor = pPokemon1->Getnivel();
	int temefec = pPokemon1->Getnivel()*2;
	int temnoe;
	if (pPokemon1->Getnivel()%2==0)  temnoe = pPokemon1->Getnivel()/2;
	if (pPokemon1->Getnivel() % 2 == 1)  temnoe = (pPokemon1->Getnivel() + 1)/ 2;
	if (pPokemon1->Gettipo() == 1)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnoe);
	}
	if (pPokemon1->Gettipo() == 2)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnoe);
	}
	if (pPokemon1->Gettipo() == 3)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temefec);
	}
	if (pPokemon1->Gettipo() == 4)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temefec);
	}
	if (pPokemon1->Gettipo() == 5)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 6)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temefec);
	}
	if (pPokemon1->Gettipo() == 7)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 8)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 9)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 10)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (pPokemon1->Gettipo() == 11)
	{
		if (pPokemon2->Gettipo() == 1) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 2) pPokemon1->Setataque(temefec);
		if (pPokemon2->Gettipo() == 3) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 4) pPokemon1->Setataque(temnoe);
		if (pPokemon2->Gettipo() == 5) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 6) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 7) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 8) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 9) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 10) pPokemon1->Setataque(temnor);
		if (pPokemon2->Gettipo() == 11) pPokemon1->Setataque(temnor);
	}
	if (yaataco == false)
	{
			if (eleccion == 1)
			{
				pPokemon1->Setataque1(pPokemon1->Getataque1() - 1);
				if (pPokemon1->Getataque1() >= 0)
				{
					pPokemon2->Setvidaactual(pPokemon2->Getvidaactual() - pPokemon1->Getataque());
					sipu = true;
				}
				else
				{
					sipu = false;
					pPokemon1->Setataque1(0);
				}
			}
			if (eleccion == 2)
			{
				pPokemon1->Setataque2(pPokemon1->Getataque2() - 1);
				if (pPokemon1->Getataque2() >= 0)
				{
					pPokemon2->Setvidaactual(pPokemon2->Getvidaactual() - pPokemon1->Getataque());
					sipu = true;
				}
				else
				{
					sipu = false;
					pPokemon1->Setataque2(0);
				}
			}
			if (eleccion == 3)
			{
				pPokemon1->Setataque3(pPokemon1->Getataque3() - 1);
				if (pPokemon1->Getataque3() >= 0)
				{
					pPokemon2->Setvidaactual(pPokemon2->Getvidaactual() - pPokemon1->Getataque());
					sipu = true;
				}
				else
				{
					sipu = false;
					pPokemon1->Setataque3(0);
				}
			}
			if (eleccion == 4)
			{
				pPokemon1->Setataque4(pPokemon1->Getataque4() - 1);
				if (pPokemon1->Getataque4() >= 0)
				{
					pPokemon2->Setvidaactual(pPokemon2->Getvidaactual() - pPokemon1->Getataque());
					sipu = true;
				}
				else
				{
					sipu = false;
					pPokemon1->Setataque4(0);
				}
			}
		yaataco = true;
	}
}
void Juego::MostrarAtaqueUsado(System::Drawing::Graphics ^gr, Pokemon* pPokemon1, Pokemon* pPokemon2, int pataque)
{
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Arial", 25);
	System::String ^s1 = gcnew System::String(pPokemon1->GetNombre());
	System::String ^s2 = gcnew System::String(" utilizo");
	System::String ^s4 = gcnew System::String(pPokemon2->GetNombre());
	
	if (pataque == 0)
	{
		System::String ^s3 = gcnew System::String(pPokemon1->Getnataque1());
		gr->DrawString(s1 + " no ataco", font, System::Drawing::Brushes::Black, 20, 340);
	}
	else
	{
		if (pataque == 1)
		{
			if (pPokemon1->Getataque1() >= 0 && sipu)
			{
				gr->DrawString(System::Convert::ToString("Bajo " + pPokemon1->Getataque() + " HP a ") + s4, font, System::Drawing::Brushes::Black, 20, 380);
				System::String ^s3 = gcnew System::String(pPokemon1->Getnataque1());
				gr->DrawString(s1 + s2 + " " + s3, font, System::Drawing::Brushes::Black, 20, 340);
			}
			else if (pPokemon1->Getataque1() == 0)
			{
				gr->DrawString(s1 + System::Convert::ToString(" no pudo atacar"), font, System::Drawing::Brushes::Black, 20, 340);
				gr->DrawString(System::Convert::ToString("porque no le quedan PP"), font, System::Drawing::Brushes::Black, 20, 380);
				
			}
			
		}
		if (pataque == 2)
		{
			if (pPokemon1->Getataque2() >= 0)
			{
				gr->DrawString(System::Convert::ToString("Bajo " + pPokemon1->Getataque() + " HP a ") + s4, font, System::Drawing::Brushes::Black, 20, 380);
				System::String ^s3 = gcnew System::String(pPokemon1->Getnataque2());
				gr->DrawString(s1 + s2 + " " + s3, font, System::Drawing::Brushes::Black, 20, 340);
			}
			else if(pPokemon1->Getataque2() == 0)
			{
				gr->DrawString(s1 + System::Convert::ToString(" no pudo atacar"), font, System::Drawing::Brushes::Black, 20, 340);
				gr->DrawString(System::Convert::ToString("porque no le quedan PP"), font, System::Drawing::Brushes::Black, 20, 380);
				
			}
		}
		if (pataque == 3)
		{
			if (pPokemon1->Getataque3() >= 0)
			{
				gr->DrawString(System::Convert::ToString("Bajo " + pPokemon1->Getataque() + " HP a ") + s4, font, System::Drawing::Brushes::Black, 20, 380);
				System::String ^s3 = gcnew System::String(pPokemon1->Getnataque3());
				gr->DrawString(s1 + s2 + " " + s3, font, System::Drawing::Brushes::Black, 20, 340);
			}
			else if(pPokemon1->Getataque3() == 0)
			{
				gr->DrawString(s1 + System::Convert::ToString(" no pudo atacar"), font, System::Drawing::Brushes::Black, 20, 340);
				gr->DrawString(System::Convert::ToString("porque no le quedan PP"), font, System::Drawing::Brushes::Black, 20, 380);
				
			}
		}
		if (pataque == 4)
		{
			if (pPokemon1->Getataque3() >= 0)
			{
				gr->DrawString(System::Convert::ToString("Bajo " + pPokemon1->Getataque() + " HP a ") + s4, font, System::Drawing::Brushes::Black, 20, 380);
				System::String ^s3 = gcnew System::String(pPokemon1->Getnataque4());
				gr->DrawString(s1 + s2 + " " + s3, font, System::Drawing::Brushes::Black, 20, 340);
			}
			else if(pPokemon1->Getataque3() == 0)
			{
				gr->DrawString(s1 + System::Convert::ToString(" no pudo atacar"), font, System::Drawing::Brushes::Black, 20, 340);
				gr->DrawString(System::Convert::ToString("porque no le quedan PP"), font, System::Drawing::Brushes::Black, 20, 380);
				
			}
		}
	}
	
}
void Juego::AgregarZonasNoPaso()
{
	Zonas* Temp1 = new Zonas(0,0,95,306,0,0, 20,18,1); //cartel pelea
	Zonas* Temp2 = new Zonas(0, 0, 217, 167, 0, 0, 180, 55, 1); //casa
	Zonas* Temp3 = new Zonas(0, 0, 375, 220, 0, 0, 10, 150, 1);//mar derecha casa
	Zonas* Temp4 = new Zonas(0, 0, 350, 370, 0, 0, 20, 200, 1);//arboles
	Zonas* Temp5 = new Zonas(0, 0, 180, 207, 0, 0, 20, 18, 1); //cartel casa
	Zonas* Temp6 = new Zonas(0, 0, -12, 90, 0, 0, 230, 65, 1); //Laboratorio
	Zonas* Temp7 = new Zonas(0, 0, -43, 140, 0, 0, 20, 18, 1); //Cartel laboratorio
	Zonas* Temp8 = new Zonas(0, 0, -290, 90, 0, 0, 210, 200, 1);//arbol salida
	Zonas* Temp9 = new Zonas(0, 0, -90, 70, 0, 0, 100, 20, 1);//arbol laboratorio
	Zonas* Temp10 = new Zonas(0, 0, -292, 373, 0, 0, 320, 55, 1);//casa1
	Zonas* Temp11 = new Zonas(0, 0, 153, 374, 0, 0, 100, 103, 1);//centropokemon
	Zonas* Temp13 = new Zonas(0, 0, 153, 477, 0, 0, 20, 16, 1);//centropokemon
	Zonas* Temp14 = new Zonas(0, 0, 208, 477, 0, 0, 45, 16, 1);//centropokemon
	Zonas* Temp12 = new Zonas(0, 0, 125, 477, 0, 0, 22, 19, 1); //cartel pelea
	Zonas* Temp15 = new Zonas(0, 0, -100, 575, 0, 0, 500, 19, 1); //arbol limite sur
	Zonas* Temp16 = new Zonas(0, 0, -150, 542, 0, 0, 181, 22, 1); //arbol limite sur2
	Zonas* Temp17 = new Zonas(0, 0, -150, 510, 0, 0, 67, 35, 1); //arbol limite sureste
	Zonas* Temp18 = new Zonas(0, 0, -185, 445, 0, 0, 50, 53, 1); //arbol limite sureste2
	Zonas* Temp19 = new Zonas(0, 0, -292, 380, 0, 0, 50, 150, 1); //arboles zona captura1
	Zonas* Temp20 = new Zonas(0, 0, -460, 512, 0, 0, 200, 100, 1); //arboles zona captura2
	Zonas* Temp21 = new Zonas(0, 0, -575, 575, 0, 0, 150, 60, 1); //arboles zona captura3
	Zonas* Temp22 = new Zonas(0, 0, -578, 175, 0, 0, 130, 85, 1); //arboles zona captura4
	Zonas* Temp23 = new Zonas(0, 0, -445, 175, 0, 0, 150, 50, 1); //arboles zona captura5
	Zonas* Temp24 = new Zonas(0, 0, -630, 235, 0, 0, 130, 55, 1); //arboles zona captura6
	Zonas* Temp25 = new Zonas(0, 0, -590, 290, 0, 0, 8, 210, 1); //muro salto1 parte1
	Zonas* Temp26 = new Zonas(0, 0, -910, 490, 0, 0, 330, 8, 1); //muro salto1 parte2
	Zonas* Temp27 = new Zonas(0, 0, -1100, 640, 0, 0, 560, 8, 1); //limite sur
	Zonas* Temp28 = new Zonas(0, 0, -855, 475, 0, 0, 105, 90, 1); //arbolmurosaltoparte2 1
	Zonas* Temp29 = new Zonas(0, 0, -827, 440, 0, 0, 76, 25, 1); //arbolmurosaltoparte2 2
	Zonas* Temp30 = new Zonas(0, 0, -380, 278, 0, 0, 20, 18, 1); //cartel zona captura
	Zonas* Temp31 = new Zonas(0, 0, -1415, 40, 0, 0, 330, 50, 1); //Limite norte 1
	Zonas* Temp32 = new Zonas(0, 0, -1052, 40, 0, 0, 700, 50, 1); //Limite norte 2
	Zonas* Temp33 = new Zonas(0, 0, -435, 90, 0, 0, 100, 80, 1); //arboles norte
	Zonas* Temp34 = new Zonas(0, 0, -520, 135, 0, 0, 100, 50, 1); //arboles norte 2
	Zonas* Temp35 = new Zonas(0, 0, -970, 70, 0, 0, 220, 90, 1); //arboles norte 3
	Zonas* Temp36 = new Zonas(0, 0, -940, 160, 0, 0, 80, 65, 1); //arboles norte 4
	Zonas* Temp37 = new Zonas(0, 0, -970, 160, 0, 0, 30, 35, 1); //arboles norte 5
	Zonas* Temp38 = new Zonas(0, 0, -1100, 40, 0, 0, 50, 40, 1); //gym
	Zonas* Temp39 = new Zonas(0, 0, -745, 240, 0, 0, 50, 120, 1); //arbusto
	Zonas* Temp40 = new Zonas(0, 0, -1025, 340, 0, 0, 215, 20, 1); //arbol corte
	Zonas* Temp41 = new Zonas(0, 0, -995, 308, 0, 0, 20, 20, 1); //arbol corte2
	Zonas* Temp42 = new Zonas(0, 0, -910, 308, 0, 0, 105, 20, 1); //arbol corte3
	Zonas* Temp43 = new Zonas(0, 0, -1025, 350, 0, 0, 8, 150, 1); //muro salto2 1
	Zonas* Temp44 = new Zonas(0, 0, -1025, 491, 0, 0, 80, 8, 1); //muro salto2 2
	Zonas* Temp45 = new Zonas(0, 0, -1472, 355, 0, 0, 470, 8, 1); //muro salto3 1
	Zonas* Temp46 = new Zonas(0, 0, -1700, 575, 0, 0, 555, 60, 1); //arboles zona captura7
	Zonas* Temp47 = new Zonas(0, 0, -1150, 605, 0, 0, 60, 30, 1); //arboles zona captura8
	Zonas* Temp48 = new Zonas(0, 0, -1274, 90, 0, 0, 133, 37, 1); //gym arboles
	Zonas* Temp49 = new Zonas(0, 0, -1190, 125, 0, 0, 48, 33, 1); //gym arboles2
	Zonas* Temp50 = new Zonas(0, 0, -1162, 158, 0, 0, 20, 32, 1); //gym arboles2
	Zonas* Temp51 = new Zonas(0, 0, -1412, 340, 0, 0, 265, 16, 1); //arbolmurosalto1
	Zonas* Temp52 = new Zonas(0, 0, -1388, 308, 0, 0, 216, 18, 1); //arbolmurosalto2
	Zonas* Temp53 = new Zonas(0, 0, -1300, 240, 0, 0, 70, 50, 1); //arbolmurosalto3
	Zonas* Temp54 = new Zonas(0, 0, -1220, 270, 0, 0, 50, 122, 1); //arbolmurosalto4
	Zonas* Temp55 = new Zonas(0, 0, -1220, 360, 0, 0, 75, 32, 1); //arbolmurosalto5
	Zonas* Temp56 = new Zonas(0, 0, -1220, 360, 0, 0, 22, 130, 1); //arbolmurosalto6
	Zonas* Temp57 = new Zonas(0, 0, -1300, 440, 0, 0, 100, 54, 1); //arbolmurosalto6
	Zonas* Temp58 = new Zonas(0, 0, -1300, 440, 0, 0, 122, 25, 1); //arbolmurosalto6
	Zonas* Temp59 = new Zonas(0, 0, -1328, 410, 0, 0, 70, 25, 1); //arbolmurosalto6
	Zonas* Temp60 = new Zonas(0, 0, -1584, 510, 0, 0, 160, 60, 1); //arbolmurosalto6
	Zonas* Temp61 = new Zonas(0, 0, -1528, 440, 0, 0, 104, 60, 1); //arbolmurosalto6
	Zonas* Temp62 = new Zonas(0, 0, -2424, 40, 0, 0, 302, 118, 1); //arbollimite norte cerezo
	Zonas* Temp63 = new Zonas(0, 0, -2088, 40, 0, 0,718 , 118, 1); //arbollimite norte cerezo
	Zonas* Temp64 = new Zonas(0, 0, -2130, 40, 0, 0, 100, 108, 1); //centropokemon cerezo
	Zonas* Temp65 = new Zonas(0, 0, -2030, 166, 0, 0, 660, 54, 1); //centropokemon cerezo
	Zonas* Temp66 = new Zonas(0, 0, -1972, 302, 0, 0, 265, 260, 1); //arbollimite norte cerezo
	Zonas* Temp67 = new Zonas(0, 0, -2400, 515, 0, 0, 500, 50, 1); //arbollimite sur cerezo
	Zonas* Temp68 = new Zonas(0, 0, -2700, 441, 0, 0, 378, 100, 1); //arbollimite sur cerezo 2
	Zonas* Temp69 = new Zonas(0, 0, -2700, 20, 0, 0, 212, 430, 1); //mar cerezo
	Zonas* Temp70 = new Zonas(0, 0, -2250, 302, 0, 0, 103, 55, 1);//casa1 cerezo
	Zonas* Temp71 = new Zonas(0, 0, -2088, 372, 0, 0, 103, 55, 1);//casa2 cerezo
	Zonas* Temp72 = new Zonas(0, 0, -2520, 20, 0, 0, 100, 38, 1);//hombre intercambio
	Zonas* Temp73 = new Zonas(0, 0, -1584, 150, 0, 0, 8, 200, 1); //muro salto entrada cerezo
	Zonas* Temp74 = new Zonas(0, 0, -1584, 352, 0, 0, 80, 8, 1); //muro salto entrada cerezo
	Zonas* Temp75 = new Zonas(0, 0, -1424, 487, 0, 0, 120, 8, 1); //muro salto2

	ListaZonasNoPaso->AgregaObjetoAnimado(Temp1);ListaZonasNoPaso->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp3);ListaZonasNoPaso->AgregaObjetoAnimado(Temp4);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp5);ListaZonasNoPaso->AgregaObjetoAnimado(Temp6);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp7);ListaZonasNoPaso->AgregaObjetoAnimado(Temp8);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp9);ListaZonasNoPaso->AgregaObjetoAnimado(Temp10);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp11);ListaZonasNoPaso->AgregaObjetoAnimado(Temp12);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp13);ListaZonasNoPaso->AgregaObjetoAnimado(Temp14);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp15);ListaZonasNoPaso->AgregaObjetoAnimado(Temp16);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp17);ListaZonasNoPaso->AgregaObjetoAnimado(Temp18);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp19);ListaZonasNoPaso->AgregaObjetoAnimado(Temp20);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp21);ListaZonasNoPaso->AgregaObjetoAnimado(Temp22);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp23);ListaZonasNoPaso->AgregaObjetoAnimado(Temp24);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp25);ListaZonasNoPaso->AgregaObjetoAnimado(Temp26);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp27);ListaZonasNoPaso->AgregaObjetoAnimado(Temp28);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp29);ListaZonasNoPaso->AgregaObjetoAnimado(Temp30);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp31);ListaZonasNoPaso->AgregaObjetoAnimado(Temp32);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp33);ListaZonasNoPaso->AgregaObjetoAnimado(Temp34);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp35);ListaZonasNoPaso->AgregaObjetoAnimado(Temp36);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp37);ListaZonasNoPaso->AgregaObjetoAnimado(Temp38);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp39);ListaZonasNoPaso->AgregaObjetoAnimado(Temp40);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp41);ListaZonasNoPaso->AgregaObjetoAnimado(Temp42);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp43);ListaZonasNoPaso->AgregaObjetoAnimado(Temp44);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp45);ListaZonasNoPaso->AgregaObjetoAnimado(Temp46);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp47);ListaZonasNoPaso->AgregaObjetoAnimado(Temp48);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp49);ListaZonasNoPaso->AgregaObjetoAnimado(Temp50);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp51);ListaZonasNoPaso->AgregaObjetoAnimado(Temp52);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp53);ListaZonasNoPaso->AgregaObjetoAnimado(Temp54);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp55);ListaZonasNoPaso->AgregaObjetoAnimado(Temp56);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp57);ListaZonasNoPaso->AgregaObjetoAnimado(Temp58);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp59);ListaZonasNoPaso->AgregaObjetoAnimado(Temp60);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp61);ListaZonasNoPaso->AgregaObjetoAnimado(Temp62);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp63);ListaZonasNoPaso->AgregaObjetoAnimado(Temp64);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp65);ListaZonasNoPaso->AgregaObjetoAnimado(Temp66);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp67);ListaZonasNoPaso->AgregaObjetoAnimado(Temp68);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp69);ListaZonasNoPaso->AgregaObjetoAnimado(Temp70);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp71);ListaZonasNoPaso->AgregaObjetoAnimado(Temp72);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp73);ListaZonasNoPaso->AgregaObjetoAnimado(Temp74);
	ListaZonasNoPaso->AgregaObjetoAnimado(Temp75);//ListaZonasNoPaso->AgregaObjetoAnimado(Temp76);
}
void Juego::AgregarZonasNoPasoCentro()
{
	Zonas* Tempo1 = new Zonas(0, 0, 150, 90, 0, 0, 410, 10, 1); //panel
	Zonas* Tempo2 = new Zonas(0, 0, 268, 105, 0, 0, 20, 20, 1); //persona panel
	Zonas* Tempo3 = new Zonas(0, 0, 555, 90, 0, 0, 20, 50, 1); //PC
	Zonas* Tempo4 = new Zonas(0, 0, 520, 205, 0, 0, 60, 60, 1); //arbusto PC
	Zonas* Tempo5 = new Zonas(0, 0, 150, 20, 0, 0, 15, 250, 1); //Limites
	Zonas* Tempo6 = new Zonas(0, 0, 150, 270, 0, 0, 250, 10, 1); //Limites
	Zonas* Tempo7 = new Zonas(0, 0, 170, 253, 0, 0, 55, 10, 1); //Limites
	Zonas* Tempo8 = new Zonas(0, 0, 300, 253, 0, 0, 280, 10, 1); //Limites
	Zonas* Tempo9 = new Zonas(0, 0, 580, 120, 0, 0, 10, 100, 1); //limite PC
	Zonas* Tempo10 = new Zonas(0, 0, 150, 205, 0, 0, 45, 45, 1); //arbusto1
	Zonas* Tempo11 = new Zonas(0, 0, 330, 208, 0, 0, 57, 45, 1); //arbusto2
	Zonas* Tempo12 = new Zonas(0, 0, 458, 198, 0, 0, 20, 15, 1); //persona arbusto
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo1);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo2);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo3);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo4);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo5);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo6);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo7);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo8);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo9);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo10);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo11);
	ListaZonasNoPasoCentro->AgregaObjetoAnimado(Tempo12);
}
void Juego::AgregarZonasNoPasoLorelei()
{
	Zonas* Temp1 = new Zonas(0, 0, 72, -70, 0, 0, 70, 120, 1); 
	Zonas* Temp2 = new Zonas(0, 0, 72, -130, 0, 0, 135, 50, 1);
	Zonas* Temp3 = new Zonas(0, 0, 280, -130, 0, 0, 135, 50, 1);
	Zonas* Temp4 = new Zonas(0, 0, 348, -70, 0, 0, 70, 120, 1);
	Zonas* Temp5 = new Zonas(0, 0, 72, 54, 0, 0, 135, 190, 1);
	Zonas* Temp6 = new Zonas(0, 0, 280, 54, 0, 0, 135, 190, 1);
	Zonas* Temp7 = new Zonas(0, 0, 207, 265, 0, 0, 75, 10, 1);
	Zonas* puerta = new Zonas(0, 0, 207, -134, 0, 0, 75, 10, 1);
	Zonas* lider = new Zonas(0, 0, 252, -70, 0, 0, 20, 5, 1);
	ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp1);ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp3);ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp4);
	ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp5);ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp6);
	ListaZonasNoPasoLorelei->AgregaObjetoAnimado(Temp7); //ListaZonasNoPasoLorelei->AgregaObjetoAnimado(puerta);
	ListaZonasNoPasoLorelei->AgregaObjetoAnimado(lider);

}
void Juego::AgregarZonasNoPasoBruno()
{
	Zonas* Temp1 = new Zonas(0, 0, 72, -70, 0, 0, 70, 120, 1);
	Zonas* Temp2 = new Zonas(0, 0, 72, -130, 0, 0, 135, 50, 1);
	Zonas* Temp3 = new Zonas(0, 0, 280, -130, 0, 0, 135, 50, 1);
	Zonas* Temp4 = new Zonas(0, 0, 348, -70, 0, 0, 70, 120, 1);
	Zonas* Temp5 = new Zonas(0, 0, 72, 54, 0, 0, 135, 190, 1);
	Zonas* Temp6 = new Zonas(0, 0, 280, 54, 0, 0, 135, 190, 1);
	Zonas* Temp7 = new Zonas(0, 0, 207, 265, 0, 0, 75, 10, 1);
	Zonas* puerta = new Zonas(0, 0, 207, -134, 0, 0, 75, 10, 1);
	Zonas* lider = new Zonas(0, 0, 252, -70, 0, 0, 20, 5, 1);
	ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp1); ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp3); ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp4);
	ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp5); ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp6);
	ListaZonasNoPasoBruno->AgregaObjetoAnimado(Temp7); //ListaZonasNoPasoBruno->AgregaObjetoAnimado(puerta);
	ListaZonasNoPasoBruno->AgregaObjetoAnimado(lider);
}
void Juego::AgregarZonasNoPasoAgatha()
{
	Zonas* Temp1 = new Zonas(0, 0, 72, -70, 0, 0, 70, 120, 1);
	Zonas* Temp2 = new Zonas(0, 0, 72, -130, 0, 0, 135, 50, 1);
	Zonas* Temp3 = new Zonas(0, 0, 280, -130, 0, 0, 135, 50, 1);
	Zonas* Temp4 = new Zonas(0, 0, 348, -70, 0, 0, 70, 120, 1);
	Zonas* Temp5 = new Zonas(0, 0, 72, 54, 0, 0, 135, 190, 1);
	Zonas* Temp6 = new Zonas(0, 0, 280, 54, 0, 0, 135, 190, 1);
	Zonas* Temp7 = new Zonas(0, 0, 207, 265, 0, 0, 75, 10, 1);
	Zonas* puerta = new Zonas(0, 0, 207, -134, 0, 0, 75, 10, 1);
	Zonas* lider = new Zonas(0, 0, 252, -70, 0, 0, 20, 5, 1);
	ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp1); ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp3); ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp4);
	ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp5); ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp6);
	ListaZonasNoPasoAgatha->AgregaObjetoAnimado(Temp7); //ListaZonasNoPasoAgatha->AgregaObjetoAnimado(puerta);
	ListaZonasNoPasoAgatha->AgregaObjetoAnimado(lider);
}
void Juego::AgregarZonasNoPasoLance()
{
	Zonas* Temp1 = new Zonas(0, 0, 72, -70, 0, 0, 70, 120, 1);
	Zonas* Temp2 = new Zonas(0, 0, 72, -130, 0, 0, 135, 50, 1);
	Zonas* Temp3 = new Zonas(0, 0, 280, -130, 0, 0, 135, 50, 1);
	Zonas* Temp4 = new Zonas(0, 0, 348, -70, 0, 0, 70, 120, 1);
	Zonas* Temp5 = new Zonas(0, 0, 72, 54, 0, 0, 135, 190, 1);
	Zonas* Temp6 = new Zonas(0, 0, 280, 54, 0, 0, 135, 190, 1);
	Zonas* Temp7 = new Zonas(0, 0, 207, 265, 0, 0, 75, 10, 1);
	Zonas* puerta = new Zonas(0, 0, 207, -134, 0, 0, 75, 10, 1);
	Zonas* lider = new Zonas(0, 0, 252, -70, 0, 0, 20, 5, 1);
	ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp1); ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp3); ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp4);
	ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp5); ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp6);
	ListaZonasNoPasoLance->AgregaObjetoAnimado(Temp7); //ListaZonasNoPasoLance->AgregaObjetoAnimado(puerta);
	ListaZonasNoPasoLance->AgregaObjetoAnimado(lider);
}
void Juego::AgregarZonasNoPasoDebora()
{
	Zonas* Temp1 = new Zonas(0, 0, 72, -70, 0, 0, 70, 120, 1);
	Zonas* Temp2 = new Zonas(0, 0, 72, -130, 0, 0, 135, 50, 1);
	Zonas* Temp3 = new Zonas(0, 0, 280, -130, 0, 0, 135, 50, 1);
	Zonas* Temp4 = new Zonas(0, 0, 348, -70, 0, 0, 70, 120, 1);
	Zonas* Temp5 = new Zonas(0, 0, 72, 54, 0, 0, 135, 190, 1);
	Zonas* Temp6 = new Zonas(0, 0, 280, 54, 0, 0, 135, 190, 1);
	Zonas* Temp7 = new Zonas(0, 0, 207, 265, 0, 0, 75, 10, 1);
	Zonas* puerta = new Zonas(0, 0, 207, -134, 0, 0, 75, 10, 1);
	Zonas* lider = new Zonas(0, 0, 252, -70, 0, 0, 20, 5, 1);
	ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp1); ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp3); ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp4);
	ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp5); ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp6);
	ListaZonasNoPasoDebora->AgregaObjetoAnimado(Temp7); //ListaZonasNoPasoDebora->AgregaObjetoAnimado(puerta);
	ListaZonasNoPasoDebora->AgregaObjetoAnimado(lider);
}
void Juego::AgregarZonasNoPasoGiovanni()
{
	Zonas* Temp1 = new Zonas(0, 0, 72, -70, 0, 0, 70, 120, 1);
	Zonas* Temp2 = new Zonas(0, 0, 72, -130, 0, 0, 343, 50, 1);
	Zonas* Temp4 = new Zonas(0, 0, 348, -70, 0, 0, 70, 120, 1);
	Zonas* Temp5 = new Zonas(0, 0, 72, 54, 0, 0, 135, 190, 1);
	Zonas* Temp6 = new Zonas(0, 0, 280, 54, 0, 0, 135, 190, 1);
	Zonas* Temp7 = new Zonas(0, 0, 207, 265, 0, 0, 75, 10, 1);
	Zonas* lider = new Zonas(0, 0, 252, -70, 0, 0, 20, 5, 1);
	ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(Temp1); ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(Temp2);
	ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(Temp4); ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(Temp5); 
	ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(Temp6); ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(Temp7); 
	ListaZonasNoPasoGiovanni->AgregaObjetoAnimado(lider); 
}
void Juego::AgregarZonasCaptura()
{
	Zonas* Temp1 = new Zonas(0, 0, -575, 375, 0, 0, 100, 190, 2); //zonas captura1
	Zonas* Temp2 = new Zonas(0, 0, -470, 440, 0, 0, 160, 60, 2); //zonas captura2
	Zonas* Temp3 = new Zonas(0, 0, -685, 510, 0, 0, 100, 120, 2); //zonas captura3
	Zonas* Temp4 = new Zonas(0, 0, -687, 310, 0, 0, 50, 120, 2); //zonas captura4
	Zonas* Temp5 = new Zonas(0, 0, -746, 100, 0, 0, 160, 130, 2); //zonas captura5
	Zonas* Temp6 = new Zonas(0, 0, -910, 240, 0, 0, 160, 56, 2); //zonas captura6
	Zonas* Temp7 = new Zonas(0, 0, -1535, 240, 0, 0, 225, 56, 2); //zonas captura7
	Zonas* Temp8 = new Zonas(0, 0, -1695, 445, 0, 0, 100, 120, 2); //zonas captura8

	ListaZonasCaptura->AgregaObjetoAnimado(Temp1);ListaZonasCaptura->AgregaObjetoAnimado(Temp2);
	ListaZonasCaptura->AgregaObjetoAnimado(Temp3);ListaZonasCaptura->AgregaObjetoAnimado(Temp4);
	ListaZonasCaptura->AgregaObjetoAnimado(Temp5);ListaZonasCaptura->AgregaObjetoAnimado(Temp6);
	ListaZonasCaptura->AgregaObjetoAnimado(Temp7);ListaZonasCaptura->AgregaObjetoAnimado(Temp8);
}
void Juego::AgregarPokemonesSalvajes()
{
	Pokemon* SquirtleF = new Pokemon(60, 60, "Squirtle", 5, 100, 100, 0, 2, "Rayo Burbuja", "Placaje", 
		"Pistola de agua", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "squirtleF.png", 0, 0, 0, 0,16);
	Pokemon* BulbasaurF = new Pokemon(60, 60, "Bulbasaur", 5, 100, 100, 0, 1, "Latigo cepa", "Placaje",
		"Hoja afilada", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "bulbasaurF.png", 0, 0, 0, 0,16);
	Pokemon* CharmanderF = new Pokemon(60, 60, "Charmander", 5, 100, 100, 0, 3,"Giro fuego", "Placaje", 
		"Ascuas", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "charmanderF.png", 0, 0, 0, 0,16);
	Pokemon* PikachuF = new Pokemon(60, 60, "Pikachu", 5, 100, 100, 0, 4, "Impactrueno", "Placaje",
		"Rayo", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "pikachuF.png", 0, 0, 0, 0, 0);
	Pokemon* PidgeyF = new Pokemon(60, 60, "Pidgey", 5, 100, 100, 0, 5, "Ataque Ala", "Placaje",
		"Picotazo", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "pidgeyF.png", 0, 0, 0, 0, 0);
	Pokemon* RioluF = new Pokemon(60,60, "Riolu", 5, 100, 100, 0, 7, "Esfera Aural", "Placaje",
		"Patada baja", "Arañazo", 15, 15, 15, 15, 280, 50, 0, 0, 120, 120, 0, true, "rioluF.png", 0, 0, 0, 0, 0);
	Pokemon* HaunterF = new Pokemon(60, 60, "Haunter", 5, 100, 100, 0, 9, "Tinieblas", "Placaje",
		"Bola sombra", "Arañazo", 15, 15, 15, 15, 280, 35, 0, 0, 120, 120, 0, true, "haunterF.png", 0, 0, 0, 0, 0);
	Pokemon* EspeonF = new Pokemon(70, 60, "Espeon", 5, 100, 100, 0, 8, "Confusion", "Placaje",
		"Psicorayo", "Arañazo", 15, 15, 15, 15, 280, 40, 0, 0, 120, 120, 0, true, "espeonF.png", 0, 0, 0, 0, 0);
	Pokemon* UmbreonF = new Pokemon(64, 60, "Umbreon", 5, 100, 100, 0, 10, "Mordisco", "Placaje",
		"Persecucion", "Arañazo", 15, 15, 15, 15, 265, 40, 0, 0, 120, 120, 0, true, "umbreonF.png", 0, 0, 0, 0, 0);
	Pokemon* TyrogueF = new Pokemon(60, 60, "Tyrogue", 5, 100, 100, 0, 7, "Golpe roca", "Placaje",
		"Ultrapuño", "Arañazo", 15, 15, 15, 15, 280, 50, 0, 0, 120, 120, 0, true, "tyrogueF.png", 0, 0, 0, 0, 0);
	Pokemon* LarvitarF = new Pokemon(60, 60, "Larvitar", 5, 100, 100, 0, 6, "Terremoto", "Placaje",
		"Magnitud", "Arañazo", 15, 15, 15, 15, 280, 50, 0, 0, 120, 120, 0, true, "larvitarF.png", 0, 0, 0, 0, 0);
	Pokemon* GrowlitheF = new Pokemon(70, 70, "Growlithe", 5, 100, 100, 0, 3, "Lanzallamas", "Placaje",
		"Sofoco", "Arañazo", 15, 15, 15, 15, 280, 50, 0, 0, 120, 120, 0, true, "growlitheF.png", 0, 0, 0, 0, 0);
	Pokemon* AbsolF = new Pokemon(50, 50, "Absol", 5, 100, 100, 0, 11, "Rayo Hielo", "Placaje",
		"Ventisca", "Arañazo", 15, 15, 15, 15, 280, 40, 0, 0, 120, 120, 0, true, "absolF.png", 0, 0, 0, 0, 0);
	ListaSalvajes->AgregaObjetoAnimado(SquirtleF);
	ListaSalvajes->AgregaObjetoAnimado(BulbasaurF);
	ListaSalvajes->AgregaObjetoAnimado(CharmanderF);
	ListaSalvajes->AgregaObjetoAnimado(PikachuF);
	ListaSalvajes->AgregaObjetoAnimado(PidgeyF);
	ListaSalvajes->AgregaObjetoAnimado(RioluF);
	ListaSalvajes->AgregaObjetoAnimado(HaunterF);
	ListaSalvajes->AgregaObjetoAnimado(EspeonF);
	ListaSalvajes->AgregaObjetoAnimado(UmbreonF);
	ListaSalvajes->AgregaObjetoAnimado(TyrogueF);
	ListaSalvajes->AgregaObjetoAnimado(LarvitarF);
	ListaSalvajes->AgregaObjetoAnimado(GrowlitheF);
	ListaSalvajes->AgregaObjetoAnimado(AbsolF);
}
bool Juego::HabraColision(Objetoanimado* pObjeto1, Objetoanimado* pObjeto2)
{
	System::Drawing::Rectangle obj1 = System::Drawing::Rectangle(pObjeto1->GetPosX() + pObjeto1->GetDeltaX(), pObjeto1->GetPosY() + pObjeto1->GetDeltaY(), pObjeto1->GetAncho(), pObjeto1->GetAlto());
	System::Drawing::Rectangle obj2 = System::Drawing::Rectangle(pObjeto2->GetPosX() + pObjeto2->GetDeltaX(), pObjeto2->GetPosY() + pObjeto2->GetDeltaY(), pObjeto2->GetAncho(), pObjeto2->GetAlto());
	return obj1.IntersectsWith(obj2);
}
bool Juego::HayColision(Objetoanimado* pObjeto1, Objetoanimado* pObjeto2)
{
	System::Drawing::Rectangle obj1 = System::Drawing::Rectangle(pObjeto1->GetPosX(), pObjeto1->GetPosY(), pObjeto1->GetAncho(), pObjeto1->GetAlto());
	System::Drawing::Rectangle obj2 = System::Drawing::Rectangle(pObjeto2->GetPosX(), pObjeto2->GetPosY(), pObjeto2->GetAncho(), pObjeto2->GetAlto());
	return obj1.IntersectsWith(obj2);
}
ArregloObjetoanimado* Juego::DameListaNoPaso()
{
	return ListaZonasNoPaso;
}
void Juego::AgregarListaLorelei()
{
	Pokemon* GeodudeF = new Pokemon(80, 80, "Geodude", 15, 100, 100, 0, 6, "Pedrada", "Placaje",
		"Tumba rocas", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "geodudeF.png", 0, 0, 0, 0, 0);
	Pokemon* OnixF = new Pokemon(60, 60, "Onix", 16, 100, 100, 0, 6, "Cola ferrea", "Placaje",
		"Lanzarrocas", "Arañazo", 15, 15, 15, 15, 270, 40, 0, 0, 120, 120, 0, true, "onixF.png", 0, 0, 0, 0, 0);

	ListaLorelei->AgregaObjetoAnimado(GeodudeF);
	ListaLorelei->AgregaObjetoAnimado(OnixF);
}
void Juego::AgregarListaBruno()
{
	Pokemon* StaryuF = new Pokemon(80, 80, "Staryu", 19, 100, 100, 0, 2, "Pistola de agua", "Placaje",
		"Rayo Burbuja", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "staryuF.png", 0, 0, 0, 0, 0);
	Pokemon* StarmieF = new Pokemon(60, 60, "Starmie", 20, 100, 100, 0, 2, "Hidrobomba", "Placaje",
		"Surf", "Arañazo", 15, 15, 15, 15, 270, 40, 0, 0, 120, 120, 0, true, "starmieF.png", 0, 0, 0, 0, 0);

	ListaBruno->AgregaObjetoAnimado(StaryuF);
	ListaBruno->AgregaObjetoAnimado(StarmieF);
}
void Juego::AgregarListaAgatha()
{
	Pokemon* VoltorbF = new Pokemon(80, 80, "Voltorb", 28, 100, 100, 0, 4, "Trueno", "Placaje",
		"Onda trueno", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "voltorbF.png", 0, 0, 0, 0, 0);
	Pokemon* RaichuF = new Pokemon(60, 60, "Raichu", 30, 100, 100, 0, 4, "Onda voltio", "Placaje",
		"Cola de acero", "Arañazo", 15, 15, 15, 15, 270, 40, 0, 0, 120, 120, 0, true, "raichuF.png", 0, 0, 0, 0, 0);

	ListaAgatha->AgregaObjetoAnimado(VoltorbF);
	ListaAgatha->AgregaObjetoAnimado(RaichuF);
}
void Juego::AgregarListaLance()
{
	Pokemon* GloomF = new Pokemon(80, 80, "Gloom", 34, 100, 100, 0, 1, "Hojas magicas", "Placaje",
		"Drenadoras", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "gloomF.png", 0, 0, 0, 0, 0);
	Pokemon* VictebrellF = new Pokemon(60, 60, "Victebrell", 35, 100, 100, 0, 1, "Hoja aguda", "Placaje",
		"Megaagotar", "Arañazo", 15, 15, 15, 15, 270, 40, 0, 0, 120, 120, 0, true, "victebrellF.png", 0, 0, 0, 0, 0);

	ListaLance->AgregaObjetoAnimado(GloomF);
	ListaLance->AgregaObjetoAnimado(VictebrellF);
}
void Juego::AgregarListaDebora()
{
	Pokemon* TogeticF = new Pokemon(80, 80, "Togetic", 38, 100, 100, 0, 8, "Psiquico", "Placaje",
		"Psicoonda", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "togeticF.png", 0, 0, 0, 0, 0);
	Pokemon* AlakazamF = new Pokemon(60, 60, "Alakazam", 39, 100, 100, 0, 8, "Psicorayo", "Placaje",
		"Metronomo", "Arañazo", 15, 15, 15, 15, 270, 40, 0, 0, 120, 120, 0, true, "alakazamF.png", 0, 0, 0, 0, 0);

	ListaDebora->AgregaObjetoAnimado(TogeticF);
	ListaDebora->AgregaObjetoAnimado(AlakazamF);
}
void Juego::AgregarListaGiovanni()
{
	Pokemon* MoltresF = new Pokemon(80, 80, "Moltres", 41, 100, 100, 0, 3, "Psiquico", "Placaje",
		"Psicoonda", "Arañazo", 15, 15, 15, 15, 280, 60, 0, 0, 120, 120, 0, true, "moltresF.png", 0, 0, 0, 0, 0);
	Pokemon* EnteiF = new Pokemon(60, 60, "Entei", 42, 100, 100, 0, 3, "Psicorayo", "Placaje",
		"Metronomo", "Arañazo", 15, 15, 15, 15, 270, 40, 0, 0, 120, 120, 0, true, "enteiF.png", 0, 0, 0, 0, 0);

	ListaGiovanni->AgregaObjetoAnimado(MoltresF);
	ListaGiovanni->AgregaObjetoAnimado(EnteiF);
}
void Juego::CambioPokemonPC(System::Drawing::Graphics ^gr)
{
	gr->FillRectangle(System::Drawing::Brushes::White, 10, 10, 300, 360);

	gr->DrawRectangle(System::Drawing::Pens::Black, 10, 10, 300, 360);
	gr->DrawRectangle(System::Drawing::Pens::Black, 11, 11, 298, 358);

	gr->DrawLine(System::Drawing::Pens::Black, 10, 150, 310, 150);
	gr->DrawLine(System::Drawing::Pens::Black, 10, 151, 310, 151);

	if (flechas)
	{
		Flechaderechaarriba->Mostrar(gr);
		Flechaderechaabajo->Mostrar(gr);

		Flechaizquierdaarriba->Mostrar(gr);
		Flechaizquierdaabajo->Mostrar(gr);
	}
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 14);
	System::Drawing::Font ^font2 = gcnew System::Drawing::Font("Lucida Sans", 18);
	System::Drawing::Font ^font3 = gcnew System::Drawing::Font("Lucida Sans", 16);
	gr->DrawString(System::Convert::ToString("Z: Intercambiar  X: Salir"), font2, System::Drawing::Brushes::Black, 20, 175);
	gr->DrawLine(System::Drawing::Pens::Black, 10, 229, 310, 229);
	gr->DrawLine(System::Drawing::Pens::Black, 10, 230, 310, 230);
	gr->DrawString(System::Convert::ToString("PC:"), font2, System::Drawing::Brushes::Black, 14, 14);
	gr->DrawString(System::Convert::ToString("Actual:"), font2, System::Drawing::Brushes::Black, 14, 233);
	if (!indicearriba)
	{
		gr->DrawRectangle(System::Drawing::Pens::Red, 12, 231, 296, 137);
		gr->DrawRectangle(System::Drawing::Pens::Red, 13, 232, 294, 135);
	}
	PokeballCambioPCAbajo->Mostrar(gr);
	System::String ^s1 = gcnew System::String(ListaMarco->DameObjetoAnimado(indicepokemonabajo)->GetNombre());
	gr->DrawString(s1, font, System::Drawing::Brushes::Blue, 130, 275);
	gr->DrawString(System::Convert::ToString("Nivel " + ListaMarco->DameObjetoAnimado(indicepokemonabajo)->Getnivel()), font, System::Drawing::Brushes::Blue, 130, 305);
	if (ListaMarcoPC->GetCantidad() > 0)
	{
		if (indicearriba)
		{
			gr->DrawRectangle(System::Drawing::Pens::Red, 12, 12, 296, 137);
			gr->DrawRectangle(System::Drawing::Pens::Red, 13, 13, 294, 135);
		}
		PokeballCambioPCArriba->Mostrar(gr);
		System::String ^s2 = gcnew System::String(ListaMarcoPC->DameObjetoAnimado(indicepokemonarriba)->GetNombre());
		gr->DrawString(s2, font, System::Drawing::Brushes::Blue, 130, 55);
		gr->DrawString(System::Convert::ToString("Nivel " + ListaMarcoPC->DameObjetoAnimado(indicepokemonarriba)->Getnivel()), font, System::Drawing::Brushes::Blue, 130, 85);
	}
	else
	{
		gr->DrawString(System::Convert::ToString("No hay pokemones"), font3, System::Drawing::Brushes::Black, 60, 55);
		gr->DrawString(System::Convert::ToString("en el PC"), font3, System::Drawing::Brushes::Black, 110, 90);
	}
}
void Juego::CambioPokemon(System::Drawing::Graphics ^gr)
{
	gr->FillRectangle(System::Drawing::Brushes::White, 3, 310, 477, 150);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 310, 477, 150);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 311, 475, 148);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 12);
	for (int i = 0; i < ListaMarco->GetCantidad(); i++)
	{
		if (i < 3)
		{
			System::String ^s1 = gcnew System::String(ListaMarco->DameObjetoAnimado(i)->GetNombre());
			gr->DrawString(s1, font, System::Drawing::Brushes::Blue, (150 * i) + 35, 320);
			gr->DrawString(System::Convert::ToString("Nivel " + ListaMarco->DameObjetoAnimado(i)->Getnivel()), font, System::Drawing::Brushes::Blue, (150 * i) + 35, 340);
			gr->DrawString(System::Convert::ToString(ListaMarco->DameObjetoAnimado(i)->Getvidaactual() + "/" + ListaMarco->DameObjetoAnimado(i)->Getvidamaxima()), font, System::Drawing::Brushes::Blue, (150 * i) + 34, 360);
		}
		else
		{
			System::String ^s1 = gcnew System::String(ListaMarco->DameObjetoAnimado(i)->GetNombre());
			gr->DrawString(s1, font, System::Drawing::Brushes::Blue, (160 * (i-3)) + 100, 395);
			gr->DrawString(System::Convert::ToString("Nivel " + ListaMarco->DameObjetoAnimado(i)->Getnivel()), font, System::Drawing::Brushes::Blue, (160 * (i - 3)) + 100, 415);
			gr->DrawString(System::Convert::ToString(ListaMarco->DameObjetoAnimado(i)->Getvidaactual() + "/" + ListaMarco->DameObjetoAnimado(i)->Getvidamaxima()), font, System::Drawing::Brushes::Blue, (160 * (i - 3)) + 99, 435);
		}
	}
	if (pokemoncambio == 0){ Pokeballcambio->SetPosX(130); Pokeballcambio->SetPosY(340); }
	if (pokemoncambio == 1){ Pokeballcambio->SetPosX(275); Pokeballcambio->SetPosY(340); }
	if (pokemoncambio == 2){ Pokeballcambio->SetPosX(420); Pokeballcambio->SetPosY(340); }
	if (pokemoncambio == 3){ Pokeballcambio->SetPosX(195); Pokeballcambio->SetPosY(410); }
	if (pokemoncambio == 4){ Pokeballcambio->SetPosX(350); Pokeballcambio->SetPosY(410); }
		
	Pokeballcambio->Mostrar(gr);
}
void Juego::MostrarPokemonesactuales(System::Drawing::Graphics ^gr)
{
	gr->FillRectangle(System::Drawing::SystemBrushes::ButtonFace, 0, 385, 480, 80);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 388, 477, 69);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 389, 475, 67);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
	for (int i = 0; i < ListaMarco->GetCantidad(); i++)
	{
		System::String ^s1 = gcnew System::String(ListaMarco->DameObjetoAnimado(i)->GetNombre());
		gr->DrawString(s1, font, System::Drawing::Brushes::Blue, (90 * i) + 15, 400);
		gr->DrawString(System::Convert::ToString("Nivel " + ListaMarco->DameObjetoAnimado(i)->Getnivel()), font, System::Drawing::Brushes::Blue, (90 * i) + 14, 415);
		gr->DrawString(System::Convert::ToString(ListaMarco->DameObjetoAnimado(i)->Getvidaactual() + "/" + ListaMarco->DameObjetoAnimado(i)->Getvidamaxima()), font, System::Drawing::Brushes::Blue, (90 * i) + 11, 430);
	}
}
void Juego::MostrarMedallas(System::Drawing::Graphics ^gr)
{
	gr->FillRectangle(System::Drawing::SystemBrushes::ButtonFace, 0, 2, 485, 77);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 5, 477, 69);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 6, 475, 67);
	
	if( medallas[0])Medalla1->Mostrar(gr);
	if (medallas[1])Medalla2->Mostrar(gr);
	if (medallas[2])Medalla3->Mostrar(gr);
	if (medallas[3])Medalla4->Mostrar(gr);
	if (medallas[4])Medalla5->Mostrar(gr);
	if (medallas[5])Medalla6->Mostrar(gr);
}
void Juego::AgregarEtiquetas()
{
	PokemonEleccion* Planta = new PokemonEleccion(-10, -5, 0, 0, 0,0 , 64, 28, 1, true, "plantaE.png", 0, 0, 0, 0);
	PokemonEleccion* Agua = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "aguaE.png", 0, 0, 0, 0);
	PokemonEleccion* Fuego = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "fuegoE.png", 0, 0, 0, 0);
	PokemonEleccion* Electrico = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "electricoE.png", 0, 0, 0, 0);
	PokemonEleccion* Volador = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "voladorE.png", 0, 0, 0, 0);
	PokemonEleccion* Roca = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "rocaE.png", 0, 0, 0, 0);
	PokemonEleccion* Lucha = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "luchaE.png", 0, 0, 0, 0);
	PokemonEleccion* Psiquico = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "psiquicoE.png", 0, 0, 0, 0);
	PokemonEleccion* Fantasma = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "fantasmaE.png", 0, 0, 0, 0);
	PokemonEleccion* Siniestro = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "siniestroE.png", 0, 0, 0, 0);
	PokemonEleccion* Hielo = new PokemonEleccion(-10, -5, 0, 0, 0, 0, 64, 28, 1, true, "hieloE.png", 0, 0, 0, 0);
	
	Etiquetatipos->AgregaObjetoAnimado(Planta);
	Etiquetatipos->AgregaObjetoAnimado(Agua);
	Etiquetatipos->AgregaObjetoAnimado(Fuego);
	Etiquetatipos->AgregaObjetoAnimado(Electrico);
	Etiquetatipos->AgregaObjetoAnimado(Volador);
	Etiquetatipos->AgregaObjetoAnimado(Roca);
	Etiquetatipos->AgregaObjetoAnimado(Lucha);
	Etiquetatipos->AgregaObjetoAnimado(Psiquico);
	Etiquetatipos->AgregaObjetoAnimado(Fantasma);
	Etiquetatipos->AgregaObjetoAnimado(Siniestro);
	Etiquetatipos->AgregaObjetoAnimado(Hielo);
}
void Juego::Intercambiopokemon(System::Drawing::Graphics ^gr)
{
	gr->FillRectangle(System::Drawing::Brushes::White, 3, 350, 477, 110);
	gr->DrawRectangle(System::Drawing::Pens::Black, 3, 350, 477, 110);
	gr->DrawRectangle(System::Drawing::Pens::Black, 4, 351, 475, 108);
	System::Drawing::Font ^font = gcnew System::Drawing::Font("Arial",25);
	System::String ^s1 = gcnew System::String(ListaIntercambio->DameObjetoAnimado(pokint)->GetNombre());
	if (letrasint == 1)
	{
		gr->DrawString(System::Convert::ToString("Hola Marco, tengo un ")+s1, font, System::Drawing::Brushes::Black, 15, 365);
		gr->DrawString(System::Convert::ToString("a nivel ") + ListaIntercambio->DameObjetoAnimado(pokint)->Getnivel()+ System::Convert::ToString(". . ."), font, System::Drawing::Brushes::Black, 15, 410);
	}
	if (letrasint == 2)
	{
		gr->DrawString(System::Convert::ToString("Te gustaria intercambiarlo por"), font, System::Drawing::Brushes::Black, 15, 365);
		
		if(pokint==0) gr->DrawString(System::Convert::ToString("un Bulbasaur a nivel 20?"), font, System::Drawing::Brushes::Black, 15, 410);
		if (pokint == 1) gr->DrawString(System::Convert::ToString("un Squirtle a nivel 30?"), font, System::Drawing::Brushes::Black, 15, 410);
		if (pokint == 2) gr->DrawString(System::Convert::ToString("un Charmander a nivel 40?"), font, System::Drawing::Brushes::Black, 15, 410);
		if (pokint == 3) gr->DrawString(System::Convert::ToString("un Pikachu a nivel 50?"), font, System::Drawing::Brushes::Black, 15, 410);
		gr->FillRectangle(System::Drawing::Brushes::White, 380, 240, 100, 100);
		gr->DrawRectangle(System::Drawing::Pens::Black, 380, 240, 100, 100);
		gr->DrawRectangle(System::Drawing::Pens::Black, 381, 241, 98, 98);
		gr->DrawString(System::Convert::ToString("Si"), font, System::Drawing::Brushes::Black, 420, 250);
		gr->DrawString(System::Convert::ToString("No"), font, System::Drawing::Brushes::Black, 420, 290);
		int px;
		int py;
		if (eleinte)
		{
			px = 405; py = 260;
		}
		if (!eleinte)
		{
			px = 405; py = 300;
		}
		System::Drawing::Point Point1 = System::Drawing::Point(px, py);
		System::Drawing::Point Point2 = System::Drawing::Point(px+10, py+10);
		System::Drawing::Point Point3 = System::Drawing::Point(px, py+20);
		array<System::Drawing::Point> ^points = { Point1, Point2, Point3 };
		gr->DrawPolygon(System::Drawing::Pens::Black, points);
	}
	if (letrasint == 3)
	{
		if (eleinte)
		{
			siloti = false;
			if (pokint == 0)
			{
				for (int i=0; i < ListaMarco->GetCantidad(); i++)
				{
					if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 20 && ListaMarco->DameObjetoAnimado(i)->Getnivel()==20)
					{
						siloti = true;
					}
				}
			}
			if (pokint == 1)
			{
				for (int i = 0; i < ListaMarco->GetCantidad(); i++)
				{
					if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 21 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 30)
					{
						siloti = true;
					}
				}
			}
			if (pokint == 2)
			{
				for (int i = 0; i < ListaMarco->GetCantidad(); i++)
				{
					if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 22 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 40)
					{
						siloti = true;
					}
				}
			}
			if (pokint == 3)
			{
				for (int i = 0; i < ListaMarco->GetCantidad(); i++)
				{
					if (ListaMarco->DameObjetoAnimado(i)->GetTipo() == 23 && ListaMarco->DameObjetoAnimado(i)->Getnivel() == 50)
					{
						siloti = true;
					}
				}
			}
			if (!siloti)
			{
				gr->DrawString(System::Convert::ToString("Lo siento no tienes uno"), font, System::Drawing::Brushes::Black, 15, 365);
				gr->DrawString(System::Convert::ToString("vuelve cuando tengas uno"), font, System::Drawing::Brushes::Black, 15, 410);
			}
			if (siloti)
			{
				gr->DrawString(System::Convert::ToString("Gracias por el cambio"), font, System::Drawing::Brushes::Black, 15, 365);
				gr->DrawString(System::Convert::ToString("vuelve cuando quieras"), font, System::Drawing::Brushes::Black, 15, 410);
				
			}
		}
		if (!eleinte)
		{
			gr->DrawString(System::Convert::ToString("Si quiere algun cambio"), font, System::Drawing::Brushes::Black, 15, 365);
			gr->DrawString(System::Convert::ToString("vuelve cuando quieras"), font, System::Drawing::Brushes::Black, 15, 410);
		}

	}
	
}
void Juego::AgregarListaIntercambio()
{
	Pokemon* MoltresE = new Pokemon(80, 80, "Moltres", 50, 100, 100, 0, 3, "Lanzallamas", "Placaje",
		"Llamarada", "Arañazo", 15, 15, 15, 15, 45, 145, 0, 0, 120, 120, 0, true, "MoltresE.png", 0, 0, 0, 0, 0);
	Pokemon* MewtwoE = new Pokemon(80, 80, "Mewtwo", 50, 100, 100, 0, 8, "Confusion", "Placaje",
		"Psicorayo", "Arañazo", 15, 15, 15, 15, 45, 145, 0, 0, 120, 120, 0, true, "mewtwoE.png", 0, 0, 0, 0, 0);
	Pokemon* RegirockE = new Pokemon(80, 80, "Regirock", 50, 100, 100, 0, 6, "Pedrada", "Placaje",
		"Terremoto", "Arañazo", 15, 15, 15, 15, 45, 135, 0, 0, 120, 120, 0, true, "regirockE.png", 0, 0, 0, 0, 0);
	Pokemon* ArceusE = new Pokemon(80, 80, "Arceus", 50, 100, 100, 0, 8, "Hiperrayo", "Placaje",
		"Psiquico", "Arañazo", 15, 15, 15, 15, 45, 120, 0, 0, 120, 120, 0, true, "arceusE.png", 0, 0, 0, 0, 0);
	ListaIntercambio->AgregaObjetoAnimado(MoltresE);
	ListaIntercambio->AgregaObjetoAnimado(MewtwoE);
	ListaIntercambio->AgregaObjetoAnimado(RegirockE);
	ListaIntercambio->AgregaObjetoAnimado(ArceusE);
}
void Juego::AgregarListaPokedex() {
	Pokemon* SquirtleF2 = new Pokemon(90, 90, "Squirtle", 5, 100, 100, 0, 2, "Rayo Burbuja", "Placaje",
		"Pistola de agua", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "squirtleF.png", 0, 0, 0, 0,16);
	Pokemon* WartortleF2 = new Pokemon(90, 90, "Wartortle", 5, 100, 100, 0, 2, "Salpicar", "Placaje",
		"Cascada", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "wartortleF.png", 0, 0, 0, 0, 36);
	Pokemon* BlastoiseF2 = new Pokemon(90, 90, "Blastoise", 5, 100, 100, 0, 2, "Hidrobomba", "Placaje",
		"Hidropulso", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "blastoiseF.png", 0, 0, 0, 0, 0);
	Pokemon* BulbasaurF2 = new Pokemon(90, 90, "Bulbasaur", 5, 100, 100, 0, 1, "Latigo cepa", "Placaje",
		"Hoja afilada", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "bulbasaurF.png", 0, 0, 0, 0, 16);
	Pokemon* IvysaurF2 = new Pokemon(90, 90, "Ivysaur", 16, 100, 100, 0, 1, "Hierba lazo", "Placaje",
		"Hoja magica", "Arañazo", 15, 15, 15, 15, 10, 20, 0, 0, 120, 120, 0, true, "ivysaurF.png", 0, 0, 0, 0, 36);
	Pokemon* VenusaurF2 = new Pokemon(90, 90, "Venusaur", 16, 100, 100, 0, 1, "Hoja aguda", "Placaje",
		"Latigazo", "Arañazo", 15, 15, 15, 15, 10, 20, 0, 0, 120, 120, 0, true, "venusaurF.png", 0, 0, 0, 0, 0);
	Pokemon* CharmanderF2 = new Pokemon(90, 90, "Charmander", 5, 100, 100, 0, 3, "Giro fuego", "Placaje",
		"Ascuas", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "charmanderF.png", 0, 0, 0, 0, 16);
	Pokemon* CharmeleonF2 = new Pokemon(90, 90, "Charmeleon", 5, 100, 100, 0, 3, "Sofoco", "Placaje",
		"Humareda", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "CharmeleonF.png", 0, 0, 0, 0, 18);
	Pokemon* CharizardF2 = new Pokemon(50, 50, "Charizard", 5, 100, 100, 0, 3, "Lanzallamas", "Placaje",
		"FuegoFatuo", "Arañazo", 15, 15, 15, 15, 15, 30, 0, 0, 137, 120, 0, true, "CharizardF.png", 0, 0, 0, 0, 36);
	Pokemon* PikachuF2 = new Pokemon(90, 90, "Pikachu", 5, 100, 100, 0, 4, "Impactrueno", "Placaje",
		"Rayo", "Arañazo", 15, 15, 15, 15, 15, 20, 0, 0, 120, 120, 0, true, "pikachuF.png", 0, 0, 0, 0,0);
	Pokemon* PidgeyF2 = new Pokemon(90, 90, "Pidgey", 5, 100, 100, 0, 5, "Ataque Ala", "Placaje",
		"Picotazo", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "pidgeyF.png", 0, 0, 0, 0,0);
	Pokemon* RioluF2 = new Pokemon(90, 90, "Riolu", 5, 100, 100, 0, 7, "Esfera Aural", "Placaje",
		"Patada baja", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "rioluF.png", 0, 0, 0, 0,0);
	Pokemon* HaunterF2 = new Pokemon(90, 90, "Haunter", 5, 100, 100, 0, 9, "Tinieblas", "Placaje",
		"Bola sombra", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "haunterF.png", 0, 0, 0, 0,0);
	Pokemon* EspeonF2 = new Pokemon(90, 90, "Espeon", 5, 100, 100, 0, 8, "Confusion", "Placaje",
		"Psicorayo", "Arañazo", 15, 15, 15, 15, 10, 15, 0, 0, 120, 120, 0, true, "espeonF.png", 0, 0, 0, 0, 0);
	Pokemon* UmbreonF2 = new Pokemon(90, 90, "Umbreon", 5, 100, 100, 0, 10, "Mordisco", "Placaje",
		"Persecucion", "Arañazo", 15, 15, 15, 15, 0, 15, 0, 0, 120, 120, 0, true, "umbreonF.png", 0, 0, 0, 0, 0);
	Pokemon* TyrogueF2 = new Pokemon(90, 90, "Tyrogue", 5, 100, 100, 0, 7, "Golpe roca", "Placaje",
		"Ultrapuño", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "tyrogueF.png", 0, 0, 0, 0, 0);
	Pokemon* LarvitarF2 = new Pokemon(90, 90, "Larvitar", 5, 100, 100, 0, 6, "Terremoto", "Placaje",
		"Magnitud", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "larvitarF.png", 0, 0, 0, 0, 0);
	Pokemon* GrowlitheF2 = new Pokemon(90, 90, "Growlithe", 5, 100, 100, 0, 3, "Lanzallamas", "Placaje",
		"Sofoco", "Arañazo", 15, 15, 15, 15, 10, 25, 0, 0, 120, 120, 0, true, "growlitheF.png", 0, 0, 0, 0, 0);
	Pokemon* AbsolF2 = new Pokemon(80, 70, "Absol", 5, 100, 100, 0, 11, "Rayo Hielo", "Placaje",
		"Ventisca", "Arañazo", 15, 15, 15, 15, 0, 20, 0, 0, 120, 120, 0, true, "absolF.png", 0, 0, 0, 0, 0);
	ListaPokedex->AgregaObjetoAnimado(SquirtleF2);
	ListaPokedex->AgregaObjetoAnimado(WartortleF2);
	ListaPokedex->AgregaObjetoAnimado(BlastoiseF2);
	ListaPokedex->AgregaObjetoAnimado(BulbasaurF2);
	ListaPokedex->AgregaObjetoAnimado(IvysaurF2);
	ListaPokedex->AgregaObjetoAnimado(VenusaurF2);
	ListaPokedex->AgregaObjetoAnimado(CharmanderF2);
	ListaPokedex->AgregaObjetoAnimado(CharmeleonF2);
	ListaPokedex->AgregaObjetoAnimado(CharizardF2);
	ListaPokedex->AgregaObjetoAnimado(PikachuF2);
	ListaPokedex->AgregaObjetoAnimado(PidgeyF2);
	ListaPokedex->AgregaObjetoAnimado(RioluF2);
	ListaPokedex->AgregaObjetoAnimado(HaunterF2);
	ListaPokedex->AgregaObjetoAnimado(EspeonF2);
	ListaPokedex->AgregaObjetoAnimado(UmbreonF2);
	ListaPokedex->AgregaObjetoAnimado(TyrogueF2);
	ListaPokedex->AgregaObjetoAnimado(LarvitarF2);
	ListaPokedex->AgregaObjetoAnimado(GrowlitheF2);
	ListaPokedex->AgregaObjetoAnimado(AbsolF2);
}
Juego::~Juego()
{
	delete Jugador;
	delete Terreno;
	delete Local;
	delete Centropokemon;
	delete Lorelei;
	delete Bruno;
	delete Agatha;
	delete Lance;
	delete Debora;
	delete Giovanni;

	delete PikachuE;
	delete SquirtleE;
	delete CharmanderE;
	delete BulbasaurE;
	delete Pokeball;
	delete Pokeballcaptura;
	delete Pokeballcambio;
	delete PokeballCambioPCArriba;
	delete PokeballCambioPCAbajo;
	delete Flechaderechaarriba;
	delete Flechaderechaabajo;
	delete Flechaizquierdaarriba;
	delete Flechaizquierdaabajo;

	delete[]ListaZonasNoPaso;
	delete[]ListaZonasNoPasoCentro;
	delete[]ListaZonasCaptura;
	delete[]ListaZonasNoPasoLorelei;
	delete[]ListaZonasNoPasoBruno;
	delete[]ListaZonasNoPasoAgatha;
	delete[]ListaZonasNoPasoLance;
	delete[]ListaZonasNoPasoDebora;
	delete[]ListaZonasNoPasoGiovanni;
	delete[]Etiquetatipos;
	delete[]ListaMarco;
	delete[]ListaMarcoPC;
	delete[]ListaSalvajes;
	delete[]ListaLorelei;
	delete[]ListaBruno;
	delete[]ListaAgatha;
	delete[]ListaLance;
	delete[]ListaDebora;
	delete[]ListaGiovanni;
}