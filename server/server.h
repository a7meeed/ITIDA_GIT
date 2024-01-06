#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QFile>
#include <QDebug>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include"cjison.h"


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    // void Handlerequest(QString,QString);
    void ReciveSendData(qint32 request, qint32 login);
   QString  file_json ="E:/QT Projects/newServer/file.json";
    QString field = "Full name";
   QString balance = "Balance";
    QString accountNumber ="Account Number";
   QString password ="Password";
    QString _age ="age";
    QString admin_objectName="Admin";
signals:
public slots:
    void start();
    void quit();
    void newConnection();
    void disconnected();
    void readyRead();


private:
    QTcpServer server;

    // Cjison jison;

};

#endif // SERVER_H
