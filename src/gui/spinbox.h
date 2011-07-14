#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>

class spinbox : public QSpinBox {
    Q_OBJECT

public:
    inline spinbox(int i, int j) : QSpinBox() {
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

#endif // SPINBOX_H
