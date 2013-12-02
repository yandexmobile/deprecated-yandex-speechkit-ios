//
// YSKRecognitionHypothesis.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

/*!
    @brief Contains a single recognition hypothesis.
    @details The structure contains the text of the hypothesis and its confidence score. 

    The confidence score is a float value between 0 and 1 estimating the measure of confidence in the result of the recognition (1 - absolutely sure).

    If the confidence is not available, a special value {@link kYSKBadConfidence} is used.

    @note The confidence score is provided just for information. The scoring formula may evolve with time, so it is not intended for making decisions using the absolute value of the score. Instead, you should rely on the {@link YSKRecognition::resultConfident} mechanism.
 */
@interface YSKRecognitionHypothesis : NSObject

/*!
    @property text
    @brief Text that was recognized in this result.
 */
@property (nonatomic, copy, readonly) NSString *text;

/*!
    @property confidence
    @brief Confidence score of the recognition result.
    @details The confidence score is a value between 0 and 1 estimating the measure of confidence in the recognition result (1 - absolutely sure).
 */
@property (nonatomic, assign, readonly) float confidence;

/*!
    @brief Initialize recognition hypothesis with text and confidence.
 */
- (instancetype)initWithText:(NSString *)text confidence:(float)confidence;

/*!
    @brief String representation of the result.
 */
- (NSString *)stringValue;

/*!
    @brief Returns the special hypothesis indicating that it is incorrect.
 */
+ (instancetype)badRecognitionHypothesis;

@end

/*!
    @const kYSKBadConfidence
    @brief The value indicating that the confidence is not available.
 */
extern const float kYSKBadConfidence;
