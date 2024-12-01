// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "WakeOnLAN",
    products: [
        .library(
            name: "WakeOnLAN",
            targets: ["WakeOnLAN"])
    ],
    targets: [
        .target(
            name: "CWakeOnLAN",
            publicHeadersPath: "include"),
        .target(
            name: "WakeOnLAN",
            dependencies: ["CWakeOnLAN"])
    ]
)
