#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

int main(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    int height, width;
    char *msg = "Suspender";
    char *msg2 = "Reiniciar";
    char *msg3 = "Desligar";
    getmaxyx(stdscr, height, width);
    int y = height / 2;
    int x = (width - strlen(msg)) / 2;
    int indice = 1;
    while (true){
	erase();
	int input = getch();
	if (input != ERR){
	    if (input == '\n'){
                if (indice == 1) {
		    system("i3lock -c 000000 && sleep 1 && systemctl suspend");
		    endwin();
		    return 0;
		}
		else if (indice == 2) {
                    system("reboot");
		}
		else if (indice == 3) {
		    system("shutdown now");
		}
	    }
	    if (input == 27) {
                endwin();
		return 0;
	    }
	    else if (input == KEY_RIGHT) {
                if (indice >= 3) {
                    indice = 1;
		}
		else {
		    indice++;
		}
	    }
	    else if (input == KEY_LEFT) {
		if (indice <= 1) {
                    indice = 3;
		}
		else {
		    indice--;
		}
	    }
	}
	if (indice == 1){
	    mvprintw(y + 1, x - 19, "%s", "-----------");
            mvprintw(y, x - 18, "%s", msg);
	    mvprintw(y - 1, x - 19, "%s", "-----------");
	    mvprintw(y - 2, x - 19, "%s", "***********");
	    mvprintw(y, x - 19, "%s", "|");
	    mvprintw(y, x - 9, "%s", "|");
	    mvprintw(y + 1, x, "%s", "-----------");
            mvprintw(y, x + 1, "%s", msg2);
	    mvprintw(y - 1, x, "%s", "-----------");
            mvprintw(y, x, "%s", "|");
	    mvprintw(y, x + 10, "%s", "|");
	    mvprintw(y + 1, x + 18, "%s", "-----------");
            mvprintw(y, x + 20, "%s", msg3);
	    mvprintw(y - 1, x + 18, "%s", "-----------");
            mvprintw(y, x + 18, "%s", "|");
	    mvprintw(y, x + 28, "%s", "|");
	}
	else if (indice == 2) {
            mvprintw(y + 1, x - 19, "%s", "-----------");
            mvprintw(y, x - 18, "%s", msg);
	    mvprintw(y - 1, x - 19, "%s", "-----------");
	    mvprintw(y, x - 19, "%s", "|");
	    mvprintw(y, x - 9, "%s", "|");
	    mvprintw(y + 1, x, "%s", "-----------");
            mvprintw(y, x + 1, "%s", msg2);
	    mvprintw(y - 1, x, "%s", "-----------");
	    mvprintw(y - 2, x, "%s", "***********");
            mvprintw(y, x, "%s", "|");
	    mvprintw(y, x + 10, "%s", "|");
	    mvprintw(y + 1, x + 18, "%s", "-----------");
            mvprintw(y, x + 20, "%s", msg3);
	    mvprintw(y - 1, x + 18, "%s", "-----------");
            mvprintw(y, x + 18, "%s", "|");
	    mvprintw(y, x + 28, "%s", "|");

	}
	else if (indice == 3) {
            mvprintw(y + 1, x - 19, "%s", "-----------");
            mvprintw(y, x - 18, "%s", msg);
	    mvprintw(y - 1, x - 19, "%s", "-----------");
	    mvprintw(y, x - 19, "%s", "|");
	    mvprintw(y, x - 9, "%s", "|");
	    mvprintw(y + 1, x, "%s", "-----------");
            mvprintw(y, x + 1, "%s", msg2);
	    mvprintw(y - 1, x, "%s", "-----------");
	    mvprintw(y, x, "%s", "|");
	    mvprintw(y, x + 10, "%s", "|");
	    mvprintw(y + 1, x + 18, "%s", "-----------");
            mvprintw(y, x + 20, "%s", msg3);
	    mvprintw(y - 1, x + 18, "%s", "-----------");
	    mvprintw(y - 2, x + 18, "%s", "***********");
            mvprintw(y, x + 18, "%s", "|");
	    mvprintw(y, x + 28, "%s", "|");

	}
	refresh();
	usleep(95000);
    }
    endwin();    
}
