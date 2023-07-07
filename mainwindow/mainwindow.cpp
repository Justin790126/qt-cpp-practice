#include "mainwindow.h"

MainWindow::MainWindow() {

  this->setWindowTitle("Music Player");
  this->setGeometry(450,150,480,700);
  this->setWindowIcon(QIcon("icons/icon.ico"));

  //menuBar();
  //toolBar();

  UI();

  //statusBar();
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

  _pgbDuration = new QProgressBar();
  _lblCurDuration = new QLabel("0:00");
  _lblMusicDuration = new QLabel("/ 0:00");

  _tlbtnAdd = new QToolButton();
  _tlbtnAdd->setIcon(QIcon("icons/add.png"));
  QObject::connect(_tlbtnAdd, SIGNAL(clicked()), this, SLOT(tlbtnPlayHandle()));
  _tlbtnShuffle = new QToolButton();
  _tlbtnShuffle->setIcon(QIcon("icons/shuffle.png"));
  _tlbtnPlay = new QToolButton();
  _tlbtnPlay->setIcon(QIcon("icons/play.png"));
  _tlbtnPrev = new QToolButton();
  _tlbtnPrev->setIcon(QIcon("icons/previous.png"));
  _tlbtnNext = new QToolButton();
  _tlbtnNext->setIcon(QIcon("icons/next.png"));
  _sldVolume = new QSlider(Qt::Horizontal);
  _tlbtnMute = new QToolButton(); //
  _tlbtnMute->setIcon(QIcon("icons/mute.png"));
  

  _lwPlayList = new QListWidget();
}

void MainWindow::tlbtnPlayHandle()
{
  qDebug() << "You have obtained";
}

void MainWindow::layouts()
{
  QVBoxLayout* mainLayout = new QVBoxLayout();
  
  QGroupBox* topGroupBox = new QGroupBox("Music Player");
    QVBoxLayout* topMainLayout = new QVBoxLayout();
      QHBoxLayout* topLayout = new QHBoxLayout();
      QHBoxLayout* middleLayout = new QHBoxLayout();
  ///////////////////////////////////////////////////////

  topLayout->addWidget(_pgbDuration);
  topLayout->addWidget(_lblCurDuration);
  topLayout->addWidget(_lblMusicDuration);

  middleLayout->addWidget(_tlbtnAdd);
  middleLayout->addWidget(_tlbtnShuffle);
  middleLayout->addWidget(_tlbtnPlay);
  middleLayout->addWidget(_tlbtnPrev);
  middleLayout->addWidget(_tlbtnNext);
  middleLayout->addWidget(_sldVolume);
  middleLayout->addWidget(_tlbtnMute);


  ///////////////////////////////////////////////////////
  topMainLayout->addLayout(topLayout);
  topMainLayout->addLayout(middleLayout);
  topGroupBox->setLayout(topMainLayout);

  ///////////////////////////////////////////////////////
  QVBoxLayout* bottomLayout = new QVBoxLayout();
  bottomLayout->addWidget(_lwPlayList);
  ///////////////////////////////////////////////////////
  

  mainLayout->addWidget(topGroupBox, 25);
  mainLayout->addLayout(bottomLayout, 75);

  _centralWidget->setLayout(mainLayout);
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
  _statusBar->showMessage("Init view");
  setStatusBar(_statusBar);
}

void MainWindow::openFile() {
  QFileDialog dialog(this);
  QStringList fileNames;
  if (dialog.exec()) {
    fileNames = dialog.selectedFiles();
  }
}

MainWindow::~MainWindow() {
  
}