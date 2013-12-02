//
// YSKInitializer.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

@protocol YSKInitializerDelegate;

/*!
    @interface YSKInitializer
    @brief The interface to a single-use initializer.
    @details Initialization is an internal process performed by SpeechKit to initialize its internals. 

    Initialization may imply reading from persistent storage, netwroking communications and as the result take significant amount of time. A special class {@link YSKInitializer} introduced to allow user to perform the initialization in the context suitable for that.

    In the current implementation, it sends a request to the server and gets some parameters and configurations (such as confidence thresholds) that will be used during recognition later. 

    The {@link YSKInitializer} class is designed to carry out a single initializer and may not be reused (for whatever reason). 

    The {@link YSKInitializer} object manages the overall initialization, which mostly includes network communications.

    @note SpeechKit shall be initialized via {@link YSKSpeechKit::configureWithAPIKey:} before creating {@link YSKInitializer} objects.
 */
@interface YSKInitializer : NSObject

/*!
    @property delegate
    @brief The delegate object for initializer callbacks.
    @details The delegate will receive notifications when the initialization starts and finishes.
 */
@property(nonatomic, weak) id<YSKInitializerDelegate> delegate;

/*!
    @brief Initializes a single-use initializer object.
    @details Call the {@link YSKInitializer::start} method to begin the initializer.
    @return The {@link YSKInitializer} object corresponding to the recognition request.
 */
- (instancetype)init;

/*!
    @brief Release the resources used by the {@link YSKInitializer} object.
 */
- (void)dealloc;

/*!
    @brief Begins the initialization.
 */
- (void)start;

/*!
    @brief Checks whether the initializer has already been completed.
 */
+ (BOOL)isInitializationCompleted;

@end
