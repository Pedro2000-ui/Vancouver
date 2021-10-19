#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA, SPACE };

void  jogador(pos_x, pos_y) {

	//al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 255, 0));
	//n�o consegui colocar o draw_bitmap dentro da fun��o, ai est� l� no final, se algu�m conseguir substituir pode fazer.
}

void inimigos(int pos_xEnemys[], int pos_yEnemys[], int vidasInimigos[]) {
	//for (int i = 0; i < 3; i++)
	//{
		//al_draw_filled_rectangle(pos_xEnemys[i], pos_yEnemys[0], pos_xEnemys[i] + 30, pos_yEnemys[0] + 30, al_map_rgb(0, 255, 0));
	//}
	//mesma coisa para os inimigos, o draw_bitmap, est� l� na parte de baixo.

	//ideia de colocar condi��es onde caso o inimigo morra a imagem daquele inimigo que morreu � destruida e desaparece do mapa
}

void menu() {
	bool teclas[] = { false, false, false, false };

	bool fim = false;

	ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;

	al_install_keyboard();
	al_init_image_addon();

	fila_eventos = al_create_evente_queue();

	al_register_event_source(fila_eventos, al_get_keyboard_event_source());

	while (!fim) {

		ALLEGRO_DISPLAY* janela = NULL;

		ALLEGRO_BITMAP* imagem = NULL;

		al_init();
		al_init_image_addon();

		janela = al_create_display(800, 600);

		imagem = al_load_bitmap("background.png");

		al_draw_bitmap(imagem, 0, 0, 0);

		al_flip_display();


		ALLEGRO_EVENT ev;

		al_wait_for_event(fila_eventos, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				fim = true;
			}
		}

	}

	al_destroy_event_queue(fila_eventos);
}
//MAIN
int main() {

	const int largura_tela = 800, altura_tela = 600; //Define altura e largura do prot�tipo da tela;
	bool x = true; //Vari�vel que ser� usada para movimenta��o dos inimigos com o intuito de evitar conflitos
	bool fim = false; //vari�vel apenas pra idenficar o fim do jogo futuramente;
	bool teclas[] = { false, false, false, false, false };
	//Posi��o que iniciar� o jogador;
	int pos_xJogador = 150, pos_yJogador = 550;
	//Variaveis para uso dos tiros que sair�o do Jogador
	int pos_yTiroJogador = pos_yJogador;
	int pos_xTiroJogador = pos_xJogador;
	bool tiroAcertouInimigo = false;
	//Regi�o que os inimigos atacar�o ao visualizarem o jogador
	int regiaoDeAtaque = 400;
	//Posi��es que os inimigos iniciar�o;
	int pos_xEnemys[] = { 50, 250, 450 }, pos_yEnemys[] = { 90 }; //ter� mais posi��es em Y para inimigos vindo das laterais
	//Variaveis para uso dos tiros que sair�o dos Inimigos
	int pos_yTiro[3];
	int pos_xTiro[3];
	for (int i = 0; i < 3; i++) {
		pos_xTiro[i] = pos_xEnemys[i]; //recebe as posi��es iniciais de XEnemys e YEnemys, pois os tiros saem dos inimigos n�!!!
		pos_yTiro[i] = pos_yEnemys[0];
	}
	bool primeiroTiro = true, tiroAcertou = false;
	//Vari�vel para velocidade de rodagem do jogo
	int FPS = 60;
	//Vari�vel para vidas do jogador;
	int vidasJogador = 8;
	//Vari�vel para vidas dos inimigos;
	int vidasInimigos[3] = { 5, 5, 5 };

	//TELA DO JOGO
	al_init();
	ALLEGRO_DISPLAY* display = 0; //criando tela do jogo com ponteiro fazendo refer�ncia em ALLEGRO_DISPLAY;
	display = al_create_display(largura_tela, altura_tela); //fun��o que cria um display (eixo x, eixo y);

	//INICIALIZA��O DE TEMPORIZADOR
	ALLEGRO_TIMER* timer = 0;

	//VARIAVEL DA IMAGEM
	ALLEGRO_BITMAP* imagem = NULL;
	ALLEGRO_BITMAP* player = NULL;
	ALLEGRO_BITMAP* enemy = NULL;

	//INICIALIZA��O DE ADDONS
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();

	timer = al_create_timer(1.5 / FPS);

	//INICIALIZA��O DE EVENTOS
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois n�o h� eventos ainda);
	fila_eventos = al_create_event_queue(); //fun��o para guardar os eventos gerados dentro da vari�vel "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(display)); //eventos de display 
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer

	al_start_timer(timer);

	//CARREGAR IMAGENS
	imagem = al_load_bitmap("sprites/mapa1.png");
	player = al_load_bitmap("sprites/playerup.png");
	enemy = al_load_bitmap("sprites/enemydown.png");

	while (fim == false && vidasJogador > 0) {
		//JOGADOR
		jogador(pos_xJogador, pos_yJogador);

		//INIMIGOS
		inimigos(pos_xEnemys, pos_yEnemys, vidasInimigos);

		printf("    | %d __ %d |    ", pos_xJogador, pos_yJogador);

		ALLEGRO_EVENT ev; //variavel para usarmos para verificar a situa��o dos eventos
		al_wait_for_event(fila_eventos, &ev); //verifica se algum evento foi detectado, se sim avan�a pra pr�xima linha, sen�o n�o continua o loop - �til para evitar uso de mem�ria indevido
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			fim = true;
		}
		//MOVIMENTOS DO JOGADOR E DOS INIMIGOS
		else {
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {//ALLEGRO_EVENT_KEY_UP -> O UP executa apenas quando soltarmos a tecla
			//ev type = verifica o TIPO de evento (pelo teclado, pelo mouse, joystick e etc, nesse if est� verificando se o tipo � igual h� um evento de teclado, por isso o ALLEGRO_EVENT_KEY_DOWN
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { //verifica se o evento do tipo teclado e o seu c�digo(qual tecla �) no casso desse if, est� verificando se � igual a tecla ESCAPE (o famoso ESC)
					fim = true;
				}

				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					teclas[CIMA] = true;
					break;
				case ALLEGRO_KEY_DOWN:
					teclas[BAIXO] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					teclas[DIREITA] = true;
					break;
				case ALLEGRO_KEY_LEFT:
					teclas[ESQUERDA] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					teclas[SPACE] = true;
					break;
				}

			}

			else {
				if (ev.type == ALLEGRO_EVENT_KEY_UP) {//ALLEGRO_EVENT_KEY_UP -> O UP executa apenas quando soltarmos a tecla
				//ev type = verifica o TIPO de evento (pelo teclado, pelo mouse, joystick e etc, nesse if est� verificando se o tipo � igual h� um evento de teclado, por isso o ALLEGRO_EVENT_KEY_DOWN
					switch (ev.keyboard.keycode) {
					case ALLEGRO_KEY_UP:
						teclas[CIMA] = false;
						break;
					case ALLEGRO_KEY_DOWN:
						teclas[BAIXO] = false;
						break;
					case ALLEGRO_KEY_RIGHT:
						teclas[DIREITA] = false;
						break;
					case ALLEGRO_KEY_LEFT:
						teclas[ESQUERDA] = false;
						break;
					}

				}

				else {
					if (ev.type == ALLEGRO_EVENT_TIMER) { //Qualquer movimento dentro desse if roda nas especifica��es do timer (segundos/fps)
						if (pos_yEnemys[0] <= 250 && x == true) { //Bloco de controle da movimenta��o dos inimigos
							if (pos_yJogador <= regiaoDeAtaque) {
								if (pos_yEnemys[0] <= 215) {
									pos_yEnemys[0] -= 1;  //entra em conflito com pos_yEnemys += 2 e os inimigos andam de uma em uma casa
								}
								else {
									pos_yEnemys[0] -= 2; //entra em conflito com pos_yEnemys += 2 e os inimigos travam na posi��o
								}
								for (int i = 0; i < 3; i++) {
									if (primeiroTiro == true) {
										pos_yTiro[i] = pos_yEnemys[0];
										primeiroTiro = false;
									}
									al_draw_filled_rectangle(pos_xTiro[i] + 8, pos_yTiro[i] + 50, (pos_xTiro[i] + 8) + 5, (pos_yTiro[i] + 50) + 5, al_map_rgb(0, 0, 0));
									pos_yTiro[i] += 15; //velocidade dos tiros
									if (pos_yTiro[i] >= pos_yJogador && (pos_xTiro[i] + 8 >= pos_xJogador && pos_xTiro[i] + 8 <= pos_xJogador + 35)) {
										tiroAcertou = true;
										vidasJogador--;
									}
									else {
										tiroAcertou = false;
									}

									if (pos_yTiro[i] > 600 || tiroAcertou == true) {
										pos_yTiro[i] = pos_yEnemys[0];
									}
								}

							}
							pos_yEnemys[0] += 2;
						}
						else {
							if (pos_yEnemys[0] <= 90) {
								x = true;
							}
							else {
								pos_yEnemys[0] -= 2;
								x = false;
							}
						}
						if (teclas[SPACE] && pos_yJogador <= regiaoDeAtaque) { //Consertar Bugs dos Tiros do Jogador
							al_draw_filled_rectangle(pos_xTiroJogador + 30, pos_yTiroJogador - 13, (pos_xTiroJogador + 30) + 5, (pos_yTiroJogador - 13) + 5, al_map_rgb(0, 0, 0));
							pos_yTiroJogador -= 20;
							for (int i = 0; i < 3; i++) {
								if (pos_yTiroJogador <= pos_yEnemys[i] + 30 && (pos_xTiroJogador + 15 >= pos_xEnemys[i] && pos_xTiroJogador + 15 <= pos_xEnemys[i] + 30)) { //Focar na l�gica
									tiroAcertouInimigo = true;
									vidasInimigos[i]--;
								}
								else {
									tiroAcertouInimigo = false;
								}
								if (pos_yTiroJogador < 0 || tiroAcertouInimigo == true) {
									pos_yTiroJogador = pos_yJogador;
									pos_xTiroJogador = pos_xJogador;
									teclas[SPACE] = false;
								}
							}
						}
						if (teclas[CIMA] && !teclas[DIREITA] && !teclas[ESQUERDA] && pos_yJogador >= 0) {
							pos_yJogador -= teclas[CIMA] * 3;

						}
						else {
							if (teclas[BAIXO] && !teclas[DIREITA] && !teclas[ESQUERDA] && pos_yJogador < 568) {
								pos_yJogador += teclas[BAIXO] * 3;
							}
							else {
								if (teclas[DIREITA] && pos_xJogador < 769) {
									pos_xJogador += teclas[DIREITA] * 3;

								}
								else {
									if (teclas[ESQUERDA] && pos_xJogador >= 4) {
										pos_xJogador -= teclas[ESQUERDA] * 3;
									}
								}
							} //tem que criar uma condi��o pra tecla espa�o com o intuito de atirar
						}
					}
				}

			}

			for (int i = 360; i < 430; i++) {
				if (pos_xJogador == i && pos_yJogador == -2) {
					imagem = al_load_bitmap("sprites/mapa2.jpg");
					pos_xJogador = 300;
					pos_yJogador = 500;
				}
			}

			for (int i = 230; i < 390; i++) {
				if ((pos_xJogador == 771 && pos_yJogador == i)) {
					imagem = al_load_bitmap("sprites/mapa2.jpg");
					pos_xJogador = 300;
					pos_yJogador = 500;
				}
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0)); //Pra limpar a tela quando movermos os objetos, n�o deixando rastros
			al_draw_bitmap(imagem, 0, 0, 0);
			//adi��o de personagem direto com bitmap
			al_draw_bitmap(player, pos_xJogador, pos_yJogador, 0);
			for (int i = 0; i < 3; i++) {
				al_draw_bitmap(enemy, pos_xEnemys[i], pos_yEnemys[0], 0);
			}

		}

	}

	//FINALIZA��O DO PROGRAMA
	al_destroy_display(display);
	al_destroy_event_queue(fila_eventos);
	al_destroy_timer(timer);
	al_destroy_bitmap(imagem);
	al_destroy_bitmap(player);
	return 0;
}



