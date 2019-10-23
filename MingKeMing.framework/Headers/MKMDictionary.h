//
//  MKMDictionary.h
//  MingKeMing
//
//  Created by Albert Moky on 2018/9/27.
//  Copyright © 2018 DIM Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MKMDictionary : NSDictionary {
    
    // inner dictionary
    NSMutableDictionary<NSString *, id> *_storeDictionary;
}

- (instancetype)initWithDictionary:(NSDictionary *)dict
NS_DESIGNATED_INITIALIZER;

- (instancetype)init
NS_DESIGNATED_INITIALIZER;

- (NSUInteger)count;
- (id)objectForKey:(NSString *)aKey;

- (NSEnumerator *)keyEnumerator;
- (NSEnumerator *)objectEnumerator;

@end

@interface MKMDictionary (Mutable)

- (instancetype)initWithCapacity:(NSUInteger)numItems
/* NS_DESIGNATED_INITIALIZER */;

- (void)removeObjectForKey:(NSString *)aKey;
- (void)setObject:(id)anObject forKey:(NSString *)aKey;

@end

NS_ASSUME_NONNULL_END
