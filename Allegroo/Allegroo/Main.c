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

void CutsCene_Introduction(ALLEGRO_TIMER* timer) {

}

void CutsCene_1(ALLEGRO_TIMER* timer) {

}

void Cutscene_2(ALLEGRO_TIMER* timer) {
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois não há eventos ainda);
	ALLEGRO_BITMAP* cutscene = NULL;
	fila_eventos = al_create_event_queue(); //função para guardar os eventos gerados dentro da variável "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer


	bool cut = false;
	cutscene = al_load_bitmap("sprites/Cutscenes/cut2.jpg");
	al_draw_bitmap(cutscene, 0, 0, 0);
	al_flip_display();

	while (!cut) {
		ALLEGRO_EVENT mn;

		al_wait_for_event(fila_eventos, &mn);

		if (mn.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (mn.keyboard.keycode == ALLEGRO_KEY_ENTER)
				cut = true;
		}

	}
	al_destroy_event_queue(fila_eventos);
	al_destroy_bitmap(cutscene);
}

void Cutscene_3(ALLEGRO_TIMER* timer) {
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois não há eventos ainda);
	ALLEGRO_BITMAP* cutscene = NULL;
	fila_eventos = al_create_event_queue(); //função para guardar os eventos gerados dentro da variável "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer


	bool cut = false;
	cutscene = al_load_bitmap("sprites/Cutscenes/cut3.jpg");
	al_draw_bitmap(cutscene, 0, 0, 0);
	al_flip_display();

	while (!cut) {
		ALLEGRO_EVENT mn;
		al_wait_for_event(fila_eventos, &mn);

		if (mn.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (mn.keyboard.keycode == ALLEGRO_KEY_ENTER)
				cut = true;
		}

	}
	al_destroy_event_queue(fila_eventos);
	al_destroy_bitmap(cutscene);
}

void Cutscene_Vitoria(ALLEGRO_TIMER* timer) {
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois não há eventos ainda);
	ALLEGRO_BITMAP* cutscene = NULL;
	fila_eventos = al_create_event_queue(); //função para guardar os eventos gerados dentro da variável "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer

	bool cut = false;
	cutscene = al_load_bitmap("sprites/Cutscenes/Vitoria.jpg");
	al_draw_bitmap(cutscene, 0, 0, 0);
	al_flip_display();

	while (!cut) {
		ALLEGRO_EVENT mn;
		al_wait_for_event(fila_eventos, &mn);

		if (mn.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (mn.keyboard.keycode == ALLEGRO_KEY_ENTER)
				cut = true;
		}

	}
	al_destroy_event_queue(fila_eventos);
	al_destroy_bitmap(cutscene);
}

void Cutscene_GameOver(ALLEGRO_TIMER* timer) {
	ALLEGRO_EVENT_QUEUE* fila_eventos = 0; //iniciando eventos com ponteiro em fila_eventos (=0, pois não há eventos ainda);
	ALLEGRO_BITMAP* cutscene = NULL;
	fila_eventos = al_create_event_queue(); //função para guardar os eventos gerados dentro da variável "fila_eventos";
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); //eventos de teclado (keyboard)
	al_register_event_source(fila_eventos, al_get_display_event_source(timer)); //eventos de timer

	bool cut = false;
	cutscene = al_load_bitmap("sprites/Cutscenes/GameOver.jpg");
	al_draw_bitmap(cutscene, 0, 0, 0);
	al_flip_display();

	while (!cut) {
		ALLEGRO_EVENT mn;
		al_wait_for_event(fila_eventos, &mn);

		if (mn.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (mn.keyboard.keycode == ALLEGRO_KEY_ENTER)
				cut = true;
		}

	}
	al_destroy_event_queue(fila_eventos);
	al_destroy_bitmap(cutscene);
}

void  jogador(ALLEGRO_BITMAP* player, int pos_x, int pos_y, int constante, int vidasJogador[], ALLEGRO_BITMAP* heart[]) {
	al_draw_bitmap(player, pos_x, pos_y, constante);
	for (int i = 8; i > 0; i--) {
		if (vidasJogador[0] == i) {
			al_draw_bitmap(heart[i], pos_x - 10, pos_y + 52, constante);
		}
	}
}

void inimigos(ALLEGRO_BITMAP* enemy[], ALLEGRO_BITMAP* enemyFaseTwo[], ALLEGRO_BITMAP* enemyFaseThree[], int pos_xEnemys[], int pos_yEnemys[], int pos_xEnemysFaseTwo[], int pos_yEnemysFaseTwo[], int pos_xEnemysFaseThree[], int pos_yEnemysFaseThree[], int constante, int vidasInimigos[], int vidasInimigosFaseTwo[], int vidasInimigosFaseThree[], ALLEGRO_BITMAP* eHeart[], bool fases[]) {
	//INIMIGOS FASE 1
	if (fases[0]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 5; j > 0; j--) {
				if (vidasInimigos[i] == j) {
					al_draw_bitmap(enemy[i], pos_xEnemys[i], pos_yEnemys[i], constante);
					al_draw_bitmap(eHeart[j], pos_xEnemys[i] + 10, pos_yEnemys[i] - 30, constante);
				}
			}
		}
	}
	else if (fases[1]) {
		//Blocos de Criação e Verificação dos Tanques
		for (int i = 0; i < 2; i++) {
			for (int j = 10; j > 0; j--) {
				if (vidasInimigosFaseTwo[i] == j) {
					al_draw_bitmap(enemyFaseTwo[i], pos_xEnemysFaseTwo[i], pos_yEnemysFaseTwo[i], constante);
					al_draw_bitmap(eHeart[j], pos_xEnemysFaseTwo[i] + 5, pos_yEnemysFaseTwo[i] - 40, constante);
				}
			}
		}
		//Blocos de Criação e Verificação dos Soldados 
		for (int i = 2; i < 4; i++) {
			for (int j = 5; j > 0; j--) {
				if (vidasInimigosFaseTwo[i] == j) {
					al_draw_bitmap(enemyFaseTwo[i], pos_xEnemysFaseTwo[i], pos_yEnemysFaseTwo[i], constante);
					al_draw_bitmap(eHeart[j], pos_xEnemysFaseTwo[i] + 10, pos_yEnemysFaseTwo[i] - 30, constante);
				}
			}
		}
	}
	else if (fases[2]) {
		//Blocos de Criação e Verificação dos Soldados 
		for (int i = 0; i < 3; i++) {
			for (int j = 5; j > 0; j--) {
				if (vidasInimigosFaseThree[i] == j) {
					al_draw_bitmap(enemyFaseThree[i], pos_xEnemysFaseThree[i], pos_yEnemysFaseThree[i], constante);
					al_draw_bitmap(eHeart[j], pos_xEnemysFaseThree[i] + 10, pos_yEnemysFaseThree[i] - 30, constante);
				}
			}
		}
	}
}

//FASE 2
void faseTwo(ALLEGRO_BITMAP* enemy[], int pos_xEnemy[], int pos_yEnemy[], bool inimigoVolta[], bool inimigoVoltaDireita[], int pos_yJogador, int pos_xJogador, int vidasInimigos[], int pos_yTiro[], int pos_xTiro[], bool tiroAcertou[], int vidasJogador[], ALLEGRO_SAMPLE_INSTANCE* inst_tiro, ALLEGRO_SAMPLE_INSTANCE* inst_tank_tiro) {
	//BLOCO DE CONTROLE DO TANQUE A DIREITA
	if (vidasInimigos[0] > 0) {
		if (pos_yEnemy[0] <= 301 && inimigoVolta[0]) {
			pos_yEnemy[0] += 1; //Tanque Descendo
			al_destroy_bitmap(enemy[0]);
			enemy[0] = al_load_bitmap("sprites/tankEnemydown.png");
			if (pos_yJogador > pos_yEnemy[0] && pos_xJogador <= pos_xEnemy[0] + 70 && pos_xJogador + 35 >= pos_xEnemy[0]) {
				pos_yEnemy[0] -= 1;

				//Bloco de controle dos tiros
				al_draw_filled_rectangle(pos_xTiro[0] + 35, pos_yTiro[0] + 70, (pos_xTiro[0] + 35) + 10, (pos_yTiro[0] + 70) + 10, al_map_rgb(0, 0, 0));
				if (pos_yTiro[0] + 50 <= pos_yEnemy[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tank_tiro);
				}
				pos_yTiro[0] += 15; //velocidade dos tiros
				if (pos_yTiro[0] > pos_yJogador && (pos_xTiro[0] + 35) <= pos_xJogador + 37 && (pos_xTiro[0] + 35) + 10 >= pos_xJogador) {
					tiroAcertou[0] = true;
					vidasJogador[0] -= 4;

				}
				else {
					tiroAcertou[0] = false;
				}
				if (pos_yTiro[0] > 600 || tiroAcertou[0] == true) {
					pos_yTiro[0] = pos_yEnemy[0];
					pos_xTiro[0] = pos_xEnemy[0];
				}
			}
		}
		else if (pos_yEnemy[0] <= 67) {
			inimigoVolta[0] = true;
		}
		else {
			pos_yEnemy[0] -= 1;
			al_destroy_bitmap(enemy[0]); //Tanque Subindo
			enemy[0] = al_load_bitmap("sprites/tankEnemyup.png");
			inimigoVolta[0] = false;


			//BLOCO DE CONTROLE DOS TIROS
			if (pos_yJogador < pos_yEnemy[0] && pos_xJogador <= pos_xEnemy[0] + 70 && pos_xJogador + 35 >= pos_xEnemy[0]) {
				pos_yEnemy[0] += 1;

				al_draw_filled_rectangle(pos_xTiro[0] + 35, pos_yTiro[0] - 13, (pos_xTiro[0] + 35) + 10, (pos_yTiro[0] - 13) + 10, al_map_rgb(0, 0, 0));
				if (pos_yTiro[0] + 50 >= pos_yEnemy[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tank_tiro);
				}
				pos_yTiro[0] -= 15;
				if (pos_yTiro[0] < pos_yJogador && (pos_xTiro[0] + 35) <= pos_xJogador + 37 && (pos_xTiro[0] + 35) + 10 >= pos_xJogador) {
					tiroAcertou[1] = true;
					//vidasJogador[0] -= 4;
				}
				else {
					tiroAcertou[1] = false;
				}
				if (pos_yTiro[0] < 0 || tiroAcertou[1] == true) {
					pos_yTiro[0] = pos_yEnemy[0];
					pos_xTiro[0] = pos_xEnemy[0];
				}
			}
		}
	}
	//BLOCO DE CONTROLE DO TANQUE DA ESQUERDA
	if (vidasInimigos[1] > 0) {
		if (pos_yEnemy[1] <= 382 && inimigoVolta[1]) {
			pos_yEnemy[1] += 1; //Tanque descendo
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/tankEnemydown.png");
			if (pos_yJogador > pos_yEnemy[1] && pos_xJogador <= pos_xEnemy[1] + 70 && pos_xJogador + 35 >= pos_xEnemy[1]) {
				pos_yEnemy[1] -= 1;
				//Bloco de controle dos tiros

				al_draw_filled_rectangle(pos_xTiro[1] + 35, pos_yTiro[1] + 70, (pos_xTiro[1] + 35) + 10, (pos_yTiro[1] + 70) + 10, al_map_rgb(0, 0, 0));
				if (pos_yTiro[1] + 50 <= pos_yEnemy[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tank_tiro);
				}
				pos_yTiro[1] += 15; //velocidade dos tiros
				if (pos_yTiro[1] > pos_yJogador && (pos_xTiro[1] + 35) <= pos_xJogador + 37 && (pos_xTiro[1] + 35) + 10 >= pos_xJogador) {
					tiroAcertou[2] = true;
					//vidasJogador[0] -= 4;
				}
				else {
					tiroAcertou[2] = false;
				}
				if (pos_yTiro[1] > 600 || tiroAcertou[2] == true) {
					pos_yTiro[1] = pos_yEnemy[1];
					pos_xTiro[1] = pos_xEnemy[1];
				}
			}
			else {
				pos_yTiro[1] = pos_yEnemy[1];
				pos_xTiro[1] = pos_xEnemy[1];
			}
		}
		else if (pos_xEnemy[1] <= 300 && inimigoVoltaDireita[0]) {
			pos_xEnemy[1] += 1; //Tanque indo para Direita
			inimigoVolta[1] = false;
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/tankEnemyright.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_xJogador > pos_xEnemy[1] && pos_yJogador <= pos_yEnemy[1] + 70 && pos_yJogador + 35 >= pos_yEnemy[1]) {

				if (pos_xJogador > pos_xEnemy[1] + 80) {
					pos_xEnemy[1] -= 1;
				}
				al_draw_filled_rectangle(pos_xTiro[1] + 70, pos_yTiro[1] + 35, (pos_xTiro[1] + 70) + 10, (pos_yTiro[1] + 35) + 10, al_map_rgb(0, 0, 0));
				if (pos_xTiro[1] + 50 <= pos_xEnemy[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tank_tiro);
				}
				if (((pos_xTiro[1] + 70) + 10 > pos_xJogador && pos_xEnemy[1] < pos_xJogador) && ((pos_yTiro[1] + 35) + 10 >= pos_yJogador && pos_yTiro[1] + 35 <= pos_yJogador + 35)) {
					tiroAcertou[5] = true;
					//vidasJogador[0] -= 4;
				}
				else {
					tiroAcertou[5] = false;
				}
				pos_xTiro[1] += 15;

				if (pos_xTiro[1] > 800 || tiroAcertou[5] == true) {
					pos_xTiro[1] = pos_xEnemy[1];
					pos_yTiro[1] = pos_yEnemy[1];
				}
			}
			else {
				pos_xTiro[1] = pos_xEnemy[1];
				pos_yTiro[1] = pos_yEnemy[1];
			}
		}
		else if (pos_xEnemy[1] > 120) {
			pos_xEnemy[1] -= 1; //Tanque indo para Esquerda
			inimigoVoltaDireita[0] = false;
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/tankEnemyleft.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_xJogador < pos_xEnemy[1] && pos_yJogador <= pos_yEnemy[1] + 70 && pos_yJogador + 35 >= pos_yEnemy[1]) {
				pos_xEnemy[1] += 1;
				al_draw_filled_rectangle(pos_xTiro[1] - 2, pos_yTiro[1] + 35, (pos_xTiro[1] - 2) + 10, (pos_yTiro[1] + 35) + 10, al_map_rgb(0, 0, 0));
				if (pos_xTiro[1] - 2 >= pos_xEnemy[1] - 2) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tank_tiro);
				}
				pos_xTiro[1] -= 15;
				if ((pos_xTiro[1] <= pos_xJogador + 15 && pos_xJogador < pos_xEnemy[1]) && ((pos_yTiro[1] + 35) + 10 >= pos_yJogador && pos_yTiro[1] + 35 <= pos_yJogador + 35)) {
					tiroAcertou[4] = true;
					//vidasJogador[0] -= 4 ;
				}
				else {
					tiroAcertou[4] = false;
				}
				if (pos_xTiro[1] < 0 || tiroAcertou[4] == true) {
					pos_xTiro[1] = pos_xEnemy[1];
					pos_yTiro[1] = pos_yEnemy[1];
				}
			}
			else {
				pos_xTiro[1] = pos_xEnemy[1];
				pos_yTiro[1] = pos_yEnemy[1];
			}
		}
		else if (pos_yEnemy[1] > 100) {
			pos_yEnemy[1] -= 1; //Tanque subindo
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/tankEnemyup.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_yJogador < pos_yEnemy[1] && pos_xJogador <= pos_xEnemy[1] + 70 && pos_xJogador + 35 >= pos_xEnemy[1]) {
				pos_yEnemy[1] += 1;

				al_draw_filled_rectangle(pos_xTiro[1] + 35, pos_yTiro[1] - 13, (pos_xTiro[1] + 35) + 10, (pos_yTiro[1] - 13) + 10, al_map_rgb(0, 0, 0));
				if (pos_yTiro[1] + 50 >= pos_yEnemy[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tank_tiro);
				}
				pos_yTiro[1] -= 15;
				if (pos_yTiro[1] < pos_yJogador && (pos_xTiro[1] + 35) <= pos_xJogador + 37 && (pos_xTiro[1] + 35) + 10 >= pos_xJogador) {
					tiroAcertou[3] = true;
					//vidasJogador[0] -= 4;
				}
				else {
					tiroAcertou[3] = false;
				}
				if (pos_yTiro[1] < 0 || tiroAcertou[3] == true) {
					pos_yTiro[1] = pos_yEnemy[1];
					pos_xTiro[1] = pos_xEnemy[1];
				}
			}
			else {
				pos_yTiro[1] = pos_yEnemy[1];
				pos_xTiro[1] = pos_xEnemy[1];
			}
		}
		else {
			inimigoVolta[1] = true;
			inimigoVoltaDireita[0] = true;
		}
	}
	//BLOCO DE CONTROLE DO SOLDADO NA ESTRADA
	if (vidasInimigos[2] > 0) {
		if (pos_xEnemy[2] >= 471 && inimigoVoltaDireita[1]) {
			pos_xEnemy[2] -= 2; //Soldado indo para esquerda
			al_destroy_bitmap(enemy[2]);
			enemy[2] = al_load_bitmap("sprites/enemyleft.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_xJogador < pos_xEnemy[2] && pos_yJogador <= pos_yEnemy[2] + 35 && pos_yJogador + 35 >= pos_yEnemy[2]) {
				pos_xEnemy[2] += 2; //entra em conflito com pos_xEnemys -= 2 e os inimigos travam na posição
				al_draw_filled_rectangle(pos_xTiro[2] - 2, pos_yTiro[2] + 5, (pos_xTiro[2] - 2) + 5, (pos_yTiro[2] + 5) + 5, al_map_rgb(0, 0, 0));
				if (pos_xTiro[2] - 2 >= pos_xEnemy[2] - 2) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_xTiro[2] -= 25;
				if (pos_xTiro[2] <= pos_xJogador && pos_yTiro[2] + 5 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 35) {
					tiroAcertou[6] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[6] = false;
				}
				if (pos_xTiro[2] <= 0 || tiroAcertou[6]) {
					pos_xTiro[2] = pos_xEnemy[2];
					pos_yTiro[2] = pos_yEnemy[2];
				}
			}
			else {
				pos_xTiro[2] = pos_xEnemy[2];
				pos_yTiro[2] = pos_yEnemy[2];
			}
		}
		else if (pos_xEnemy[2] <= 741) {
			pos_xEnemy[2] += 2; //Soldado indo para Direita
			inimigoVoltaDireita[1] = false;
			al_destroy_bitmap(enemy[2]);
			enemy[2] = al_load_bitmap("sprites/enemyright.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_xJogador > pos_xEnemy[2] && pos_yJogador <= pos_yEnemy[2] + 35 && pos_yJogador + 35 >= pos_yEnemy[2]) {
				pos_xEnemy[2] -= 2;
				al_draw_filled_rectangle(pos_xTiro[2] + 50, pos_yTiro[2] + 25, (pos_xTiro[2] + 50) + 5, (pos_yTiro[2] + 25) + 5, al_map_rgb(0, 0, 0));
				if (pos_xTiro[2] + 50 <= pos_xEnemy[2] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				if ((pos_xTiro[2] + 40 >= pos_xJogador && pos_xEnemy[2] < pos_xJogador) && (pos_yTiro[2] + 25 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 20)) {
					tiroAcertou[7] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[7] = false;
				}
				pos_xTiro[2] += 25;
				if (pos_xTiro[2] > 800 || tiroAcertou[7]) {
					pos_xTiro[2] = pos_xEnemy[2];
					pos_yTiro[2] = pos_yEnemy[2];
				}
			}
			else {
				pos_xTiro[2] = pos_xEnemy[2];
				pos_yTiro[2] = pos_yEnemy[2];
			}
		}
		else {
			inimigoVoltaDireita[1] = true;
		}
	}
	//BLOCO DE CONTROLE DO SOLDADO ABAIXO
	if (vidasInimigos[3] > 0) {
		if (pos_yEnemy[3] >= 160 && inimigoVolta[2]) {
			pos_yEnemy[3] -= 2; //Soldado Subindo
			al_destroy_bitmap(enemy[3]);
			enemy[3] = al_load_bitmap("sprites/enemyup.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_yJogador < pos_yEnemy[3] && pos_xJogador <= pos_xEnemy[3] + 35 && pos_xJogador + 35 >= pos_xEnemy[3]) {
				pos_yEnemy[3] += 2;

				al_draw_filled_rectangle(pos_xTiro[3] + 30, pos_yTiro[3] - 13, (pos_xTiro[3] + 30) + 5, (pos_yTiro[3] - 13) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[3] + 50 >= pos_yEnemy[3] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[3] -= 15;
				if (pos_yTiro[3] <= pos_yJogador + 30 && pos_xTiro[3] + 30 >= pos_xJogador && pos_xTiro[3] + 20 <= pos_xJogador + 30) {
					tiroAcertou[8] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[8] = false;
				}
				if (pos_yTiro[3] < 0 || tiroAcertou[8] == true) {
					pos_xTiro[3] = pos_xEnemy[3];
					pos_yTiro[3] = pos_yEnemy[3];
				}
			}
			else {
				pos_xTiro[3] = pos_xEnemy[3];
				pos_yTiro[3] = pos_yEnemy[3];
			}
		}
		else if (pos_yEnemy[3] <= 316) {
			pos_yEnemy[3] += 2; //Soldado Descendo
			inimigoVolta[2] = false;
			al_destroy_bitmap(enemy[3]);
			enemy[3] = al_load_bitmap("sprites/enemydown.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_yJogador > pos_yEnemy[3] && pos_xJogador <= pos_xEnemy[3] + 35 && pos_xJogador + 35 >= pos_xEnemy[3]) {
				pos_yEnemy[3] -= 2;

				al_draw_filled_rectangle(pos_xTiro[3] + 8, pos_yTiro[3] + 50, (pos_xTiro[3] + 8) + 5, (pos_yTiro[3] + 50) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[3] + 50 <= pos_yEnemy[3] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[3] += 15;
				if (pos_yTiro[3] >= pos_yJogador && pos_xTiro[3] + 8 <= pos_xJogador + 35 && (pos_xTiro[3] + 8) + 5 >= pos_xJogador) {
					tiroAcertou[9] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[9] = false;
				}
				if (pos_yTiro[3] > 600 || tiroAcertou[9] == true) {
					pos_yTiro[3] = pos_yEnemy[3];
					pos_xTiro[3] = pos_xEnemy[3];
				}
			}
			else {
				pos_yTiro[3] = pos_yEnemy[3];
				pos_xTiro[3] = pos_xEnemy[3];
			}
		}
		else {
			inimigoVolta[2] = true;
		}
	}
}

void faseThree(ALLEGRO_BITMAP* enemy[], int pos_xEnemy[], int pos_yEnemy[], bool inimigoVolta[], int pos_xJogador, int pos_yJogador, int pos_xTiro[], int pos_yTiro[], bool tiroAcertou[], int vidasJogador[], int vidasInimigos[], ALLEGRO_SAMPLE_INSTANCE* inst_tiro) {
	//BLOCO DE CONTROLE DO SOLDADO 1
	if(vidasInimigos[0] > 0) {
		if (pos_yEnemy[0] <= 502 && inimigoVolta[0]) {
			pos_yEnemy[0] += 2; //Soldado Descendo
			al_destroy_bitmap(enemy[0]);
			enemy[0] = al_load_bitmap("sprites/enemydown.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_yJogador > pos_yEnemy[0] && pos_xJogador <= pos_xEnemy[0] + 35 && pos_xJogador + 35 >= pos_xEnemy[0]) {
				pos_yEnemy[0] -= 2;

				al_draw_filled_rectangle(pos_xTiro[0] + 8, pos_yTiro[0] + 50, (pos_xTiro[0] + 8) + 5, (pos_yTiro[0] + 50) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[0] + 50 <= pos_yEnemy[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[0] += 15;
				if (pos_yTiro[0] >= pos_yJogador && pos_xTiro[0] + 8 <= pos_xJogador + 35 && (pos_xTiro[0] + 8) + 5 >= pos_xJogador) {
					tiroAcertou[0] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[0] = false;
				}
				if (pos_yTiro[0] > 600 || tiroAcertou[0] == true) {
					pos_yTiro[0] = pos_yEnemy[0];
					pos_xTiro[0] = pos_xEnemy[0];
				}
			}
			else {
				pos_yTiro[0] = pos_yEnemy[0];
				pos_xTiro[0] = pos_xEnemy[0];
			}
		}
		else if (pos_yEnemy[0] <= 43) {
			inimigoVolta[0] = true;
		}
		else {
			inimigoVolta[0] = false;
			pos_yEnemy[0] -= 2; //Soldado Subindo
			al_destroy_bitmap(enemy[0]);
			enemy[0] = al_load_bitmap("sprites/enemyup.png");

			//BLOCO DE CONTROLE DOS TIROS
			if (pos_yJogador < pos_yEnemy[0] && pos_xJogador <= pos_xEnemy[0] + 35 && pos_xJogador + 35 >= pos_xEnemy[0]) {
				pos_yEnemy[0] += 2;

				al_draw_filled_rectangle(pos_xTiro[0] + 30, pos_yTiro[0] - 13, (pos_xTiro[0] + 30) + 5, (pos_yTiro[0] - 13) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[0] + 50 >= pos_yEnemy[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[0] -= 15;
				if (pos_yTiro[0] <= pos_yJogador + 30 && pos_xTiro[0] + 30 >= pos_xJogador && pos_xTiro[0] + 20 <= pos_xJogador + 30) {
					tiroAcertou[1] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[1] = false;
				}
				if (pos_yTiro[0] < 0 || tiroAcertou[1] == true) {
					pos_xTiro[0] = pos_xEnemy[0];
					pos_yTiro[0] = pos_yEnemy[0];
				}
			}
			else {
				pos_xTiro[0] = pos_xEnemy[0];
				pos_yTiro[0] = pos_yEnemy[0];
			}
		}
	}
	//BLOCO DE CONTROLE DO SOLDADO 2
	if(vidasInimigos[1] > 0) {
		if (pos_xEnemy[1] > 458 && pos_yEnemy[1] == 254) {
			pos_xEnemy[1] -= 2; //Soldado indo para a esquerda
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/enemyleft.png");
			if (pos_xEnemy[2] + 12 < pos_xEnemy[1] && pos_yEnemy[2] == pos_yEnemy[1]) {
				pos_xEnemy[1] += 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_xJogador < pos_xEnemy[1] && pos_yJogador <= pos_yEnemy[1] + 35 && pos_yJogador + 35 >= pos_yEnemy[1] && pos_xJogador >= 381) {
				pos_xEnemy[1] += 2; //entra em conflito com pos_xEnemys -= 2 e os inimigos travam na posição
				al_draw_filled_rectangle(pos_xTiro[1] - 2, pos_yTiro[1] + 5, (pos_xTiro[1] - 2) + 5, (pos_yTiro[1] + 5) + 5, al_map_rgb(0, 0, 0));
				if (pos_xTiro[1] - 2 >= pos_xEnemy[1] - 2) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_xTiro[1] -= 25;
				if (pos_xTiro[1] <= pos_xJogador && pos_yTiro[1] + 5 >= pos_yJogador && pos_yTiro[1] <= pos_yJogador + 35) {
					tiroAcertou[2] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[2] = false;
				}
				if (pos_xTiro[1] < 381 || tiroAcertou[2]) {
					pos_xTiro[1] = pos_xEnemy[1];
					pos_yTiro[1] = pos_yEnemy[1];
				}
			}
			else {
				pos_xTiro[1] = pos_xEnemy[1];
				pos_yTiro[1] = pos_yEnemy[1];
			}
		}
		else if (pos_xEnemy[1] == 458 && pos_yEnemy[1] > 64) {
			pos_yEnemy[1] -= 2; //Soldado Subindo
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/enemyup.png");
			if (pos_yEnemy[2] + 12 < pos_yEnemy[1] && pos_xEnemy[2] == pos_xEnemy[1]) {
				pos_yEnemy[1] += 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_yJogador < pos_yEnemy[1] && pos_xJogador <= pos_xEnemy[1] + 35 && pos_xJogador + 35 >= pos_xEnemy[1]) {
				pos_yEnemy[1] += 2;

				al_draw_filled_rectangle(pos_xTiro[1] + 30, pos_yTiro[1] - 13, (pos_xTiro[1] + 30) + 5, (pos_yTiro[1] - 13) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[1] + 50 >= pos_yEnemy[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[1] -= 15;
				if (pos_yTiro[1] <= pos_yJogador + 30 && pos_xTiro[1] + 30 >= pos_xJogador && pos_xTiro[1] + 20 <= pos_xJogador + 30) {
					tiroAcertou[3] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[3] = false;
				}
				if (pos_yTiro[1] < 0 || tiroAcertou[3] == true) {
					pos_xTiro[1] = pos_xEnemy[1];
					pos_yTiro[1] = pos_yEnemy[1];
				}
			}
			else {
				pos_xTiro[1] = pos_xEnemy[1];
				pos_yTiro[1] = pos_yEnemy[1];
			}
		}
		else if (pos_xEnemy[1] < 738) {
			pos_xEnemy[1] += 2; //Soldado indo para a direita
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/enemyright.png");
			if (pos_xEnemy[2] - 12 > pos_xEnemy[1] && pos_yEnemy[2] == pos_yEnemy[1]) {
				pos_xEnemy[1] -= 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_xJogador > pos_xEnemy[1] && pos_yJogador <= pos_yEnemy[1] + 35 && pos_yJogador + 35 >= pos_yEnemy[1]) {
				pos_xEnemy[1] -= 2;
				al_draw_filled_rectangle(pos_xTiro[1] + 50, pos_yTiro[1] + 25, (pos_xTiro[1] + 50) + 5, (pos_yTiro[1] + 25) + 5, al_map_rgb(0, 0, 0));
				if (pos_xTiro[1] + 50 <= pos_xEnemy[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				if ((pos_xTiro[1] + 40 >= pos_xJogador && pos_xEnemy[1] < pos_xJogador) && (pos_yTiro[1] + 25 >= pos_yJogador && pos_yTiro[1] <= pos_yJogador + 20)) {
					tiroAcertou[4] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[4] = false;
				}
				pos_xTiro[1] += 25;
				if (pos_xTiro[1] > 800 || tiroAcertou[4]) {
					pos_xTiro[1] = pos_xEnemy[1];
					pos_yTiro[1] = pos_yEnemy[1];
				}
			}
			else {
				pos_xTiro[1] = pos_xEnemy[1];
				pos_yTiro[1] = pos_yEnemy[1];
			}
		}
		else if (pos_yEnemy[1] < 254) {
			pos_yEnemy[1] += 2; //Soldado descendo
			al_destroy_bitmap(enemy[1]);
			enemy[1] = al_load_bitmap("sprites/enemydown.png");
			if (pos_yEnemy[2] - 12 > pos_yEnemy[1] && pos_xEnemy[2] == pos_xEnemy[1]) {
				pos_yEnemy[1] -= 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_yJogador > pos_yEnemy[1] && pos_xJogador <= pos_xEnemy[1] + 35 && pos_xJogador + 35 >= pos_xEnemy[1]) {
				pos_yEnemy[1] -= 2;

				al_draw_filled_rectangle(pos_xTiro[1] + 8, pos_yTiro[1] + 50, (pos_xTiro[1] + 8) + 5, (pos_yTiro[1] + 50) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[1] + 50 <= pos_yEnemy[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[1] += 15;
				if (pos_yTiro[1] >= pos_yJogador && pos_xTiro[1] + 8 <= pos_xJogador + 35 && (pos_xTiro[1] + 8) + 5 >= pos_xJogador) {
					tiroAcertou[5] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[5] = false;
				}
				if (pos_yTiro[1] > 600 || tiroAcertou[5] == true) {
					pos_yTiro[1] = pos_yEnemy[1];
					pos_xTiro[1] = pos_xEnemy[1];
				}
			}
			else {
				pos_yTiro[1] = pos_yEnemy[1];
				pos_xTiro[1] = pos_xEnemy[1];
			}
		}
	}
	//BLOCO DE CONTROLE DO SOLDADO 3
	if (vidasInimigos[2] > 0) {
		if (pos_xEnemy[2] > 458 && pos_yEnemy[2] == 254) {
			pos_xEnemy[2] -= 2; //Soldado indo para a esquerda
			al_destroy_bitmap(enemy[2]);
			enemy[2] = al_load_bitmap("sprites/enemyleft.png");
			if (pos_xEnemy[1] + 12 < pos_xEnemy[2] && pos_yEnemy[2] == pos_yEnemy[1]) {
				pos_xEnemy[2] += 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_xJogador < pos_xEnemy[2] && pos_yJogador <= pos_yEnemy[2] + 35 && pos_yJogador + 35 >= pos_yEnemy[2] && pos_xJogador >= 381) {
				pos_xEnemy[2] += 2; //entra em conflito com pos_xEnemys -= 2 e os inimigos travam na posição
				al_draw_filled_rectangle(pos_xTiro[2] - 2, pos_yTiro[2] + 5, (pos_xTiro[2] - 2) + 5, (pos_yTiro[2] + 5) + 5, al_map_rgb(0, 0, 0));
				if (pos_xTiro[2] - 2 >= pos_xEnemy[2] - 2) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_xTiro[2] -= 25;
				if (pos_xTiro[2] <= pos_xJogador && pos_yTiro[2] + 5 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 35) {
					tiroAcertou[6] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[6] = false;
				}
				if (pos_xTiro[2] < 381 || tiroAcertou[6]) {
					pos_xTiro[2] = pos_xEnemy[2];
					pos_yTiro[2] = pos_yEnemy[2];
				}
			}
			else {
				pos_xTiro[2] = pos_xEnemy[2];
				pos_yTiro[2] = pos_yEnemy[2];
			}
		}
		else if (pos_xEnemy[2] == 458 && pos_yEnemy[2] > 64) {
			pos_yEnemy[2] -= 2; //Soldado Subindo
			al_destroy_bitmap(enemy[2]);
			enemy[2] = al_load_bitmap("sprites/enemyup.png");
			if (pos_yEnemy[1] + 12 < pos_yEnemy[2] && pos_xEnemy[2] == pos_xEnemy[1]) {
				pos_yEnemy[2] += 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_yJogador < pos_yEnemy[2] && pos_xJogador <= pos_xEnemy[2] + 35 && pos_xJogador + 35 >= pos_xEnemy[2]) {
				pos_yEnemy[2] += 2;
				al_draw_filled_rectangle(pos_xTiro[2] + 30, pos_yTiro[2] - 13, (pos_xTiro[2] + 30) + 5, (pos_yTiro[2] - 13) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[2] + 50 >= pos_yEnemy[2] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[2] -= 15;
				if (pos_yTiro[2] <= pos_yJogador + 30 && pos_xTiro[2] + 30 >= pos_xJogador && pos_xTiro[2] + 20 <= pos_xJogador + 30) {
					tiroAcertou[7] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[7] = false;
				}
				if (pos_yTiro[2] < 0 || tiroAcertou[7] == true) {
					pos_xTiro[2] = pos_xEnemy[2];
					pos_yTiro[2] = pos_yEnemy[2];
				}
			}
			else {
				pos_xTiro[2] = pos_xEnemy[2];
				pos_yTiro[2] = pos_yEnemy[2];
			}
		}
		else if (pos_xEnemy[2] < 738) {
			pos_xEnemy[2] += 2; //Soldado indo para a direita
			al_destroy_bitmap(enemy[2]);
			enemy[2] = al_load_bitmap("sprites/enemyright.png");
			if (pos_xEnemy[1] - 12 > pos_xEnemy[2] && pos_yEnemy[2] == pos_yEnemy[1]) {
				pos_xEnemy[2] -= 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_xJogador > pos_xEnemy[2] && pos_yJogador <= pos_yEnemy[2] + 35 && pos_yJogador + 35 >= pos_yEnemy[2]) {
				pos_xEnemy[2] -= 2;
				al_draw_filled_rectangle(pos_xTiro[2] + 50, pos_yTiro[2] + 25, (pos_xTiro[2] + 50) + 5, (pos_yTiro[2] + 25) + 5, al_map_rgb(0, 0, 0));
				if (pos_xTiro[2] + 50 <= pos_xEnemy[2] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				if ((pos_xTiro[2] + 40 >= pos_xJogador && pos_xEnemy[2] < pos_xJogador) && (pos_yTiro[2] + 25 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 20)) {
					tiroAcertou[8] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[8] = false;
				}
				pos_xTiro[2] += 25;
				if (pos_xTiro[2] > 800 || tiroAcertou[8]) {
					pos_xTiro[2] = pos_xEnemy[2];
					pos_yTiro[2] = pos_yEnemy[2];
				}
			}
			else {
				pos_xTiro[2] = pos_xEnemy[2];
				pos_yTiro[2] = pos_yEnemy[2];
			}
		}
		else if (pos_yEnemy[2] < 254) {
			pos_yEnemy[2] += 2; //Soldado descendo
			al_destroy_bitmap(enemy[2]);
			enemy[2] = al_load_bitmap("sprites/enemydown.png");
			if (pos_yEnemy[1] - 12 > pos_yEnemy[2] && pos_xEnemy[2] == pos_xEnemy[1]) {
				pos_yEnemy[2] -= 2;
			}
			//BLOCO DE CONTROLE DOS TIROS
			else if (pos_yJogador > pos_yEnemy[2] && pos_xJogador <= pos_xEnemy[2] + 35 && pos_xJogador + 35 >= pos_xEnemy[2]) {
				pos_yEnemy[2] -= 2;
				al_draw_filled_rectangle(pos_xTiro[2] + 8, pos_yTiro[2] + 50, (pos_xTiro[2] + 8) + 5, (pos_yTiro[2] + 50) + 5, al_map_rgb(0, 0, 0));
				if (pos_yTiro[2] + 50 <= pos_yEnemy[2] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
					al_play_sample_instance(inst_tiro);
				}
				pos_yTiro[2] += 15;
				if (pos_yTiro[2] >= pos_yJogador && pos_xTiro[2] + 8 <= pos_xJogador + 35 && (pos_xTiro[2] + 8) + 5 >= pos_xJogador) {
					tiroAcertou[9] = true;
					//vidasJogador[0]--;
				}
				else {
					tiroAcertou[9] = false;
				}
				if (pos_yTiro[2] > 600 || tiroAcertou[9] == true) {
					pos_yTiro[2] = pos_yEnemy[2];
					pos_xTiro[2] = pos_xEnemy[2];
				}
			}
			else {
				pos_yTiro[2] = pos_yEnemy[2];
				pos_xTiro[2] = pos_xEnemy[2];
			}
		}
	}
}
//MAIN E FASE 1
int main() {
	const int largura_tela = 800, altura_tela = 600; //Define altura e largura do protótipo da tela;
	bool x = true, y = true, z = true, inimigoVolta[] = { true, true, true }; bool inimigoVoltaDireita[] = { true, true }, inimigoVoltaFaseThree[] = { true }; //Variáveis que serão usadas para movimentação dos inimigos com o intuito de evitar conflitos
	bool fim = false; //variável apenas pra idenficar o fim do jogo futuramente;
	bool teclas[] = { false, false, false, false, false };
	bool fases[] = { true, false, false };
	//Posição que iniciará o jogador;
	int pos_xJogador = 150, pos_yJogador = 550;
	//Variaveis para uso dos tiros que sairão do Jogador
	int pos_yTiroJogador = pos_yJogador;
	int pos_xTiroJogador = pos_xJogador;
	bool tiroAcertouInimigo = false;
	//Posições que os inimigos iniciarão;
	int pos_xEnemys[] = { 100, 300, 741 }, pos_yEnemys[] = { 90, 90, 148 };
	int pos_xEnemysFaseTwo[] = { 261, 105, 741, 696 }, pos_yEnemysFaseTwo[] = { 67, 145, 121, 316 };
	int pos_xEnemysFaseThree[] = { 252, 648, 604 }, pos_yEnemysFaseThree[] = { 43, 254, 64 };
	//Variaveis para uso dos tiros que sairão dos Inimigos
	int pos_yTiro[3];
	int pos_xTiro[3];
	for (int i = 0; i < 3; i++) {
		pos_xTiro[i] = pos_xEnemys[i]; //recebe as posições iniciais de XEnemys e YEnemys, pois os tiros saem dos inimigos né!!!
		pos_yTiro[i] = pos_yEnemys[i];
	}
	int pos_yTiroFaseTwo[4];
	int pos_xTiroFaseTwo[4];
	for (int i = 0; i < 4; i++) {
		pos_xTiroFaseTwo[i] = pos_xEnemysFaseTwo[i];
		pos_yTiroFaseTwo[i] = pos_yEnemysFaseTwo[i];
	}
	int pos_yTiroFaseThree[3];
	int pos_xTiroFaseThree[3];
	for (int i = 0; i < 3; i++) {
		pos_xTiroFaseThree[i] = pos_xEnemysFaseThree[i];
		pos_yTiroFaseThree[i] = pos_yEnemysFaseThree[i];
	}
	bool posicoes[] = { true, false, false, false };
	bool tiroAcertou[] = { false, false, false, false, false, false };
	bool tiroAcertouFaseTwo[] = { false, false, false, false, false, false, false, false, false, false };
	bool tiroAcertouFaseThree[] = { false, false, false, false, false, false, false, false, false, false };
	//bool tiroAcertouFaseThree[] = {};
	//Variável para velocidade de rodagem do jogo
	int FPS = 60;
	//Variável para vidas do jogador;
	int vidasJogador[] = { 8 };
	//Variável para vidas dos inimigos;
	int vidasInimigos[] = { 5, 5, 5 };
	int vidasInimigosFaseTwo[] = { 10, 10, 5, 5 };
	int vidasInimigosFaseThree[] = { 5, 5, 5 };
	//Variavel de Som
	ALLEGRO_SAMPLE* trilha_sonora = NULL;
	ALLEGRO_SAMPLE* tiro = NULL;
	ALLEGRO_SAMPLE* tank_tiro = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_trilha_sonora = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_tiro = NULL;
	ALLEGRO_SAMPLE_INSTANCE* inst_tank_tiro = NULL;
	//TELA DO JOGO
	al_init();
	ALLEGRO_DISPLAY* display = 0; //criando tela do jogo com ponteiro fazendo referência em ALLEGRO_DISPLAY;
	display = al_create_display(largura_tela, altura_tela); //função que cria um display (eixo x, eixo y);

	//INICIALIZAÇÂO DE TEMPORIZADOR
	ALLEGRO_TIMER* timer = 0;

	//Fonte do menu
	//ALLEGRO_FONT* font09 = al_load_font("04b.TTF", 50, NULL);

	//VARIAVEL DA IMAGEM
	ALLEGRO_BITMAP* fundoMenu = NULL;
	ALLEGRO_BITMAP* imagem = NULL;
	ALLEGRO_BITMAP* player = NULL;
	ALLEGRO_BITMAP* enemy[3] = { NULL, NULL, NULL, };
	ALLEGRO_BITMAP* enemyFaseTwo[4] = { NULL, NULL, NULL, NULL };
	ALLEGRO_BITMAP* enemyFaseThree[3] = { NULL, NULL, NULL };
	//coração player 
	ALLEGRO_BITMAP* heart[9] = { 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	//coração enemy
	ALLEGRO_BITMAP* eHeart[11] = { 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

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
	tank_tiro = al_load_sample("sounds/tank.ogg");
	inst_tank_tiro = al_create_sample_instance(tank_tiro);
	al_attach_sample_instance_to_mixer(inst_trilha_sonora, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(inst_tiro, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(inst_tank_tiro, al_get_default_mixer());
	al_set_sample_instance_playmode(inst_trilha_sonora, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_gain(inst_trilha_sonora, 0.1);
	al_set_sample_instance_gain(inst_tiro, 0.1);
	al_set_sample_instance_gain(inst_tank_tiro, 0.1);

	//CARREGAR IMAGENS
	fundoMenu = al_load_bitmap("sprites/fundo.png");
	imagem = al_load_bitmap("sprites/mapa1.png");
	player = al_load_bitmap("sprites/playerup.png");
	enemy[0] = al_load_bitmap("sprites/enemydown.png");
	enemy[1] = al_load_bitmap("sprites/enemydown.png");
	enemy[2] = al_load_bitmap("sprites/enemyleft.png");
	//coração player
	heart[1] = al_load_bitmap("sprites/heartplayer/heart1.png");
	heart[2] = al_load_bitmap("sprites/heartplayer/heart2.png");
	heart[3] = al_load_bitmap("sprites/heartplayer/heart3.png");
	heart[4] = al_load_bitmap("sprites/heartplayer/heart4.png");
	heart[5] = al_load_bitmap("sprites/heartplayer/heart5.png");
	heart[6] = al_load_bitmap("sprites/heartplayer/heart6.png");
	heart[7] = al_load_bitmap("sprites/heartplayer/heart7.png");
	heart[8] = al_load_bitmap("sprites/heartplayer/heart8.png");
	//coração inimigo
	eHeart[1] = al_load_bitmap("sprites/heartenemy/eHeart1.png");
	eHeart[2] = al_load_bitmap("sprites/heartenemy/eHeart2.png");
	eHeart[3] = al_load_bitmap("sprites/heartenemy/eHeart3.png");
	eHeart[4] = al_load_bitmap("sprites/heartenemy/eHeart4.png");
	eHeart[5] = al_load_bitmap("sprites/heartenemy/eHeart5.png");
	eHeart[6] = al_load_bitmap("sprites/heartenemy/eHeart6.png");
	eHeart[7] = al_load_bitmap("sprites/heartenemy/eHeart7.png");
	eHeart[8] = al_load_bitmap("sprites/heartenemy/eHeart8.png");
	eHeart[9] = al_load_bitmap("sprites/heartenemy/eHeart9.png");
	eHeart[10] = al_load_bitmap("sprites/heartenemy/eHeart10.png");
	//CARREGAR TRILHA SONORA
	al_play_sample_instance(inst_trilha_sonora);

	//Menu
	bool menu = false; //Váriavel de para a condição do MENU funcionar
	al_draw_bitmap(fundoMenu, 0, 0, 0);
	al_flip_display();

	while (!menu) {
		ALLEGRO_EVENT mn;

		al_wait_for_event(fila_eventos, &mn);

		if (mn.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (mn.keyboard.keycode == ALLEGRO_KEY_ENTER)
				menu = true;
		}

	}
	//Fim Menu

	while (fim == false && vidasJogador[0] > 0) {
		//JOGADOR
		jogador(player, pos_xJogador, pos_yJogador, 0, vidasJogador, heart);
		//INIMIGOS
		inimigos(enemy, enemyFaseTwo, enemyFaseThree, pos_xEnemys, pos_yEnemys, pos_xEnemysFaseTwo, pos_yEnemysFaseTwo, pos_xEnemysFaseThree, pos_yEnemysFaseThree, 0, vidasInimigos, vidasInimigosFaseTwo, vidasInimigosFaseThree, eHeart, fases);

		printf(/*"Posição no eixo X: %d ---- %d ----- %d \nPosição no eixo Y %d ---- %d: \n\n %d ----- %d"*/"x = %d e y = %d", /*pos_xEnemys[0], pos_xEnemys[1], pos_xEnemys[2], pos_yEnemys[0] - 20, pos_yEnemys[0],*/ pos_xJogador, pos_yJogador);

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
						if (fases[0]) {
							//INIMIGO 1
							if (pos_yEnemys[0] <= 300 && x) {
								al_destroy_bitmap(enemy[0]);
								enemy[0] = al_load_bitmap("sprites/enemydown.png");
								if (pos_yJogador > pos_yEnemys[0] && pos_xJogador <= pos_xEnemys[0] + 35 && pos_xJogador + 35 >= pos_xEnemys[0] && vidasInimigos[0] > 0) {
									if (pos_yEnemys[0] <= 215) {
										pos_yEnemys[0] -= 1;  //entra em conflito com pos_yEnemys += 2 e os inimigos andam de uma em uma casa
									}
									else {
										pos_yEnemys[0] -= 2; //entra em conflito com pos_yEnemys += 2 e os inimigos travam na posição
									}

									//Bloco de controle dos tiros dos inimigos
									al_draw_filled_rectangle(pos_xTiro[0] + 8, pos_yTiro[0] + 50, (pos_xTiro[0] + 8) + 5, (pos_yTiro[0] + 50) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiro[0] + 50 <= pos_yEnemys[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									pos_yTiro[0] += 15; //velocidade dos tiros
									if (pos_yTiro[0] >= pos_yJogador && pos_xTiro[0] + 8 >= pos_xJogador && pos_xTiro[0] <= pos_xJogador + 35) {
										tiroAcertou[0] = true;
										//vidasJogador[0]--;
									}
									else {
										tiroAcertou[0] = false;
									}
									if (pos_yTiro[0] > 600 || tiroAcertou[0] == true) {
										pos_yTiro[0] = pos_yEnemys[0];
									}
								}
								else {
									pos_yTiro[0] = pos_yEnemys[0];
								}
								pos_yEnemys[0] += 2;
							}
							else if (pos_yEnemys[0] <= 90) {
								x = true;
							}
							else {
								pos_yEnemys[0] -= 2;
								x = false;
								al_destroy_bitmap(enemy[0]);
								enemy[0] = al_load_bitmap("sprites/enemyup.png");
								if (pos_yJogador < pos_yEnemys[0] && pos_xJogador <= pos_xEnemys[0] + 35 && pos_xJogador + 35 >= pos_xEnemys[0] && vidasInimigos[0] > 0) {
									pos_yEnemys[0] += 1;
									al_draw_filled_rectangle(pos_xTiro[0] + 30, pos_yTiro[0] - 13, (pos_xTiro[0] + 30) + 5, (pos_yTiro[0] - 13) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiro[0] + 50 >= pos_yEnemys[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									pos_yTiro[0] -= 15;
									if (pos_yTiro[0] <= pos_yJogador + 30 && pos_xTiro[0] + 30 >= pos_xJogador && pos_xTiro[0] + 20 <= pos_xJogador + 30) {
										tiroAcertou[3] = true;
										//vidasJogador[0]--;
									}
									else {
										tiroAcertou[3] = false;
									}
									if (pos_yTiro[0] < 0 || tiroAcertou[3] == true) {
										pos_yTiro[0] = pos_yEnemys[0];
									}
								}
								else {
									pos_yTiro[0] = pos_yEnemys[0];
								}
							}

							//INIMIGO 2
							if (pos_yEnemys[1] <= 300 && z) {
								al_destroy_bitmap(enemy[1]);
								enemy[1] = al_load_bitmap("sprites/enemydown.png");
								if (pos_yJogador > pos_yEnemys[1] && pos_xJogador <= pos_xEnemys[1] + 35 && pos_xJogador + 35 >= pos_xEnemys[1] && vidasInimigos[1] > 0) {
									if (pos_yEnemys[1] <= 215) {
										pos_yEnemys[1] -= 1;  //entra em conflito com pos_yEnemys += 2 e os inimigos andam de uma em uma casa
									}
									else {
										pos_yEnemys[1] -= 2; //entra em conflito com pos_yEnemys += 2 e os inimigos travam na posição
									}

									//Bloco de controle dos tiros dos inimigos
									al_draw_filled_rectangle(pos_xTiro[1] + 8, pos_yTiro[1] + 50, (pos_xTiro[1] + 8) + 5, (pos_yTiro[1] + 50) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiro[1] + 50 <= pos_yEnemys[1] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									pos_yTiro[1] += 15; //velocidade dos tiros
									if (pos_yTiro[1] >= pos_yJogador && pos_xTiro[1] + 8 >= pos_xJogador && pos_xTiro[1] <= pos_xJogador + 35) {
										tiroAcertou[4] = true;
										//vidasJogador[0]--;
									}
									else {
										tiroAcertou[4] = false;
									}
									if (pos_yTiro[1] > 600 || tiroAcertou[4] == true) {
										pos_yTiro[1] = pos_yEnemys[1];
									}
								}
								else {
									pos_yTiro[1] = pos_yEnemys[1];
								}
								pos_yEnemys[1] += 2;
							}
							else if (pos_yEnemys[1] <= 90) {
								z = true;
							}
							else {
								pos_yEnemys[1] -= 2;
								z = false;
								al_destroy_bitmap(enemy[1]);
								enemy[1] = al_load_bitmap("sprites/enemyup.png");
								if (pos_yJogador < pos_yEnemys[1] && pos_xJogador <= pos_xEnemys[1] + 35 && pos_xJogador + 35 >= pos_xEnemys[1] && vidasInimigos[1] > 0) {
									pos_yEnemys[1] += 1;
									al_draw_filled_rectangle(pos_xTiro[1] + 30, pos_yTiro[1] - 13, (pos_xTiro[1] + 30) + 5, (pos_yTiro[1] - 13) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiro[0] + 50 >= pos_yEnemys[0] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									pos_yTiro[1] -= 15;
									if (pos_yTiro[1] <= pos_yJogador + 30 && pos_xTiro[1] + 30 >= pos_xJogador && pos_xTiro[1] + 20 <= pos_xJogador + 30) {
										tiroAcertou[5] = true;
										//vidasJogador[0]--;
									}
									else {
										tiroAcertou[5] = false;
									}
									if (pos_yTiro[1] < 0 || tiroAcertou[5] == true) {
										pos_yTiro[1] = pos_yEnemys[1];
									}
								}
								else {
									pos_yTiro[1] = pos_yEnemys[1];
								}
							}

							//INIMIGO 3
							if (pos_xEnemys[2] >= 432 && y && vidasInimigos[2] > 0) {
								al_destroy_bitmap(enemy[2]);
								enemy[2] = al_load_bitmap("sprites/enemyleft.png");
								pos_xEnemys[2] -= 2;

								//BLOCO DE CONTROLE DOS TIROS
								if (pos_xJogador < pos_xEnemys[2] && pos_yJogador <= pos_yEnemys[2] + 35 && pos_yJogador + 35 >= pos_yEnemys[2]) {
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
										//vidasJogador[0]--;
									}
									else {
										tiroAcertou[1] = false;
									}
								}
								else {
									pos_xTiro[2] = pos_xEnemys[2];
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
									if (pos_xJogador > pos_xEnemys[2] && pos_yJogador <= pos_yEnemys[2] + 35 && pos_yJogador + 35 >= pos_yEnemys[2] && vidasInimigos[2] > 0) {
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
											//vidasJogador[0]--;
										}
										else {
											tiroAcertou[2] = false;
										}
										pos_xTiro[2] += 25;
									}
									else {
										pos_xTiro[2] = pos_xEnemys[2];
									}
								}
							}
							if (pos_xTiro[2] < 0 || pos_xTiro[2] > 800 || tiroAcertou[1] == true || tiroAcertou[2] == true) {
								pos_xTiro[2] = pos_xEnemys[2];
							}
							//MAPA 2
							for (int i = 360; i < 430; i++) {
								if (pos_xJogador == i && pos_yJogador == -2 && vidasInimigos[0] <= 0 && vidasInimigos[1] <= 0 && vidasInimigos[2] <= 0) {
									Cutscene_2(timer);
									al_destroy_bitmap(imagem);
									imagem = al_load_bitmap("sprites/mapa2.png");
									enemyFaseTwo[0] = al_load_bitmap("sprites/tankEnemydown.png");
									enemyFaseTwo[1] = al_load_bitmap("sprites/tankEnemydown.png");
									enemyFaseTwo[2] = al_load_bitmap("sprites/enemyleft.png");
									enemyFaseTwo[3] = al_load_bitmap("sprites/enemyup.png");
									pos_xJogador = 360; pos_yJogador = 550; vidasJogador[0] = 8;
									fases[0] = false; fases[1] = true;
								}
							}
						}
						else if (fases[1]) {
							faseTwo(enemyFaseTwo, pos_xEnemysFaseTwo, pos_yEnemysFaseTwo, inimigoVolta, inimigoVoltaDireita, pos_yJogador, pos_xJogador, vidasInimigosFaseTwo, pos_yTiroFaseTwo, pos_xTiroFaseTwo, tiroAcertouFaseTwo, vidasJogador, inst_tiro, inst_tank_tiro);
							//MAPA 3
							for (int i = 88; i < 189; i++) {
								if (pos_xJogador == 750 && pos_yJogador == i && vidasInimigosFaseTwo[0] <= 0 && vidasInimigosFaseTwo[1] <= 0 && vidasInimigosFaseTwo[2] <= 0 && vidasInimigosFaseTwo[3] <= 0) {
									Cutscene_3(timer);
									al_destroy_bitmap(imagem);
									imagem = al_load_bitmap("sprites/mapa3.png");
									enemyFaseThree[0] = al_load_bitmap("sprites/enemydown.png");
									enemyFaseThree[1] = al_load_bitmap("sprites/enemyleft.png");
									enemyFaseThree[2] = al_load_bitmap("sprites/enemyright.png");
									pos_xJogador = 12;
									pos_yJogador = 229;
									vidasJogador[0] = 8;
									fases[1] = false;
									fases[2] = true;
								}
							}
						}
						else if (fases[2]) {
							faseThree(enemyFaseThree, pos_xEnemysFaseThree, pos_yEnemysFaseThree, inimigoVoltaFaseThree, pos_xJogador, pos_yJogador, pos_xTiroFaseThree, pos_yTiroFaseThree, tiroAcertouFaseThree, vidasJogador, vidasInimigosFaseThree, inst_tiro);
							for (int i = 579; i < 628; i++) {
								if (pos_xJogador == i && pos_yJogador == -2) { //&& vidasInimigosFaseThree[0] <= 0 && vidasInimigosFaseThree[1] <= 0 && vidasInimigosFaseThree[2] <= 0) {
									Cutscene_Vitoria(timer);
									fases[2] = false;
								}
							}
						}
						else {
							fim = true;
						}
						//BLOCO DE CONTROLE DE MOVIMENTAÇÂO E TIROS DO JOGADOR
						if (teclas[SPACE]) {
							if (posicoes[cima]) { //se a img do jogador estiver posicionada para cima
								al_draw_filled_rectangle(pos_xTiroJogador + 30, pos_yTiroJogador - 13, (pos_xTiroJogador + 30) + 5, (pos_yTiroJogador - 13) + 5, al_map_rgb(0, 0, 0));
								if (pos_yTiroJogador - 13 == pos_yJogador - 13) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
									al_play_sample_instance(inst_tiro);
								}
								pos_yTiroJogador -= 20;
								//Intervalos para Acertar Inimigos na Fase 1
								if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[0] && pos_xTiroJogador + 20 <= pos_xEnemys[0] + 30) && vidasInimigos[0] > 0) {
									tiroAcertouInimigo = true;
									vidasInimigos[0]--;
								}
								else if ((pos_yTiroJogador <= pos_yEnemys[1] + 30 && pos_yJogador >= pos_yEnemys[1]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[1] && pos_xTiroJogador + 20 <= pos_xEnemys[1] + 30) && vidasInimigos[1] > 0) {
									tiroAcertouInimigo = true;
									vidasInimigos[1]--;
								}
								//Intervalos para Acertar Inimigos na Fase 2
								else if ((pos_yTiroJogador <= pos_yEnemysFaseTwo[0] + 70 && pos_yJogador >= pos_yEnemysFaseTwo[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemysFaseTwo[0] && pos_xTiroJogador + 20 <= pos_xEnemysFaseTwo[0] + 70) && vidasInimigosFaseTwo[0] > 0 && fases[1]) {
									tiroAcertouInimigo = true;
									vidasInimigosFaseTwo[0]--;
								}
								else if ((pos_yTiroJogador <= pos_yEnemysFaseTwo[1] + 70 && pos_yJogador >= pos_yEnemysFaseTwo[1]) && ((pos_xTiroJogador + 30) >= pos_xEnemysFaseTwo[1] && pos_xTiroJogador + 20 <= pos_xEnemysFaseTwo[1] + 70) && vidasInimigosFaseTwo[1] > 0 && fases[1]) {
									tiroAcertouInimigo = true;
									vidasInimigosFaseTwo[1]--;
								}
								else if (pos_yTiroJogador <= pos_yEnemysFaseTwo[3] + 35 && pos_yJogador >= pos_yEnemysFaseTwo[3] && pos_xTiroJogador + 30 >= pos_xEnemysFaseTwo[3] && pos_xTiroJogador + 20 <= pos_xEnemysFaseTwo[3] + 35 && vidasInimigosFaseTwo[3] > 0 && fases[1]) {
									tiroAcertouInimigo = true;
									vidasInimigosFaseTwo[3]--;
								}
								//Intervalos para Acertar Inimigos na Fase 3
								else if ((pos_yTiroJogador <= pos_yEnemysFaseThree[0] + 70 && pos_yJogador >= pos_yEnemysFaseThree[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemysFaseThree[0] && pos_xTiroJogador + 20 <= pos_xEnemysFaseThree[0] + 70) && vidasInimigosFaseThree[0] > 0 && fases[2]) {
									tiroAcertouInimigo = true;
									vidasInimigosFaseThree[0]--;
								}
								else {
									tiroAcertouInimigo = false;
								}
							}
							else {
								if (posicoes[baixo]) { //se o personagem estiver para baixo
									al_draw_filled_rectangle(pos_xTiroJogador + 8, pos_yTiroJogador + 50, (pos_xTiroJogador + 8) + 5, (pos_yTiroJogador + 50) + 5, al_map_rgb(0, 0, 0));
									if (pos_yTiroJogador + 50 == pos_yJogador + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
										al_play_sample_instance(inst_tiro);
									}
									//Intervalos para Acertar Inimigos na Fase 1
									if (pos_yTiroJogador >= pos_yEnemys[0] - 30 && pos_yEnemys[0] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemys[0] && pos_xTiroJogador + 8 <= pos_xEnemys[0] + 35 && vidasInimigos[0] > 0) { //corrigir
										tiroAcertouInimigo = true;
										vidasInimigos[0]--;
									}
									else if (pos_yTiroJogador >= pos_yEnemys[1] - 30 && pos_yEnemys[1] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemys[1] && pos_xTiroJogador + 8 <= pos_xEnemys[1] + 35 && vidasInimigos[1] > 0) {
										tiroAcertouInimigo = true;
										vidasInimigos[1]--;
									}
									//Intervalos para Acertar Inimigos na Fase 2
									else if (pos_yTiroJogador >= pos_yEnemysFaseTwo[0] - 30 && pos_yEnemysFaseTwo[0] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemysFaseTwo[0] && pos_xTiroJogador + 8 <= pos_xEnemysFaseTwo[0] + 70 && vidasInimigosFaseTwo[0] > 0 && fases[1]) {
										tiroAcertouInimigo = true;
										vidasInimigosFaseTwo[0]--;
									}
									else if (pos_yTiroJogador >= pos_yEnemysFaseTwo[1] - 30 && pos_yEnemysFaseTwo[1] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemysFaseTwo[1] && pos_xTiroJogador + 8 <= pos_xEnemysFaseTwo[1] + 70 && vidasInimigosFaseTwo[1] > 0 && fases[1]) {
										tiroAcertouInimigo = true;
										vidasInimigosFaseTwo[1]--;
									}
									else if (pos_yTiroJogador >= pos_yEnemysFaseTwo[3] - 30 && pos_yEnemysFaseTwo[3] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemysFaseTwo[3] && pos_xTiroJogador + 8 <= pos_xEnemysFaseTwo[3] + 35 && vidasInimigosFaseTwo[3] > 0 && fases[1]) {
										tiroAcertouInimigo = true;
										vidasInimigosFaseTwo[3]--;
									}
									//Intervalos para Acertar Inimigos na Fase 3
									else if (pos_yTiroJogador >= pos_yEnemysFaseThree[0] - 30 && pos_yEnemysFaseThree[0] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemysFaseThree[0] && pos_xTiroJogador + 8 <= pos_xEnemysFaseThree[0] + 70 && vidasInimigosFaseThree[0] > 0 && fases[2]) {
										tiroAcertouInimigo = true;
										vidasInimigosFaseThree[0]--;
									}
									else {
										tiroAcertouInimigo = false;
									}
									pos_yTiroJogador += 20;
								}
								else {
									if (posicoes[direita]) { //se o personagem estiver para a direita
										al_draw_filled_rectangle(pos_xTiroJogador + 50, pos_yTiroJogador + 25, (pos_xTiroJogador + 50) + 5, (pos_yTiroJogador + 25) + 5, al_map_rgb(0, 0, 0));
										if (pos_xTiroJogador + 50 == pos_xJogador + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
											al_play_sample_instance(inst_tiro);
										}
										//Intervalos para Acertar Inimigos na Fase 1
										if ((pos_xTiroJogador + 40 >= pos_xEnemys[2] && pos_xEnemys[2] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemys[2] && pos_yTiroJogador <= pos_yEnemys[2] + 20 && vidasInimigos[2] > 0)) {
											tiroAcertouInimigo = true;
											vidasInimigos[2]--;
										}
										//Intervalos para Acertar Inimigos na Fase 2
										else if ((pos_xTiroJogador + 40 >= pos_xEnemysFaseTwo[1] && pos_xEnemysFaseTwo[1] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemysFaseTwo[1] && pos_yTiroJogador <= pos_yEnemysFaseTwo[1] + 70 && vidasInimigosFaseTwo[1] > 0 && fases[1])) {
											tiroAcertouInimigo = true;
											vidasInimigosFaseTwo[1]--;
										}
										else if ((pos_xTiroJogador + 40 >= pos_xEnemysFaseTwo[2] && pos_xEnemysFaseTwo[2] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemysFaseTwo[2] && pos_yTiroJogador <= pos_yEnemysFaseTwo[2] + 20 && vidasInimigosFaseTwo[2] > 0 && fases[1])) {
											tiroAcertouInimigo = true;
											vidasInimigosFaseTwo[2]--;
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
											//Intervalos para Acertar Inimigos na Fase 1
											if (pos_xTiroJogador - 40 <= pos_xEnemys[2] && pos_xEnemys[2] < pos_xJogador && pos_yTiroJogador + 5 >= pos_yEnemys[2] && pos_yTiroJogador <= pos_yEnemys[2] + 35 && vidasInimigos[2] > 0) {
												tiroAcertouInimigo = true;
												vidasInimigos[2]--;
											}
											//Intervalos para Acertar Inimigos na Fase 2
											else if ((pos_xTiroJogador - 40 <= pos_xEnemysFaseTwo[1] && pos_xEnemysFaseTwo[1] < pos_xJogador) && (pos_yTiroJogador + 5 >= pos_yEnemysFaseTwo[1] && pos_yTiroJogador <= pos_yEnemysFaseTwo[1] + 70 && vidasInimigosFaseTwo[1] > 0 && fases[1])) {
												tiroAcertouInimigo = true;
												vidasInimigosFaseTwo[1]--;
											}
											else if ((pos_xTiroJogador - 40 <= pos_xEnemysFaseTwo[2] && pos_xEnemysFaseTwo[2] < pos_xJogador) && (pos_yTiroJogador + 5 >= pos_yEnemysFaseTwo[2] && pos_yTiroJogador <= pos_yEnemysFaseTwo[2] + 35 && vidasInimigosFaseTwo[2] > 0 && fases[1])) {
												tiroAcertouInimigo = true;
												vidasInimigosFaseTwo[2]--;
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
			//printf("posicao x %d ---- %d ---- %d", pos_xEnemys[0], pos_xEnemys[1], pos_xEnemys[2]);
			//COLISÕES PRA CIMA
			//soldado esquerda
			for (int i = 70; i < 130; i++) { //espaco de posições que representam a largura do inimigo (x)
				for (int j = 35; j > 0; j--) { //intervalo da colisão
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 270; i < 330; i++) { //espaco de posições que representam a largura do inimigo (x)
				for (int j = 35; j > 0; j--) { //intevalo de espaço
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] + j) && fases[0]) {
						teclas[CIMA] = false;
					}
				}

			}
			//soldado direita
			for (int i = 190; i > 100; i--) { //espaco de posições que representam 
				for (int j = 35; j > -35; j--) { //espaco de posições para a parada do jogador
					if ((pos_yJogador == i) && (pos_xJogador == pos_xEnemys[2] + j) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//COLISÕES PRA BAIXO
			//soldado esquerda
			for (int i = 90; i < 110; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//soldado meio
			for (int i = 290; i < 310; i++) { //espaco de posições que representam 
				for (int j = 35; j > 0; j--) { //espaco de posições para a parada do jogador
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - j) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//soldado direita
			for (int i = 100; i < 130; i++) { //espaco de posições que representam 
				for (int j = 35; j > -35; j--) { //espaco de posições para a parada do jogador
					if ((pos_yJogador == i) && (pos_xJogador == pos_xEnemys[2] - j) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//COLISÕES PRA DIREITA
			//soldado esquerda
			for (int i = 70; i < 100; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j)) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 270; i < 300; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j)) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//soldado direita
			for (int i = 100; i < 160; i++) { //espaco de posições para a parada do jogador
				for (int j = 35; j > 0; j--) { //espaco de posições que representam 
					if ((pos_yJogador == i) && (pos_xJogador == pos_xEnemys[2] - (j)) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//COLISÕES PRA ESQUERDA
			//soldado esquerda
			for (int i = 150; i > 100; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j)) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//soldado meio
			for (int i = 350; i > 300; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[0] - (j)) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//soldado direita
			for (int i = 160; i > 100; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[2] - (j)) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//COLISÕES COM OBJETOS

			//ÁGUA	
			//Direita
			for (int i = 445; i < 600; i++) {
				for (int j = 300; j < 320; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			for (int i = 375; i < 446; i++) {
				for (int j = 483; j < 500; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//Baixo
			for (int i = 445; i <= 460; i++) {
				for (int j = 300; j <= 483; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			for (int i = 375; i < 390; i++) {
				for (int j = 483; j <= 771; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}

			//ARVORE1
			//cima
			for (int i = 30; i <= 35; i++) {//i é y
				for (int j = 0; j <= 68; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo
			for (int i = 125; i < 130; i++) {//i é y
				for (int j = 0; j < 68; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 40; i < 120; i++) {//i é y
				for (int j = 0; j < 70; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//esquerda (não tem)

			//ARVORE 2
			//cima (não tem)			
			//baixo
			for (int i = 80; i < 85; i++) {//i é y
				for (int j = 190; j < 258; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = -2; i < 80; i++) {//i é y
				for (int j = 185; j < 190; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = -2; i < 80; i++) {//i é y
				for (int j = 273; j < 278; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//ARVORE 3
			//cima
			for (int i = 10; i <= 15; i++) {//i é y
				for (int j = 660; j <= 745; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo
			for (int i = 105; i < 107; i++) {//i é y
				for (int j = 663; j < 747; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 30; i < 90; i++) {//i é y
				for (int j = 653; j < 660; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 25; i < 85; i++) {//i é y
				for (int j = 743; j < 748; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//ARVORE 4
			//cima
			for (int i = 145; i <= 150; i++) {//i é y
				for (int j = 160; j <= 252; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo
			for (int i = 250; i < 255; i++) {//i é y
				for (int j = 160; j < 252; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 145; i < 245; i++) {//i é y
				for (int j = 150; j < 155; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 175; i < 248; i++) {//i é y
				for (int j = 250; j < 255; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//ARVORE 5
			//cima
			for (int i = 424; i <= 429; i++) {//i é y
				for (int j = 0; j <= 87; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo
			for (int i = 523; i < 528; i++) {//i é y
				for (int j = 0; j < 87; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita (não tem)
			//esquerda
			for (int i = 454; i < 523; i++) {//i é y
				for (int j = 83; j < 87; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//barricada1
			//baixo
			for (int i = 150; i <= 155; i++) { //i é = y
				for (int j = 400; j <= 555; j++) {// j é = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//cima
			for (int i = 260; i <= 265; i++) { //i é = y
				for (int j = 400; j <= 555; j++) {// j é = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//Direita
			for (int i = 150; i <= 260; i++) { //i é = y
				for (int j = 390; j <= 405; j++) {// j é = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 150; i <= 260; i++) { //i é = y
				for (int j = 550; j <= 560; j++) {// j é = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//barril
			//baixo 
			for (int i = 380; i <= 385; i++) {
				for (int j = 470; j <= 570; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//cima
			for (int i = 290; i <= 295; i++) {
				for (int j = 470; j <= 570; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}//295 446
			//direita
			for (int i = 290; i < 380; i++) {
				for (int j = 470; j < 475; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 295; i < 390; i++) {
				for (int j = 570; j < 575; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//barreira
			//baixo
			for (int i = 300; i <= 305; i++) {
				for (int j = 730; j <= 800; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[CIMA] = false;
					}
				}
			}
			//cima
			for (int i = 220; i <= 225; i++) {
				for (int j = 730; j <= 800; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//direita
			for (int i = 220; i < 300; i++) {
				for (int j = 730; j < 735; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda (não tem)

			// =========================================================================== //
			// ==     COLISÕES                    DO                       M A P A 2    == //
			// =========================================================================== //


			//objetos

			///ARVORE 1
			//baixo
			for (int i = 436; i <= 440; i++) {//i é y
				for (int j = 85; j <= 183; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//cima
			for (int i = 538; i < 543; i++) {//i é y
				for (int j = 105; j < 180; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 435; i < 540; i++) {//i é y
				for (int j = 87; j < 92; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 435; i < 540; i++) {//i é y
				for (int j = 175; j < 180; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			///ARVORE 2
			//baixo
			for (int i = 256; i <= 261; i++) {//i é y
				for (int j = 153; j <= 252; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//cima
			for (int i = 355; i < 360; i++) {//i é y
				for (int j = 153; j < 252; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 256; i < 355; i++) {//i é y
				for (int j = 153; j < 158; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 256; i < 355; i++) {//i é y
				for (int j = 252; j < 257; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			///ARVORE 3
			//baixo
			for (int i = 240; i <= 340; i++) {//i é y
				for (int j = 0; j <= 90; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//cima
			for (int i = 343; i < 348; i++) {//i é y
				for (int j = 0; j < 90; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//esquerda
			for (int i = 241; i < 343; i++) {//i é y
				for (int j = 90; j < 95; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			///ARVORE 4
			//cima
			for (int i = 80; i < 87; i++) {//i é y
				for (int j = 90; j < 192; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = -2; i < 82; i++) {//i é y
				for (int j = 90; j < 95; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = -2; i < 82; i++) {//i é y
				for (int j = 189; j < 194; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//ARVORE 5
			//baixo
			for (int i = 442; i <= 447; i++) {//i é y
				for (int j = 462; j <= 564; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//cima
			for (int i = 545; i < 550; i++) {//i é y
				for (int j = 462; j < 561; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 439; i < 541; i++) {//i é y
				for (int j = 462; j < 467; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 442; i < 541; i++) {//i é y
				for (int j = 560; j < 565; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//ARVORE 6
			//baixo
			for (int i = 211; i <= 216; i++) {//i é y
				for (int j = 522; j <= 622; j++) {//i = x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//cima
			for (int i = 310; i < 315; i++) {//i é y
				for (int j = 519; j < 624; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 208; i < 310; i++) {//i é y
				for (int j = 522; j < 527; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = 208; i < 310; i++) {//i é y
				for (int j = 620; j < 625; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//ARVORE 7
			//cima
			for (int i = 60; i < 85; i++) {//i é y
				for (int j = 642; j < 742; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = -2; i < 85; i++) {//i é y
				for (int j = 639; j < 644; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda
			for (int i = -2; i < 85; i++) {//i é y
				for (int j = 741; j < 746; j++) {//i é x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//barreira1
			//baixo
			for (int i = 205; i <= 210; i++) {//y
				for (int j = 0; j <= 60; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//cima
			for (int i = 30; i <= 35; i++) {//y
				for (int j = 0; j <= 60; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//direita (não tem)
			//esquerda
			for (int i = 30; i <= 210; i++) {//y
				for (int j = 55; j <= 60; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//barreira2
			//baixo
			for (int i = 40; i <= 55; i++) {//y
				for (int j = 290; j <= 465; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//cima (não tem)
			//direita
			for (int i = -5; i <= 55; i++) {//y
				for (int j = 290; j <= 295; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda 
			for (int i = -5; i <= 55; i++) {//y
				for (int j = 460; j <= 465; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//acampamento
			//cima
			for (int i = 320; i <= 325; i++) {//y
				for (int j = 630; j <= 805; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo (não tem)
			//direita
			for (int i = 340; i <= 605; i++) {//y
				for (int j = 595; j <= 600; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}
			//esquerda (não tem)

			//tank destruido
			//cima
			for (int i = 460; i <= 465; i++) {//y
				for (int j = 230; j <= 315; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo
			for (int i = 460; i <= 515; i++) {//y
				for (int j = 230; j <= 315; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 460; i <= 590; i++) {//y
				for (int j = 315; j <= 320; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//esquerda
			for (int i = 500; i <= 590; i++) {//y
				for (int j = 225; j <= 230; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[1]) {
						teclas[DIREITA] = false;
					}
				}
			}

			// =========================================================================== //
			// ==     COLISÕES                    DO                       M A P A 3    == //
			// =========================================================================== //

			//objetos

			//barreira1
			//cima (não tem)		
			//baixo
			for (int i = 195; i <= 200; i++) {//y
				for (int j = 100; j <= 235; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = -5; i <= 190; i++) {//y
				for (int j = 235; j <= 240; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//esquerda
			for (int i = -5; i <= 190; i++) {//y
				for (int j = 95; j <= 110; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[DIREITA] = false;
					}
				}
			}

			//barreira2
			//cima
			for (int i = 280; i <= 285; i++) {//y
				for (int j = 95; j <= 235; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo (não tem)
			//direita
			for (int i = 280; i <= 605; i++) {//y
				for (int j = 235; j <= 240; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//esquerda
			for (int i = 280; i <= 605; i++) {//y
				for (int j = 95; j <= 110; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[DIREITA] = false;
					}
				}
			}

			//barricada
			//cima (não tem)
			//baixo
			for (int i = 15; i <= 20; i++) {//y
				for (int j = 230; j <= 320; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita (não tem)
			//esquerda (não tem)

			//barreira3
			//cima
			//baixo
			for (int i = 520; i <= 525; i++) {//y
				for (int j = 282; j <= 420; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = -5; i <= 525; i++) {//y
				for (int j = 410; j <= 420; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//esquerda
			for (int i = -5; i <= 525; i++) {//y
				for (int j = 282; j <= 305; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[DIREITA] = false;
					}
				}
			}

			//bunker
			//cima
			for (int i = 340; i <= 345; i++) {//y
				for (int j = 420; j <= 620; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//baixo
			for (int i = 520; i <= 525; i++) {//y
				for (int j = 420; j <= 620; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[CIMA] = false;
					}
				}
			}
			//direita
			for (int i = 340; i <= 525; i++) {//y
				for (int j = 615; j <= 625; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[ESQUERDA] = false;
					}
				}
			}
			//esquerda(não tem)

			//barricada baixo
			for (int i = 241; i <= 547; i++) {//y
				for (int j = 3; j <= 90; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[BAIXO] = false;
					}
				}
			}

			//barricada cima
			for (int i = -2; i <= 205; i++) {//y
				for (int j = 3; j <= 90; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[CIMA] = false;
					}
				}
			}

			//lago
			//cima
			for (int i = 235; i <= 240; i++) {//y
				for (int j = 474; j <= 732; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[CIMA] = false;
					}
				}
			}
			//baixo
			for (int i = 73; i <= 78; i++) {//y
				for (int j = 474; j <= 732; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[BAIXO] = false;
					}
				}
			}
			//esquerda
			for (int i = 73; i <= 232; i++) {//y
				for (int j = 732; j <= 737; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[ESQUERDA] = false;
					}
				}
			}

			//direita
			for (int i = 73; i <= 238; i++) {//y
				for (int j = 474; j <= 479; j++) {//x
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[2]) {
						teclas[DIREITA] = false;
					}
				}
			}

			al_flip_display();
			al_draw_bitmap(imagem, 0, 0, 0);
		}
	}
	if (vidasJogador[0] <= 0) {
		Cutscene_GameOver(timer);
	}
	//FINALIZAÇÃO DO PROGRAMA
	al_destroy_display(display);
	al_destroy_event_queue(fila_eventos);
	al_destroy_timer(timer);
	al_destroy_bitmap(imagem);
	al_destroy_bitmap(player);
	for (int i = 0; i < 3; i++) {
		al_destroy_bitmap(enemy[i]);
	}
	for (int i = 0; i < 4; i++) {
		al_destroy_bitmap(enemyFaseTwo[i]);
	}
	for (int i = 0; i < 3; i++) {
		al_destroy_bitmap(enemyFaseThree[i]);
	}
	return 0;
}