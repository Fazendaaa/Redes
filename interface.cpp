#include <ncurses.h>
#include <string>
#include <unistd.h>


int main(){

  initscr();
  noecho();
  cbreak();

  int yMax, xMax;
  getmaxyx(stdscr,yMax,xMax);

  WINDOW * displayWindow = newwin(yMax-4,xMax-4,2,3);
  box(displayWindow,0,0);
  refresh();
  for(int i=0;i<20;i++){
    //refresh();
    mvwprintw(displayWindow,1,1,"message %d",i);
    wrefresh(displayWindow);
    usleep(200000);
  }


/*  int derp = 4;
  printw("This is output %d",derp);
  addch('a');
  move(12,13); //y x

  mvprintw(15,20, "Movement");
  mvaddch(12,50,'@');*/

  getch();
  endwin();

  return 0;



}
