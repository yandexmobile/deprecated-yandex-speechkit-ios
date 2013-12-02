//
// YSKRecognition.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

#import "YSKRecognitionHypothesis.h"

/*!
    @interface YSKRecognition
    @brief Represents the complete recognition result provided by {@link YSKRecognizer}
    @details The recognition result contains the N-best list of recognition hypotheses (along with their confidence scores), sorted by confidence in descending order. That is, the most probable recognition result is the first one.

    The most probable result might not be confident enough to be treated as the right recognition result. There is a special property flag {@link resultConfident} introduced that specifies whether the best result is confident. If the {@link resultConfident} flag is set, the confident result can be accessed via the {@link result} property. 

    In any case, the N-best list is available through the {@link allResults} property.
 */
@interface YSKRecognition : NSObject

/*!
    @property resultConfident
    @brief The flag indicating wether there is a confident recognition result.
    @details If the flag is set, the confident result is available via the {@link result} property.
 */
@property (nonatomic, assign, readonly, getter=isResultConfident) BOOL resultConfident;

/*! 
    @property result
    @brief The confident recognition result.
    @note The value of this property is only valid if the {@link resultConfident} flag is set.
 */
@property (nonatomic, retain, readonly) YSKRecognitionHypothesis *result;

/*!
    @property allResults
    @brief The vector of {@link YSKRecognitionHypothesis} objects representing the N-best list.
 */
@property (nonatomic, copy, readonly) NSArray *allResults;

- (instancetype)initWithResultHypothesis:(NSArray*)allResults resultConfident:(BOOL)resultConfident;

/*!
    @var stringValue
    @brief Default string representation of the results.
 */
- (NSString *)stringValue;

@end
