//
// Created by anran on 24-10-20.
//

#ifndef DEVICE_H
#define DEVICE_H
#include <cstring>
#include <string>
#include <linux/uinput.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>


class Device {
public:
    Device() {
        if (fd < 0) {
            throw std::runtime_error("Unable to open /dev/uinput");
        }

        ioctl(fd, UI_SET_EVBIT, EV_KEY);
        ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
        ioctl(fd, UI_SET_EVBIT, EV_REL);
        ioctl(fd, UI_SET_RELBIT, REL_X);
        ioctl(fd, UI_SET_RELBIT, REL_Y);

        uinput_setup setup = {};
        setup.id.bustype = BUS_USB;
        setup.id.vendor = VENDOR;
        setup.id.product = PRODUCT;
        std::strncpy(setup.name, NAME.c_str(), sizeof(setup.name));

        ioctl(fd, UI_DEV_SETUP, &setup);
        ioctl(fd, UI_DEV_CREATE);

    }
    const std::string NAME = "VBT_MOON";
    const int VENDOR = 0x1;
    const int PRODUCT = 0x2;
    void move(int x, int y, int num) const;

    ~Device() {
        ioctl(fd, UI_DEV_DESTROY);
        close(fd);
    }

private:
    const int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
};



#endif //DEVICE_H
