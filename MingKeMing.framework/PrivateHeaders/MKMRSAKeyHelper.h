//
//  MKMRSAKeyHelper.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/11/25.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

SecKeyRef SecKeyRefFromPublicData(NSData *data);
SecKeyRef SecKeyRefFromPrivateData(NSData *data);

NSData *NSDataFromSecKeyRef(SecKeyRef keyRef);

NSString *RSAPublicKeyContentFromNSString(NSString *content);
NSString *RSAPrivateKeyContentFromNSString(NSString *content);

NSString *NSStringFromRSAPublicKeyContent(NSString *content);
NSString *NSStringFromRSAPrivateKeyContent(NSString *content);

NS_ASSUME_NONNULL_END
