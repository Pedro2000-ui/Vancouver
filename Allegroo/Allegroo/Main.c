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
void  jogador(ALLEGRO_BITMAP* player, int pos_x, int pos_y, int constante, int vidasJogador[], ALLEGRO_BITMAP* heart[]) {
	al_draw_bitmap(player, pos_x, pos_y, constante);
	for (int i = 8; i > 0; i--) {
		if (vidasJogador[0] == i) {
			al_draw_bitmap(heart[i], pos_x - 10, pos_y + 52, constante);
		}
	}
}

void inimigos(ALLEGRO_BITMAP* enemy[], ALLEGRO_BITMAP* enemyFaseTwo[], int pos_xEnemys[], int pos_yEnemys[], int pos_xEnemysFaseTwo[], int pos_yEnemysFaseTwo[], int constante, int vidasInimigos[], int vidasInimigosFaseTwo[], ALLEGRO_BITMAP* eHeart[], bool fases[]) {
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

//FASE 2
void faseTwo(ALLEGRO_BITMAP* enemy[], int pos_xEnemy[], int pos_yEnemy[], bool inimigoVolta[], bool inimigoVoltaDireita[], int pos_yJogador, int pos_xJogador, int vidasInimigos[], int pos_yTiro[], int pos_xTiro[], bool tiroAcertou[], int vidasJogador[], ALLEGRO_SAMPLE_INSTANCE* inst_tiro, ALLEGRO_SAMPLE_INSTANCE* inst_tank_tiro) {
	//BLOCO DE CONTROLE DO TANQUE A DIREITA
	if(vidasInimigos[0] > 0) {
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
					//vidasJogador[0] -= 4;

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
				if (pos_yTiro[0] < pos_yJogador &&  (pos_xTiro[0] + 35) <= pos_xJogador + 37 && (pos_xTiro[0] + 35) + 10 >= pos_xJogador) {
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
	if(vidasInimigos[1] > 0) {
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
	if(vidasInimigos[2] > 0) {
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
				if (pos_xTiro[2] <= pos_xJogador  && pos_yTiro[2] + 5 >= pos_yJogador && pos_yTiro[2] <= pos_yJogador + 35) {
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
	if(vidasInimigos[3] > 0) {
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
				if (pos_yTiro[3] + 50 >= pos_yEnemy[3] + 50) { //condição pra apenas sair o som do tiro quando o tiro estiver saindo da arma
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

//MAIN
int main() {
	const int largura_tela = 800, altura_tela = 600; //Define altura e largura do protótipo da tela;
	bool x = true, y = true, z = true, inimigoVolta[] = { true, true, true }; bool inimigoVoltaDireita[] = { true, true }; //Variáveis que serão usadas para movimentação dos inimigos com o intuito de evitar conflitos
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
	bool posicoes[] = { true, false, false, false };
	bool tiroAcertou[] = { false, false, false, false, false, false };
	bool tiroAcertouFaseTwo[] = { false, false, false, false, false, false, false, false, false, false };
	//Variável para velocidade de rodagem do jogo
	int FPS = 60;
	//Variável para vidas do jogador;
	int vidasJogador[] = { 8 };
	//Variável para vidas dos inimigos;
	int vidasInimigos[] = { 5, 5, 5 };
	int vidasInimigosFaseTwo[] = { 10, 10, 5, 5 };
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
	ALLEGRO_FONT* font09 = al_load_font("04b.TTF", 50, NULL);

	//VARIAVEL DA IMAGEM
	ALLEGRO_BITMAP* imagem = NULL;
	ALLEGRO_BITMAP* player = NULL;
	ALLEGRO_BITMAP* enemy[3] = { NULL, NULL, NULL, };
	ALLEGRO_BITMAP* enemyFaseTwo[4] = { NULL, NULL, NULL, NULL };
	//coração player 
	ALLEGRO_BITMAP* heart[9] = { 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	//coração enemy
	ALLEGRO_BITMAP* eHeart[11] = { 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	
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

	//Chamando a função do MENU
	//menu();
	//CARREGAR IMAGENS
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

	while (fim == false && vidasJogador[0] > 0) {
		//JOGADOR
		jogador(player, pos_xJogador, pos_yJogador, 0, vidasJogador, heart);
		//INIMIGOS
		inimigos(enemy, enemyFaseTwo, pos_xEnemys, pos_yEnemys, pos_xEnemysFaseTwo, pos_yEnemysFaseTwo, 0, vidasInimigos, vidasInimigosFaseTwo, eHeart, fases);

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
							//criar uma função para mostrar a cutscene por alguns segundos e dps sair
							faseTwo(enemyFaseTwo, pos_xEnemysFaseTwo, pos_yEnemysFaseTwo, inimigoVolta, inimigoVoltaDireita, pos_yJogador, pos_xJogador, vidasInimigosFaseTwo, pos_yTiroFaseTwo, pos_xTiroFaseTwo, tiroAcertouFaseTwo, vidasJogador, inst_tiro, inst_tank_tiro);
							//MAPA 3
							for (int i = 88; i < 189; i++) {
								if (pos_xJogador == 750 && pos_yJogador == i && vidasInimigosFaseTwo[0] <= 0 && vidasInimigosFaseTwo[1] <= 0 && vidasInimigosFaseTwo[2] <= 0 && vidasInimigosFaseTwo[3] <= 0) {
									al_destroy_bitmap(imagem);
									imagem = al_load_bitmap("sprites/mapa3.png");
									pos_xJogador = 12;
									pos_yJogador = 229;
									vidasJogador[0] = 4;
									fases[1] = false;
								}
							}
						}
						else if (fases[2]) {
							//criar uma função para mostrar a cutscene por alguns segundos e dps sair
							//criar uma função para a fase 3
							//condições para ganhar o jogo
						}
						else {
							//criar uma função pra cutscene final e setar a váriavel fim = true
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
								if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[0] && pos_xTiroJogador + 20 <= pos_xEnemys[0] + 30 ) && vidasInimigos[0] > 0){
									tiroAcertouInimigo = true;
									vidasInimigos[0]--;
								}
								else if ((pos_yTiroJogador <= pos_yEnemys[0] + 30 && pos_yJogador >= pos_yEnemys[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemys[1] && pos_xTiroJogador + 20 <= pos_xEnemys[1] + 30) && vidasInimigos[1] > 0){
									tiroAcertouInimigo = true;
									vidasInimigos[1]--;
								}
								//Intervalos para Acertar Inimigos na Fase 2
								else if ((pos_yTiroJogador <= pos_yEnemysFaseTwo[0] + 70 && pos_yJogador >= pos_yEnemysFaseTwo[0]) && ((pos_xTiroJogador + 30) >= pos_xEnemysFaseTwo[0] && pos_xTiroJogador + 20 <= pos_xEnemysFaseTwo[0] + 70) && vidasInimigosFaseTwo[0] > 0 && fases[1]){
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
									else if (pos_yTiroJogador >= pos_yEnemys[0] - 30 && pos_yEnemys[0] > pos_yJogador && pos_xTiroJogador + 8 >= pos_xEnemys[1] && pos_xTiroJogador + 8 <= pos_xEnemys[1] + 35 && vidasInimigos[1] > 0) {
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
										if ((pos_xTiroJogador + 40 >= pos_xEnemys[2] && pos_xEnemys[2] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemys[2] && pos_yTiroJogador <= pos_yEnemys[2] + 20)) {
											tiroAcertouInimigo = true;
											vidasInimigos[2]--;
										}
										//Intervalos para Acertar Inimigos na Fase 2
										else if ((pos_xTiroJogador + 40 >= pos_xEnemysFaseTwo[1] && pos_xEnemysFaseTwo[1] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemysFaseTwo[1] && pos_yTiroJogador <= pos_yEnemysFaseTwo[1] + 70)) {
											tiroAcertouInimigo = true;
											vidasInimigosFaseTwo[1]--;
										}
										else if ((pos_xTiroJogador + 40 >= pos_xEnemysFaseTwo[2] && pos_xEnemysFaseTwo[2] > pos_xJogador) && (pos_yTiroJogador + 25 >= pos_yEnemysFaseTwo[2] && pos_yTiroJogador <= pos_yEnemysFaseTwo[2] + 20)) {
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
											if ((pos_xTiroJogador - 40 <= pos_xEnemys[2] && pos_xEnemys[2] < pos_xJogador) && (pos_yTiroJogador + 5 >= pos_yEnemys[2] && pos_yTiroJogador <= pos_yEnemys[2] + 35)) {
												tiroAcertouInimigo = true;
												vidasInimigos[2]--;
											}
											//Intervalos para Acertar Inimigos na Fase 2
											else if ((pos_xTiroJogador - 40 <= pos_xEnemysFaseTwo[1] && pos_xEnemysFaseTwo[1] < pos_xJogador) && (pos_yTiroJogador + 5 >= pos_yEnemysFaseTwo[1] && pos_yTiroJogador <= pos_yEnemysFaseTwo[1] + 70)) {
												tiroAcertouInimigo = true;
												vidasInimigosFaseTwo[1]--;
											}
											else if ((pos_xTiroJogador - 40 <= pos_xEnemysFaseTwo[2] && pos_xEnemysFaseTwo[2] < pos_xJogador) && (pos_yTiroJogador + 5 >= pos_yEnemysFaseTwo[2] && pos_yTiroJogador <= pos_yEnemysFaseTwo[2] + 35)) {
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
			printf("posicao x %d ---- %d ---- %d", pos_xEnemys[0], pos_xEnemys[1], pos_xEnemys[2]);
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
			for (int i = 100; i > 160; i--) { //espaco de posições para a parada do jogador
				for (int j = 35; j > -35; j--) { //espaco de posições que representam 
					if ((pos_xJogador == i) && (pos_yJogador == pos_yEnemys[2] - (j)) && fases[0]) {
						teclas[ESQUERDA] = false;
					}
				}

			}

			//COLISÕES COM OBJETOS

			//ÁGUA	

			for (int i = 445; i < 600; i++) {
				for (int j = 300; j < 320; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[DIREITA] = false;
					}
				}
			}

			for (int i = 445; i <= 460; i++) {
				for (int j = 300; j <= 483; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
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
			for (int i = 375; i < 390; i++) {
				for (int j = 483; j <= 771; j++) {
					if ((pos_xJogador == j) && (pos_yJogador == i) && fases[0]) {
						teclas[BAIXO] = false;
					}
				}
			}
			al_flip_display();
			al_draw_bitmap(imagem, 0, 0, 0);
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
	for (int i = 0; i < 4; i++) {
		al_destroy_bitmap(enemyFaseTwo[i]);
	}
	return 0;
}