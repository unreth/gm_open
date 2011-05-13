#include "glcolor.h"

static glcolor * instance = NULL;

glcolor * glcolor::getInstance () {
    if (instance == NULL){
        instance = new glcolor ();
    }
    return instance;
}
