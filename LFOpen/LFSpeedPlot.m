//
//  LFSpeedPlot.m
//  LFOpen
//
//  Created by Lee Sing Jie on 22/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import "LFSpeedPlot.h"

#import "LFService.h"
#import "LFData.h"

#import "CPTColor.h"

#import "CPTXYAxisSet.h"
#import "CPTXYAxis.h"

#import "TestXYTheme.h"

@implementation LFSpeedPlot

- (NSString *)xAxisTitle
{
    return @"Time (s)";
}

- (NSString *)yAxisTitle
{
    return @"Speed (km/h)";
}

- (CPTColor *)lineColor
{
    return [CPTColor greenColor];
}

-(NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)idx
{
    NSArray *datasource = [self plotData];
    
    LFData *data = datasource[idx];
    
    switch (fieldEnum) {
        case CPTScatterPlotFieldX:
            return @(data.timestamp);
            break;
        case CPTScatterPlotFieldY:
            return @(data.speed);
            break;
        default:
            break;
    }
    
    return nil;
}

- (void)updateYRangeForXMin:(NSUInteger)min length:(NSUInteger)length
{
    NSArray *datas = [self.plotData subarrayWithRange:NSMakeRange(min, MIN(self.plotData.count - min, length))];
    
    float maxValue = FLT_MIN;
    
    if (datas.count == 0) {
        maxValue = 0;
    }
    
    for (LFData *data in datas) {
        maxValue = fmaxf(maxValue, data.speed);
    }
    
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *)self.graph.defaultPlotSpace;
    
    plotSpace.yRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromFloat(0)
                                                    length:CPTDecimalFromFloat(maxValue * 1.1)];
    
}

@end
