//
//  MKMMeta.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/24.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMDictionary.h"

#import "MKMAddress.h"

NS_ASSUME_NONNULL_BEGIN

@class MKMPublicKey;
@class MKMPrivateKey;

@class MKMID;

/**
 *  User/Group Meta data
 *
 *      data format: {
 *          version: 1,          // algorithm version
 *          key: "{public key}", // PK = secp256k1(SK);
 *          seed: "moKy",        // user/group name
 *          fingerprint: "..."   // CT = sign(seed, SK);
 *      }
 *
 *      algorithm:
 *          fingerprint = sign(seed, SK);
 */
@interface MKMMeta : MKMDictionary

/**
 *  Meta algorithm version
 *
 *      0x01 - username@address
 *      0x02 - btc_address
 *      0x03 - username@btc_address
 *      0x04 - eth_address
 *      0x05 - username@eth_address
 *      ....
 */
@property (readonly, nonatomic) NSUInteger version;

/**
 *  Public key
 *
 *      RSA / ECC
 */
@property (readonly, strong, nonatomic) MKMPublicKey *key;

/**
 *  Seed to generate fingerprint
 *
 *      Username / Group-X
 */
@property (readonly, strong, nonatomic, nullable) NSString *seed;

/**
 *  Fingerprint to verify ID and public key
 *
 *      Build: fingerprint = sign(seed, privateKey)
 *      Check: verify(seed, fingerprint, publicKey)
 */
@property (readonly, strong, nonatomic, nullable) NSData *fingerprint;

/**
 *  Create meta with dictionary
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict
NS_DESIGNATED_INITIALIZER;

/**
 *  Generate fingerprint, initialize meta data
 *
 * @param version - meta version for MKM or ExBTC
 * @param SK - private key to generate fingerprint
 * @param name - seed for fingerprint
 * @return Meta object
 */
+ (instancetype)generateWithVersion:(NSUInteger)version
                         privateKey:(MKMPrivateKey *)SK
                               seed:(nullable NSString *)name;

- (BOOL)matchPublicKey:(MKMPublicKey *)PK;

#pragma mark - ID & address

- (BOOL)matchID:(MKMID *)ID;
- (BOOL)matchAddress:(MKMAddress *)address;

- (MKMID *)generateID:(MKMNetworkType)type;
- (MKMAddress *)generateAddress:(MKMNetworkType)type;

@end

/**
 *  @enum MKMMetaVersion
 *
 *  @abstract Defined for algorithm that generating address.
 *
 *  @discussion Generate & check ID/Address
 *
 *      MKMMetaVersion_MKM give a seed string first, and sign this seed to get
 *      fingerprint; after that, use the fingerprint to generate address.
 *      This will get a firmly relationship between (username, address & key).
 *
 *      MKMMetaVersion_BTC use the key data to generate address directly.
 *      This can build a BTC address for the entity ID (no username).
 *
 *      MKMMetaVersion_ExBTC use the key data to generate address directly, and
 *      sign the seed to get fingerprint (just for binding username & key).
 *      This can build a BTC address, and bind a username to the entity ID.
 */
#define MKMMetaVersion_MKM    0x01  // 0000 0001
#define MKMMetaVersion_BTC    0x02  // 0000 0010
#define MKMMetaVersion_ExBTC  0x03  // 0000 0011
#define MKMMetaVersion_ETH    0x04  // 0000 0100
#define MKMMetaVersion_ExETH  0x05  // 0000 0101
#define MKMMetaDefaultVersion MKMMetaVersion_MKM

// convert Dictionary to Meta
#define MKMMetaFromDictionary(meta)                                            \
            [MKMMeta getInstance:(meta)]                                       \
                                         /* EOF 'MKMMetaFromDictionary(meta)' */

// generate Meta
#define MKMMetaGenerate(ver, SK, name)                                         \
            [MKMMeta generateWithVersion:(ver) privateKey:(SK) seed:(name)]    \
                                      /* EOF 'MKMMetaGenerate(ver, SK, name)' */

@interface MKMMeta (Runtime)

+ (void)registerClass:(nullable Class)metaClass forVersion:(NSUInteger)version;

+ (nullable instancetype)getInstance:(id)meta;

@end

NS_ASSUME_NONNULL_END
