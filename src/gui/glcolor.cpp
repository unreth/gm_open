#include "glcolor.h"

static glcolor * glcolorinstance = NULL;

glcolor * glcolor::getInstance () {
    if (glcolorinstance == NULL){
        glcolorinstance = new glcolor();
    }
    return glcolorinstance;
}
