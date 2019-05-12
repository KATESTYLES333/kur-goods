#include "combobox.h"
#include <QSqlQuery>

ComboBoxModel::ComboBoxModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QSqlQuery query;
    query.exec("SELECT id, c_name FROM Countries");
    while(query.next()){
        m_content.push_back(DataPair(query.value(0), query.value(1)));
    }
}



int ComboBoxModel::rowCount(const QModelIndex &parent) const
{
    return m_content.count();
}

QVariant ComboBoxModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    const DataPair& data = m_content.at(index.row());
    QVariant value;
    switch (role) {
    case Qt::DisplayRole:
    {
        value = data.second;
    }
        break;
       case Qt::UserRole:
    {
        value = data.first;
    }
        break;
    default:
        break;
    }
    // FIXME: Implement me!
    return value;
}
