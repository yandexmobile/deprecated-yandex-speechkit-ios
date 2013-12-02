//
// YSKInitializerDelegate.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

@class YSKInitializer;

/*! 
    @protocol YSKInitializerDelegate
    @brief The interface defines callback methods invoked by {@link YSKInitializer}.
    @details These methods indicate the flow of the initialization. The delegate will be notified when the initialization starts and completes with error or success.
*/
@protocol YSKInitializerDelegate<NSObject>

@optional

/*!
    @brief Called when the initialization starts.
 */
- (void)initializerDidBegin:(YSKInitializer *)initializer;

/*! 
    @brief Called when the initialization completes succssfully.
 */
- (void)initializerDidFinish:(YSKInitializer *)initializer;

/*!
    @brief Called when the tartup process failed with error.
    @param error describes the error that occurred during the recognition process.
 */
- (void)initializer:(YSKInitializer *)initializer didFailWithError:(NSError *)error;

@end
