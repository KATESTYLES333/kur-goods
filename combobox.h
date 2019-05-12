#ifndef COMBOBOX_H
#define COMBOBOX_H
#include "queries.h"
#include <QAbstractListModel>
#include <QVector>

class ComboBoxModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ComboBoxModel(QObject *parent = nullptr);
    typedef QPair<QVariant, QVariant> DataPair;
    QVector<DataPair> m_content;


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // COMBOBOX_H
