//
//  File.swift
//  WakeOnLAN
//
//  Created by Felix Pultar on 01.12.2024.
//

import CWakeOnLAN

public func sendWakeOnLAN(macAddress: String, broadcastIP: String = "255.255.255.255", port: Int = 9, interfaceName: String = "en0") -> Bool {
    return send_magic_packet(macAddress, broadcastIP, Int32(port), interfaceName)
}
