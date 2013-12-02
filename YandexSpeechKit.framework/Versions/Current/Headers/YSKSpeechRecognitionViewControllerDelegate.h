//
// YSKSpeechRecognitionViewControllerDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

@class YSKSpeechRecognitionViewController;

/*!
    @protocol YSKSpeechRecognitionViewControllerDelegate
    @brief The protocol defines the delegate interface invoked by {@link YSKSpeechRecognitionViewController}.
    @details These methods indicate the flow of the recognition process. The delegate will be notified when the recognition process either fails or completes successfully.
 */
@protocol YSKSpeechRecognitionViewControllerDelegate<NSObject>

/*!
    @brief Called when the recognition process completes successfully.
    @details This method is the way YSKRecognizerViewController provides the recognition results.
    @param result string containing the confident recognition result.
 */
- (void)speechRecognitionViewController:(YSKSpeechRecognitionViewController *)speechRecognitionViewController
                    didFinishWithResult:(NSString *)result;

/*!
    @brief Called when the recognition process failed with an error.
    @details Several errors are possible during the recognition process. Some of them can be resolved by retrying, some may not. This function is called when either a non-retriable error occured or the user cancelled the recognition process.
    @param error the error that occurred during the recognition process.
 */
- (void)speechRecognitionViewController:(YSKSpeechRecognitionViewController *)speechRecognitionViewController didFailWithError:(NSError *)error;

@end
