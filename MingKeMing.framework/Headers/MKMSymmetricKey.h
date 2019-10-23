//
//  MKMSymmetricKey.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/30.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMCryptographyKey.h"

NS_ASSUME_NONNULL_BEGIN

#define SCAlgorithmAES @"AES"
#define SCAlgorithmDES @"DES"

@protocol MKMSymmetricKey <NSObject>

/**
 *  CT = encrypt(text, PW)
 */
- (NSData *)encrypt:(NSData *)plaintext;

/**
 *  text = decrypt(CT, PW);
 */
- (nullable NSData *)decrypt:(NSData *)ciphertext;

@end

// convert Dictionary to SymmetricKey
#define MKMSymmetricKeyFromDictionary(key)                                     \
            [MKMSymmetricKey getInstance:(key)]                                \
                                  /* EOF 'MKMSymmetricKeyFromDictionary(key)' */

// generate SymmetricKey
#define MKMSymmetricKeyWithAlgorithm(name)                                     \
            [MKMSymmetricKey getInstance:@{@"algorithm":(name)}]               \
                                   /* EOF 'MKMSymmetricKeyWithAlgorithm(name) */

/**
 *  Symmetric Cryptography Key
 *
 *      keyInfo format: {
 *          algorithm: "AES", // DES, ...
 *          data     : "{BASE64_ENCODE}",
 *          ...
 *      }
 */
@interface MKMSymmetricKey : MKMCryptographyKey <MKMSymmetricKey>

@end

NS_ASSUME_NONNULL_END
