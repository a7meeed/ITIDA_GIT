#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{


    connect(&server,&QTcpServer::newConnection,this,&Server::newConnection);
}

void Server::start()
{
    if(!server.listen(QHostAddress::Any,4509))
    {
        qWarning()<<server.errorString();
        return;
    }
    qInfo()<<"Listening";

}

void Server::quit()
{
    server.close();
}

void Server::newConnection()
{
    QTcpSocket* socket=server.nextPendingConnection();
    connect(socket,&QTcpSocket::disconnected,this,&Server::disconnected);
    connect(socket,&QTcpSocket::readyRead,this,&Server::readyRead);
    qInfo()<<"connected to"<<socket;
}

void Server::disconnected()
{
    QTcpSocket* socket=qobject_cast<QTcpSocket*>(sender());
    qInfo()<<"Disconnected"<<socket;
    qInfo()<<"parent"<<socket->parent();
}

void Server::readyRead()
{
    //create pointer to the socket connected to the object send the request
    QTcpSocket* socket=qobject_cast<QTcpSocket*>(sender());
    //create an in datasream to take the needed data from the client
    QDataStream inStream(socket);
    QDataStream outStream(socket);
    inStream.setVersion(QDataStream::Qt_6_6);
    //take the request message and the role of our client to be able to handle the request
    qint32 choice,login ;
    QString _name,_pass;
    inStream>>choice;
    qInfo() <<"choice is "<<choice;
    inStream>>_name;
    qInfo()<<"name is"<<_name;
    inStream>>_pass;
    qInfo()<<"pass is "<<_pass;
    inStream>>login;
     qDebug()<<"log in is "<<login;
    //call this method to handle the request according to client role
     if(_pass == Cjison::printObjectFields(file_json,_name,password))
     {

         ReciveSendData(choice,login);

     }
     else {
         qInfo()<<"not autharized";
         outStream<<"false";
     }

}

void Server::ReciveSendData(qint32 choice, qint32 login)
{


    //create pointer to the socket connected to the object send the request
    QTcpSocket* socket=qobject_cast<QTcpSocket*>(sender());
    //create an in datasream to take the needed data from the client
    QDataStream inStream(socket);
    //create an out datastream to send the respond to the client
    QDataStream outStream(socket);
    inStream.setVersion(QDataStream::Qt_6_6);
    outStream.setVersion(QDataStream::Qt_6_6);
    QString oldAmout,dataBase,name,age,city,data,data2,user_name,subAmount,pass,fromaccount,toaccount,full_name,account_no;
    QString account_name,updatedValue,choice_,admin_name,oldAmout2,AddedAmount,account;
    QString update_msg="The Field updated succesfully";
    qint32 transferamount,Amount,Amount2,TransactionAmount;
    //check if oour client is user or admin to handle his request

    switch (choice) {
case 1:

//**********************************user role*******************************************************************
        switch (login)
        {
        case 1:
 /********************************************************************************************/
           // client.ViewAccount();
            inStream>>user_name;
           qInfo()<<"user is : "<<user_name;
           data=Cjison::printObjectFields(file_json,user_name,field);
            //jison.printObjectFields(file_json,user_name);
           qInfo()<<"return from json"<<data;

           outStream<<data;
            break;
/********************************************************************************************/

        case 2:
           // client.TransferAmount();
            inStream>>fromaccount;
           qInfo()<<fromaccount;
           inStream>>toaccount;
           qInfo()<<toaccount;
            inStream>>transferamount;
           qInfo()<<transferamount;
         oldAmout = Cjison::printObjectFields(file_json,toaccount,balance);
           Amount = oldAmout.toInt() + transferamount;
         Cjison::EditSpecifcField(file_json, toaccount,balance, QString::number(Amount));
       //*********************************************************
           oldAmout2 = Cjison::printObjectFields(file_json,fromaccount,balance);
          Amount2 = oldAmout2.toInt() - transferamount;
            Cjison::EditSpecifcField(file_json,fromaccount,balance,QString::number(Amount2));
            qInfo()<<"transfer done";
           outStream<<Cjison::printObjectFields(file_json,toaccount,balance);

           break;
/********************************************************************************************/
        case 3:
           // client.MakeTransaction();
            inStream>>account>>TransactionAmount;
            oldAmout2 = Cjison::printObjectFields(file_json,account,balance);
            Amount2 = oldAmout2.toInt() - TransactionAmount;
            Cjison::EditSpecifcField(file_json,account,balance,QString::number(Amount2));
            qInfo()<<"transfer done";
            outStream<<Cjison::printObjectFields(file_json,account,balance);

            break;
/********************************************************************************************/
        case 4:
           // client.GetAccNo();
           inStream>>account;
      outStream<<Cjison::printObjectFields(file_json,account,accountNumber);
          //  jison.printObjectFields(file_json,user_name);
            break;
/********************************************************************************************/
        case 5:
           // client.ViewTransactionHistory();
            break;
        default:
            break;
        }
        break;

case 2:
//*********************************admin role*************************************************************************

    switch (login)
    {
     case 1:
        inStream>>admin_name;
         qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
         qInfo()<<"from json : "<<data2;
        if(admin_name == data2){
        inStream>>user_name;
        qInfo()<<"user is : "<<user_name;
        data=Cjison::printObjectFields(file_json,user_name,field);
            //jison.printObjectFields(file_json,user_name);
        qInfo()<<"return from json"<<data;

        outStream<<data;
         }
        break;
    case 2:
        // client.TransferAmount();
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo()<<"from json : "<<data2;
        if(admin_name == data2){
        inStream>>user_name>>AddedAmount;
        Cjison::EditSpecifcField(file_json, user_name,"amount", AddedAmount );
        }
        break;
    case 3:
        // client.MakeTransaction();
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo()<<"from json : "<<data2;
        if(admin_name == data2){
        inStream>>user_name>>subAmount;
        Cjison::EditSpecifcField(file_json,user_name,"amount",subAmount);
        //  jison.EditSpecifcField(file_json,user_name,"amount",subAmount);
        }
        break;
    case 4:
        // client.GetAccNo();
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo()<<"from json : "<<data2;
        if(admin_name == data2){
        inStream>>user_name;
        Cjison::printObjectFields(file_json,user_name,field);
        //  jison.printObjectFields(file_json,user_name);
        }
        break;
    case 5:
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo()<<"from json : "<<data2;
        if(admin_name == data2){
        // client.ViewTransactionHistory();
        }
        break;
    case 6:
       //add new user
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo()<<"from json : "<<data2;
        if(admin_name == data2){
        inStream>>account_no>>balance>>full_name>>pass>>age;
        Cjison::AddNewObject(file_json,account_no,balance,full_name,pass,age);
        qInfo()<<"user is added";
        outStream<<"user is added";
        }
        break;
    case 7:
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo().noquote()<<"from json : "<<data2;
        if(admin_name == data2){
//***********************view bank data base**********
            qInfo()<<"loading DB ......";
            dataBase=Cjison::PrintAllDb(file_json);
            outStream<<dataBase;
        }
        break;
    case 8:
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo().noquote()<<"from json : "<<data2;
        if(admin_name == data2){
            inStream>> account_name;
            inStream>> choice_;
            switch (choice_.toInt()) {
            case 1:
                inStream>>updatedValue;
                Cjison::EditSpecifcField(file_json,account_name,balance,updatedValue);
                outStream<<update_msg;
                break;
            case 2:
                inStream>>updatedValue;
                Cjison::EditSpecifcField(file_json,account_name,field,updatedValue);
                outStream<<update_msg;
                break;
            case 3:
                inStream>>updatedValue;
                Cjison::EditSpecifcField(file_json,account_name,password,updatedValue);
                outStream<<update_msg;
                break;
            case 4:
                inStream>>updatedValue;
                Cjison::EditSpecifcField(file_json,account_name,_age,updatedValue);

                outStream<<update_msg;
                break;

            default:
                break;
            }
        }
        break;
    case 9:
        inStream>>admin_name;
        qInfo()<<"recived data : "<<admin_name;
        data2 =Cjison::printObjectFields(file_json,admin_objectName,field);
        qInfo().noquote()<<"from json : "<<data2;
        if(admin_name == data2){

        }
        break;
    default:
             break;
    }

      break;
default:
    break;
    }
}

// void Server::Handlerequest(QString request,QString role)
// {
//     //create pointer to the socket connected to the object send the request
//     QTcpSocket* socket=qobject_cast<QTcpSocket*>(sender());
//     //create an in datasream to take the needed data from the client
//     QDataStream inStream(socket);
//     //create an out datastream to send the respond to the client
//     QDataStream outStream(socket);
//     inStream.setVersion(QDataStream::Qt_6_6);
//     outStream.setVersion(QDataStream::Qt_6_6);
//     //check if oour client is user or admin to handle his request
//     if(role.toUpper()=="USER")
//     {
//     if(request=="Transfer Account")
//     {
//         bool ok = true;
//         QString fromtransferaccount,totransferaccount;
//         quint32 transferamount;
//         inStream >> fromtransferaccount >> totransferaccount >> transferamount;
//         qDebug() << "Received from client:" << fromtransferaccount<<" "<<totransferaccount<<" "<<transferamount ;
//         //sending respond to the server using the socket
//         outStream<<ok;

//     }
//     else if(request=="View Account")
//     {
//         // create a map container to test the code
//         QMap<QString,qint32>data;
//         data["4545"]=12500;
//         QString accountnumber;
//         inStream >> accountnumber;
//          //sending respond to the server using the socket
//         outStream<<data[accountnumber];
//     }
//     else if(request=="Make Transaction")
//     {
//         QMap<QString,qint32>data;
//         data["4545"]=12500;
//         QString accountnumber;
//         qint32 TransactionAmount;
//         inStream >> accountnumber>>TransactionAmount;

//     }
//     }
// }
