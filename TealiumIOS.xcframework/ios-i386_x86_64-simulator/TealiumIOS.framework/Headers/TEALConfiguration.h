//
//  TEALConfiguration.h
//  Tealium Mobile Library
//
//  Created by George Webster on 3/2/15.
//  Copyright (c) 2015 Tealium Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TealiumIOS/TEALLogLevels.h>
#import <TealiumIOS/TEALConsentConstants.h>

#ifdef TEAL_TARGET_IOS
#import <UIKit/UIKit.h>
#endif
#if !TARGET_OS_TV
@import WebKit;
#endif

/**
 Defines the endpoint of where to send data for the CollectDispatchService.
 */
typedef NS_ENUM(NSInteger, TEALCollectURL) {
    TEALCollectURLVdata,
    TEALCollectURLEvent
};

/**
 *  Configuration Class for the Tealium Mobile Library
 *  An instance of this is passed to Tealium enableWithConfiguration: to start the Collect Library
 */
@interface TEALConfiguration : NSObject

/**
 *  Tealium iQ account name
 */
@property (nonatomic, copy) NSString *_Nonnull accountName;

/**
 *  Tealium iQ profile name, this should be the TiQ profile where the mobile publish settings have been configured for Tealium collect.
 *
 *  Note: This is usually not the same profile used for Collect which defaults to "main"
 */
@property (nonatomic, copy) NSString *_Nonnull profileName;

/**
 *  Tealium iQ evnvironment name.
 *
 *  @example dev/qa/prod
 */
@property (nonatomic, copy) NSString *_Nonnull environmentName;


/**
 *  Tealium UDH Data source Id.
 *
 *  @example abc123
 */
@property (nonatomic, copy) NSString *_Nullable datasourceId;

/**
 *  Debug log level to use. Default 'silent' (none)
 */
@property (nonatomic) TEALLogLevel logLevel;

/**
 *  If assigned, will replace the default mobile publish setting source location with an alternate address. Example - "https://my.domain.com/app/publish.html"
 */
@property (nonatomic) NSString *_Nullable overridePublishSettingsURL;

/**
 *  If assigned, will replace the default address used to retrieve the tag management UTAG.js file.  Example - "https://my.domain.com/app/mobile.html"
 */
@property (nonatomic) NSString *_Nullable overrideTagManagementURL;

/**
 Optionally enable Consent Manager.
 */
@property (nonatomic, assign) BOOL enableConsentManager;

/**
 Optionally set initial userConsentCategories.
 */
@property (nonatomic, strong) NSArray *_Nullable userConsentCategories;

/**
 Optionally set initial userConsentStatus.
 */
@property (nonatomic, assign) TEALConsentStatus userConsentStatus;

/**
 Set the endpoint for the CollectDispatchService. By default this is set to the /event endpoint and is a POST request.
 */
@property (nonatomic, assign) TEALCollectURL collectURL;

#if !TARGET_OS_TV
/**
 Optionally set a WKProcessPool for the WKWebView
 */
@property (nonatomic, retain) WKProcessPool *_Nullable wkProcessPool;

/**
 Optionally set a WKWebViewConfiguration for the WKWebView
 */
@property (nonatomic, retain) WKWebViewConfiguration *_Nullable wkWebViewConfig;
#endif

#pragma mark - Core Methods
/** @name Core Methods */


/**
 *  Creates a default configration instance for a given account / profile / environment combination.  The TiQ information is used to fetch the profile's mobile publish settings used
 *
 *  @param accountName     String of TiQ / AudienceStream account name. Required.
 *  @param profileName     String of TiQ Profile name. Required.
 *  @param environmentName String of TiQ Environment name. Typically dev/qa/prod. Required.
 *
 *  @returns Valid configuration instance to pass to the enableWithConfiguration: method.
 */
+ (instancetype _Nonnull)configurationWithAccount:(NSString *_Nonnull)accountName
                                          profile:(NSString *_Nonnull)profileName
                                      environment:(NSString *_Nonnull)environmentName;

/**
 *  Creates a default configration instance for a given account / profile / environment combination.  The TiQ information is used to fetch the profile's mobile publish settings used
 *
 *  @param accountName     String of TiQ / AudienceStream account name. Required.
 *  @param profileName     String of TiQ Profile name. Required.
 *  @param environmentName String of target environment, typically dev, qa, or prod. Required.
 *  @param datasourceId      String data source id for UDH. 6 alphanumerics long. Optional.
 *
 *  @returns Valid configuration instance to pass to the enableWithConfiguration: method.
 */
+ (instancetype _Nonnull)configurationWithAccount:(NSString *_Nonnull)accountName
                                          profile:(NSString *_Nonnull)profileName
                                      environment:(NSString *_Nonnull)environmentName
                                       datasource:(NSString *_Nullable)datasourceId;

/**
 *  Checks to see if configuration is populated with the minimum required properties.
 *
 *  @param configuration TEALConfiguration to check.
 *
 *  @return Boolean of whether the argument configuration is valid.
 */
+ (BOOL)isValidConfiguration:(TEALConfiguration *_Nonnull)configuration;

/**
 *  A unique identifier generated from the account-profile-environment.
 *
 *  @returns instanceID NSString identifier
 */
- (NSString *_Nonnull)instanceID;

@end
