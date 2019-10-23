//
//  MKMPublicKey.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/25.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMAsymmetricKey.h"

NS_ASSUME_NONNULL_BEGIN

// convert Dictionary to PublicKey
#define MKMPublicKeyFromDictionary(key)                                        \
            [MKMPublicKey getInstance:(key)]                                   \
                                     /* EOF 'MKMPublicKeyFromDictionary(key)' */

@class MKMPrivateKey;

/**
 *  AC Public Key
 *
 *      keyInfo format: {
 *          algorithm: "RSA", // ECC, ...
 *          data     : "{BASE64_ENCODE}",
 *          ...
 *      }
 */
@interface MKMPublicKey : MKMAsymmetricKey <MKMPublicKey>

- (BOOL)isMatch:(MKMPrivateKey *)SK;

@end

NS_ASSUME_NONNULL_END
