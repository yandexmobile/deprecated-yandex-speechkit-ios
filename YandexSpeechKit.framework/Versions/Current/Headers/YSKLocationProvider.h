//
// YSKLocationProvider.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Alexander Panin <agpanin@yandex-team.ru>
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

/*!
    @protocol YSKLocationProvider
    @brief The protocol defines the location provider used by SpeechKit.
*/
@protocol YSKLocationProvider<NSObject>

/*!
    @brief Returns location.
 */
- (CLLocation*) getLocation;

@end
