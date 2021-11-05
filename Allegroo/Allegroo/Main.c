#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA, SPACE };
enum POSICOES {cima, baixo, direita, esquerda};
void  jogador(ALLEGRO_BITMAP* player, int pos_x, int pos_y, int constante) {
	al_draw_bitmap(player, pos_x, pos_y, constante);
}

void inimigos(ALLEGRO_BITMAP* enemy[], int pos_xEnemys[], int pos_yEnemys[], int constante, int vidasInimigos[]) {
	for (int i = 0; i < 2; i++) {
		if (vidasInimigos[i] > 0) {
			al_draw_bitmap(enemy[i], pos_xEnemys[i], pos_yEnemys[0], constante);
			
		}
		if (vidasInimigos[2] > 0) {
			al_draw_bitmap(enemy[2], pos_xEnemys[2], pos_yEnemys[1], constante);
		}
		
	}
	//ideia de colocar condi��es onde caso o inimigo morra a imagem daquele inimigo que morreu � destruida e desaparece do mapa
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
	const int largura_tela = 800, altura_tela = 600; //Define altura e largura do prot�tipo da tela;
	bool x = true, y = true; //Vari�veis que ser�o usadas para movimenta��o dos inimigos com o intuito de evitar conflitos
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
	int pos_xEnemys[] = { 100, 300, 741 }, pos_yEnemys[] = { 90, 148 }; //ter� mais posi��es em Y para inimigos vindo das laterais
	//Variaveis para uso dos tiros que sair�o dos Inimigos
	int pos_yTiro[3];
	int pos_xTiro[3];
	for (int i = 0; i < 2; i++) {
		pos_xTiro[i] = pos_xEnemys[i]; //recebe as posi��es iniciais de XEnemys e YEnemys, pois os tiros saem dos inimigos n�!!!
		pos_yTiro[i] = pos_yEnemys[0];
	}
	pos_yTiro[2] = pos_yEnemys[1];
	pos_xTiro[2] = pos_xEnemys[2];
	bool posicoes [] = { true, false, false, false };
	bool primeiroTiro[] = { true, true, true, true }, tiroAcertou[] = { false, false, false, false };
	//Vari�vel para velocidade de rodagem do jogo
	int FPS = 60;
	//Vari�vel para vidas do jogador;
	int vidasJogador = 8;
	//Vari�vel para vidas dos inimigos;
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
	ALLEGRO_DISPLAY* display = 0; //criando tela do jogo com ponteiro fazendo refer�ncia em ALLEGRO_DISPLAY;
	display = al_create_display(largura_tela, altura_tela); //fun��o que cria um display (eixo x, eixo y);

	//INICIALIZA��O DE TEMPORIZADOR
	ALLEGRO_TIMER* timer = 0;

	//VARIAVEL DA IMAGEM
	ALLEGRO_BITMAP* imagem = NULL;
	ALLEGRO_BITMAP* player = NULL;
	ALLEGRO_BITMAP* enemy[3] = { NULL, NULL, NULL };
	
	//INICIALIZA��O DE ADDONS
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples('10');

	timer = al_create_timer(1.5 / FPS);

	//INICIALIZA��O DE EVENTOS
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois n�o h� eventos ainda);
	fila_eventos = al_create_event_queue(); //fun��o para guardar os eventos gerados dentro da vari�vel "fila_eventos";
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


	//CARREGAR IMAGENS
	imagem = al_load_bitmap("sprites/mapa1.png");
	player = al_load_bitmap("sprites/playerup.png");
	enemy[0] = al_load_bitmap("sprites/enemydown.png");
	enemy[1] = al_load_bitmap("sprites/enemydown.png");
	enemy[2] = al_load_bitmap("sprites/enemyleft.png");
	al_play_sample_instance(inst_trilha_sonora);
	while (fim == false && vidasJogador > 0) {
		//JOGADOR
		jogador(player, pos_xJogador, pos_yJogador, 0);
		//INIMIGOS
		inimigos(enemy, pos_xEnemys, pos_yEnemys, 0, vidasInimigos);
		
		printf("Posi��o no eixo X: %d ---- %d ----- %d \nPosi��o no eixo Y %d ---- %d: \n\n %d ----- %d", pos_xEnemys[0], pos_xEnemys[1], pos_xEnemys[2], pos_yEnemys[0] - 20, pos_yEnemys[0], pos_xJogador, pos_yJogador);
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
						if (pos_yEnemys[0] <= 300 && x) { //Bloco de controle da movimenta��o dos inimigos
							for (int i = 0; i < 2; i++) {
								al_destroy_bitmap(enemy[i]);
								enemy[i] = al_load_bitmap("sprites/enemydown.png");
								if (pos_yJogador <= regiaoDeAtaque && pos_yJogador > pos_yEnemys[0] && pos_xJogador <= 380 && vidasInimigos[i] > 0) {
									if (pos_yEnemys[0] <= 215) {
										pos_yEnemys[0] -= 1;  //entra em conflito com pos_yEnemys += 2 e os inimigos andam de uma em uma casa
									}
									else {
										pos_yEnemys[0] -= 2; //entra em conflito com pos_yEnemys += 2 e os inimigos travam na posi��o
									}
									  //Bloco de controle dos tiros dos inimigos
									if (primeiroTiro[0] == true) {
										pos_yTiro[i] = pos_yEnemys[0];
										primeiroTiro[0] = false;
									}
									al_draw_filled_rectangle(pos_xTiro[i] + 8, pos_yTiro[i] + 50, (pos_xTiro[i] + 8) + 5, (pos_yTiro[i] + 50) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiro[i] + 50 <= pos_yEnemys[0] + 50) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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
										if (pos_yTiro[i] + 50 >= pos_yEnemys[0] + 50) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
											al_play_sample_instance(inst_tiro);
										}
										pos_yTiro[i] -= 15;
										if ((pos_yTiro[i] <= pos_yJogador + 30 && pos_yEnemys[0] >= pos_yJogador) && ((pos_xTiro[i] + 30) >= pos_xJogador && pos_xTiro[i] + 20 <= pos_xJogador + 30)) { //Focar na l�gica
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
									pos_xEnemys[2] += 2; //entra em conflito com pos_xEnemys -= 2 e os inimigos travam na posi��o
								}
								al_draw_filled_rectangle(pos_xTiro[2] - 2, pos_yTiro[2] + 5, (pos_xTiro[2] - 2) + 5, (pos_yTiro[2] + 5) + 5, al_map_rgb(0, 0, 0));
								if (pos_xTiro[2] - 2 >= pos_xEnemys[2] - 2) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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
									if (pos_xTiro[2] + 50 <= pos_xEnemys[2] + 50) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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
								if (pos_yTiroJogador - 13 == pos_yJogador - 13) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
									al_play_sample_instance(inst_tiro);
								}
								pos_yTiroJogador -= 20;
								if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[0] && pos_xTiroJogador + 20 <= pos_xEnemys[0] + 30)) { //Focar na l�gica
									tiroAcertouInimigo = true;
									vidasInimigos[0]--;
								}
								else {
									if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[1] && pos_xTiroJogador + 20 <= pos_xEnemys[1] + 30)) { //Focar na l�gica
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
									if (pos_yTiroJogador + 50 == pos_yJogador + 50) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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
										if (pos_xTiroJogador + 50 == pos_xJogador + 50) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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
											if (pos_xTiroJogador - 2 == pos_xJogador - 2) { //condi��o pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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
							if (pos_yTiroJogador < 0 || pos_yTiroJogador > 600  || pos_xTiroJogador > 800 || pos_xTiroJogador < 0 || tiroAcertouInimigo == true) {
								pos_yTiroJogador = pos_yJogador;
								pos_xTiroJogador = pos_xJogador;
								teclas[SPACE] = false;
							}
						}
						else {
							teclas[SPACE] = false; //apenas para bugs caso apertar o espa�o antes de entrar na zona de ataque
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
									posicoes[i] = false; //pra n ter conflito, seta as demais posi��es como falsa
								}
								posicoes[baixo] = true; //pra saber pra que lado o personagem est� virado
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
			// ==     COLIS�ES                    DO                       M A P A 1    ==
			// =========================================================================== //
			
			//COLIS�ES PRA CIMA
			//soldado esquerda
			/*for (int i = 420; i < 480; i++) { //espaco de posi��es que representam 
				for (int j = 35; j > 0; j--) { //espaco de posi��es para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 220; i < 280; i++) { //espaco de posi��es que representam 
				for (int j = 35; j > 0; j--) { //espaco de posi��es para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 20; i < 80; i++) { //espaco de posi��es que representam 
				for (int j = 35; j > 0; j--) { //espaco de posi��es para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j)) {
						teclas[CIMA] = false;
					}
				}

			}
			//COLIS�ES PRA BAIXO
			//soldado esquerda
			for (int i = 420; i < 480; i++) { //espaco de posi��es que representam 
				for (int j = 35; j > 0; j--) { //espaco de posi��es para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}
			}
			//soldado meio
			for (int i = 220; i < 280; i++) { //espaco de posi��es que representam 
				for (int j = 35; j > 0; j--) { //espaco de posi��es para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}

			}
			//soldado direita
			for (int i = 20; i < 80; i++) { //espaco de posi��es que representam 
				for (int j = 35; j > 0; j--) { //espaco de posi��es para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j)) {
						teclas[BAIXO] = false;
					}
				}

			}
			//COLIS�ES PRA DIREITA
			//soldado esquerda
			for (int i = 400; i < 450; i++) { //espaco de posi��es para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posi��es que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 200; i < 250; i++) { //espaco de posi��es para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posi��es que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 0; i < 50; i++) { //espaco de posi��es para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posi��es que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[DIREITA] = false;
					}
				}

			}
			//COLIS�ES PRA ESQUERDA
			//soldado esquerda
			for (int i = 500; i > 450; i--) { //espaco de posi��es para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posi��es que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 300; i > 250; i--) { //espaco de posi��es para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posi��es que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 100; i > 50; i--) { //espaco de posi��es para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posi��es que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j))) {
						teclas[ESQUERDA] = false;
					}
				}

			}
			*/
			//COLIS�ES COM A �GUA

			for (int i = 445; i < 600; i++) {
				for (int j = 300; j < 320; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i)) {
						teclas[DIREITA] = false;
					}
				}
			}

			for (int i = 445; i < 460; i++) {
				for (int j = 300; j < 483; j++) {
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
				if (pos_xJogador == i && pos_yJogador == -2 && vidasInimigos[0] == 0 && vidasInimigos[1] == 0 && vidasInimigos[2] == 0) {
					imagem = al_load_bitmap("sprites/mapa2.png");
					pos_xJogador = 360;
					pos_yJogador = 550;
				}

			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0)); //Pra limpar a tela quando movermos os objetos, n�o deixando rastros
			al_draw_bitmap(imagem, 0, 0, 0);
			//adi��o de personagem direto com bitmap
		}
	}

	//FINALIZA��O DO PROGRAMA
	al_destroy_display(display);
	al_destroy_event_queue(fila_eventos);
	al_destroy_timer(timer);
	al_destroy_bitmap(imagem);
	al_destroy_bitmap(player);
	for (int i = 0; i < 3; i++) {
		al_destroy_bitmap(enemy[i]);
	}
	return 0;
}



