#include "mainwindow.h"
#include <QApplication>
#include "SDL2/SDL.h"

void fill_audio(void *udata, Uint8 *stream, int len)
{

}

int main(int argc, char *argv[])
{
   //if (SDL_Init(SDL_INIT_AUDIO) < 0)
   //    return 1;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int result = a.exec();

    //SDL_Quit();

    return result;
}
