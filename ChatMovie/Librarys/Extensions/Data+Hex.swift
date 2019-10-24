//
//  Data+Hex.swift
//  ChatMovie
//
//  Created by Yuri Boyka on 2019/10/24.
//  Copyright © 2019 Yuri Boyka. All rights reserved.
//

import Foundation
extension Data {
    func hexString() -> String {
        var bytesPointer: UnsafeBufferPointer<UInt8> = UnsafeBufferPointer(start: nil, count: 0)
        self.withUnsafeBytes { (bytes) in
            bytesPointer = UnsafeBufferPointer<UInt8>(start: UnsafePointer(bytes), count:self.count)
        }
        let hexBytes = bytesPointer.map { return String(format: "%02x", $0) }
        print("device token = \(hexBytes.joined(separator: ""))")
        return hexBytes.joined()
    }
}
