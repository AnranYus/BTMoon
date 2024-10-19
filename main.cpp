#include <iostream>

#include "device/Device.h"

int main() {
    const auto* device = new Device();
    device->move(2,2,200);
    delete device;
    return 0;
}
