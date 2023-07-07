#include "mainwindow.h"

MainWindow::MainWindow() {

  menuBar();
  toolBar();

  UI();

  statusBar();
}

void MainWindow::UI()
{
  _centralWidget = new QWidget(this);
  setCentralWidget(_centralWidget);

  widgets();
  layouts();
}

void MainWindow::widgets()
{

}

void MainWindow::layouts()
{

}

void MainWindow::menuBar() {
  _menuBar = new QMenuBar(this);

  _file = new QMenu("File");
  _file->addMenu("Open");
  _file->addMenu("Exit");

  _menuBar->addMenu(_file);
  setMenuBar(_menuBar);
}

void MainWindow::toolBar() {
  _toolBar = addToolBar("Tool bar");
  _toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

  QAction* actionProduct = new QAction(QIcon("icons/add.png"), "Add Product", this);
  _toolBar->addAction(actionProduct);
  _toolBar->addSeparator();
}

void MainWindow::statusBar() {
  _statusBar = new QStatusBar(this);
  setStatusBar(_statusBar);
}

void MainWindow::openFile() {
  QFileDialog dialog(this);
  QStringList fileNames;
  if (dialog.exec()) {
    fileNames = dialog.selectedFiles();
  }
}

MainWindow::~MainWindow() {}