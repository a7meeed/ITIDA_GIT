#include "cjison.h"
#include"server.h"
QTextStream qin(stdin);
QTextStream qout(stdout);
Cjison::Cjison(QObject *parent)
    : QObject{parent}
{
    outStream.setDevice(&socket);
    inStream.setDevice(&socket);
    outStream.setVersion(QDataStream::Qt_6_6);
    inStream.setVersion(QDataStream::Qt_6_6);
}
void Cjison::AddNewObject(const QString &fileName,const QString account_no,const QString balance,const QString full_name,const QString password,const QString age)
{
    static quint32 counter =1;
    // QString account_no,balance,full_name,password,age;
    QString UserNameKey="USER";
    QVariantMap newObject;
    QString num = QString::number(counter);
    QString NewObjectName =UserNameKey + num;

    // qout << "Enter name age city" << Qt::endl;
    // qin >> name >> age >> city;

    newObject["Account Number"] = account_no;
    newObject["Balance"] = balance;
    newObject["Full name"] =full_name;
    newObject["Password"] =password;
    newObject["age"] =age;

    QFile file(fileName);
    //Check for opening the file in Read only mode && as Text file
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Read all file contnents and then parse it as a json document and then save it in a qjson document ...Read existing JSON data from the file
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        // close file
        file.close();

        // Checking that json fileis successfully read and parsed && contains a valid json object
        if(!jsonDoc.isNull() && jsonDoc.isObject())
        {
            // Convert the JSON object to a QVariantMap
            QVariantMap jsonMap = jsonDoc.object().toVariantMap();

            // Add the new object to the QVariantMap
            jsonMap[NewObjectName] = newObject;

            // Convert the QVariantMap back to a JSON object
            QJsonObject jsonObj = QJsonObject::fromVariantMap(jsonMap);

            // Open the file for writing
            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                // Write the modified JSON data back to the file
                file.write(QJsonDocument(jsonObj).toJson());
                file.close();
                qDebug() << "New object added to" << fileName;
            }else {
                qWarning() << "Failed to open file for writing:" << file.errorString();
            }
        } else {
            qWarning() << "Failed to parse JSON data from" << fileName;
        }
    } else {
        qWarning() << "Failed to open file for reading:" << file.errorString();
    }
    counter++;
}

QString Cjison::PrintAllDb(const QString &fileName)
{
    QString dataBase;
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return 0;
    }

    // Read all data from the file
    QByteArray jsonData = file.readAll();

    // Parse the JSON data
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    // Check if the document is valid
    if (!doc.isNull())
    {
        // Convert JSON document to formatted string
        QString jsonString = doc.toJson(QJsonDocument::Indented);
        dataBase=jsonString;
        // Print the entire JSON content
        qDebug().noquote() << "Contents of JSON file:";
        qDebug().noquote() << jsonString;
    }
    else
    {
        qDebug() << "Failed to parse JSON document";
    }
    return dataBase;
}



QString Cjison::printObjectFields(const QString &fileName, const QString &objectName,const QString &field)
{
    QString data;
    QFile file(fileName);
    if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (!jsonDoc.isNull() && jsonDoc.isObject()) {
            QJsonObject jsonObject = jsonDoc.object();

            // Check if the specified objectName exists
            if (jsonObject.contains(objectName)) {
                QJsonObject targetObject = jsonObject.value(objectName).toObject();
                data = targetObject[field].toString();
                // Print the fields of the specified object
                // qInfo() << "Fields of" << objectName << ":";
                // qInfo() << "Age:" << targetObject["age"].toString();
                // qInfo() << "Account Number:" << targetObject["Account Number"].toString();
                // qInfo() << "Name:" << targetObject["Full name"].toString();
                qInfo()<<data;
            } else {
                qWarning() << "Object with name" << objectName << "not found in the JSON file.";
            }
        } else {
            qWarning() << "Failed to parse JSON data from" << fileName;
        }
    } else {
        qWarning() << "Failed to open file for reading:" << file.errorString();
    }
    return data;

}

/*
 *bool modifyFieldInJsonObject(const QString &filePath, int targetId, const QString &fieldName, const QString &newValue)
{
    // Step 1: Read the JSON file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to open the file for reading.";
        return false;
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
    file.close();

    // Step 2: Find the specific JSON object
    if (!jsonDoc.isNull() && jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();

        // Assume each element of the array is a JSON object
        for (int i = 0; i < jsonArray.size(); ++i) {
            QJsonObject jsonObject = jsonArray[i].toObject();

            // Check if this is the specific JSON object you want to modify
            if (jsonObject["id"].toInt() == targetId) {
                // Step 3: Modify the value of a specific field in the JSON object
                jsonObject[fieldName] = newValue;

                // Step 4: Write the modified QJsonObject back to the JSON file
                jsonArray[i] = jsonObject;

                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QJsonDocument modifiedJsonDoc(jsonArray);
                    file.write(modifiedJsonDoc.toJson());
                    file.close();

                    qDebug() << "Field updated successfully.";
                    return true;
                } else {
                    qDebug() << "Error: Unable to open the file for writing.";
                    return false;
                }
            }
        }
    } else {
        qDebug() << "Error: Invalid JSON document.";
        return false;
    }

    qDebug() << "Error: JSON object not found.";
    return false;
}
 */



void Cjison::EditSpecifcField(const QString &fileName, const QString &ObjectKey, const QString &FieldToChange, const QString &NewValue)
{
    // read json file
    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        //Parse the JSON document from the file
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        file.close();

        // Check if the JSON document is an object
        if(!jsonDoc.isNull() && jsonDoc.isObject())
        {
            // Create a new json object and save the old json object in it
            QJsonObject jsonObj = jsonDoc.object();

            // Check if the specified object key exists and is an object
            if ( jsonObj.contains(ObjectKey) && jsonObj[ObjectKey].isObject() )
            {
                // Modify the new json object
                QJsonObject TheNewObject = jsonObj[ObjectKey].toObject();
                TheNewObject[FieldToChange] = NewValue;

                // Update the original json object in the main json file
                jsonObj[ObjectKey] = TheNewObject ;

                // write the modifited json object to the main json file
                if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
                {
                    QJsonDocument modifiedJsonDoc(jsonObj);
                    file.write(modifiedJsonDoc.toJson());
                    file.close();
                    qDebug() << "Field updated successfully.";
                }else {
                    qDebug() << "Error: Unable to open the file for writing.";
                }
            }else {
                qDebug() << "Error: Object key not found or not an object.";
            }


        } else {
            qDebug() << "Error: Invalid JSON document.";
        }
    }else {
        qWarning() << "Failed to open file for reading:" << file.errorString();
    }

}


void Cjison::deleteObject(const QString &filePath, const QString &objectKey)
{
    // Step 1: Read the JSON file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << "Error: Unable to open the file for reading.";
        return;
    }

    // Parse the JSON document from the file
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
    file.close();

    // Step 2: Check if the JSON document is an object
    if (jsonDoc.isObject())
    {
        QJsonObject jsonObject = jsonDoc.object();

        // Step 3: Check if the specified object key exists
        if (jsonObject.contains(objectKey))
        {
            // Step 4: Remove the specified object from the main JSON object
            jsonObject.remove(objectKey);

            // Step 5: Write the modified JSON object back to the file
            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QJsonDocument modifiedJsonDoc(jsonObject);
                file.write(modifiedJsonDoc.toJson());
                file.close();

                qDebug() << "Object deleted successfully.";
                return ;
            } else {
                qDebug() << "Error: Unable to open the file for writing.";
                return ;
            }
        } else {
            qDebug() << "Error: Object key not found.";
            return ;
        }
    } else {
        qDebug() << "Error: Invalid JSON document. Expected an object.";
        return ;
    }
}


