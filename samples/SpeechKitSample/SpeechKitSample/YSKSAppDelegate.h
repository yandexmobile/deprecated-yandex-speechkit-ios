//
//  YSKSAppDelegate.h
//  SpeechKitSample
//
//  Created by Sergey Zimin on 7/18/13.
//  Copyright (c) 2013 Sergey Zimin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YSKSViewController;

@interface YSKSAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) YSKSViewController *viewController;

@end