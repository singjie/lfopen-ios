//
//  LFViewController.m
//  LFOpen
//
//  Created by Lee Sing Jie on 18/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import "LFViewController.h"

#import "CorePlot-CocoaTouch.h"
#import "LFService.h"
#import "TestXYTheme.h"

#import "LFSpeedPlot.h"
#import "LFAverageSpeedPlot.h"

#import "LFData.h"

static CGFloat const kHostingViewStartY = 360;
static CGFloat const kHostingViewHeight = 300;

@interface LFViewController ()

@property (nonatomic, strong) CPTGraphHostingView *hostingView;

@property (nonatomic, strong) NSArray *plots;

@end

@implementation LFViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Live Graphs";
    
    // Setup Plots
    LFAverageSpeedPlot *averageSpeedPlot = [[LFAverageSpeedPlot alloc] init];
    LFSpeedPlot *speedPlot = [[LFSpeedPlot alloc] init];
    
    self.plots = @[averageSpeedPlot, speedPlot];
    
    CGFloat startPlotY = CGRectGetMaxY(self.averageSpeedLabel.frame);
    
    CGFloat availableY = self.view.frame.size.height - startPlotY - self.navigationController.navigationBar.frame.size.height;
    
    CGFloat heightForEachPlot = roundf(availableY/self.plots.count);
    
    CPTGraphHostingView *speedHostingView = [[CPTGraphHostingView alloc] initWithFrame:CGRectMake(0,
                                                                                                  startPlotY,
                                                                                                  self.view.frame.size.width,
                                                                                                  heightForEachPlot)];
    [self.view addSubview:speedHostingView];
    
    CPTGraphHostingView *averageSpeedHostingView = [[CPTGraphHostingView alloc] initWithFrame:CGRectMake(0,
                                                                                                    startPlotY+heightForEachPlot,
                                                                                                    self.view.frame.size.width,
                                                                                                         heightForEachPlot)];
    [self.view addSubview:averageSpeedHostingView];
    
    [averageSpeedPlot renderInView:averageSpeedHostingView
                         withTheme:[[TestXYTheme alloc] init]];
    
    [speedPlot renderInView:speedHostingView
                  withTheme:[[TestXYTheme alloc] init]];
    
    [NSTimer scheduledTimerWithTimeInterval:1
                                     target:self
                                   selector:@selector(reloadData:)
                                   userInfo:nil
                                    repeats:YES];
    
    [self reloadData:nil];
    
    [[LFService sharedInstance] registerService];
}

- (void)reloadData:(id)sender
{
    [self reloadLabels];
    [self reloadGraphs];
    [self updateStatusView];
}

- (void)reloadGraphs
{
    for (LFPlot *plot in self.plots) {
        [plot reloadData];
    }
}

- (void)reloadLabels
{
    NSArray *datasource = [[LFService sharedInstance] datasource];
    
    LFData *data = [datasource lastObject];
    
    self.inclineLabel.text = [NSString stringWithFormat:@"Incline: %.2f", data.incline];
    self.timeLabel.text = [NSString stringWithFormat:@"Elapsed Time: %f", data.timestamp];
    self.speedLabel.text = [NSString stringWithFormat:@"Current Speed (km/h): %.2f", data.speed];
    self.averageSpeedLabel.text = [NSString stringWithFormat:@"Average Speed (km/h): %.2f", data.averageSpeed];
}

- (void)updateStatusView
{
    LFServiceStatus status = [[LFService sharedInstance] status];
    
    switch (status) {
        case LFServiceStatusActive:
            self.statusView.image = [UIImage imageNamed:@"green"];
            break;
        case LFServiceStatusConnected:
            self.statusView.image = [UIImage imageNamed:@"yellow"];
            break;
        case LFServiceStatusDisconnected:
            self.statusView.image = [UIImage imageNamed:@"red"];
            break;
        default:
            break;
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
