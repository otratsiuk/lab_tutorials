#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    QWidget* window = new QWidget;

    textEdit = new QPlainTextEdit(window);
    textEdit->setMaximumHeight(50);

    sendButton   = new QPushButton(tr("Send"));
    randomButton = new QPushButton("Random");

    chatView  = new QListView(window);
    chatModel = new QStringListModel;
    chatList  = new QStringList;

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(textEdit, 1, 0);
    layout->addWidget(sendButton, 1, 1);
    layout->addWidget(randomButton, 1, 2);
    layout->addWidget(chatView, 0, 0);

    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendButtonClicked()));
    connect(randomButton, SIGNAL(clicked()), this, SLOT(randomButtonClicked()));
};

void MainWindow::sendButtonClicked()
{
    QString message = textEdit->toPlainText();

    chatList->append(message);
    chatModel->setStringList(*chatList);
    chatView->setModel(chatModel);

    textEdit->clear();
};

void MainWindow::randomButtonClicked()
{
    QStringList phrases = {
        "hello",          "how r u?",     "I'm fine", "see you tomorrow", "good morning",
        "good afternoon", "good evening", "bye",      "what r u doing?",  "hi"};

    QString message = phrases.at(std::rand() % 10);
    textEdit->setPlainText(message);
};

MainWindow::~MainWindow()
{
    delete sendButton;
    delete randomButton;
    delete textEdit;
    delete chatView;
    delete chatModel;
    delete chatList;
};