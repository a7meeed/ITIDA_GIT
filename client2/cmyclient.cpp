#include "cmyclient.h"
bool CmyClient::_flage = false;
CmyClient::CmyClient(QObject *parent)
    : QObject{parent}
{

    outStream.setDevice(&socket);
    inStream.setDevice(&socket);
    outStream.setVersion(QDataStream::Qt_6_6);
    inStream.setVersion(QDataStream::Qt_6_6);
    connect(&socket,&QTcpSocket::connected,this,&CmyClient::connected);
    connect(&socket,&QTcpSocket::disconnected,this,&CmyClient::disconnected);
    connect(&socket,&QTcpSocket::stateChanged,this,&CmyClient::stateChanged);
    connect(&socket,&QTcpSocket::readyRead,this,&CmyClient::readyRead);
    connect(&socket,&QTcpSocket::errorOccurred,this,&CmyClient::error);

}

void CmyClient::disconnect()
{
    socket.close();
    socket.disconnectFromHost();
    socket.waitForDisconnected();
}

void CmyClient::TransferAmount()
{
    // create a datastream to send the nedded info to the server to transfer the money.

    qInfo()<<"Please send the account name which you will transfer from:";
    std::string fromaccount;
    std::cin>>fromaccount;
    outStream<<QString::fromStdString(fromaccount);
    qInfo()<<"Please send the account name which you will transfer to:";
    std::string toaccount;
    std::cin>>toaccount;
    outStream<<QString::fromStdString(toaccount);
    qInfo()<<"Please send the transfer amount:";
    quint32 transferamount;
    std::cin>>transferamount;
    //convert the data from stdString to QString to send it to the server and process it.
    //send the data to the server to handle that
    outStream<<transferamount;
    socket.waitForBytesWritten();
    //wait for the respond from the server to view it to the client

}

void CmyClient::MakeTransaction()
{
    // create a datastream to send the nedded info to the server to make a transacton
    qInfo()<<"Please send the account name:";
    std::string account;
    std::cin>>account;
    qInfo()<<"Please send the transaction amount:";
    qint32 TransactionAmount;
    std::cin>> TransactionAmount;
    //send the data to the server to handle that
    outStream<<QString::fromStdString(account)<<TransactionAmount;
    socket.waitForReadyRead();
    // qInfo()<<"Transaction is :"<<m_serverrespond.toBool();
}

void CmyClient::ViewAccount()
{
    QString data;
    // create a datastream to send the nedded info to the server to get the the money in the account
    qInfo()<<"Please send the user name:";
    std::string user_name;
    std::cin>>user_name;
    outStream<<QString::fromStdString(user_name);

    socket.waitForBytesWritten();
// wait for the respond from the server to view it to the client
    socket.waitForReadyRead();
//     qInfo()<<"Your account money is :"<<m_serverrespond.toInt();
//
}

void CmyClient::GetAccNo()
{
    qInfo()<<"Please send the account name:";
    std::string account;
    std::cin>>account;
    outStream<<QString::fromStdString(account);
    qInfo()<<"your account number is : ";
}

void CmyClient::ViewTransactionHistory()
{
    // qInfo()<<"\t\tPlease send the account :";
    // std::string account;
    // std::cin>>account;
    // qInfo()<<"\t\tPlease send the number of transactions:";
    // quint32 count;
    // std::cin>>count;
    // outStream<<QString::fromStdString(accountNumber)<<count;
    // socket.waitForBytesWritten();
    // socket.waitForReadyRead();
    // //qInfo()<<m_serverrespond.toString();
}

// void CmyClient::sendrequesttoserver()
// {

// }

qint32 CmyClient::Login(qint32 choice)
{
    qInfo()<<"WELCOME!!";
     qInfo()<<"Username: ";
    qint32 loginChoice;
    int serverResponse=true;
    std::string name;
    std::cin>>name;
    outStream<<QString::fromStdString(name);
    qInfo()<<"Password: ";
    std::string pass;
    std::cin>>pass;
  outStream<<QString::fromStdString(pass);
    system("cls");
    if (choice==1){
qInfo()<<"\t\tenter your choice\n"
                   "\t\t1.View Account\n"
                   "\t\t2.Transfer Amount\n"
                   "\t\t3.Make Transaction\n"
                   "\t\t4.GetAccount Number\n"
                   "\t\t5.View Transaction History\n"
                   "\t\t6.exit\n";
        std::cin>>loginChoice;
    outStream<<loginChoice;
    return loginChoice;
}
    else{
 qInfo()<<"**************enter your choice************\n"
               "\t\t1.View Account\n"
               "\t\t2.Transfer Amount\n"
               "\t\t3.Make Transaction\n"
               "\t\t4.GetAccount Number\n"
               "\t\t5.View Transaction History\n"
               "\t\t6.add new account\n"
               "\t\t7.read all data base\n"
               "\t\t8.Update User\n"
               "\t\t9.delet user\n"
               "\t\t10.exit\n";
    std::cin>>loginChoice;
    outStream<<loginChoice;
    return loginChoice;
    }
}

void CmyClient::ViewBankDatabase()
{
    socket.waitForReadyRead();
    qInfo()<<m_serverrespond.toString();
}

void CmyClient::CreateNewUser()
{
    std::string user_name,account_no,balance,full_name,pass,age;
    // std::cout<<"user_name:";
    // std::cin>>user_name;
    std::cout<<"account_no:";
    std::cin>>account_no;
    std::cout<<"balance:";
    std::cin>>balance;
    std::cout<<"full_name:";
    std::cin>>full_name;
    std::cout<<"pass:";
    std::cin>>pass;
    std::cout<<"age:";
    std::cin>>age;
    outStream<<QString::fromStdString(account_no)<<QString::fromStdString(balance)<<QString::fromStdString(full_name)<<QString::fromStdString(pass)<<QString::fromStdString(age);
    socket.waitForReadyRead();
}

void CmyClient::Deleteuser()
{
    qInfo()<<"Enter the user account name:";
    std::string account;
    std::cin>>account;
    outStream<<QString::fromStdString(account);
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
}

void CmyClient::UpdateUser()
{
    std::string choice_;
    qInfo()<<"\t\tenter account user name:";
    std::string account_name;
    std::cin>>account_name;
    outStream<<QString::fromStdString(account_name);
    qInfo()<<"\t\tchoose what you want to update \n"
               "\t\t1.Balance\n"
               "\t\t2.Full name\n"
               "\t\t3.Password\n"
               "\t\t4.age\n"
               "\t\t5.account number\n";
    std::cin>>choice_;
    outStream<<QString::fromStdString(choice_);
    qInfo()<<"\t\tenter new value of update :";
        std::string updatedValue;
    std::cin>>updatedValue;
        outStream<<QString::fromStdString(updatedValue);
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

 }

bool CmyClient::serverResponse()
{
    QString server_Response;
    inStream >>server_Response;
}

void CmyClient::exit()
{
    qInfo()<<"**************good bye********** ";

}

bool CmyClient::getFlage()
{
    return _flage;
}

void CmyClient::setFlage(bool newFlage)
{

    _flage = newFlage;
}


void CmyClient::connectToHost(QString host, quint16 port)
{
    if(socket.isOpen()) disconnect();
    qInfo()<<"connecting to host"<<host<<"on port:"<<port;
    socket.connectToHost(host,port);
}
void CmyClient::connected()
{
std::string admin_name;
qint32 choice=0;
setFlage(true);
while(getFlage()){
setFlage(false);
    qInfo()<<"*************Welcome*****************\n"
           "************Please choose**************\n"
           "______1.client__________\n"
           "______2.admin____________\n"
           "______3.exit______________";
    std::cin>>choice;
    outStream<<choice;
    switch (choice) {
    case 1:
        switch (Login(choice)) {
        case 1:
            ViewAccount();
            setFlage(true);
            break;
        case 2:
            TransferAmount();
            setFlage(true);
            break;
        case 3:
            MakeTransaction();
            setFlage(true);
            break;
        case 4:
            GetAccNo();
            setFlage(true);
            break;
        case 5:
            ViewTransactionHistory();
            setFlage(true);
            break;
        case 6:
           exit();
           setFlage(false);
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (Login(choice)) {
        case 1:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            ViewAccount();
            setFlage(true);
            break;
        case 2:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            TransferAmount();
            setFlage(true);
            break;
        case 3:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            MakeTransaction();
            setFlage(true);
            break;
        case 4:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            GetAccNo();
            setFlage(true);
            break;
        case 5:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            ViewTransactionHistory();
            setFlage(true);
            break;
        case 6:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            CreateNewUser();
            setFlage(true);
            break;
        case 7:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
           ViewBankDatabase();
            setFlage(true);
           break;
        case 8:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            //update user
            UpdateUser();
            setFlage(true);
            break;
        case 9:
            qInfo()<<"enter admin KEY";
            std::cin>>admin_name;
            outStream<<QString::fromStdString(admin_name);
            //delete user
            Deleteuser();
            setFlage(true);
            break;
        case 10:
            exit();
            setFlage(false);
            break;
        default:
            break;
        }
        break;
    case 3:
        setFlage(false);
        qInfo()<<"good bye";
        break;
default:
        break;
    }
    // QTextStream input(stdin, QIODevice::ReadOnly);
    // QString CmyClientInput = input.readLine().trimmed();
    // socket.write(CmyClientInput.toUtf8());
}
}

void CmyClient::disconnected()
{
    qInfo()<<"Thank you!...system is closing";
    qInfo()<<"Disconnected";
}

void CmyClient::error(QAbstractSocket::SocketError socketerror)
{

        qInfo()<<"Error:"<<socketerror<<socket.errorString();
    }

    void CmyClient::stateChanged(QAbstractSocket::SocketState socketstate)
    {
        QMetaEnum metaenum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
        QString str= metaenum.valueToKey(socketstate);

}



void CmyClient::readyRead()
{
    QString data;
    inStream>>data;
    qInfo().noquote()<<data;
}
