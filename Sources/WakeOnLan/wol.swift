//
//  File.swift
//  WakeOnLAN
//
//  Created by Felix Pultar on 01.12.2024.
//

import CWakeOnLAN

// Swift wrapper around C function
func sendWakeOnLAN(macAddress: String,
                   broadcastIP: String = "255.255.255.255",
                   port: Int = 9) -> Bool {
    return send_wake_on_lan_packet(
        macAddress,
        broadcastIP,
        Int32(port)
    )
}
