//
//  File.swift
//  WakeOnLAN
//
//  Created by Felix Pultar on 01.12.2024.
//

import CWakeOnLAN

// Swift wrapper around C function
public func sendWakeOnLAN(macAddress: String,
                   broadcastIP: String = "255.255.255.255",
                   port: Int = 9) -> Bool {
    return sendMagicPacket(
        macAddress,
        broadcastIP,
        Int32(port)
    )
}
