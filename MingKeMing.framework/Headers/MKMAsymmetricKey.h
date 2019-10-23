//
//  MKMAsymmetricKey.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/25.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMCryptographyKey.h"

NS_ASSUME_NONNULL_BEGIN

#define ACAlgorithmRSA @"RSA"
#define ACAlgorithmECC @"ECC"

@protocol MKMPublicKey <NSObject>

/**
 *  CT = encrypt(text, PK)
 */
- (NSData *)encrypt:(NSData *)plaintext;

/**
 *  OK = verify(data, signature, PK)
 */
- (BOOL)verify:(NSData *)data withSignature:(NSData *)signature;

@end

@protocol MKMPrivateKey <NSObject>

/**
 *  text = decrypt(CT, SK);
 */
- (nullable NSData *)decrypt:(NSData *)ciphertext;

/**
 *  signature = sign(data, SK);
 */
- (NSData *)sign:(NSData *)data;

@end

/**
 *  Asymmetric Cryptography Key
 *
 *      keyInfo format: {
 *          algorithm: "RSA", // ECC, ...
 *          data     : "{BASE64_ENCODE}",
 *          ...
 *      }
 */
@interface MKMAsymmetricKey : MKMCryptographyKey

@end

NS_ASSUME_NONNULL_END
