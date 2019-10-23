//
//  MKMID.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/24.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMAddress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ID for entity (User/Group)
 *
 *      data format: "name@address[/terminal]"
 *
 *      fileds:
 *          name     - entity name, the seed of fingerprint to build address
 *          address  - a string to identify an entity
 *          terminal - entity login resource(device), OPTIONAL
 */
@interface MKMID : MKMString

@property (readonly, strong, nonatomic, nullable) NSString *name;
@property (readonly, strong, nonatomic) MKMAddress *address;

@property (readonly, nonatomic) MKMNetworkType type; // Network ID
@property (readonly, nonatomic) UInt32 number;       // search number

@property (strong, nonatomic, nullable) NSString *terminal;

@property (readonly, nonatomic, getter=isValid) BOOL valid;

/**
 *  Initialize an ID with string form "name@address[/terminal]"
 *
 * @param aString - ID string
 * @return ID object
 */
- (instancetype)initWithString:(NSString *)aString;

/**
 *  Initialize an ID with username & address
 *
 * @param seed - username
 * @param addr - hash(fingerprint)
 * @return ID object
 */
- (instancetype)initWithName:(nullable NSString *)seed
                     address:(MKMAddress *)addr;

/**
 *  For ID without name(only contains address), likes BTC/ETH/...
 */
- (instancetype)initWithAddress:(MKMAddress *)addr;

@end

@interface MKMID (Broadcast)

@property (readonly, nonatomic, getter=isBroadcast) BOOL broadcast;

@end

// convert String to ID
#define MKMIDFromString(ID)                                                    \
            [MKMID getInstance:(ID)]                                           \
                                                 /* EOF 'MKMIDFromString(ID)' */

/**
 *  ID for broadcast
 */
#define MKMAnyone()                                                            \
            MKMIDFromString(@"anyone@anywhere")                                \
                                                         /* EOF 'MKMAnyone()' */
#define MKMEveryone()                                                          \
            MKMIDFromString(@"everyone@everywhere")                            \
                                                       /* EOF 'MKMEveryone()' */

@interface MKMID (Runtime)

+ (nullable instancetype)getInstance:(id)ID;

@end

NS_ASSUME_NONNULL_END
