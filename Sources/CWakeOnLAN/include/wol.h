#ifndef WAKE_ON_LAN_H
#define WAKE_ON_LAN_H

#include <stdbool.h>

bool send_magic_packet(const char *mac_address, const char *broadcast_ip, int port, const char *interface_name);

#endif // WAKE_ON_LAN_H
