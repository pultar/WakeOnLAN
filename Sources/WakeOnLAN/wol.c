#include "include/wol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define WOL_DEFAULT_PORT 9
#define MAC_ADDRESS_LENGTH 6

bool sendMagicPacket(
    const char* mac_address,
    const char* broadcast_ip, 
    int port
) {
    // Default port if not specified
    if (port <= 0) {
        port = WOL_DEFAULT_PORT;
    }

    // Parse MAC address
    unsigned char mac[MAC_ADDRESS_LENGTH];
    if (sscanf(mac_address, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", 
               &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]) != MAC_ADDRESS_LENGTH) {
        fprintf(stderr, "Invalid MAC address format\n");
        return false;
    }

    // Create magic packet
    unsigned char packet[102];
    memset(packet, 0xFF, 6);  // First 6 bytes are 0xFF

    // Repeat MAC address 16 times
    for (int i = 0; i < 16; i++) {
        memcpy(packet + 6 + (i * 6), mac, 6);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        perror("Socket creation failed");
        return false;
    }

    // Enable broadcast
    int broadcast = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("Broadcast socket option failed");
        close(sock);
        return false;
    }

    // Setup socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, broadcast_ip, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid broadcast IP\n");
        close(sock);
        return false;
    }

    // Send packet
    ssize_t sent = sendto(sock, packet, sizeof(packet), 0, 
                          (struct sockaddr*)&addr, sizeof(addr));
    
    close(sock);

    return sent == sizeof(packet);
}
