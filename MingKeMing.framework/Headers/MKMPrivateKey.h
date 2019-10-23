//
//  MKMPrivateKey.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/25.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMAsymmetricKey.h"

NS_ASSUME_NONNULL_BEGIN

// convert Dictionary to PrivateKey
#define MKMPrivateKeyFromDictionary(key)                                       \
            [MKMPrivateKey getInstance:(key)]                                  \
                                    /* EOF 'MKMPrivateKeyFromDictionary(key)' */

// generate PrivateKey
#define MKMPrivateKeyWithAlgorithm(name)                                       \
            [MKMPrivateKey getInstance:@{@"algorithm":(name)}]                 \
                                    /* EOF 'MKMPrivateKeyWithAlgorithm(name)' */

@class MKMPublicKey;

/**
 *  AC Private Key
 *
 *      keyInfo format: {
 *          algorithm: "RSA", // ECC, ...
 *          data     : "{BASE64_ENCODE}",
 *          ...
 *      }
 */
@interface MKMPrivateKey : MKMAsymmetricKey <MKMPrivateKey>

/**
 Get public key from private key
 */
@property (readonly, strong, atomic, nullable) __kindof MKMPublicKey *publicKey;

@end

NS_ASSUME_NONNULL_END
