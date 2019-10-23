//
//  MingKeMing.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/30.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for MingKeMing.
FOUNDATION_EXPORT double MingKeMingVersionNumber;

//! Project version string for MingKeMing.
FOUNDATION_EXPORT const unsigned char MingKeMingVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MingKeMing/PublicHeader.h>

#if !defined(__MING_KE_MING__)
#define __MING_KE_MING__ 1

// Types
//#import <MingKeMing/MKMString.h>
//#import <MingKeMing/MKMDictionary.h>

// Cryptography
//#import <MingKeMing/MKMCryptographyKey.h>
//-- Symmetric
#import <MingKeMing/MKMSymmetricKey.h>
//---- AES
//#import <MingKeMing/MKMAESKey.h>
//-- Asymmetric
//#import <MingKeMing/MKMAsymmetricKey.h>
#import <MingKeMing/MKMPublicKey.h>
#import <MingKeMing/MKMPrivateKey.h>
//---- RSA
//#import <MingKeMing/MKMRSAKeyHelper.h>
//#import <MingKeMing/MKMRSAPublicKey.h>
//#import <MingKeMing/MKMRSAPrivateKey.h>
//#import <MingKeMing/MKMRSAPrivateKey+PersistentStore.h>

// Entity
#import <MingKeMing/MKMID.h>
#import <MingKeMing/MKMAddress.h>
#import <MingKeMing/MKMMeta.h>
#import <MingKeMing/MKMProfile.h>
#import <MingKeMing/MKMEntity.h>

//-
#import <MingKeMing/MKMGroup.h>
#import <MingKeMing/MKMUser.h>
#import <MingKeMing/MKMLocalUser.h>

//#import <MingKeMing/MKMImmortals.h>

#endif /* ! __MING_KE_MING__ */
