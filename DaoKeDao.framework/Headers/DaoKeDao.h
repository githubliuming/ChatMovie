//
//  DaoKeDao.h
//  DaoKeDao
//
//  Created by Albert Moky on 2018/10/1.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for DaoKeDao.
FOUNDATION_EXPORT double DaoKeDaoVersionNumber;

//! Project version string for DaoKeDao.
FOUNDATION_EXPORT const unsigned char DaoKeDaoVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <DaoKeDao/PublicHeader.h>

#if !defined(__DAO_KE_DAO__)
#define __DAO_KE_DAO__ 1

// Types
//#import <DaoKeDao/DKDDictionary.h>

#import <DaoKeDao/DKDEnvelope.h>
#import <DaoKeDao/DKDContent.h>
#import <DaoKeDao/DKDForwardContent.h>

// Message
#import <DaoKeDao/DKDMessage.h>
#import <DaoKeDao/DKDInstantMessage.h>
#import <DaoKeDao/DKDSecureMessage.h>
#import <DaoKeDao/DKDReliableMessage.h>

#import <DaoKeDao/DKDMessage+Transform.h>
#import <DaoKeDao/DKDSecureMessage+Packing.h>

#endif /* ! __DAO_KE_DAO__ */
