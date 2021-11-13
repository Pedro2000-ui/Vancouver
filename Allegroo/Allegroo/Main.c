#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA, SPACE, ENTER };
enum POSICOES { cima, baixo, direita, esquerda };
void  jogador(ALLEGRO_BITMAP* player, int pos_x, int pos_y, int constante, int vidasJogador, ALLEGRO_BITMAP* heart1, ALLEGRO_BITMAP* heart2, ALLEGRO_BITMAP* heart3, ALLEGRO_BITMAP* heart4, ALLEGRO_BITMAP* heart5, ALLEGRO_BITMAP* heart6, ALLEGRO_BITMAP* heart7, ALLEGRO_BITMAP* heart8) {
	al_draw_bitmap(player, pos_x, pos_y, constante);

	if (vidasJogador == 8) {
		al_draw_bitmap(heart8, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 7) {
		al_draw_bitmap(heart7, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 6) {
		al_draw_bitmap(heart6, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 5) {
		al_draw_bitmap(heart5, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 4) {
		al_draw_bitmap(heart4, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 3) {
		al_draw_bitmap(heart3, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 2) {
		al_draw_bitmap(heart2, pos_x - 10, pos_y + 52, constante);
	}
	else if (vidasJogador == 1) {
		al_draw_bitmap(heart1, pos_x - 10, pos_y + 52, constante);
	}
}

void inimigos(ALLEGRO_BITMAP* enemy[], int pos_xEnemys[], int pos_yEnemys[], int constante, int vidasInimigos[], ALLEGRO_BITMAP* eHeart1, ALLEGRO_BITMAP* eHeart2, ALLEGRO_BITMAP* eHeart3, ALLEGRO_BITMAP* eHeart4, ALLEGRO_BITMAP* eHeart5){
	if (vidasInimigos[0] == 5) {
		al_draw_bitmap(enemy[0], pos_xEnemys[0], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart5, pos_xEnemys[0] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[0] == 4) {
		al_draw_bitmap(enemy[0], pos_xEnemys[0], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart4, pos_xEnemys[0] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[0] == 3) {
		al_draw_bitmap(enemy[0], pos_xEnemys[0], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart3, pos_xEnemys[0] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[0] == 2) {
		al_draw_bitmap(enemy[0], pos_xEnemys[0], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart2, pos_xEnemys[0] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[0] == 1) {
		al_draw_bitmap(enemy[0], pos_xEnemys[0], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart1, pos_xEnemys[0] + 10, pos_yEnemys[0] - 30, constante);
	}
	//INIMIGO 2  
	if (vidasInimigos[1] == 5) {
		al_draw_bitmap(enemy[1], pos_xEnemys[1], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart5, pos_xEnemys[1] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[1] == 4) {
		al_draw_bitmap(enemy[1], pos_xEnemys[1], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart4, pos_xEnemys[1] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[1] == 3) {
		al_draw_bitmap(enemy[1], pos_xEnemys[1], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart3, pos_xEnemys[1] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[1] == 2) {
		al_draw_bitmap(enemy[1], pos_xEnemys[1], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart2, pos_xEnemys[1] + 10, pos_yEnemys[0] - 30, constante);
	}
	else if (vidasInimigos[1] == 1) {
		al_draw_bitmap(enemy[1], pos_xEnemys[1], pos_yEnemys[0], constante);
		al_draw_bitmap(eHeart1, pos_xEnemys[1] + 10, pos_yEnemys[0] - 30, constante);
	}
	//INIMIGO 3
	if (vidasInimigos[2] == 5) {
		al_draw_bitmap(enemy[2], pos_xEnemys[2], pos_yEnemys[1], constante);
		al_draw_bitmap(eHeart5, pos_xEnemys[2] + 10, pos_yEnemys[1] - 30, constante);
	}
	else if (vidasInimigos[2] == 4) {
		al_draw_bitmap(enemy[2], pos_xEnemys[2], pos_yEnemys[1], constante);
		al_draw_bitmap(eHeart4, pos_xEnemys[2] + 10, pos_yEnemys[1] - 30, constante);
	}
	else if (vidasInimigos[2] == 3) {
		al_draw_bitmap(enemy[2], pos_xEnemys[2], pos_yEnemys[1], constante);
		al_draw_bitmap(eHeart3, pos_xEnemys[2] + 10, pos_yEnemys[1] - 30, constante);
	}
	else if (vidasInimigos[2] == 2) {
		al_draw_bitmap(enemy[2], pos_xEnemys[2], pos_yEnemys[1], constante);
		al_draw_bitmap(eHeart2, pos_xEnemys[2] + 10, pos_yEnemys[1] - 30, constante);
	}
	else if (vidasInimigos[2] == 1) {
		al_draw_bitmap(enemy[2], pos_xEnemys[2], pos_yEnemys[1], constante);
		al_draw_bitmap(eHeart1, pos_xEnemys[2] + 10, pos_yEnemys[1] - 30, constante);
	}
}


//ideia de colocar condições onde caso o inimigo morra a imagem daquele inimigo que morreu é destruida e desaparece do map

ALLEGRO_BITMAP* fundoMenu;



/*void menu() {
	int tempo = 0, flash = 0;
	bool fimMenu = false;

	while (!fimMenu) {

		fundoMenu = al_load_bitmap("sprites/menuF.png");

		al_draw_text(font09, al_map_rgb(255, 255, 255), 50, 50, NULL, "PRESS ENTER TO CONTINUE");

		al_draw_bitmap(fundoMenu, 0, 0, 0);

		if (ALLEGRO_KEY_ENTER) fimMenu = true;
	}
}
*/

//MAIN
int main() {
	const int largura_tela = 800, altura_tela = 600; //Define altura e largura do protótipo da tela;
	bool x = true, y = true; //Variáveis que serão usadas para movimentação dos inimigos com o intuito de evitar conflitos
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
	int pos_xEnemys[] = { 100, 300, 741 }, pos_yEnemys[] = { 90, 148 }; //terá mais posições em Y para inimigos vindo das laterais
	//Variaveis para uso dos tiros que sairão dos Inimigos
	int pos_yTiro[3];
	int pos_xTiro[3];
	for (int i = 0; i < 2; i++) {
		pos_xTiro[i] = pos_xEnemys[i]; //recebe as posições iniciais de XEnemys e YEnemys, pois os tiros saem dos inimigos né!!!
		pos_yTiro[i] = pos_yEnemys[0];
	}
	pos_yTiro[2] = pos_yEnemys[1];
	pos_xTiro[2] = pos_xEnemys[2];
	bool posicoes[] = { true, false, false, false };
	bool primeiroTiro[] = { true, true, true, true }, tiroAcertou[] = { false, false, false, false };
	//Variável para velocidade de rodagem do jogo
	int FPS = 60;
	//Variável para vidas do jogador;
	int vidasJogador = 8;
	//Variável para vidas dos inimigos;
	int vidasInimigos[3] = { 5, 5, 5 };
	//Variavel de Som
	ALLEGRO_SAMPLE* trilha_sonora = NULL;
	ALLEGRO_SAMPLE* tiro = NULL;
	ALLEGRO_SAMPLE* passos = NULL;
	ALLEGRO_SAMPLE* dano = NULL;

	ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_tiro = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_passos = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_dano = NULL;

	//TELA DO JOGO
	al_init();
	ALLEGRO_DISPLAY* display = 0; //criando tela do jogo com ponteiro fazendo referência em ALLEGRO_DISPLAY;
	display = al_create_display(largura_tela, altura_tela); //função que cria um display (eixo x, eixo y);

	//INICIALIZAÇÂO DE TEMPORIZADOR
	ALLEGRO_TIMER* timer = 0;

	//Fonte do menu
	ALLEGRO_FONT* font09 = al_load_font("04b.TTF", 50, NULL);

	//VARIAVEL DA IMAGEM
	ALLEGRO_BITMAP* imagem = NULL;
	ALLEGRO_BITMAP* player = NULL;
	ALLEGRO_BITMAP* enemy[3] = { NULL, NULL, NULL };
	//coração player
	ALLEGRO_BITMAP* heart8 = NULL;
	ALLEGRO_BITMAP* heart7 = NULL;
	ALLEGRO_BITMAP* heart6 = NULL;
	ALLEGRO_BITMAP* heart5 = NULL;
	ALLEGRO_BITMAP* heart4 = NULL;
	ALLEGRO_BITMAP* heart3 = NULL;
	ALLEGRO_BITMAP* heart2 = NULL;
	ALLEGRO_BITMAP* heart1 = NULL;
	//coração enemy
	ALLEGRO_BITMAP* eHeart5 = NULL;
	ALLEGRO_BITMAP* eHeart4 = NULL;
	ALLEGRO_BITMAP* eHeart3 = NULL;
	ALLEGRO_BITMAP* eHeart2 = NULL;
	ALLEGRO_BITMAP* eHeart1 = NULL;
	//INICIALIZAÇÃO DE ADDONS
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples('10');

	timer = al_create_timer(1.5 / FPS);

	//INICIALIZAÇÃO DE EVENTOS
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois não há eventos ainda);
	fila_eventos = al_create_event_queue(); //função para guardar os eventos gerados dentro da variável "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(display)); //eventos de display 
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer

	al_start_timer(timer);

	trilha_sonora = al_load_sample("sounds/trilhasonorateste.ogg");
	inst_trilha_sonora = al_create_sample_instance(trilha_sonora);
	tiro = al_load_sample("sounds/tiro.ogg");
	inst_tiro = al_create_sample_instance(tiro);
	al_attach_sample_instance_to_mixer(inst_trilha_sonora, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(inst_tiro, al_get_default_mixer());
	al_set_sample_instance_playmode(inst_trilha_sonora, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_gain(inst_trilha_sonora, 0.8);
	al_set_sample_instance_gain(inst_tiro, 0.8);

	//Chamando a função do MENU
	//menu();



	//CARREGAR IMAGENS
	imagem = al_load_bitmap("sprites/mapa1.png");
	player = al_load_bitmap("sprites/playerup.png");
	enemy[0] = al_load_bitmap("sprites/enemydown.png");
	enemy[1] = al_load_bitmap("sprites/enemydown.png");
	enemy[2] = al_load_bitmap("sprites/enemyleft.png");
	//coração player
	heart1 = al_load_bitmap("sprites/heartplayer/heart1.png");
	heart2 = al_load_bitmap("sprites/heartplayer/heart2.png");
	heart3 = al_load_bitmap("sprites/heartplayer/heart3.png");
	heart4 = al_load_bitmap("sprites/heartplayer/heart4.png");
	heart5 = al_load_bitmap("sprites/heartplayer/heart5.png");
	heart6 = al_load_bitmap("sprites/heartplayer/heart6.png");
	heart7 = al_load_bitmap("sprites/heartplayer/heart7.png");
	heart8 = al_load_bitmap("sprites/heartplayer/heart8.png");
	//coração inimigo
	eHeart1 = al_load_bitmap("sprites/heartenemy/eHeart1.png");
	eHeart2 = al_load_bitmap("sprites/heartenemy/eHeart2.png");
	eHeart3 = al_load_bitmap("sprites/heartenemy/eHeart3.png");
	eHeart4 = al_load_bitmap("sprites/heartenemy/eHeart4.png");
	eHeart5 = al_load_bitmap("sprites/heartenemy/eHeart5.png");

	//CARREGAR TRILHA SONORA
	al_play_sample_instance(inst_trilha_sonora);

	while (fim == false && vidasJogador > 0) {
		//JOGADOR
		jogador(player, pos_xJogador, pos_yJogador, 0, vidasJogador, heart1, heart2, heart3, heart4, heart5, heart6, heart7, heart8);
		//INIMIGOS
		inimigos(enemy, pos_xEnemys, pos_yEnemys, 0, vidasInimigos, heart1, heart2, heart3, heart4, heart5, heart6, heart7, heart8);

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
						if (pos_yEnemys[0] <= 300 && x) { //Bloco de controle da movimentação dos inimigos
							for (int i = 0; i < 2; i++) {
								al_destroy_bitmap(enemy[i]);
								enemy[i] = al_load_bitmap("sprites/enemydown.png");
								if (pos_yJogador <= regiaoDeAtaque && pos_yJogador > pos_yEnemys[0] && pos_xJogador <= 380 && vidasInimigos[i] > 0) {
									if (pos_yEnemys[0] <= 215) {
										pos_yEnemys[0] -= 1;  //entra em conflito com pos_yEnemys += 2 e os inimigos andam de uma em uma casa
									}
									else {
										pos_yEnemys[0] -= 2; //entra em conflito com pos_yEnemys += 2 e os inimigos travam na posição
									}
									//Bloco de controle dos tiros dos inimigos
									if (primeiroTiro[0] == true) {
										pos_yTiro[i] = pos_yEnemys[0];
										primeiroTiro[0] = false;
									}
									al_draw_filled_rectangle(pos_xTiro[i] + 8, pos_yTiro[i] + 50, (pos_xTiro[i] + 8) + 5, (pos_yTiro[i] + 50) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiro[i] + 50 <= pos_yEnemys[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									pos_yTiro[i] += 15; //velocidade dos tiros
									if ((pos_yTiro[i] >= pos_yJogador && pos_yJogador > pos_yEnemys[0]) && (pos_xTiro[i] + 8 >= pos_xJogador && pos_xTiro[i] <= pos_xJogador + 35)) {
										tiroAcertou[0] = true;
										vidasJogador--;
									}
									else {
										tiroAcertou[0] = false;
									}
									if (pos_yTiro[i] > 600 || tiroAcertou[0] == true) {
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
								for (int i = 0; i < 2; i++) {
									al_destroy_bitmap(enemy[i]);
									enemy[i] = al_load_bitmap("sprites/enemyup.png");
									if (pos_yJogador < pos_yEnemys[0] && pos_xJogador <= 380 && vidasInimigos[i] > 0) {
										pos_yEnemys[0] += 1;
										if (primeiroTiro[3] == true) {
											pos_yTiro[i] = pos_yEnemys[0];
											primeiroTiro[3] = false;
										}
										al_draw_filled_rectangle(pos_xTiro[i] + 30, pos_yTiro[i] - 13, (pos_xTiro[i] + 30) + 5, (pos_yTiro[i] - 13) + 5, al_map_rgb(0, 0, 0));
										if (pos_yTiro[i] + 50 >= pos_yEnemys[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
											al_play_sample_instance(inst_tiro);
										}
										pos_yTiro[i] -= 15;
										if ((pos_yTiro[i] <= pos_yJogador + 30 && pos_yEnemys[0] >= pos_yJogador) && ((pos_xTiro[i] + 30) >= pos_xJogador && pos_xTiro[i] + 20 <= pos_xJogador + 30)) { //Focar na lógica
											tiroAcertou[3] = true;
											vidasJogador--;
										}
										else {
											tiroAcertou[3] = false;
										}
										if (pos_yTiro[i] < 0 || tiroAcertou[3] == true) {
											pos_yTiro[i] = pos_yEnemys[0];
										}
									}
								}
							}
						}
						if (pos_xEnemys[2] >= 432 && y && vidasInimigos[2] > 0) //bloco de controle do inimigo da lateral
						{
							al_destroy_bitmap(enemy[2]);
							enemy[2] = al_load_bitmap("sprites/enemyleft.png");
							pos_xEnemys[2] -= 2;
							if (primeiroTiro[1] == true) {
								pos_xTiro[2] = pos_xEnemys[2];
								primeiroTiro[1] = false;
							}
							if (pos_yJogador <= 175 && pos_xJogador < pos_xEnemys[2]) {
								if (pos_xEnemys[2] >= 500 && pos_xJogador < pos_xEnemys[2] - 80) {
									pos_xEnemys[2] += 1;  //entra em conflito com pos_xEnemys -= 2 e os inimigos andam de uma em uma casa
								}
								else {
									pos_xEnemys[2] += 2; //entra em conflito com pos_xEnemys -= 2 e os inimigos travam na posição
								}
								al_draw_filled_rectangle(pos_xTiro[2] - 2, pos_yTiro[2] + 5, (pos_xTiro[2] - 2) + 5, (pos_yTiro[2] + 5) + 5, al_map_rgb(0, 0, 0));
								if (pos_xTiro[2] - 2 >= pos_xEnemys[2] - 2) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
									al_play_sample_instance(inst_tiro);
								}
								pos_xTiro[2] -= 25;
								if ((pos_xTiro[2] <= pos_xJogador && pos_xJogador < pos_xEnemys[2]) && (pos_yTiro[2] + 5 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 35)) {
									tiroAcertou[1] = true;
									vidasJogador--;
								}
								else {
									tiroAcertou[1] = false;
								}
							}
						}
						else {
							if (pos_xEnemys[2] >= 747) {
								y = true;
							}
							else {
								al_destroy_bitmap(enemy[2]);
								enemy[2] = al_load_bitmap("sprites/enemyright.png");
								pos_xEnemys[2] += 2;
								y = false;
								if (pos_yJogador <= 175 && pos_xJogador > pos_xEnemys[2] && vidasInimigos[2] > 0) {
									if (primeiroTiro[2] == true) {
										pos_xTiro[2] = pos_xEnemys[2];
										primeiroTiro[2] = false;
									}
									if (pos_xJogador > pos_xEnemys[2] + 80) {
										pos_xEnemys[2] -= 1;
									}
									else {
										pos_xEnemys[2] -= 2;
									}
									al_draw_filled_rectangle(pos_xTiro[2] + 50, pos_yTiro[2] + 25, (pos_xTiro[2] + 50) + 5, (pos_yTiro[2] + 25) + 5, al_map_rgb(0, 0, 0));
									if (pos_xTiro[2] + 50 <= pos_xEnemys[2] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									if ((pos_xTiro[2] + 40 >= pos_xJogador && pos_xEnemys[2] < pos_xJogador) && (pos_yTiro[2] + 25 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 20)) {
										tiroAcertou[2] = true;
										vidasJogador--;
									}
									else {
										tiroAcertou[2] = false;
									}
									pos_xTiro[2] += 25;

								}

							}
						}
						if (pos_xTiro[2] < 0 || pos_xTiro[2] > 800 || tiroAcertou[1] == true || tiroAcertou[2] == true) {
							pos_xTiro[2] = pos_xEnemys[2];
						}
						if (teclas[SPACE] && pos_yJogador <= regiaoDeAtaque) {
							if (posicoes[cima]) { //se a img do jogador estiver posicionada para cima
								al_draw_filled_rectangle(pos_xTiroJogador + 30, pos_yTiroJogador - 13, (pos_xTiroJogador + 30) + 5, (pos_yTiroJogador - 13) + 5, al_map_rgb(0, 0, 0));
								if (pos_yTiroJogador - 13 == pos_yJogador - 13) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
									al_play_sample_instance(inst_tiro);
								}
								pos_yTiroJogador -= 20;
								if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[0] && pos_xTiroJogador + 20 <= pos_xEnemys[0] + 30)) { //Focar na lógica
									tiroAcertouInimigo = true;
									vidasInimigos[0]--;
								}
								else {
									if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[1] && pos_xTiroJogador + 20 <= pos_xEnemys[1] + 30)) { //Focar na lógica
										tiroAcertouInimigo = true;
										vidasInimigos[1]--;
									}
									else {
										tiroAcertouInimigo = false;
									}
								}
							}
							else {
								if (posicoes[baixo]) { //se o personagem estiver para baixo
									al_draw_filled_rectangle(pos_xTiroJogador + 8, pos_yTiroJogador + 50, (pos_xTiroJogador + 8) + 5, (pos_yTiroJogador + 50) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiroJogador + 50 == pos_yJogador + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									if ((pos_yTiroJogador >= pos_yEnemys[0] - 30 && pos_yEnemys[0] > pos_yJogador) && (pos_xTiroJogador + 8 >= pos_xEnemys[0] && pos_xTiroJogador + 8 <= pos_xEnemys[0] + 35)) { //corrigir
										tiroAcertouInimigo = true;
										vidasInimigos[0]--;
									}
									else {
										if ((pos_yTiroJogador >= pos_yEnemys[0] - 30 && pos_yEnemys[0] > pos_yJogador) && (pos_xTiroJogador + 8 >= pos_xEnemys[1] && pos_xTiroJogador + 8 <= pos_xEnemys[1] + 35)) { //corrigir
											tiroAcertouInimigo = true;
											vidasInimigos[1]--;
										}
										else {
											tiroAcertouInimigo = false;
										}
									}
									pos_yTiroJogador += 20;
								}
								else {
									if (posicoes[direita]) { //se o personagem estiver para a direita
										al_draw_filled_rectangle(pos_xTiroJogador + 50, pos_yTiroJogador + 25, (pos_xTiroJogador + 50) + 5, (pos_yTiroJogador + 25) + 5, al_map_rgb(0, 0, 0));
										if (pos_xTiroJogador + 50 == pos_xJogador + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
											al_play_sample_instance(inst_tiro);
										}
										if ((pos_xTiroJogador + 40 >= pos_xEnemys[2] && pos_xEnemys[2] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemys[1] && pos_yTiroJogador <= pos_yEnemys[1] + 20)) {
											tiroAcertouInimigo = true;
											vidasInimigos[2]--;
										}
										else {
											tiroAcertouInimigo = false;
										}
										pos_xTiroJogador += 25;
									}
									else {
										if (posicoes[esquerda]) {
											al_draw_filled_rectangle(pos_xTiroJogador - 2, pos_yTiroJogador + 5, (pos_xTiroJogador - 2) + 5, (pos_yTiroJogador + 5) + 5, al_map_rgb(0, 0, 0));
											if (pos_xTiroJogador - 2 == pos_xJogador - 2) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
												al_play_sample_instance(inst_tiro);
											}
											if ((pos_xTiroJogador - 40 <= pos_xEnemys[2] && pos_xEnemys[2] < pos_xJogador) && (pos_yTiroJogador + 5 >= pos_yEnemys[1] && pos_yTiroJogador <= pos_yEnemys[1] + 35)) {
												tiroAcertouInimigo = true;
												vidasInimigos[2]--;
											}
											else {
												tiroAcertouInimigo = false;
											}
											pos_xTiroJogador -= 25;
										}
									}
								}
							}
							if (pos_yTiroJogador < 0 || pos_yTiroJogador > 600 || pos_xTiroJogador > 800 || pos_xTiroJogador < 0 || tiroAcertouInimigo == true) {
								pos_yTiroJogador = pos_yJogador;
								pos_xTiroJogador = pos_xJogador;
								teclas[SPACE] = false;
							}
						}
						else {
							teclas[SPACE] = false; //apenas para bugs caso apertar o espaço antes de entrar na zona de ataque
						}
						if (teclas[CIMA] && !teclas[SPACE] && !teclas[BAIXO] && !teclas[DIREITA] && !teclas[ESQUERDA] && pos_yJogador >= 0) {
							pos_yJogador -= teclas[CIMA] * 3;
							pos_yTiroJogador = pos_yJogador;
							for (int i = 1; i < 4; i++) {
								posicoes[i] = false;
							}
							posicoes[cima] = true;
							al_destroy_bitmap(player);
							player = al_load_bitmap("sprites/playerup.png");
						}
						else {
							if (teclas[BAIXO] && !teclas[SPACE] && !teclas[DIREITA] && !teclas[ESQUERDA] && pos_yJogador < 547) {
								pos_yJogador += teclas[BAIXO] * 3;
								pos_yTiroJogador = pos_yJogador;
								for (int i = 0; i < 4 && i != 1; i++) {
									posicoes[i] = false; //pra n ter conflito, seta as demais posições como falsa
								}
								posicoes[baixo] = true; //pra saber pra que lado o personagem está virado
								al_destroy_bitmap(player);
								player = al_load_bitmap("sprites/playerdown.png");
							}
							else {
								if (teclas[DIREITA] && !teclas[SPACE] && !teclas[ESQUERDA] && pos_xJogador < 750) {
									pos_xJogador += teclas[DIREITA] * 3;
									pos_xTiroJogador = pos_xJogador;
									for (int i = 0; i < 4 && i != 2; i++) {
										posicoes[i] = false;
									}
									posicoes[direita] = true;
									al_destroy_bitmap(player);
									player = al_load_bitmap("sprites/playerright.png");

								}
								else {
									if (teclas[ESQUERDA] && !teclas[SPACE] && pos_xJogador >= 4) {
										pos_xJogador -= teclas[ESQUERDA] * 3;
										pos_xTiroJogador = pos_xJogador;
										for (int i = 0; i < 3; i++) {
											posicoes[i] = false;
										}
										posicoes[esquerda] = true;
										al_destroy_bitmap(player);
										player = al_load_bitmap("sprites/playerleft.png");
									}
								}
							}
						}
					}
				}
			}
			// =========================================================================== //
			// ==     COLISÕES                    DO                       M A P A 1    ==
			// =========================================================================== //
			printf("posicao x %d ---- %d ---- %d", pos_xEnemys[0], pos_xEnemys[1], pos_xEnemys[2]);
			//COLISÕES PRA CIMA
			//soldado esquerda
			for (int i = 70; i < 130; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 270; i < 330; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 190; i > 100; i--) { //espaco de posições que representam 
				for (int j = 35; j > -35; j--) { //espaco de posições para a parada do jogador
					if ((pos_yJogador == i) && (pos_xJogador == pos_xEnemys[2] + j)) {
						teclas[CIMA] = false;
					}
				}

			}
			//COLISÕES PRA BAIXO
			//soldado esquerda
			for (int i = 90; i < 110; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}
			}
			//soldado meio
			for (int i = 290; i < 310; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}

			}
			//soldado direita
			for (int i = 100; i < 130; i++) { //espaco de posições que representam 
				for (int j = 35; j > -35; j--) { //espaco de posições para a parada do jogador
					if ((pos_yJogador == i) && (pos_xJogador == pos_xEnemys[2] - j)) {
						teclas[BAIXO] = false;
					}
				}

			}
			//COLISÕES PRA DIREITA
			//soldado esquerda
			for (int i = 70; i < 100; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 270; i < 300; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 100; i < 160; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > 0; j--) { //espaco de posições que representam 
					if ((pos_yJogador == i) && (pos_xJogador == pos_xEnemys[2] - (j))) {
						teclas[DIREITA] = false;
					}
				}

			}
			//COLISÕES PRA ESQUERDA
			//soldado esquerda
			for (int i = 150; i > 100; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 350; i > 300; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 100; i > 160; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[2] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}

			}

			//COLISÕES COM A ÁGUA

			for (int i = 445; i < 600; i++) {
				for (int j = 300; j < 320; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i)) {
						teclas[DIREITA] = false;
					}
				}
			}

			for (int i = 445; i <= 460; i++) {
				for (int j = 300; j <= 483; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i)) {
						teclas[BAIXO] = false;
					}
				}
			}

			for (int i = 375; i < 446; i++) {
				for (int j = 483; j < 500; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i)) {
						teclas[DIREITA] = false;
					}
				}
			}
			for (int i = 375; i < 390; i++) {
				for (int j = 483; j <= 771; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i)) {
						teclas[BAIXO] = false;
					}
				}
			}
			// mapa 2
			for (int i = 360; i < 430; i++) {
				if (pos_xJogador == i && pos_yJogador == -2 && vidasInimigos[0] <= 0 && vidasInimigos[1] <= 0 && vidasInimigos[2] <= 0) {
					imagem = al_load_bitmap("sprites/mapa2.png");
					pos_xJogador = 360;
					pos_yJogador = 550;
					vidasJogador = 8;
				}

			}
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
	al_destroy_font(font09);
	for (int i = 0; i < 3; i++) {
		al_destroy_bitmap(enemy[i]);
	}
	return 0;
}