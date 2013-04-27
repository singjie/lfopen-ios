//
//  TestXYTheme.m
//  CPTTestApp-iPhone
//
//  Created by Joan on 03/06/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "TestXYTheme.h"

@implementation TestXYTheme

+(NSString *)name
{
    return @"TestXYTheme";
}

-(id)init
{
    if ( (self = [super init]) ) {
        self.graphClass = [CPTXYGraph class];
    }
    return self;
}

#pragma mark -

-(void)applyThemeToAxis:(CPTXYAxis *)axis usingMajorLineStyle:(CPTLineStyle *)majorLineStyle
         minorLineStyle:(CPTLineStyle *)minorLineStyle majorGridLineStyle:majorGridLineStyle textStyle:(CPTTextStyle *)textStyle labelingPolicy:(CPTAxisLabelingPolicy)policy titleOffset:(CGFloat)titleOffset
{
    axis.labelingPolicy              = policy;
    axis.majorIntervalLength         = CPTDecimalFromDouble(1);
    axis.orthogonalCoordinateDecimal = CPTDecimalFromDouble(0.0);
    axis.tickDirection               = CPTSignNone;
    axis.minorTicksPerInterval       = 1;
    axis.majorTickLineStyle          = majorLineStyle;
    axis.minorTickLineStyle          = minorLineStyle;
    axis.axisLineStyle               = majorLineStyle;
    axis.majorTickLength             = 5.0f;
    axis.minorTickLength             = 3.0f;
    axis.labelTextStyle              = textStyle;
    axis.titleTextStyle              = textStyle;
    axis.majorGridLineStyle = majorGridLineStyle;
    axis.titleOffset                 = titleOffset;
}

-(void)applyThemeToPlotArea:(CPTPlotAreaFrame *)plotAreaFrame
{
    plotAreaFrame.paddingLeft   = 90;
    plotAreaFrame.paddingTop    = 10;
    plotAreaFrame.paddingRight  = 50;
    plotAreaFrame.paddingBottom = 60;
}

-(void)applyThemeToAxisSet:(CPTXYAxisSet *)axisSet
{
    CPTMutableLineStyle *majorLineStyle = [CPTMutableLineStyle lineStyle];

    majorLineStyle.lineCap   = kCGLineCapSquare;
    majorLineStyle.lineColor = [CPTColor grayColor];
    majorLineStyle.lineWidth = 2.0f;

    CPTMutableLineStyle *minorLineStyle = [CPTMutableLineStyle lineStyle];
    minorLineStyle.lineCap   = kCGLineCapSquare;
    minorLineStyle.lineColor = [CPTColor grayColor];
    minorLineStyle.lineWidth = 1.0f;

    CPTMutableLineStyle *majorGridLineStyle = [CPTMutableLineStyle lineStyle];
    majorGridLineStyle.lineWidth = 0.1f;
    majorGridLineStyle.lineColor = [CPTColor lightGrayColor];

    CPTMutableLineStyle *minorGridLineStyle = [CPTMutableLineStyle lineStyle];
    minorGridLineStyle.lineWidth = 0.25f;
    minorGridLineStyle.lineColor = [CPTColor blueColor];

    CPTMutableTextStyle *whiteTextStyle = [[CPTMutableTextStyle alloc] init];
    whiteTextStyle.color    = [CPTColor whiteColor];
    whiteTextStyle.fontSize = 14.0f;

    [self applyThemeToAxis:axisSet.xAxis usingMajorLineStyle:majorLineStyle minorLineStyle:minorLineStyle majorGridLineStyle:majorGridLineStyle textStyle:whiteTextStyle labelingPolicy:CPTAxisLabelingPolicyFixedInterval titleOffset:30];
    [self applyThemeToAxis:axisSet.yAxis usingMajorLineStyle:majorLineStyle minorLineStyle:minorLineStyle majorGridLineStyle:majorGridLineStyle textStyle:whiteTextStyle labelingPolicy:CPTAxisLabelingPolicyAutomatic titleOffset:50];
}

@end
