#include "being.hpp"
#include "translate.hpp"

// Документация BearLibTerminal:
// http://foo.wyrd.name/ru:bearlibterminal#lightbox[gal-0c334be4ffffb384009c6492d316]/2/

int main(){
    std::cout << "Opening window...";
    terminal_open();
    std::cout << "Window opened.\n\n";

    std::cout << "Setting window...\n";
    terminal_set("window: title = 'Samost', size = 50x20;"); /* input: alt-functions = true; */
    std::cout << "Window seted.\n\n";

    std::cout << "Draw language menu.\n";
    // Библиотека использует кодировку UTF-8
    terminal_print(0, 0, "Choose language:");
    terminal_print(0, 1, "1. English");
    terminal_print(0, 2, "2. Russian");
    terminal_refresh();
    std::cout << "Draw ended.\n\n";
  
    // При каждом вызове terminal_read() считывается единичный ввод клавиши,
    // поэтому русский язык можно выбрать только после повторного нажатия клавиши "2".
    //
    // Необходимо сделать выделение опций белым цветом,
    // выбор с помощью клавиатуры и мыши.
    if(g_language != English || g_language != Russian){
        std::cout << "Checking Input...\n";
        if (terminal_read() == TK_1) {
            g_language = English;
            std::cout << "Language: English.\n";
        }
        else if(terminal_read() == TK_2){
            g_language = Russian;
            std::cout << "Language: Russian.\n";
        }
    }
    std::cout << "Input checked.\n\n";

    std::cout << "Translating...\n";
    Translate(g_language);
    std::cout << "Translate completed.\n\n";

    std::cout << "Refreshing window...\n";
    terminal_clear();

    terminal_print(0, 0, newgame);
    terminal_refresh();
    std::cout << "Refresh ended.\n\n";

    std::cout << "Waiting of close...\n";
    while (terminal_read() != TK_ESCAPE); // Выход из программы с помощью ESCAPE
    terminal_close();
    std::cout << "Close complete.\n\n";

    system("pause");

    return 0;
}