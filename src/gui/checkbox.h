#ifndef CHECKBOX_H
#define CHECKBOX_H

#endif // CHECKBOX_H

#include <QCheckBox>

class checkbox : public QCheckBox{
    Q_OBJECT

public:
    inline checkbox(int i, int j, QString s) : QCheckBox(s) {
        this->i = i;
        this->j = j;
    }

    inline int get_i() { return this->i; }
    inline int get_j() { return this->j; }

private:
    int i;
    int j;

signals:

public slots:

};
