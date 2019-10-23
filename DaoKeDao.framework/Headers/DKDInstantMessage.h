//
//  DKDInstantMessage.h
//  DaoKeDao
//
//  Created by Albert Moky on 2018/9/30.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "DKDMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class DKDContent;

/**
 *  Instant Message
 *
 *      data format: {
 *          //-- envelope
 *          sender   : "moki@xxx",
 *          receiver : "hulk@yyy",
 *          time     : 123,
 *          //-- content
 *          content  : {...}
 *      }
 */
@interface DKDInstantMessage : DKDMessage

@property (readonly, strong, nonatomic) DKDContent *content;

- (instancetype)initWithContent:(DKDContent *)content
                         sender:(NSString *)from
                       receiver:(NSString *)to
                           time:(nullable NSDate *)time;

- (instancetype)initWithContent:(DKDContent *)content
                       envelope:(DKDEnvelope *)env
NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDictionary:(NSDictionary *)dict
NS_DESIGNATED_INITIALIZER;

@end

// convert Dictionary to InstantMessage
#define DKDInstantMessageFromDictionary(msg)                                   \
            [DKDInstantMessage getInstance:(msg)]                              \
                                /* EOF 'DKDInstantMessageFromDictionary(msg)' */

// create InstantMessage
#define DKDInstantMessageCreate(content, from, to, when)                       \
            [[DKDInstantMessage alloc] initWithContent:(content)               \
                                                sender:(from)                  \
                                              receiver:(to)                    \
                                                  time:(when)]                 \
                    /* EOF 'DKDInstantMessageCreate(content, from, to, when)' */

NS_ASSUME_NONNULL_END
