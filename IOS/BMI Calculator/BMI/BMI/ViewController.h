//
//  ViewController.h
//  BMI
//
//  Created by 权一恒 on 16/03/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <iAd/iAd.h>

@interface ViewController : UIViewController <ADBannerViewDelegate>
@property (strong, nonatomic) IBOutlet UITextField *heightext;
@property (strong, nonatomic) IBOutlet UITextField *weightext;
@property (strong, nonatomic) NSString *weight;
@property (strong, nonatomic) NSString *height;

@end
