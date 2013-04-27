//
//  LFConstant.h
//  LFDeviceLib
//
//  Created by Dulip Gayan Dasanayaka on 11/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LF_INPUT_BUFFER_SIZE                 256

#define STRING_TRUE                  @"true"
#define STRING_FALSE                 @"false"



/**
 Preferred Language code of the Virtual Trainer user. Possible values: 'en_US', 'en', 'de', 'es', 'fr', 'it', 'ja', 'nl', 'pt', 'ru', 'tr', 'zh'
 */
typedef enum LFLanguageCode
{
    LFLangCode_EN_US = 0,
    LFLangCode_EN,
    LFLangCode_DE,
    LFLangCode_ES,
    LFLangCode_FR,
    LFLangCode_IT,
    LFLangCode_JA,
    LFLangCode_NL,
    LFLangCode_PT,
    LFLangCode_RU,
    LFLangCode_TR,
    LFLangCode_ZH,
    
}LFLanguageCode;

typedef enum LFDeviceType
{
    LFDeviceType_Treadmill_Classic_Refresh               =           41,
    LFDeviceType_Bike_Classic_Refresh                    =           42,
    LFDeviceType_Crosstrainer_Classic_Refresh            =           43,
    LFDeviceType_Step_Classic_Refresh                    =           44,
    LFDeviceType_Summittrainer_Classic_Refresh           =           45,
    
    LFDeviceType_Treadmill_Led                           =            4,
    LFDeviceType_Treadmill_Lcd                           =           14,
    LFDeviceType_Treadmill_Lcd_Con                       =           18,
    LFDeviceType_Treadmill_Acheive                       =           21,
    LFDeviceType_Treadmill_Inspire                       =           22,
    LFDeviceType_Treadmill_Engage                        =           23,
    LFDeviceType_Treadmill_1_1                           =            1,
    LFDeviceType_Treadmill_Discover_Engage               =           49,
    LFDeviceType_Treadmill_Discover_Inspire              =           53,
    
    LFDeviceType_Crosstrainer_Fd_Led                     =            5,
    LFDeviceType_Crosstrainer_Rd_Led                     =            6,
    LFDeviceType_Crosstrainer_Lcd                        =           16,
    LFDeviceType_Crosstrainer_Lcd_Adj                    =           17,
    LFDeviceType_Crosstrainer_Acheive                    =           24,
    LFDeviceType_Crosstrainer_Inspire                    =           25,
    LFDeviceType_Crosstrainer_Engage                     =           26,
    LFDeviceType_Crosstrainer_1_1                        =            2,
    LFDeviceType_Crosstrainer_Discover_Engage            =           50,
    LFDeviceType_Crosstrainer_Discover_Inspire           =           54,
    
    LFDeviceType_UprightBike_Led                         =           11,
    LFDeviceType_UprightBike_Acheive                     =           27,
    LFDeviceType_UprightBike_Inspire                     =           28,
    LFDeviceType_UprightBike_Engage                      =           29,
    LFDeviceType_UprightBike_Discover_Engage             =           51,
    LFDeviceType_UprightBike_Discover_Inspire            =           55,
    LFDeviceType_Bike_1_1                                =            0,
    
    LFDeviceType_RecumbentBike_Led                       =           12,
    LFDeviceType_RecumbentBike_Acheive                   =           30,
    LFDeviceType_RecumbentBike_Inspire                   =           31,
    LFDeviceType_RecumbentBike_Engage                    =           32,
    LFDeviceType_RecumbentBike_Discover_Engage           =           52,
    LFDeviceType_RecumbentBike_Discover_Inspire          =           56,
    
    LFDeviceType_Consumer_Treadmill                      =           19,
    LFDeviceType_Consumer_Crosstrainer                   =          260,
    LFDeviceType_Consumer_Lifecycle                      =          261,
    LFDeviceType_Consumer_Treadmill_T3                   =          262,
    LFDeviceType_Consumer_Smart_Crosstrainer             =          263,
    LFDeviceType_Consumer_Smart_Lifecycle                =          264,
    LFDeviceType_Consumer_Treadmill_F3                   =          265,
    LFDeviceType_Consumer_Treadmill_T5                   =          266,
    
}LFDeviceType;


typedef enum LFRequestType 
{
    LFAuthenticationRequestType = 1,
    LFWorkoutsListRequestType = 2,         // support for user workouts(LFUserWorkoutList) and Predefine workouts (LFPredefineWorkoutList) type
    LFWorkoutsDetailRequestType = 3,
    LFWorkoutResultRequestType = 4,
    LFUserRegisterRequestType = 5,
    LFDefaultPresetsDetailRequestType = 6, // not support
    LFFacilityRequestType = 7,             // not support
    LFGetProgressRequestType = 8,
    LFServiceAutherizarionType = 9,
    LFPredefineWorkoutRequestType = 10,    // not support
    LFValidateLicense = 11,
}LFRequestType;


enum LFWorkoutTypes {
    LFUserWorkoutList = 0,
    LFPredefineWorkoutList = 1
}LFWorkoutTypes;

extern NSString *const  kLFVTClientIDKey;
extern NSString *const  kLFVTClientIDValue;

extern NSString *const  kLFVTClientSecretKey;
extern NSString *const  kLFVTClientSecretValue;

extern NSString *const  kLFVTUserIDKey;
extern NSString *const  kLFVTUserIDValue;

extern NSString *const  kLFVTPasswordKey;
extern NSString *const  kLFVTPasswordValue;

extern NSString *const  kLFVTMountPoint;

extern NSString *const  kLFVTServiceIdentifier;

extern NSString *const  kLFVTTokenSuccess;
extern NSString *const  kLFVTTokenRefreshed;
extern NSString *const  kLFVTTokenLost;
extern NSString *const  kLFVTTokenFailed;

extern NSString *const  kWorkoutSummaryBatchSize;

extern NSString *const  kGetWorkoutSummaryListRelativePath;
extern NSString *const  kGetWorkoutPresetFileRelativePath;
extern NSString *const  kGetResultFileRelativePath;
extern NSString *const  kGetAuthenticationRelativePath;
extern NSString *const  kGetUserRegistrationRelativePath;
extern NSString *const  kGetUserDefaultPresetsRelativePath;
extern NSString *const  kGetFacilityListRelativePath;
extern NSString *const  kGetProgressRelativePath;

extern NSString *const  kAuthraizeURL;
extern NSString *const  kTokenURL;
extern NSString *const  kBaseURL;

// HTTP ERROR CODE
extern NSString *const  kHTTPRespCodeOk;
extern NSString *const  hHTTPRespCodeNoContent;

extern NSString *const  kLFVTServiceIdentifier;


@interface LFShared : NSObject
{
    
}


+(void) logeDebugMessage:(NSString*)msg;
+(NSURL*) getUrlValue:(enum LFRequestType)requestType;
+(NSString*) getLanguageCode:(enum LFLanguageCode)langCode;
+(enum LFLanguageCode) getLanguageCodeType:(NSString*)langCode;
+(NSString*) replaceDateOftheWorkoutResult:(NSMutableString*)data;

@end
