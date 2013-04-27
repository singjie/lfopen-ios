//
//  LFViewController.h
//  LFOpen
//
//  Created by Lee Sing Jie on 18/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LFViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *timeLabel;
@property (weak, nonatomic) IBOutlet UILabel *averageSpeedLabel;
@property (weak, nonatomic) IBOutlet UILabel *speedLabel;
@property (weak, nonatomic) IBOutlet UILabel *inclineLabel;

@property (weak, nonatomic) IBOutlet UIImageView *statusView;

@end
