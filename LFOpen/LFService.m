//
//  LFService.m
//  LFOpen
//
//  Created by Lee Sing Jie on 20/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import "LFService.h"

#import "LFData.h"

@interface LFService ()

@property (nonatomic, strong) NSMutableArray *liveData;

@property (nonatomic, strong) NSArray *workouts;

@end

@implementation LFService

+ (id)sharedInstance
{
    static LFService *instance;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    
    });
    
    return instance;
}

- (id)init
{
    self =  [super init];
    
    if (self) {
        self.liveData = [NSMutableArray arrayWithCapacity:10];
        
        LFData *data = [[LFData alloc] init];
        data.timestamp = 0;
        data.speed = 0;
        data.incline = 0;
        
        [self.liveData addObject:data];
    }
    
    return self;
}

- (void)registerService
{
    LFServiceProvider *serviceProvider = [LFServiceProvider getInstence];
    [serviceProvider setLicence:@"98-1100984446-422239"];
    [serviceProvider registerForDeviceService:self simulation:YES];
    
#define SETUP_DUMMY
#ifdef SETUP_DUMMY
    [self setupDummyWorkout];
#endif
}

- (void)setupDummyWorkout
{
    // These workout profiles do not work. Simulator seems to just
    // generate random parameters regardless of params here.
    
    LFWorkout *workout1 = [[LFWorkout alloc] init];
    workout1.distanceValue = 2000;
    workout1.workoutName = @"2KM Jog";
    
    LFWorkout *workout2 = [[LFWorkout alloc] init];
    workout2.time = 20*60;
    workout2.workoutName = @"20 Minutes Jog";
    
    LFWorkout *workout3 = [[LFWorkout alloc] init];
    workout3.calories = 300;
    workout3.workoutName = @"300 Calories Jog";
    
    self.workouts = @[workout1, workout2, workout3];
}

#pragma mark - Device Communication Protocol

/**
 Inform that the LifeFitness Device are successfully connected.
 */
-(void) didDeviceConnect
{
    LFLog(@"");
    self.status = LFServiceStatusConnected;
}

/**
 Inform that the LifeFitness Device are  disconnected.
 */
-(void) didDeviceDisconnect
{
    LFLog(@"");
    self.status = LFServiceStatusDisconnected;
}

/**
 Recived version number of Life Fitness console.
 
 @param consoleVersion Console version number as string value ex: "1.50"
 */

-(void) didRecivedConsoleVersion:(NSString*)consoleVersion
{
    LFLog(@"%@", consoleVersion);
}

/**
 API ask number of preset (workouts) that match with device type which is going to disply on the console.
 */
-(int) numberOfPresetsToShow:(enum LFDeviceType) deviceTypeValue
{
    LFLog(@"%d", deviceTypeValue);
    
    return self.workouts.count;
}

/**
 Retrive Array of presets(workout) names that list on the console.
 
 @param fromIndex Starting preset index
 @param toIndex The number of workout names
 */
-(NSMutableArray*) presetListToShowFrom:(NSInteger)fromIndex toIndex:(NSInteger)toIndex
{
    LFLog(@"from:%d to:%d", fromIndex, toIndex);
    
    NSIndexSet *indexSet = [NSIndexSet indexSetWithIndexesInRange:NSMakeRange(fromIndex, toIndex-fromIndex)];
    
    NSArray *workouts = [self.workouts objectsAtIndexes:indexSet];
    
    NSMutableArray *names = [NSMutableArray arrayWithCapacity:5];
    for (LFWorkout *workout in workouts) {
        [names addObject:workout.workoutName];
    }
    
    return names;
}

/**
 Console wating for the preset file data. If this delegate fires you can use "-(void) sendPresetDataToConsole:(LFWorkout*) workout" method to
 send preset file data to consol
 
 @param Index Preset index number
 */
-(void) didConsoleWaitingPresetFileDataFor:(NSInteger)index
{
    LFLog(@"%d", index);
    LFServiceProvider *serviceProvider = [LFServiceProvider getInstence];
    
    [serviceProvider sendPresetDataToConsole:self.workouts[index]];
}

/**
 Retrive Name of the music file related to perticuler preset.
 
 @param index Preset index number
 @result Provide Play list file name as NSstring
 */
-(NSString*) playListNameForIndex:(NSInteger)index
{
    LFLog(@"%d", index);
    return @"Random";
}

/**
 API ask the iOS application version number.
 
 @result Version number version number as NSstring
 */
-(NSString*) applicationVersionNumber
{
    LFLog(@"");
    return @"1.0";
}

/**
 Received the workout result file name after user finished the workout with
 Life Fitness equipment
 
 @result Result file name as NSString
 */
-(void) didReceivedResultFileName:(NSString*)fileName
{
    LFLog(@"%@", fileName);
}

/**
 @discussion Received the workout result file data as XML string after user finished the workout with
 Life Fitness equipment
 
 @result Result file data as NSString
 */
-(void) didReceivedResultData:(LFWorkout*)workout
{
    // WTF Not returning anything
    LFLog(@"time:%d", workout.time);
    LFLog(@"days:%@", workout.workoutDays);
    LFLog(@"dist:%f", workout.distanceValue);
    LFLog(@"distclimbed:%f", workout.distanceClimbed);
    LFLog(@"name:%@", workout.workoutName);
    LFLog(@"id:%ld", workout.workoutId);
    LFLog(@"fileData:%@", workout.fileData);
    LFLog(@"fileName:%@", workout.fileName);
    
    self.status = LFServiceStatusConnected;
}

/**
 @discussion Received the current state the workout stream data as LFStreamData object
 Life Fitness equipment
 
 @result Result file data as NSString
 */
-(void) didReceivedWorkoutStream:(LFWorkoutStream*)streamData
{
    LFLog(@"%d", streamData.elapsedWorkoutSeconds);
    LFLog(@"----------------------------------------");
    
    self.status = LFServiceStatusActive;
    
    LFData *data = [[LFData alloc] initWithStreamData:streamData];
    
    [self.liveData addObject:data];
}

/**
 Retrive Preset file data to execute workout on the console.
 
 @param Index Preset index number
 @result Provide preset file data as NSString value
 */
-(LFWorkout*) presetDataForIndex:(NSInteger)index
{
    LFLog(@"%d", index);
    return self.workouts[index];
}

#pragma mark - Public Method

- (NSArray *)datasource
{
    return [NSArray arrayWithArray:self.liveData];
}

@end
