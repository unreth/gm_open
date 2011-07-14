#include "eegcoord.h"

static eegcoord * eegcoordinstance = NULL;

eegcoord * eegcoord::getInstance () {
    if (eegcoordinstance == NULL){
        eegcoordinstance = new eegcoord();
    }
    return eegcoordinstance;
}
