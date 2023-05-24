#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

  QWidget *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
  mainLayout->setContentsMargins(0, 0, 0, 0);

  createMenuBar();

  createContent(centralWidget, mainLayout);
  

  createStatusBar();
}

void MainWindow::createContent(QWidget *centralWidget, QHBoxLayout *mainLayout)
{
QWidget *contentWidget = new QWidget(centralWidget);
  contentWidget->setObjectName("contentWidget");
  QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
  QLabel *contentLabel1 = new QLabel("Content 1");
  QLabel *contentLabel2 = new QLabel("Content 2");
  contentLayout->addWidget(contentLabel1);
  contentLayout->addWidget(contentLabel2);

  mainLayout->addWidget(contentWidget);
}

void MainWindow::createMenuBar() {
  QMenuBar *menuBar = new QMenuBar(this);
  menuBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  menuBar->setFixedHeight(30);

  QMenu *fileMenu = new QMenu("File", menuBar);
  QAction *openNew = new QAction("New", fileMenu);

  fileMenu->addAction(openNew);
  menuBar->addMenu(fileMenu);

  setMenuBar(menuBar);
}

void MainWindow::createStatusBar() {
  QStatusBar *statusBar = new QStatusBar(this);
  statusBar->setSizeGripEnabled(false); // Disable the size grip
  statusBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  statusBar->setFixedHeight(20); // Adjust the height as per your requirements

  // Add your status bar contents here
  QLabel *statusLabel = new QLabel("Status Bar");
  statusBar->addWidget(statusLabel);

  setStatusBar(statusBar);
}

MainWindow::~MainWindow() {}