//
//  TypeDefine.swift
//  ChatMovie
//
//  Created by Yuri Boyka on 2019/10/24.
//  Copyright © 2019 Yuri Boyka. All rights reserved.
//
import MingKeMing
import DaoKeDao
import DIMCore
import DIMClient

import Foundation

//Cryptography
typealias CMSymmetricKey = MKMSymmetricKey
typealias CMPublicKey = MKMPublicKey
typealias CMPrivateKey = MKMPrivateKey

//Entity
typealias CMID = MKMID
typealias CMAddress = MKMAddress
typealias CMMeta = MKMMeta
typealias CMProfile = MKMProfile
typealias CMEntity = MKMEntity
typealias CMEntityDataSource = MKMEntityDataSource

//User
typealias CMUser = MKMUser
typealias CMLocalUser = MKMLocalUser
typealias CMUserDataSource = MKMUserDataSource

//Group
typealias CMGroup = MKMGroup
typealias CMGroupDataSource = MKMGroupDataSource

// Types
typealias CMDictionary = DKDDictionary
typealias CMEnvelope = DKDEnvelope
typealias CMContent = DKDContent
typealias CMForwardContent = DKDForwardContent

// Message
typealias CMMessage = DKDMessage
typealias CMInstantMessage = DKDInstantMessage
typealias CMSecureMessage = DKDSecureMessage
typealias CMReliableMessage = DKDReliableMessage
typealias CMMessageDelegate = DKDMessageDelegate
typealias CMInstantMessageDelegate = DKDInstantMessageDelegate
typealias CMSecureMessageDelegate = DKDSecureMessageDelegate
typealias CMReliableMessageDelegate = DKDReliableMessageDelegate

//重写下层的宏定义方法
func Meta(for id:CMID) -> CMMeta?{
    return DIMFacebook.sharedInstance().meta(for: id)
}
func Profile(for id:CMID) ->CMProfile? {
    return DIMFacebook.sharedInstance().profile(for: id);
}
func Id(with address:CMAddress) ->CMID? {
    return DIMFacebook.sharedInstance().id(with: address)
}
func Id(with idStr:String) ->CMID? {
    DIMFacebook.sharedInstance().id(with: idStr)
}
func user(with id:CMID) ->CMUser? {
    DIMFacebook.sharedInstance().user(with: id)
}
func group(with id:CMID) -> CMGroup? {
    DIMFacebook.sharedInstance().group(with: id)
}
func Meta(from meta:Dictionary<String,Any>) -> CMMeta?
{
    return MKMMeta.getInstance(meta)
}
func Meta(with version:UInt,privateKey:CMPrivateKey,seed:String) -> CMMeta? {
    
   return MKMMeta.generate(withVersion: version, privateKey: privateKey, seed: seed)
}

