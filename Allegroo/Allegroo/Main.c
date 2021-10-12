#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
enum TECLAS { CIMA, BAIXO, DIREITA, ESQUERDA, SPACE };

void  jogador(pos_x, pos_y) {
	al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 255, 0));
}

void inimigos(pos_xEnemy1, pos_xEnemy2, pos_xEnemy3, pos_yEnemys, vidasInimigo1, vidasInimigo2, vidasInimigo3) {
	//tentar melhorar, muito repetitiva
	if(vidasInimigo1 > 0){
		al_draw_filled_rectangle(pos_xEnemy1, pos_yEnemys, pos_xEnemy1 + 30, pos_yEnemys + 30, al_map_rgb(0, 255, 0));
	}
	
	if (vidasInimigo2 > 0) {
		al_draw_filled_rectangle(pos_xEnemy2, pos_yEnemys, pos_xEnemy2 + 30, pos_yEnemys + 30, al_map_rgb(0, 255, 0));
	}

	if (vidasInimigo3 > 0) {
		al_draw_filled_rectangle(pos_xEnemy3, pos_yEnemys, pos_xEnemy3 + 30, pos_yEnemys + 30, al_map_rgb(0, 255, 0));
	}
}

//MAIN
int main(){
	
	const int largura_tela = 500, altura_tela = 500; //Define altura e largura do prot�tipo da tela;
	bool x = true; //Vari�vel que ser� usada para movimenta��o dos inimigos com o intuito de evitar conflitos
	bool fim = false; //vari�vel apenas pra idenficar o fim do jogo futuramente;
	bool teclas[] = { false, false, false, false, false };
	//Posi��o que iniciar� o jogador;
	int pos_x = 250, pos_y = 401;
	//Regi�o de ataque dos inimigos
	int regiaoDeAtaque = 335;
	//Posi��es que os inimigos iniciar�o;
	int pos_xEnemy1 = 50, pos_xEnemy2 = 250, pos_xEnemy3 = 450, pos_yEnemys = 101;
	//Vari�vel para uso dos tiros que sair�o dos Inimigos
	int pos_yAtaque = pos_yEnemys;
	bool primeiroTiro = true;
	//Vari�vel para velocidade de rodagem do jogo
	int FPS = 60;
	//Vari�vel para vidas do jogador;
	int vidasJogador = 5;
	//Vari�vel para vidas dos inimigos;
	int vidasInimigo1 = 5, vidasInimigo2 = 5, vidasInimigo3 = 5;
	//TELA DO JOGO
	al_init();
	ALLEGRO_DISPLAY* display = 0; //criando tela do jogo com ponteiro fazendo refer�ncia em ALLEGRO_DISPLAY;
	display = al_create_display(largura_tela, altura_tela); //fun��o que cria um display (eixo x, eixo y);
	
	//INICIALIZA��O DE TEMPORIZADOR
	ALLEGRO_TIMER* timer = 0;

	//INICIALIZA��O DE ADDONS
	al_init_primitives_addon();
	al_install_keyboard();

	timer = al_create_timer(1.5 / FPS);

	//INICIALIZA��O DE EVENTOS
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois n�o h� eventos ainda);
	fila_eventos = al_create_event_queue(); //fun��o para guardar os eventos gerados dentro da vari�vel "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(display)); //eventos de display 
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer


	al_start_timer(timer);
	
	while (fim == false && vidasJogador > 0) {
		//JOGADOR
		jogador(pos_x, pos_y);
		
		//INIMIGOS
		inimigos(pos_xEnemy1, pos_xEnemy2, pos_xEnemy3, pos_yEnemys, vidasInimigo1, vidasInimigo2, vidasInimigo3);
			
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
						if (pos_yEnemys < 300 && x == true) {
							if(pos_y <= regiaoDeAtaque) {
								if (primeiroTiro == true) { 
									pos_yAtaque = pos_yEnemys;
									primeiroTiro = false;
								}

								pos_yEnemys -= 3; //entra em conflito com pos_yEnemys += 3 e trava os inimigos na posi��o
								al_draw_filled_rectangle(pos_xEnemy1 + 15, pos_yAtaque + 32, (pos_xEnemy1 + 15) + 5, (pos_yAtaque + 32) + 5, al_map_rgb(255, 0, 0));
								al_draw_filled_rectangle(pos_xEnemy2 + 15, pos_yAtaque + 32, (pos_xEnemy2 + 15) + 5, (pos_yAtaque + 32) + 5, al_map_rgb(255, 0, 0));
								al_draw_filled_rectangle(pos_xEnemy3 + 15, pos_yAtaque + 32, (pos_xEnemy3 + 15) + 5, (pos_yAtaque + 32) + 5, al_map_rgb(255, 0, 0));
								pos_yAtaque += 15;
								
								if (pos_yAtaque > 501) {
									pos_yAtaque = pos_yEnemys;
								}
							}
							pos_yEnemys += 3;
						}
						else {
							if (pos_yEnemys ==101) {
								x = true;
							}
							else {
								pos_yEnemys -= 3;
								x = false;
							}
						}

						if (teclas[CIMA] && !teclas[DIREITA] && !teclas[ESQUERDA] &&pos_y >=0) {
							pos_y -= teclas[CIMA] * 3;
						}
						else {
							if (teclas[BAIXO] && !teclas[DIREITA] && !teclas[ESQUERDA] &&pos_y <470){
								pos_y += teclas[BAIXO] * 3;
							}
							else {
								if (teclas[DIREITA] && pos_x <469) {
									pos_x += teclas[DIREITA] * 3;
								}
								else {
									if (teclas[ESQUERDA] && pos_x >= 4) {
										pos_x -= teclas[ESQUERDA] * 3;
									}
								}
							} //tem que criar uma condi��o pra tecla espa�o com o intuito de atirar
						}
					}
				}

			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0)); //Pra limpar a tela quando movermos os objetos, n�o deixando rastros
		}
		
	}

	//FINALIZA��O DO PROGRAMA
	al_destroy_display(display);
	al_destroy_event_queue(fila_eventos);
	al_destroy_timer(timer);
	return 0;
}

