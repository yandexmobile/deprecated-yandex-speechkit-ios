//
//  YSKSViewController.m
//  SpeechKitGUISample
//
//  Created by Sergey Zimin on 7/17/13.
//  Copyright (c) 2013 Sergey Zimin. All rights reserved.
//

#import <YandexSpeechKit/SpeechKit.h>

#import "YSKSViewController.h"

@interface YSKSViewController () <YSKSpeechRecognitionViewControllerDelegate>

@property(nonatomic, retain) YSKSpeechRecognitionViewController *recognizerViewController;

@end

@implementation YSKSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}

- (IBAction)onStartButtonPressed
{
    NSLog(@"Start button pressed");

    [self startSpeechRecognition];
}

- (void)startSpeechRecognition {    
    self.recognizerViewController = [[YSKSpeechRecognitionViewController alloc] initWithLanguage:@"ru-RU" model:@"general"];
    self.recognizerViewController.delegate = self;
    
    [self presentViewController:self.recognizerViewController animated:YES completion:^{}];

    [self.recognizerViewController start];
}

- (void)speechRecognitionViewControllerDidCancel:(YSKSpeechRecognitionViewController *)speechRecognitionViewController
{
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Error"
					      message:@"Recognition cancelled by user"
					      delegate:nil
					      cancelButtonTitle:@"OK" 
					      otherButtonTitles: nil];
    [alert show];

    [self dismissViewControllerAnimated:YES completion:^{}];

    self.recognizerViewController = nil;
}

- (void)speechRecognitionViewController:(YSKSpeechRecognitionViewController *)speechRecognitionViewController didFinishWithResult:(NSString *)result
{
    [self.resultView setText:result];

    [self dismissViewControllerAnimated:YES completion:^{}];

    self.recognizerViewController = nil;
}

- (void) speechRecognitionViewController:(YSKSpeechRecognitionViewController *)speechRecognitionViewController didFailWithError:(YSKError *)error {
    [self.resultView setText:[error localizedDescription]];

    [self dismissViewControllerAnimated:YES completion:^{}];

    self.recognizerViewController = nil;
}

@end
