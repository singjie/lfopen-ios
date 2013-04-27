//
//  WorkoutServiceHandler.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFRequest.h"
#import "LFBaseService.h"
#import "XMLReader.h"

@interface LFWorkoutService : LFBaseService <LFXmlParseDelegate>
{
    
}

-(void) requestPredefineWorkoutSummaryList:(LFWorkoutSummaryListRequest*)workoutrequest;
-(void) requestWorkoutSummaryList:(LFWorkoutSummaryListRequest*)request;
-(void) requestWorkoutDetail:(LFWorkoutDetailRequest*)request;
-(void) sendWorkoutResultDetail:(LFWorkoutResultRequest*)request;
-(void) getDefaultPresetsFiles:(LFWorkoutDetailRequest*)request;
-(void) getProgressResult:(LFProgressRequest*)request;
@end
