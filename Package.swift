// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "WakeOnLAN",
    products: [
        .library(
            name: "WakeOnLAN",
            targets: ["CWakeOnLAN"])
    ],
    targets: [
        .target(
            name: "CWakeOnLAN",
            publicHeadersPath: "include")
    ]
)
