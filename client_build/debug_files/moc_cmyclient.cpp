/****************************************************************************
** Meta object code from reading C++ file 'cmyclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/Ahmed shawky/Desktop/New folder/myClient/cmyclient.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmyclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCmyClientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCmyClientENDCLASS = QtMocHelpers::stringData(
    "CmyClient",
    "connectToHost",
    "",
    "host",
    "port",
    "disconnect",
    "connected",
    "disconnected",
    "error",
    "QAbstractSocket::SocketError",
    "socketerror",
    "stateChanged",
    "QAbstractSocket::SocketState",
    "socketstate",
    "readyRead"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCmyClientENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[10];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[5];
    char stringdata5[11];
    char stringdata6[10];
    char stringdata7[13];
    char stringdata8[6];
    char stringdata9[29];
    char stringdata10[12];
    char stringdata11[13];
    char stringdata12[29];
    char stringdata13[12];
    char stringdata14[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCmyClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCmyClientENDCLASS_t qt_meta_stringdata_CLASSCmyClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "CmyClient"
        QT_MOC_LITERAL(10, 13),  // "connectToHost"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 4),  // "host"
        QT_MOC_LITERAL(30, 4),  // "port"
        QT_MOC_LITERAL(35, 10),  // "disconnect"
        QT_MOC_LITERAL(46, 9),  // "connected"
        QT_MOC_LITERAL(56, 12),  // "disconnected"
        QT_MOC_LITERAL(69, 5),  // "error"
        QT_MOC_LITERAL(75, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(104, 11),  // "socketerror"
        QT_MOC_LITERAL(116, 12),  // "stateChanged"
        QT_MOC_LITERAL(129, 28),  // "QAbstractSocket::SocketState"
        QT_MOC_LITERAL(158, 11),  // "socketstate"
        QT_MOC_LITERAL(170, 9)   // "readyRead"
    },
    "CmyClient",
    "connectToHost",
    "",
    "host",
    "port",
    "disconnect",
    "connected",
    "disconnected",
    "error",
    "QAbstractSocket::SocketError",
    "socketerror",
    "stateChanged",
    "QAbstractSocket::SocketState",
    "socketstate",
    "readyRead"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCmyClientENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   56,    2, 0x0a,    1 /* Public */,
       5,    0,   61,    2, 0x0a,    4 /* Public */,
       6,    0,   62,    2, 0x09,    5 /* Protected */,
       7,    0,   63,    2, 0x09,    6 /* Protected */,
       8,    1,   64,    2, 0x09,    7 /* Protected */,
      11,    1,   67,    2, 0x09,    9 /* Protected */,
      14,    0,   70,    2, 0x09,   11 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CmyClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCmyClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCmyClientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCmyClientENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CmyClient, std::true_type>,
        // method 'connectToHost'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'disconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'error'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CmyClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CmyClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectToHost((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 1: _t->disconnect(); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->error((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 5: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 6: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *CmyClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CmyClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCmyClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CmyClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
