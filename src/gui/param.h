#ifndef PARAM_H
#define PARAM_H

#include <iostream>
#include <stdlib.h>
#include <QObject>

#include "vec3D.h"
#include "eegcoord.h"

using namespace std;

class param : public QObject
{
    Q_OBJECT
public:
    //constructor
    static param * getInstance ();
    inline param() { reset(); }

    inline void reset() {
        control_width                       = 200;
        time_res                            = 0.01;     //seconds
        time_flush                          = 1000;   //microseconds!
        //render
        this->mesh                          = 0;
        this->alfa                          = 1;
        this->draw                          = 2;
        this->epsilon                       = 0.25;
        this->lighting                      = true;
        this->trianglescolor                = false;
        this->grad                          = true;
        this->brain                         = vec3Df(1,1,1);
        this->lines                         = vec3Df(1,1,1);
        this->bg                            = vec3Df(1,1,1);
        //epoc
        this->key                           = 1;
        this->pvid                          = 1;
        this->numepoc                       = 0;
        this->started                       = false;
        this->x                             = false;
        this->y                             = false;
        this->acceleration                  = true;
        //sensors
        this->xspeed = 100000;
        this->yspeed = 100000;
        this->all = true;
        this->slider = true;
        this->c[eegcoord::iAF][eegcoord::j3] = 8371;    this->r[eegcoord::iAF][eegcoord::j3] = 200;
        this->c[eegcoord::iAF][eegcoord::j4] = 8436;    this->r[eegcoord::iAF][eegcoord::j4] = 200;
        this->c[eegcoord::iF][eegcoord::j7]  = 8434;    this->r[eegcoord::iF][eegcoord::j7]  = 200;
        this->c[eegcoord::iF][eegcoord::j8]  = 8795;    this->r[eegcoord::iF][eegcoord::j8]  = 200;
        this->c[eegcoord::iF][eegcoord::j3]  = 8696;    this->r[eegcoord::iF][eegcoord::j3]  = 200;
        this->c[eegcoord::iF][eegcoord::j4]  = 8755;    this->r[eegcoord::iF][eegcoord::j4]  = 200;
        this->c[eegcoord::iFC][eegcoord::j5] = 8842;    this->r[eegcoord::iFC][eegcoord::j5] = 200;
        this->c[eegcoord::iFC][eegcoord::j6] = 8411;    this->r[eegcoord::iFC][eegcoord::j6] = 200;
        this->c[eegcoord::iT][eegcoord::j7]  = 9116;    this->r[eegcoord::iT][eegcoord::j7]  = 200;
        this->c[eegcoord::iT][eegcoord::j8]  = 7825;    this->r[eegcoord::iT][eegcoord::j8]  = 200;
        this->c[eegcoord::iP][eegcoord::j7]  = 8529;    this->r[eegcoord::iP][eegcoord::j7]  = 200;
        this->c[eegcoord::iP][eegcoord::j8]  = 8270;    this->r[eegcoord::iP][eegcoord::j8]  = 200;
        this->c[eegcoord::iO][eegcoord::j1]  = 8170;    this->r[eegcoord::iO][eegcoord::j1]  = 200;
        this->c[eegcoord::iO][eegcoord::j2]  = 9103;    this->r[eegcoord::iO][eegcoord::j2]  = 200;
    }

private:
    int     control_width;
    float   time_res;
    int     time_flush;
    //render
    int     mesh;
    float   alfa;
    float   epsilon;
    bool    lighting;           //just for initialization
    bool    trianglescolor;
    bool    grad;
    int     draw;
    vec3Df  brain;
    vec3Df  lines;
    vec3Df  bg;
    //epoc
    int     key;
    int     pvid;
    int     numepoc;
    bool    started;
    bool    x;
    bool    y;
    bool    acceleration;
    //sensors
    float   xspeed;
    float   yspeed;
    bool    all;                //must be initialized on true
    bool    slider;
    int     c[9][9];
    int     r[9][9];


public slots:
    //SET
    //render
    inline void set_mesh(int mesh)              { this->mesh = mesh;                }
    inline void set_alfa(int alfa)              { this->alfa    = alfa/100.;        }
    inline void set_epsilon(int e)              { this->epsilon = (float)e/1000.;   }
    inline void set_epsilon(double e)           { this->epsilon = (float)e;         }
    inline void set_trianglescolor(bool tc)     { this->trianglescolor = tc;        }
    inline void set_grad(bool grad)             { this->grad    = grad;             }
    inline void set_draw(int draw)              { this->draw    = draw;             }
    inline void set_brain(vec3Df brain)         { this->brain   = brain;            }
    inline void set_lines(vec3Df lines)         { this->lines   = lines;            }
    inline void set_bg   (vec3Df bg)            { this->bg      = bg;               }
    //epoc
    inline void set_key(int key)                { this->key     = key;              }
    inline void set_pvid(int pvid)              { this->pvid    = pvid;             }
    inline void set_numepoc(int numepoc)        { this->numepoc = numepoc;          }
    inline void set_started(bool started)       { this->started = started;          }
    inline void set_x(bool x)                   { this->x       = x;                }
    inline void set_y(bool y)                   { this->y       = y;                }
    inline void set_acceleration(bool a)        { this->acceleration = a;           }
    //sensors
    inline void set_xspeed(int xspeed)          { this->xspeed  = xspeed;           }
    inline void set_yspeed(int yspeed)          { this->yspeed  = yspeed;           }
    inline void set_all(bool all)               { this->all = all;                  }
    inline void set_slider(bool slider)         { this->slider  = slider;           }
    inline void set_c(int i, int j, int c)      { this->c[i][j] = c;                }
    inline void set_r(int i, int j, int r)      { this->r[i][j] = r;                }

    //GET
    inline int get_controlwidth()               { return control_width;             }
    inline float get_timeres()                  { return time_res;                  }
    inline int get_timeflush()                  { return time_flush;                }
    //render
    inline int get_mesh()                       { return mesh;                      }
    inline float get_alfa()                     { return alfa;                      }
    inline float get_epsilon()                  { return epsilon;                   }
    inline bool get_lighting()                  { return lighting;                  }
    inline bool get_trianglescolor()            { return trianglescolor;            }
    inline bool get_grad()                      { return grad;                      }
    inline int get_draw()                       { return draw;                      }
    inline vec3Df get_brain()                   { return brain;                     }
    inline vec3Df get_lines()                   { return lines;                     }
    inline vec3Df get_bg()                      { return bg;                        }
    //epoc
    inline int get_key()                        { return key;                       }
    inline int get_pvid()                       { return pvid;                      }
    inline int get_numepoc()                    { return numepoc;                   }
    inline bool get_started()                   { return started;                   }
    inline bool get_x()                         { return x;                         }
    inline bool get_y()                         { return y;                         }
    inline bool get_acceleration()              { return acceleration;              }
    //sensors
    inline int get_xspeed()                     { return xspeed;                    }
    inline int get_yspeed()                     { return yspeed;                    }
    inline bool get_all()                       { return all;                       }
    inline bool get_slider()                    { return slider;                    }
    inline int get_c(int i, int j)              { return c[i][j];                   }
    inline int get_r(int i, int j)              { return r[i][j];                   }
};

#endif // PARAM_H
