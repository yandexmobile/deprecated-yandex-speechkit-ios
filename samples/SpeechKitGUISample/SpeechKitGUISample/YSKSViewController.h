//
//  YSKSViewController.h
//  SpeechKitGUISample
//
//  Created by Sergey Zimin on 7/17/13.
//  Copyright (c) 2013 Sergey Zimin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YSKSViewController : UIViewController

@property (retain, nonatomic) IBOutlet UIButton *startButton;

@property (retain, nonatomic) IBOutlet UITextField *resultView;

@property (retain, nonatomic) IBOutlet UITableView *alternativesView;

- (IBAction)onStartButtonPressed;

@end
