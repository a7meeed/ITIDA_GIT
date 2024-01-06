#include <QCoreApplication>
#include"cmyclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CmyClient client;
    client.connectToHost("127.0.0.1",4509);
    return a.exec();
}
