//
//  YSKSViewController.mm
//  SpeechKitTest
//
//  Created by Sergey Zimin on 7/18/13.
//  Copyright (c) 2012 Yandex LLC. All rights reserved.
//
#include <math.h>

#import <YandexSpeechKit/SpeechKit.h>

#import "YSKSViewController.h"

@interface YSKSViewController() <YSKRecognizerDelegate, UITableViewDataSource> {
    YSKRecognizer *recognizer;
    YSKRecognition *result;
}

// UITableViewDataSource
- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section;

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

@end 

@implementation YSKSViewController

@synthesize resultsView, powerLevelView;

- (id)initWithNibName:(NSString*)nibNameOrNil bundle:(NSBundle*)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];

    if (self) {
        [[YSKSpeechKit sharedInstance] configureWithAPIKey:@"developers-simple-key"];
    }
    
    return self;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}

- (IBAction)onStartButtonPressed:(id)sender {
    NSLog(@"Start button pressed");

    if (result) {
        result = nil;
    }
    [self.resultsView setDataSource:self];
    [self.resultsView reloadData];

    self->recognizer = [[YSKRecognizer alloc] initWithLanguage:@"ru-RU" model:@"general"];
    self->recognizer.delegate = self;
    
    [recognizer start];
}

- (IBAction)onFinishButtonPressed:(id)sender {
    NSLog(@"Finish button pressed");

    [recognizer finishRecording];
}

- (IBAction)onCancelButtonPressed:(id)sender {
    NSLog(@"Cancel button pressed");
    
    [recognizer cancel];
}

- (void)recognizer:(YSKRecognizer *)recognizer didUpdatePower:(float)power {
    NSLog(@"Power updated: %f", power);

    float volumeToDisplay = power / 30.0;
    if (volumeToDisplay < 0.0) {
        volumeToDisplay = 0.0;
    } else if (volumeToDisplay > 1.0) {
        volumeToDisplay = 1.0;
    }

    [self.powerLevelView setProgress:volumeToDisplay];
}

- (void)recognizer:(YSKRecognizer *)recognizer didCompleteWithResults:(YSKRecognition *)results
{
    NSLog(@"Recognition complete:\n%@", results);

    result = results;
    [self.resultsView reloadData];

    [self.powerLevelView setProgress:0.0];

    self->recognizer = nil;
}

- (void)recognizer:(YSKRecognizer *)recognizer didFailWithError:(NSError *)error {
    NSLog(@"Recognizer failed (%@)", error);

    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Recognition failed"
					      message:[error localizedDescription]
					      delegate:nil 
					      cancelButtonTitle:@"OK" 
					      otherButtonTitles: nil];
    [alert show];

    [self.powerLevelView setProgress:0.0];

    self->recognizer = nil;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    if (result == nil)
        return 0;

    return [result.allResults count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellIdentifier = @"resultCell";

    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];

    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }

    cell.textLabel.text = [[result.allResults objectAtIndex:indexPath.row] stringValue];
    
    return cell;
}
@end
