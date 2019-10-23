//
//  MKMLocalUser.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/24.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import "MKMUser.h"

NS_ASSUME_NONNULL_BEGIN

@class MKMPrivateKey;
@class MKMContact;

@interface MKMLocalUser : MKMUser

@property (readonly, copy, nonatomic) NSArray<MKMID *> *contacts;

- (BOOL)existsContact:(MKMID *)ID;

/**
 *  Sign data with user's private key
 *
 * @param data - message data
 * @return signature
 */
- (NSData *)sign:(NSData *)data;

/**
 *  Decrypt data with user's private key
 *
 * @param ciphertext - encrypted data
 * @return plain text
 */
- (nullable NSData *)decrypt:(NSData *)ciphertext;

@end

#pragma mark - User Data Source

@protocol MKMUserDataSource <MKMEntityDataSource>

/**
 *  Get user's private key
 *
 * @param user - user ID
 * @return private key
 */
- (nullable MKMPrivateKey *)privateKeyForSignatureOfUser:(MKMID *)user;

/**
 *  Get user's private keys for decryption
 *
 * @param user - user ID
 * @return private key
 */
- (nullable NSArray<MKMPrivateKey *> *)privateKeysForDecryptionOfUser:(MKMID *)user;

/**
 *  Get contacts list
 *
 * @param user - user ID
 * @return contacts list (ID)
 */
- (nullable NSArray<MKMID *> *)contactsOfUser:(MKMID *)user;

@end

NS_ASSUME_NONNULL_END
