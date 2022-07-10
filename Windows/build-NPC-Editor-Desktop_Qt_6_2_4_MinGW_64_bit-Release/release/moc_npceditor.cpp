/****************************************************************************
** Meta object code from reading C++ file 'npceditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NPC-Editor/npceditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'npceditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NPCEditor_t {
    const uint offsetsAndSize[22];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NPCEditor_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NPCEditor_t qt_meta_stringdata_NPCEditor = {
    {
QT_MOC_LITERAL(0, 9), // "NPCEditor"
QT_MOC_LITERAL(10, 22), // "on_open_code_triggered"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 22), // "on_save_code_triggered"
QT_MOC_LITERAL(57, 25), // "on_save_code_as_triggered"
QT_MOC_LITERAL(83, 22), // "on_clear_all_triggered"
QT_MOC_LITERAL(106, 28), // "on_assign_npc_name_triggered"
QT_MOC_LITERAL(135, 26), // "on_upload_avatar_triggered"
QT_MOC_LITERAL(162, 25), // "on_upload_model_triggered"
QT_MOC_LITERAL(188, 28), // "on_upload_location_triggered"
QT_MOC_LITERAL(217, 21) // "on_open_map_triggered"

    },
    "NPCEditor\0on_open_code_triggered\0\0"
    "on_save_code_triggered\0on_save_code_as_triggered\0"
    "on_clear_all_triggered\0"
    "on_assign_npc_name_triggered\0"
    "on_upload_avatar_triggered\0"
    "on_upload_model_triggered\0"
    "on_upload_location_triggered\0"
    "on_open_map_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NPCEditor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NPCEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NPCEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_open_code_triggered(); break;
        case 1: _t->on_save_code_triggered(); break;
        case 2: _t->on_save_code_as_triggered(); break;
        case 3: _t->on_clear_all_triggered(); break;
        case 4: _t->on_assign_npc_name_triggered(); break;
        case 5: _t->on_upload_avatar_triggered(); break;
        case 6: _t->on_upload_model_triggered(); break;
        case 7: _t->on_upload_location_triggered(); break;
        case 8: _t->on_open_map_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject NPCEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_NPCEditor.offsetsAndSize,
    qt_meta_data_NPCEditor,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NPCEditor_t
, QtPrivate::TypeAndForceComplete<NPCEditor, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NPCEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NPCEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NPCEditor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int NPCEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
