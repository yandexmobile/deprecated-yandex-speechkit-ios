//
//  YSKSAppDelegate.m
//  SpeechKitGUISample
//
//  Created by Sergey Zimin on 7/17/13.
//  Copyright (c) 2013 Sergey Zimin. All rights reserved.
//

#import "YSKSAppDelegate.h"

#import <YandexSpeechKit/SpeechKit.h>

@implementation YSKSAppDelegate

@synthesize window = _window;

@synthesize viewController = _viewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[YSKSpeechKit sharedInstance] configureWithAPIKey:@"developers-simple-key"];
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    self.viewController = [[YSKSViewController alloc] initWithNibName:@"YSKSViewController" bundle:nil];
    self.window.rootViewController = self.viewController;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}
							
@end
