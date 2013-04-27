//
//  LFDeviceSimulator.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 16/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFDeviceHandler.h"
#import "LFBaseDeviceHandler.h"
#import "XMLReader.h"

@interface LFDeviceSimulator : LFBaseDeviceHandler <LFXmlParseDelegate>
{
    int time;
    
    int numberOfPresets;
    //int maxPacketSize;
    NSMutableArray *presetFileList;
    NSTimer *timer;
    NSTimer *workoutTimer;
    
    NSString *xmlFileData;
    LFWorkout *processWorkout;
    
    int elapsedWorkoutSecond;
}

@property(nonatomic, retain) NSMutableArray *presetFileList;
@property(nonatomic, retain) LFWorkout *processWorkout;



@end
