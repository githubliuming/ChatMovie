//
//  MKMEntity.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/26.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMAddress.h"

NS_ASSUME_NONNULL_BEGIN

@class MKMID;
@class MKMMeta;
@class MKMProfile;

@protocol MKMEntityDataSource;

@interface MKMEntity : NSObject <NSCopying> {
    
    // convenience for instance accessing
    MKMID *_ID;
}

@property (readonly, copy, nonatomic) MKMID *ID;        // name@address

@property (readonly, nonatomic) MKMNetworkType type;    // Network ID
@property (readonly, nonatomic) UInt32 number;          // search number

@property (readonly, strong, nonatomic) MKMMeta *meta;
@property (readonly, strong, nonatomic, nullable) __kindof MKMProfile *profile;
@property (readonly, strong, nonatomic) NSString *name; // profile.name or seed

@property (weak, nonatomic) __kindof id<MKMEntityDataSource> dataSource;

- (instancetype)initWithID:(MKMID *)ID NS_DESIGNATED_INITIALIZER;

@end

#pragma mark - Entity Data Source

@protocol MKMEntityDataSource <NSObject>

/**
 *  Get meta for entity ID
 *
 * @param ID - entity ID
 * @return meta object
 */
- (nullable MKMMeta *)metaForID:(MKMID *)ID;

/**
 *  Get profile for entity ID
 *
 * @param ID - entity ID
 * @return profile object
 */
- (nullable __kindof MKMProfile *)profileForID:(MKMID *)ID;

@end

NS_ASSUME_NONNULL_END
