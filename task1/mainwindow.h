#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QListView>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QStringListModel>
#include <QWidget>
#include <cstdlib>
#include <iostream>
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QPushButton* sendButton;
    QPushButton* randomButton;
    QPlainTextEdit* textEdit;
    QListView* chatView;
    QStringListModel* chatModel;
    QStringList* chatList;

private slots:
    void sendButtonClicked();
    void randomButtonClicked();
};

#endif