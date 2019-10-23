//
//  DKDReliableMessage.h
//  DaoKeDao
//
//  Created by Albert Moky on 2018/9/30.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "DKDSecureMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Instant Message signed by an asymmetric key
 *
 *      data format: {
 *          //-- envelope
 *          sender   : "moki@xxx",
 *          receiver : "hulk@yyy",
 *          time     : 123,
 *          //-- content data & key/keys
 *          data     : "...",  // base64_encode(symmetric)
 *          key      : "...",  // base64_encode(asymmetric)
 *          keys     : {
 *              "ID1": "key1", // base64_encode(asymmetric)
 *          },
 *          //-- signature
 *          signature: "..."   // base64_encode()
 *      }
 */
@interface DKDReliableMessage : DKDSecureMessage

@property (readonly, strong, nonatomic) NSData *signature;

- (instancetype)initWithDictionary:(NSDictionary *)dict
NS_DESIGNATED_INITIALIZER;

@end

// convert Dictionary to ReliableMessage
#define DKDReliableMessageFromDictionary(msg)                                  \
            [DKDReliableMessage getInstance:(msg)]                             \
                               /* EOF 'DKDReliableMessageFromDictionary(msg)' */

#pragma mark -

/**
 *  Extends for the first message package of 'Handshake' protocol
 */
@interface DKDReliableMessage (Meta)

@property (strong, nonatomic) NSDictionary *meta;

@end

NS_ASSUME_NONNULL_END
