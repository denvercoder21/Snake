#pragma once

#include "board.h"

#include <QAbstractListModel>
#include <QMetaEnum>

using RoleNames = QHash<int, QByteArray>;

template<typename ENUM>
RoleNames roleNamesFromEnum()
{
    RoleNames roles;
    auto e = QMetaEnum::fromType<ENUM>();

    for (int i = 0; i < e.keyCount(); ++i) {
        auto name = QByteArray(e.key(i));
        if (name.isEmpty())
            continue;
        name[0] = std::tolower(name[0]);
        roles.insert(e.value(i), name);
    }

    return roles;
}

#define QX_ROLE(ROLE) \
    Q_ENUM(ROLE) \
    inline virtual RoleNames roleNames() const override { return ::roleNamesFromEnum<ROLE>(); }

class board_viewmodel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Role
    {
        CellState = Qt::UserRole,
        Color
    };
    QX_ROLE(Role)

//    enum State
//    {
//        Empty,
//        Snake,
//        Fruit
//    };
//    Q_ENUM(State)

    board_viewmodel(const board& _board, QObject *parent = nullptr);

    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
    const board& m_board;
};
