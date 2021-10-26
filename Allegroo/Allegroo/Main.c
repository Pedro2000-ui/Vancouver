#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA, SPACE };

void  jogador(ALLEGRO_BITMAP* player, int pos_x, int pos_y, int constante) {
	al_draw_bitmap(player, pos_x, pos_y, constante);
}

void inimigos(ALLEGRO_BITMAP* enemy, int pos_xEnemys[], int pos_yEnemys[], int constante, int vidaInimigos[]) {
	for (int i = 0; i < 3; i++) {
		al_draw_bitmap(enemy, pos_xEnemys[i], pos_yEnemys[0], constante);
	}
	//ideia de colocar condições onde caso o inimigo morra a imagem daquele inimigo que morreu é destruida e desaparece do mapa
}
/*
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
}*/
//MAIN
int main() {

	const int largura_tela = 800, altura_tela = 600; //Define altura e largura do protótipo da tela;
	bool x = true; //Variável que será usada para movimentação dos inimigos com o intuito de evitar conflitos
	bool fim = false; //variável apenas pra idenficar o fim do jogo futuramente;
	bool teclas[] = { false, false, false, false, false };
	//Posição que iniciará o jogador;
	int pos_xJogador = 150, pos_yJogador = 550;
	//Variaveis para uso dos tiros que sairão do Jogador
	int pos_yTiroJogador = pos_yJogador;
	int pos_xTiroJogador = pos_xJogador;
	bool tiroAcertouInimigo = false;
	//Região que os inimigos atacarão ao visualizarem o jogador
	int regiaoDeAtaque = 400;
	//Posições que os inimigos iniciarão;
	int pos_xEnemys[] = { 50, 250, 450 }, pos_yEnemys[] = { 90 }; //terá mais posições em Y para inimigos vindo das laterais
	//Variaveis para uso dos tiros que sairão dos Inimigos
	int pos_yTiro[3];
	int pos_xTiro[3];
	for (int i = 0; i < 3; i++) {
		pos_xTiro[i] = pos_xEnemys[i]; //recebe as posições iniciais de XEnemys e YEnemys, pois os tiros saem dos inimigos né!!!
		pos_yTiro[i] = pos_yEnemys[0];
	}
	bool primeiroTiro = true, tiroAcertou = false;
	//Variável para velocidade de rodagem do jogo
	int FPS = 60;
	//Variável para vidas do jogador;
	int vidasJogador = 8;
	//Variável para vidas dos inimigos;
	int vidasInimigos[3] = { 5, 5, 5 };

	//TELA DO JOGO
	al_init();
	ALLEGRO_DISPLAY* display = 0; //criando tela do jogo com ponteiro fazendo referência em ALLEGRO_DISPLAY;
	display = al_create_display(largura_tela, altura_tela); //função que cria um display (eixo x, eixo y);

	//INICIALIZAÇÂO DE TEMPORIZADOR
	ALLEGRO_TIMER* timer = 0;

	//VARIAVEL DA IMAGEM
	ALLEGRO_BITMAP* imagem = NULL;
	ALLEGRO_BITMAP* player = NULL;
	ALLEGRO_BITMAP* enemy = NULL;

	//INICIALIZAÇÃO DE ADDONS
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();

	timer = al_create_timer(1.5 / FPS);

	//INICIALIZAÇÃO DE EVENTOS
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois não há eventos ainda);
	fila_eventos = al_create_event_queue(); //função para guardar os eventos gerados dentro da variável "fila_eventos";
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
		jogador(player, pos_xJogador, pos_yJogador, 0);
		//INIMIGOS
		inimigos(enemy, pos_xEnemys, pos_yEnemys, 0, vidasInimigos);
		
		printf("Posição no eixo X: %d ---- %d ----- %d \nPosição no eixo Y %d ---- %d: \n\n %d ----- %d", pos_xEnemys[0], pos_xEnemys[1], pos_xEnemys[2], pos_yEnemys[0] - 20, pos_yEnemys[0], pos_xJogador, pos_yJogador);
		ALLEGRO_EVENT ev; //variavel para usarmos para verificar a situação dos eventos
		al_wait_for_event(fila_eventos, &ev); //verifica se algum evento foi detectado, se sim avança pra próxima linha, senão não continua o loop - útil para evitar uso de memória indevido
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			fim = true;
		}
		//MOVIMENTOS DO JOGADOR E DOS INIMIGOS
		else {
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {//ALLEGRO_EVENT_KEY_UP -> O UP executa apenas quando soltarmos a tecla
			//ev type = verifica o TIPO de evento (pelo teclado, pelo mouse, joystick e etc, nesse if está verificando se o tipo é igual há um evento de teclado, por isso o ALLEGRO_EVENT_KEY_DOWN
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { //verifica se o evento do tipo teclado e o seu código(qual tecla é) no casso desse if, está verificando se é igual a tecla ESCAPE (o famoso ESC)
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
				//ev type = verifica o TIPO de evento (pelo teclado, pelo mouse, joystick e etc, nesse if está verificando se o tipo é igual há um evento de teclado, por isso o ALLEGRO_EVENT_KEY_DOWN
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
					if (ev.type == ALLEGRO_EVENT_TIMER) { //Qualquer movimento dentro desse if roda nas especificações do timer (segundos/fps)
						if (pos_yEnemys[0] <= 250 && x == true) { //Bloco de controle da movimentação dos inimigos
							al_destroy_bitmap(enemy);
							enemy = al_load_bitmap("sprites/enemydown.png");
							if (pos_yJogador <= regiaoDeAtaque) {
								if (pos_yEnemys[0] <= 215) {
									pos_yEnemys[0] -= 1;  //entra em conflito com pos_yEnemys += 2 e os inimigos andam de uma em uma casa
								}
								else {
									pos_yEnemys[0] -= 2; //entra em conflito com pos_yEnemys += 2 e os inimigos travam na posição
								}
								for (int i = 0; i < 3; i++) { //Bloco de controle dos tiros dos inimigos
									if (primeiroTiro == true) {
										pos_yTiro[i] = pos_yEnemys[0];
										primeiroTiro = false;
									}
									al_draw_filled_rectangle(pos_xTiro[i] + 8, pos_yTiro[i] + 50, (pos_xTiro[i] + 8) + 5, (pos_yTiro[i] + 50) + 5, al_map_rgb(0, 0, 0));
									pos_yTiro[i] += 15; //velocidade dos tiros
									if ((pos_yTiro[i] >= pos_yJogador && pos_yJogador > pos_yEnemys[0]) && (pos_xTiro[i] + 8 >= pos_xJogador && pos_xTiro[i] + 8 <= pos_xJogador + 35)) {
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
								al_destroy_bitmap(enemy);
								enemy = al_load_bitmap("sprites/enemyup.png");
							}
						}
						if (teclas[SPACE] && pos_yJogador <= regiaoDeAtaque) { //Consertar Bugs dos Tiros do Jogador
							al_draw_filled_rectangle(pos_xTiroJogador + 30, pos_yTiroJogador - 13, (pos_xTiroJogador + 30) + 5, (pos_yTiroJogador - 13) + 5, al_map_rgb(0, 0, 0));
							pos_yTiroJogador -= 20;
							for (int i = 0; i < 3; i++) {
								if (pos_yTiroJogador <= pos_yEnemys[i] + 30 && (pos_xTiroJogador + 15 >= pos_xEnemys[i] && pos_xTiroJogador + 15 <= pos_xEnemys[i] + 30)) { //Focar na lógica
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
						if (teclas[CIMA]  && !teclas[BAIXO] && !teclas[DIREITA] && !teclas[ESQUERDA] && pos_yJogador >= 0) {
							pos_yJogador -= teclas[CIMA] * 3;
							al_destroy_bitmap(player);
							player = al_load_bitmap("sprites/playerup.png");
						}
						else {
							
							if (teclas[BAIXO] && !teclas[DIREITA] && !teclas[ESQUERDA] && pos_yJogador < 568) {
								pos_yJogador += teclas[BAIXO] * 3;
								al_destroy_bitmap(player);
								player = al_load_bitmap("sprites/playerdown.png");
							}
							else {
								if (teclas[DIREITA] && !teclas[ESQUERDA] && pos_xJogador < 769) {
									pos_xJogador += teclas[DIREITA] * 3;
									al_destroy_bitmap(player);
									player = al_load_bitmap("sprites/playerright.png");
								}
								else {
									if (teclas[ESQUERDA] && pos_xJogador >= 4) {
										pos_xJogador -= teclas[ESQUERDA] * 3;
										al_destroy_bitmap(player);
										player = al_load_bitmap("sprites/playerleft.png");
									}
								}
							} 
						}
					}
				}
			}

			//CIMA
			for (int i = 420; i < 480; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}
			}
			for (int i = 220; i < 280; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}

			}
			for (int i = 20; i < 80; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}

			}
			//CIMA
			//BAIXO
			for (int i = 420; i < 480; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}
			}
			for (int i = 220; i < 280; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}

			}
			for (int i = 20; i < 80; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}

			}
			//BAIXO
			//DIREITA
			for (int i = 400; i < 450; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}
			}
			for (int i = 200; i < 250; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}

			}
			for (int i = 0; i < 50; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}

			}
			//DIREITA
			//ESQUERDA
			for (int i = 500; i > 450; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			for (int i = 300; i > 250; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}

			}
			for (int i = 100; i > 50; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}

			}
			//ESQUERDA
			/*
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
			}*/

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0)); //Pra limpar a tela quando movermos os objetos, não deixando rastros
			al_draw_bitmap(imagem, 0, 0, 0);
			//adição de personagem direto com bitmap
		}
	}

	//FINALIZAÇÃO DO PROGRAMA
	al_destroy_display(display);
	al_destroy_event_queue(fila_eventos);
	al_destroy_timer(timer);
	al_destroy_bitmap(imagem);
	al_destroy_bitmap(player);
	al_destroy_bitmap(enemy);
	return 0;
}



