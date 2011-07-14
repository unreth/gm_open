#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

class slider : public QSlider {
    Q_OBJECT

public:
    inline slider(int i, int j) : QSlider(Qt::Horizontal) {
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

#endif // SLIDER_H
