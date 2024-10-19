//
// Created by anran on 24-10-20.
//

#include "Device.h"
#define SLEEP

void Device::move(const int x,const int y, const int num) const {
    auto* ev = new input_event();
    for (int i = 0; i < num; i++) {
        ev->type = EV_REL;
        ev->code = REL_X;
        ev->value = x;
        write(fd, ev, sizeof(input_event));

        ev->type = EV_REL;
        ev->code = REL_Y;
        ev->value = y;
        write(fd, ev, sizeof(input_event));

        ev->type = EV_SYN;
        ev->code = SYN_REPORT;
        ev->value = 0;
        write(fd, ev, sizeof(input_event));

        usleep(10000);
    }

    delete ev;


}
