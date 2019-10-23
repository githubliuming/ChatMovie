//
//  DKDMessage.h
//  DaoKeDao
//
//  Created by Albert Moky on 2018/10/20.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "DKDDictionary.h"

NS_ASSUME_NONNULL_BEGIN

@class DKDEnvelope;

@protocol DKDMessageDelegate <NSObject>
@end

/**
 *  Common Message
 *
 *      data format: {
 *          //-- envelope
 *          sender   : "moki@xxx",
 *          receiver : "hulk@yyy",
 *          time     : 123,
 *          //-- others
 *          ...
 *      }
 */
@interface DKDMessage : DKDDictionary {
    
}

@property (readonly, strong, nonatomic) DKDEnvelope *envelope;

/**
 *  Group ID
 *      when a group message was split/trimmed to a single message
 *      the 'receiver' will be changed to a member ID, and
 *      the group ID will be saved as 'group'.
 */
@property (strong, nonatomic, nullable) NSString *group;

// delegate to transform message
@property (weak, nonatomic) __kindof id<DKDMessageDelegate> delegate;

- (instancetype)initWithSender:(NSString *)from
                      receiver:(NSString *)to
                          time:(nullable NSDate *)time;

- (instancetype)initWithEnvelope:(DKDEnvelope *)env
NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDictionary:(NSDictionary *)dict
NS_DESIGNATED_INITIALIZER;

@end

// convert Dictionary to Message
#define DKDMessageFromDictionary(msg)                                          \
            [DKDMessage getInstance:(msg)]                                     \
                                       /* EOF 'DKDMessageFromDictionary(msg)' */

@interface DKDMessage (Runtime)

+ (nullable instancetype)getInstance:(id)msg;

@end

NS_ASSUME_NONNULL_END
