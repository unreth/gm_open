#include "param.h"

using namespace std;

static param * paraminstance = NULL;

param * param::getInstance () {
    if (paraminstance == NULL){
        paraminstance = new param ();
    }
    return paraminstance;
}
