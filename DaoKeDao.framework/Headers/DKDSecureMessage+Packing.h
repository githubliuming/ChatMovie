//
//  DKDSecureMessage+Packing.h
//  DaoKeDao
//
//  Created by Albert Moky on 2018/12/28.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "DKDSecureMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface DKDSecureMessage (Packing)

/**
 *  Group ID
 *      when a group message was splitted/trimmed to a single message
 *      the 'receiver' will be changed to a member ID, and
 *      the group ID will be saved as 'group'.
 */
@property (strong, nonatomic, nullable) NSString *group;

/**
 *  Split the group message to single person messages
 *
 *  @param members - group members
 *  @return secure/reliable message(s)
 */
- (NSArray *)splitForMembers:(NSArray<NSString *> *)members;

/**
 *  Trim the group message for a member
 *
 * @param member - group member ID
 * @return SecureMessage/ReliableMessage
 */
- (instancetype)trimForMember:(NSString *)member;

@end

NS_ASSUME_NONNULL_END
