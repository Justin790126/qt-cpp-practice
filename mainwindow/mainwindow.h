#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

class MainWindow: public QMainWindow
{
    

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




private slots:
    void openFile();
};

#endif // !MAINWINDOW_H