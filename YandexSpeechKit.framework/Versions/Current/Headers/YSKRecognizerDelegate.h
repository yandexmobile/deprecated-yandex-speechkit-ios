//
// YSKRecognizerDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

#include "YSKRecognition.h"

@class YSKRecognizer;

/*!
    @protocol YSKRecognizerDelegate
    @brief The interface defines delegate interface invoked by {@link YSKRecognizer}.
    @details These methods indicate the flow of the recognition process. The delegate will be notified when the recording has begun, when the new portion of audio data has recorded, when the recognition process is finished, etc.
 */
@protocol YSKRecognizerDelegate<NSObject>

@optional

/*!
    @brief Called when the recognizer starts recording audio.
 */
- (void)recognizerDidStartRecording:(YSKRecognizer *)recognizer;

/*!
    @brief Called when the user starts speaking.
    @note This method is only called if the Voice Activity Detector (VAD) is enabled.
 */
- (void)recognizerDidDetectSpeech:(YSKRecognizer *)recognizer;

/*!
    @brief Called when the recognizer finishes recording audio.
 */
- (void)recognizerDidFinishRecording:(YSKRecognizer *)recognizer;

/*!
    @brief Called when a new chunk of audio data has been recorded.
    @param data the raw sound data collected by the recorder from the input device.
    @note The sample width and rate are unspecified and may change.
 */
- (void)recognizer:(YSKRecognizer *)recognizer didRecordSoundData:(NSData *)data;

/*!
    @brief Called when the speech signal power gets updated.
    @details The function is called on every new chunk of audio data and should be used to update the voice power indicator in the user interface.
    @param power a float value between 0 and 1 indicating the power of the signal (0 - no signal, 1 - maximum).
    @note The function is called even if the power has not changed.
 */
- (void)recognizer:(YSKRecognizer *)recognizer didUpdatePower:(float)power;

/*!
    @brief Called when the recognition process completes successfully.
    @details This is the way {@link YSKRecognizer} provides the recognition results.

    The method is only invoked if the recognition completes successfully. Otherwise, {@link recognizer:didFailWithError:} is invoked.

    @param results the result of recognition
 */
- (void)recognizer:(YSKRecognizer *)recognizer didCompleteWithResults:(YSKRecognition *)results;

/*!
    @brief Called when the recognition process failed with an error.
    @details The recognition process fails with an error due to a number of circumstances. The audio system may fail to initialize, the server connection may be disrupted or a parameter specified during initialization, such as language or authentication information was invalid, user may cancel the active request, etc.

    The method is only invoked if the recognition fails. Otherwise, {@link recognizer:didCompleteWithResults:} is invoked.

    @param error the error occured during the recognition process.
 */
- (void)recognizer:(YSKRecognizer *)recognizer didFailWithError:(NSError *)error;

@end
