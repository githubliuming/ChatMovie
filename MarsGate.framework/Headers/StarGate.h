//
//  StarGate.h
//  StarGate
//
//  Created by Albert Moky on 2019/2/21.
//  Copyright © 2019 DIM Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, SGStarStatus) {
    SGStarStatus_Error = -1,
    SGStarStatus_Init = 0,
    SGStarStatus_Connecting = 1,
    SGStarStatus_Connected = 2,
};

@protocol SGStarDelegate;

@protocol SGStar <NSObject>

@property (readonly, nonatomic) SGStarStatus status;

- (BOOL)launchWithOptions:(nullable NSDictionary *)launchOptions;
- (void)terminate;

- (void)enterBackground;
- (void)enterForeground;

/**
 
 @return 0 on success, -1 on error
 */
- (NSInteger)send:(NSData *)requestData;
- (NSInteger)send:(NSData *)requestData handler:(nullable id<SGStarDelegate>)sender;

@end

#pragma mark -

@protocol SGStarDelegate <NSObject>

/**
 
 @return 0 on success, -1 on error
 */
- (NSInteger)star:(id<SGStar>)star onReceive:(NSData *)responseData;

@optional
- (void)star:(id<SGStar>)star onConnectionStatusChanged:(SGStarStatus)status;

// callback for sending data
- (void)star:(id<SGStar>)star onFinishSend:(NSData *)requestData withError:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
