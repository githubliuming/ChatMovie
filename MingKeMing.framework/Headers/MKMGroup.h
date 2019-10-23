//
//  MKMGroup.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/28.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMEntity.h"

NS_ASSUME_NONNULL_BEGIN

@interface MKMGroup : MKMEntity

@property (readonly, strong, nonatomic) MKMID *founder;
@property (readonly, strong, nonatomic) MKMID *owner;

@property (readonly, copy, nonatomic) NSArray<MKMID *> *members;

// +create(founder)
// -setName(name)
// -abdicate(member, owner)
// -invite(user, admin)
// -expel(member, admin)
// -join(user)
// -quit(member)

@end

#pragma mark - Group Data Source

@protocol MKMGroupDataSource <MKMEntityDataSource>

/**
 *  Get group founder
 *
 * @param group - group ID
 * @return fonder ID
 */
- (nullable MKMID *)founderOfGroup:(MKMID *)group;

/**
 *  Get group owner
 *
 * @param group - group ID
 * @return owner ID
 */
- (nullable MKMID *)ownerOfGroup:(MKMID *)group;

/**
 *  Get group members list
 *
 * @param group - group ID
 * @return members list (ID)
 */
- (nullable NSArray<MKMID *> *)membersOfGroup:(MKMID *)group;

@end

NS_ASSUME_NONNULL_END
