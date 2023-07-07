#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
using namespace std;

#include <QMainWindow>
#include <QMenuBar>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTableWidget>
#include <QSplitter>
#include <QMessageBox>
#include <QFileDialog>
#include <QToolBar>
#include <QGroupBox>
#include <QProgressBar>
#include <QPushButton>
#include <QListWidget>
#include <QDebug>


class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    QMenuBar* _menuBar;
    QMenu* _file;

    void menuBar();
    void toolBar();
    void statusBar();

    void UI();
    void widgets();
    void layouts();

    QToolBar* _toolBar;
    QWidget* _centralWidget;
    QStatusBar* _statusBar;


    QLabel* _lblCurDuration;
    QLabel* _lblMusicDuration;
    QProgressBar* _pgbDuration;

    QToolButton* _tlbtnAdd;
    QToolButton* _tlbtnShuffle;
    QToolButton* _tlbtnPlay;
    QToolButton* _tlbtnPrev;
    QToolButton* _tlbtnNext;

    QSlider* _sldVolume;
    QToolButton* _tlbtnMute;
    QListWidget* _lwPlayList;





private slots:
    void openFile();

    void tlbtnPlayHandle();
};

#endif // !MAINWINDOW_H