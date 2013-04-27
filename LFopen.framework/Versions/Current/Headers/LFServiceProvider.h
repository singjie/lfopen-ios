//
//  LFServiceLib.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//


#import <Foundation/Foundation.h>
//#import "LFAuthenticationService.h"
//#import "LFWorkoutService.h"
#import "LFResponse.h"
//#import "LFOAuth2AutheraizationService.h"
#import "LFOAuthAccessToken.h"
#import "LFAuthRequest.h"
#import "XMLReader.h"
#import "LFWorkoutStream.h"

/**
 LFServiceProvider.h
 The DeviceCommunicationDelegate provides a functional interface to the LFServiceLib.
 Use the functions declared here to send, retrive data from LifeFitness Apllo Consol.

 
 @flag LFServiceLib
 @updated 27-06-2012
 @version 1.0
 @copyright Life Fitness
 @author Dulip
 */

@protocol DeviceCommunicationDelegate <NSObject>

@required
/**
 Inform that the LifeFitness Device are successfully connected.
 */
-(void) didDeviceConnect;

/**
 Inform that the LifeFitness Device are  disconnected.
 */
-(void) didDeviceDisconnect;

/**
 Recived version number of Life Fitness console.
 
 @param consoleVersion Console version number as string value ex: "1.50"
 */

-(void) didRecivedConsoleVersion:(NSString*)consoleVersion;

/**
 API ask number of preset (workouts) that match with device type which is going to disply on the console.
 */
-(int) numberOfPresetsToShow:(enum LFDeviceType) deviceTypeValue;

/**
 Retrive Array of presets(workout) names that list on the console.
 
 @param fromIndex Starting preset index
 @param toIndex The number of workout names
 */
-(NSMutableArray*) presetListToShowFrom:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

/**
 Console wating for the preset file data. If this delegate fires you can use "-(void) sendPresetDataToConsole:(LFWorkout*) workout" method to
 send preset file data to consol
 
 @param Index Preset index number
 */
-(void) didConsoleWaitingPresetFileDataFor:(NSInteger)index;

/**
 Retrive Name of the music file related to perticuler preset.
 
 @param index Preset index number
 @result Provide Play list file name as NSstring
 */
-(NSString*) playListNameForIndex:(NSInteger)index;

/**
 API ask the iOS application version number.
 
 @result Version number version number as NSstring
 */
-(NSString*) applicationVersionNumber;

/**
 Received the workout result file name after user finished the workout with 
 Life Fitness equipment
 
 @result Result file name as NSString
 */
-(void) didReceivedResultFileName:(NSString*)fileName;

/**
 @discussion Received the workout result file data as XML string after user finished the workout with 
 Life Fitness equipment
 
 @result Result file data as NSString
 */
-(void) didReceivedResultData:(LFWorkout*)workout;

/**
 @discussion Received the current state the workout stream data as LFStreamData object
 Life Fitness equipment
 
 @result Result file data as NSString
 */
-(void) didReceivedWorkoutStream:(LFWorkoutStream*)streamData;

@optional
/**
 Retrive Preset file data to execute workout on the console.
 
 @param Index Preset index number
 @result Provide preset file data as NSString value
 */
-(LFWorkout*) presetDataForIndex:(NSInteger)index;
@end


/**
 LFServiceProvider.h
 The WebServiceDelegate provides a functional interface between LFServiceLib and the application that use LFServiceLib for communicate with Life Fitness vertual trainer web service.
 Use the functions declared here to send, retrive data from LifeFitness Vertual App Trainer Web portal.
 
 @flag LFServiceLib
 @updated 27-06-2012
 @version 1.0
 @copyright Life Fitness
 @author Dulip
 */

@protocol WebServiceDelegate <NSObject>

/**
 Received LFResponse object as response to request for the Life Fitness Web Service request
 
 @result LFResponse with wraping all the result informations
 */
@required
-(void) didReceivedResponseWith:(LFResponse*)response;
-(void) didReceivedLFAutherizationToken:(LFOAuthAccessToken*)token;

@optional
-(void) didReceivedLFDeveloperLicenseStatus:(NSString*)token;

@end


/**
 Class to communicate between LFServiceLib API and the program which use LFDeviceLib.  
 */
@interface LFServiceProvider : NSObject <LFXmlParseDelegate>
{
    @private
    /**
      Keep instence of WebServiceDelegate
      Once web service give feedback to the API , use this object to transfer data to client wh use the API.
     */
    id<WebServiceDelegate> webDelegate;
    BOOL didProvideValidLicense;
    NSString *strDevLicense;
}

@property (nonatomic, assign) id<WebServiceDelegate> webDelegate;



/**
 Provide singleton instence of the LFServiceProvider
 
 @result instence of LFServiceProvider
 */
+(LFServiceProvider*) getInstence;

/**
 User program must register for device service if they willing to communicate with Life Fitness Apllo console
 
 @param Object that confirms to DeviceCommunicationDelegate
 */
-(void) registerForDeviceService:(id<DeviceCommunicationDelegate>) deviceServiceListner   simulation:(BOOL)simulation;

/**
 @discussion User program must register for the web service output using this method
 
 @param Object that confirms to WebServiceDelegate
 */
-(void) registerForWebService:(id<WebServiceDelegate>) webServiceListnerDelegate;

/**
 @discussion Send request to the Life Fitness Web portal with appopriate LFRequest object 
 @param LFRequest object
 */
-(void) requestDataFromWebService:(LFRequest*)request;

/**
 @discussion Execute OAuth2 authrization process for LifeFitness web server
 @param LFAuthRequest object
 */
-(void) authorizeLFWebService:(LFAuthRequest*)request;

/**
 @discussion Refreash OAuth2 LifeFitness token to access lf web server
 @param LFAuthRequest object
 */
-(void) refreshLFAccessToken:(LFAuthRequest*)request   token:(LFOAuthAccessToken*)token;

/**
 Set Life Fitness developer licence 
 @param  strLicence  : Liecense string that provide from LFopen developer web site
 @prram  accessToken : Oauth2 accesstoken
 */
-(void) setLicence:(NSString*)strLicence;

-(void) sendPresetDataToConsole:(LFWorkout*) workout;

@end
