//
//  IMTerminal.swift
//  ChatMovie
//
//  Created by Yuri Boyka on 2019/10/24.
//  Copyright © 2019 Yuri Boyka. All rights reserved.
//

import UIKit
import DIMClient
import DIMCore

public class IMTerminal: DIMTerminal {
    static let `default` = IMTerminal()
    
    public var deviceToken:Data?
    
    public override var userAgent:String {
        
        let device = UIDevice.current
        let model:String = device.model
        let sysName:String = device.systemName
        let sysVersion:String = device.systemVersion
        let agentStr = "DIMP/1.0 (\(model); U; \(sysName); \(sysVersion); \(self.language)) DIMCoreKit/1.0 (Terminal, like WeChat) DIM-by-GSP/1.0.1";
        print("user-Agent = \(agentStr)")
        return agentStr
    }
    
    private override init() {
        super.init()
    }
    
    func displayName() -> String {
        return Bundle.info(key: "CFBundleDisplayName")
    }
    func version() -> String {
        return Bundle.info(key: "CFBundleShortVersionString")
    }
    
    override public func onHandshakeAccepted(_ session: String) {
        super.onHandshakeAccepted(session)
        
        if let deviceData = self.deviceToken {
            let token = deviceData.hexString()
            let cmd:DIMCommand = DIMCommand(command: "report")
            cmd.setObject("apns", forKey: "title")
            cmd.setObject(token, forKey: "device_token")
            self.send(cmd);
        }
        let date = Date();
        let station:DIMServer = self.value(forKey: "_currentStation") as! DIMServer
        let spid = station.sp.id;
        let sid = station.id;
        let host = station.host;
        let port = station.port;
        
        let uid = self.currentUser.id
        let terminal = self.version()
        let agent = self.userAgent;
        
        let login:Dictionary<String,Any> = ["provider": spid,
                                            "station": sid,
                                            "host": host,
                                            "port": port,
                                            "time":(Int32)(date.timeIntervalSince1970),
                                            "account":uid,
                                            "terminal":terminal,
                                            "userAgent":agent
        ]
        let cmd = DIMCommand(command: "login")
        cmd.setObject(login, forKey: "login")
        self.broadcast(cmd)
    }
}
extension IMTerminal {
    
    public func didFinishLaunching(options launchOptions:Dictionary<String,Any>){
        
        let app = UIApplication.shared
        if app.applicationIconBadgeNumber > 0 {
            
            app.applicationIconBadgeNumber = 0
        }
        app.registerForRemoteNotifications();
        
        let noficationCenter = UNUserNotificationCenter.current()
        noficationCenter.delegate = self;
        let options = UNAuthorizationOptions.badge.rawValue | UNAuthorizationOptions.alert.rawValue | UNAuthorizationOptions.sound.rawValue
        noficationCenter.requestAuthorization(options: UNAuthorizationOptions(rawValue: options)) { (granted, error) in
            if granted {
                print("通知权限已经打开")
            } else
            {
                print("通知权限授权失败")
            }
        }
        
        
        noficationCenter.removeAllPendingNotificationRequests()
        
    }
    
    private func launchServiceProvider(config:Dictionary<String,Any>){
        
        let IDString = config["ID"] as! String
        let id = Id(with: IDString)
        let sp = DIMServiceProvider.init(id: id!)
        let stations:Array<Dictionary<String,Any>> = config["stations"] as! Array<Dictionary<String,Any>>
        let station:Dictionary<String,Any> = stations.first!
        print("server info = \(station)")
    }
    private func startServer(server:Dictionary<String,Any>, provider:DIMServiceProvider) {
        
       let ID = Id(with: server["ID"] as! String)!
       let meta = Meta(from: server["meta"] as! Dictionary<String,Any>)!
        
//        let userDB = AccountDatabase
        
    }
}


extension IMTerminal:UNUserNotificationCenterDelegate {
    
    public func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        
        completionHandler(UNNotificationPresentationOptions.alert)
    }
}

