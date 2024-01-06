#ifndef CMYCLIENT_H
#define CMYCLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMetaEnum>
#include <windows.h>
#include<iostream>
#include<QDataStream>
#include<QHostAddress>
#include <QObject>
#include<QDataStream>
#include<QIODevice>

class CmyClient : public QObject
{
    Q_OBJECT
public:
    explicit CmyClient(QObject *parent = nullptr);
    void TransferAmount();
    void MakeTransaction();
    void ViewAccount();
    void GetAccNo();
    void ViewTransactionHistory();
    void sendrequesttoserver();
    qint32 Login(qint32 choice);
    void UserOptions();
    void Start();
    void ViewBankDatabase();
    void CreateNewUser();
    void Deleteuser();
    void UpdateUser();
    bool serverResponse();
    void exit();

   static void setFlage( bool newFlage);
   static bool getFlage();

signals:
public slots:
    void connectToHost(QString host,quint16 port);
    void disconnect();
protected slots:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketerror);
    void stateChanged(QAbstractSocket::SocketState socketstate);
    void readyRead();
private:
    QTcpSocket socket;
    QDataStream outStream;
    QDataStream inStream;
    static bool _flage;
protected:
    QString m_role;
    QString m_request;
    QVariant m_serverrespond;

};

#endif // CMYCLIENT_H
