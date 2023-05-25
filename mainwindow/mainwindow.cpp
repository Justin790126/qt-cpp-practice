#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
QWidget *centralWidget = new QWidget(this);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);
        
        // Set the central widget and layout to the main window
        setCentralWidget(centralWidget);
        
        // Add menu bar
        QMenuBar *menuBar = new QMenuBar(this);
        layout->setMenuBar(menuBar);
        
        // Create some menu items
        QMenu *fileMenu = menuBar->addMenu(tr("File"));
        QAction *openAction = fileMenu->addAction(tr("Open"));
        QAction *saveAction = fileMenu->addAction(tr("Save"));
        // Add more menu items as needed

        
        // Create the splitter
        QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
        layout->addWidget(splitter);
        
        // Add widgets to the splitter
        QWidget *leftWidget = new QWidget(splitter);
        QWidget *rightWidget = new QWidget(splitter);
        splitter->addWidget(leftWidget);
        splitter->addWidget(rightWidget);
        
        // Add other widgets to the left and right widgets as needed
        QLabel *leftLabel = new QLabel(tr("Left Widget"), leftWidget);
        QLabel *rightLabel = new QLabel(tr("Right Widget"), rightWidget);
        QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);
        QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);
        leftLayout->addWidget(leftLabel);
        rightLayout->addWidget(rightLabel);

                
        // Add status bar
        QStatusBar *statusBar = new QStatusBar(this);
        layout->addWidget(statusBar);
}

void MainWindow::createContent(QWidget *centralWidget, QHBoxLayout *mainLayout)
{
  QWidget *contentWidget = new QWidget(centralWidget);
  contentWidget->setObjectName("contentWidget");

#if V_LAYOUT
  QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
  QLabel *contentLabel1 = new QLabel("Content 1");
  QLabel *contentLabel2 = new QLabel("Content 2");
  contentLayout->addWidget(contentLabel1);
  contentLayout->addWidget(contentLabel2);
#endif

#if LAYOUT_BY_STRETCH
  QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
  contentLayout->setSpacing(0);
  contentLayout->setMargin(5);

//////////////////////////////////////////////////

  QFontComboBox *font = new QFontComboBox(this);
  font->setFixedSize(150, 20);
  QComboBox *size = new QComboBox(this);
  size->setFixedSize(45, 20);

  QList<QString> sizeList; //添加字号
  sizeList << "8"
           << "9"
           << "10";
  size->addItems(sizeList);

  QHBoxLayout *hlayout1 = new QHBoxLayout(this);
  QToolButton *btnBold = new QToolButton(this);
  btnBold->setText("B");
  btnBold->setFixedSize(33, 33);
  QToolButton *btnItalic = new QToolButton(this);
  btnItalic->setText("I");
  btnItalic->setFixedSize(33, 33);
  QToolButton *btnUnderline = new QToolButton(this);
  btnUnderline->setText("U");
  btnUnderline->setFixedSize(33, 33);
  QToolButton *btnColor = new QToolButton(this);
  btnColor->setText("C");
  btnColor->setFixedSize(33, 33);
  QToolButton *btnSave = new QToolButton(this);
  btnSave->setText("S");
  btnSave->setFixedSize(33, 33);
  QToolButton *btnClear = new QToolButton(this);
  btnClear->setText("R");
  btnClear->setFixedSize(33, 33);

  hlayout1->addWidget(font);
  hlayout1->addWidget(size);
  hlayout1->addWidget(btnBold);
  hlayout1->addWidget(btnItalic);
  hlayout1->addWidget(btnUnderline);
  hlayout1->addWidget(btnColor);
  hlayout1->addWidget(btnSave);
  hlayout1->addWidget(btnClear);
  hlayout1->setMargin(10);
  hlayout1->setSpacing(7);

  QTextBrowser *browser = new QTextBrowser(this);
  QTextEdit *edit = new QTextEdit(this);

  QVBoxLayout *vlayout = new QVBoxLayout(this);
  vlayout->addWidget(browser);
  vlayout->addLayout(hlayout1);
  vlayout->addWidget(edit);
  vlayout->setStretchFactor(browser, 4);
  vlayout->setStretchFactor(hlayout1, 1);
  vlayout->setStretchFactor(edit, 2);

  // contentLayout->addWidget(browser);
  // contentLayout->addLayout(hlayout1);
  // contentLayout->addWidget(edit);
  // contentLayout->setStretchFactor(browser, 4);
  // contentLayout->setStretchFactor(hlayout1, 1);
  // contentLayout->setStretchFactor(edit, 2);

  QHBoxLayout *hlayout2 = new QHBoxLayout(this);
  QTableWidget* table = new QTableWidget(this);
  hlayout2->addLayout(vlayout);
  hlayout2->addWidget(table);
  hlayout2->setSpacing(0);


  contentLayout->addLayout(hlayout2);
#endif

#if SPLITTER
  QSplitter *splitter = new QSplitter(Qt::Horizontal, mainLayout);
  
  QTextEdit* textLeft = new QTextEdit(QObject::tr("Left Widget"),splitter);
  textLeft->setAlignment(Qt::AlignLeft);

  QSplitter *splitterR = new QSplitter(Qt::Vertical, mainLayout);
  splitterR->setOpaqueResize(false);
  QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"), splitterR);
  textUp->setAlignment(Qt::AlignCenter);
  QTextEdit *textBottom = new QTextEdit(QObject::tr("Bottom Widget"), splitterR);


  QHBoxLayout *hlayout3 = new QHBoxLayout(this);
  hlayout3->addWidget(splitter);
  hlayout3->addWidget(splitterR);
  hlayout3->setStretchFactor(splitter, 3);
  hlayout3->setStretchFactor(splitterR, 1);
  contentWidget->setLayout(hlayout3);
#endif
//////////////////////////////////////////////////
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