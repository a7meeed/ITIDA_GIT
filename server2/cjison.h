#ifndef CJISON_H
#define CJISON_H

#include <QObject>
#include<QJsonObject>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTextStream>
#include<QTcpSocket>
#include "server.h"
class  Cjison : public QObject
{
    Q_OBJECT
public :
        explicit Cjison(QObject *parent = nullptr);
 static   void AddNewObject(const QString &fileName, const QString account_no, const QString balance, const QString full_name, const QString password, const QString age);
  static  QString PrintAllDb(const QString &fileName);
 static  QString printObjectFields(const QString &fileName, const QString &objectName,const QString &field);
  static  void EditSpecifcField(const QString &fileName,
                          const QString &ObjectKey,
                          const QString &FieldToChange,
                          const QString &NewValue);
  static  void deleteObject(const QString &filePath, const QString &objectKey);

 static QString ViewTransactionHistory(const QString accountnumber,const quint16 count);

signals:
  private:
   QDataStream outStream;
   QDataStream inStream;
  QTcpSocket socket ;
};

#endif // CJISON_H
