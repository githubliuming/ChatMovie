//
//  MKMCryptographyKey.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/30.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMDictionary.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Cryptography Key
 *
 *      keyInfo format: {
 *          algorithm: "RSA", // ECC, AES, ...
 *          data     : "{BASE64_ENCODE}",
 *          ...
 *      }
 */
@interface MKMCryptographyKey : MKMDictionary {
    
    // key data, set by subclass
    NSData *_data;
}

@property (readonly, strong, nonatomic) NSData *data;

- (instancetype)initWithDictionary:(NSDictionary *)keyInfo
NS_DESIGNATED_INITIALIZER;

@end

@interface MKMCryptographyKey (Runtime)

+ (void)registerClass:(nullable Class)keyClass forAlgorithm:(NSString *)name;

+ (nullable instancetype)getInstance:(id)key;

@end

@interface MKMCryptographyKey (PersistentStore)

+ (nullable instancetype)loadKeyWithIdentifier:(NSString *)identifier;

- (BOOL)saveKeyWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
