//
// SpeechKit.h
//
// This file is a part of the Yandex SpeechKit project.
//
// (C) Copyright 2013 Yandex, LLC. All rights reserved.
//
// Author: Sergey Zimin <szimin@yandex-team.ru>
//

#import <Foundation/Foundation.h>

/*!
    @interface YSKSpeechKit
    @brief Singleton class aimed at setting up and controlling overall SpeechKit operation.
    @details The SpeechKit object shall not be explicitly created or destroyed by the user. Access to the object is performed by the sharedInstance method that creates the object when called for the first time. The object is destroyed during the user application termination.
 */
@interface YSKSpeechKit : NSObject

/*!
    @brief Returns the SpeechKit version
    @return The SpeechKit version as a string.
 */
+ (NSString *)speechkitVersion;

/*!
    @brief Returns a shared instance of the {@link YSKSpeechKit} class
    @return The shared instance of the {@link YSKSpeechKit} class
 */
+ (instancetype)sharedInstance;

/*!
    @brief Configures and sets up the SpeechKit framework.
    @details This method should be called before any actual functionality (such as creating a {@link YSKRecognizer}).
    @param apiKey the key provided by Yandex. Refer to \ref apikeys for the instructions.
    @note The actual API Key validation is performed during backend operations (such as initialization) and may result in the {@link _YSKSpeechErrorCode::kYSKErrorAPIKey} error.
 */
- (void)configureWithAPIKey:(NSString *) apiKey;

/*!
    @brief Set the proprietary SpeechKit parameter.
    @param name the name of the parameter.
    @param value the value of the parameter.
 */
- (void)setParameter:(NSString *)name withValue:(NSString *)value;

/*!
    @brief Gets the proprietary SpeechKit parameter.
    @param name the name of the parameter.
    @return The value of the parameter.
 */
- (NSString *) getParameterValue:(NSString *)name;

@end
