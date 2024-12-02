#ifndef WAKE_ON_LAN_H
#define WAKE_ON_LAN_H

#include <stdbool.h>

/**
 * Send a Wake-on-LAN magic packet to the specified MAC address
 * 
 * @param mac_address String representation of MAC address (e.g. "00:11:22:33:44:55")
 * @param broadcast_ip IP address to send the broadcast packet to (e.g. "255.255.255.255")
 * @param port Port to send the WoL packet (default is 9)
 * @return true if packet sent successfully, false otherwise
 */
bool send_magic_packet(
    const char *mac_address,
    const char *broadcast_ip,
    int port,
    const char *interface_name
);

int get_interface_index(const char *interface_name);

int list_interfaces();

#endif // WAKE_ON_LAN_H
