#include "BearLibTerminal.h"
  
int main(){
    terminal_open();

    // Using UTF-8
    terminal_printf(0, 0, "Привет! Hi!");
    terminal_refresh();
  

    if(terminal_read() != TK_CLOSE || terminal_read() != TK_E){
    	terminal_close();
    }
}