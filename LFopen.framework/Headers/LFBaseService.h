//
//  LFBaseService.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 14/9/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFHTTPRequest.h"
#import "LFShared.h"

#define POST                @"POST"
#define GET                 @"GET"
#define AUTHORIZATION       @"Authorization"

@interface LFBaseService : NSObject<LFHTTPRequestDelegate>
{
   LFHTTPRequest* request;
   enum LFRequestType lfRequestType;
}

@property (nonatomic, retain) LFHTTPRequest* request;
@property enum LFRequestType lfRequestType;

-(LFHTTPRequest*)getRequest:(NSString*)method url:(NSURL*)url;
-(NSString*)generateOAuthHeader:(NSString*)access_token;

@end
