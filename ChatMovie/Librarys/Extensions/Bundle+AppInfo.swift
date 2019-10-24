//
//  Bundle+AppInfo.swift
//  ChatMovie
//
//  Created by Yuri Boyka on 2019/10/24.
//  Copyright © 2019 Yuri Boyka. All rights reserved.
//

import Foundation
extension Bundle{
    
    open class func info(key:String)->String{
        guard let info:String = Bundle.main.infoDictionary?[key] as? String else {
            return ""
        }
        return info
    }
}
