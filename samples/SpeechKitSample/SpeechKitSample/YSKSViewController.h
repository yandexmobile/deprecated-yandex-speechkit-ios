//
//  YSKSViewController.h
//  SpeechKitTest
//
//  Created by Sergey Zimin on 7/18/13.
//  Copyright (c) 2012 Yandex LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YSKSViewController : UIViewController

@property (retain, nonatomic) IBOutlet UIButton *startButton;

@property (retain, nonatomic) IBOutlet UIButton *finishButton;

@property (retain, nonatomic) IBOutlet UIButton *cancelButton;

@property (retain, nonatomic) IBOutlet UITableView *resultsView;

@property (retain, nonatomic) IBOutlet UIProgressView *powerLevelView;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;

- (IBAction)onStartButtonPressed:(id)sender;

- (IBAction)onFinishButtonPressed:(id)sender;

- (IBAction)onCancelButtonPressed:(id)sender;

@end
