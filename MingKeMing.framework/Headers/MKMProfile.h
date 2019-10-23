//
//  MKMProfile.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/30.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMDictionary.h"

NS_ASSUME_NONNULL_BEGIN

@class MKMPublicKey;
@class MKMPrivateKey;
@class MKMID;
@class MKMUser;
@class MKMLocalUser;

/**
 *  The Additional Information (Profile)
 *
 *      'Meta' is the information for entity which never changed,
 *          which contains the key for verify signature;
 *      'TAI' is the variable part(signed by meta.key's private key),
 *          which contains the key for asymmetric encryption.
 */
@interface MKMTAI : MKMDictionary

@property (readonly, strong, nonatomic) MKMID *ID;
@property (readonly, nonatomic, getter=isValid) BOOL valid;

- (instancetype)initWithDictionary:(NSDictionary *)dict
NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithID:(MKMID *)ID
                      data:(nullable NSString *)json
                 signature:(nullable NSData *)signature
NS_DESIGNATED_INITIALIZER;

// create a new empty profile
- (instancetype)initWithID:(MKMID *)ID;

#pragma mark Interfaces for profile properties

/**
 *  Update profile property with data & key
 *  (this will reset data & signature)
 */
- (void)setData:(nullable NSObject *)value forKey:(NSString *)key;

/**
 *  Get profile property data with key
 */
- (nullable NSObject *)dataForKey:(NSString *)key;

/**
 *  Get all keys for properties
 */
- (NSArray *)dataKeys;

#pragma mark -

/**
 *  Verify 'data' and 'signature', if OK, refresh properties from 'data'
 *
 * @param PK - public key in meta.key
 * @return true on signature matched
 */
- (BOOL)verify:(MKMPublicKey *)PK;

/**
 *  Encode properties to 'data' and sign it to 'signature'
 *
 * @param SK - private key match meta.key
 * @return signature
 */
- (NSData *)sign:(MKMPrivateKey *)SK;

@end

#pragma mark - Profile

@interface MKMProfile : MKMTAI

@property (strong, nonatomic) NSString *name;

/**
 *  Public key (used for encryption, can be same with meta.key)
 *
 *      RSA
 */
@property (strong, nonatomic, nullable) MKMPublicKey *key;

@end

// convert Dictionary to Profile
#define MKMProfileFromDictionary(profile)  [MKMProfile getInstance:(profile)]

@interface MKMProfile (Runtime)

+ (void)registerClass:(Class)profileClass;

+ (nullable instancetype)getInstance:(id)profile;

@end

NS_ASSUME_NONNULL_END
