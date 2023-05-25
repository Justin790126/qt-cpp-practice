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
namespace Ui {
    class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    void createMenuBar();
    void createStatusBar();
    void createContent(QWidget *centralWidget, QHBoxLayout *mainLayout);
    Ui::MainWindow* ui;
};

#endif // !MAINWINDOW_H