#include "BearLibTerminal.h"

enum Language{
    English,
    Russian
};

int g_language = 9999;
const char *p_newgame = "New Game";
const char *p_loadgame = "Load Game";
const char *p_setupgame = "Setup";
const char *p_exitgame = "Exit";

void Translate(int cur_language){
	if(cur_language == Russian){
		p_newgame = "Новая Игра";
        p_loadgame = "Продолжить";
		p_setupgame = "Настройки";
		p_exitgame = "Выход";
	}
}