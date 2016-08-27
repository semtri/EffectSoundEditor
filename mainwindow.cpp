#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <SDL2/SDL.h>

static Uint8 * audio_pos;
static Uint32 audio_len;
static Uint8 * wav_buffer;

#define MUS_PATH "ef_lose.wav"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), mIsPlaying(false)
{
    ui->setupUi(this);

    connect(&mTimer, SIGNAL(timeout()),this, SLOT(onTimer()));
    mTimer.start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void my_audio_callback(void *userdata, Uint8 * stream, int len)
{
    if (audio_len == 0) {
        return;
    }

    len = ( len > audio_len ? audio_len : len);

    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);

    audio_pos += len;
    audio_len -= len;
}

void MainWindow::on_pushButton_clicked()
{
    static Uint32 wav_length;
    static SDL_AudioSpec wav_spec;

    if (SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL) {
        return;
    }

    wav_spec.callback = my_audio_callback;
    wav_spec.userdata = NULL;

    audio_pos = wav_buffer;
    audio_len = wav_length;

    if (SDL_OpenAudio(&wav_spec, NULL) < 0) {
        qDebug() << "Couldn't open audio: " << SDL_GetError();
        SDL_FreeWAV(wav_buffer);
        return;
    }

    mIsPlaying = true;
    SDL_PauseAudio(0);
}

void MainWindow::onTimer()
{
    if (mIsPlaying && audio_len == 0) {
        SDL_CloseAudio();
        SDL_FreeWAV(wav_buffer);
        mIsPlaying = false;
    }
}
