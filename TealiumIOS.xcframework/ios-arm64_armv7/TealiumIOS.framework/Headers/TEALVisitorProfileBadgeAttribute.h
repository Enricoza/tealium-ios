//
//  TEALVisitorProfileBadgeAttribute.h
//  Tealium Mobile Library
//
//  Created by George Webster on 6/8/15.
//  Copyright (c) 2015 Tealium Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <TealiumIOS/TEALVisitorProfileBaseAttribute.h>

@interface TEALVisitorProfileBadgeAttribute : TEALVisitorProfileBaseAttribute <NSCoding, NSCopying>

/**
 *  Name of the Audience, this is a display name, all attributes are refenerenced by their unique attributeID
 *
 *  @return string of the human friendly name or nil.
 */
- (NSString *)name;

@end

