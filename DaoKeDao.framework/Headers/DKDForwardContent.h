//
//  DKDForwardContent.h
//  DaoKeDao
//
//  Created by Albert Moky on 2018/10/23.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "DKDContent.h"

NS_ASSUME_NONNULL_BEGIN

@class DKDReliableMessage;

@interface DKDForwardContent : DKDContent

// Top-Secret message forwarded by a proxy (Service Provider)
@property (readonly, nonatomic) DKDReliableMessage *forwardMessage;

/**
 *  Top-Secret message: {
 *      type : 0xFF,
 *      sn   : 456,
 *
 *      forward : {...}  // reliable (secure + certified) message
 *  }
 */
- (instancetype)initWithForwardMessage:(DKDReliableMessage *)rMsg;

@end

NS_ASSUME_NONNULL_END
